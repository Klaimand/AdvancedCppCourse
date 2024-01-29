#include "FractalCreator.h"

FractalCreator::FractalCreator(int width, int height)
{
    m_width = width;
    m_height = height;

    m_histogram = make_unique<int[]>(Mandelbrot::MAX_ITERATIONS);
    m_fractal = make_unique<int[]>(m_width * m_height);

    m_bitmap = Bitmap(m_width, m_height);
    m_zoomList = ZoomList(m_width, m_height);

    addZoom(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

void FractalCreator::calculateIterations()
{
    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            auto coords = m_zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIteration(coords.first, coords.second);

            m_fractal[x + y * m_width] = iterations;

            if (iterations < Mandelbrot::MAX_ITERATIONS)
                m_histogram[iterations]++;

        }
    }

}

void FractalCreator::calculateTotalIterations()
{
    m_total = 0;

    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    {
        m_total += m_histogram[i];
    }
}

void FractalCreator::drawFractal()
{

    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = m_fractal[x + y * m_width];

            if (iterations != Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;
                for (int i = 0; i < iterations + 1; i++)
                {
                    hue += (double)m_histogram[i] / m_total;
                }

                //green = pow(255, hue);
                green = hue * 255;

            }

            m_bitmap.setPixel(x, y, red, green, blue);
        }
    }

}

void FractalCreator::addZoom(const Zoom& zoom)
{
	m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string name)
{
    m_bitmap.write(name);
}
