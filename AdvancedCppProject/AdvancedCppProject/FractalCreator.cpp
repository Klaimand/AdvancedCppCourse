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

void FractalCreator::calculateRangeTotals()
{
    int rangeIndex = 0;

    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
    {
        int pixels = m_histogram[i];

        if (i >= m_ranges[rangeIndex + 1])
        {
            rangeIndex++;
        }

        m_rangeTotals[rangeIndex] += pixels;
    }

    for (int value : m_rangeTotals)
    {
        cout << "Range totals : " << value << endl;
    }
}

void FractalCreator::drawFractal()
{

    RGB startColor(0, 0, 0);
    RGB endColor(0, 255, 0);
    RGB colorDiff = endColor - startColor;

    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = m_fractal[x + y * m_width];

            if (iterations < Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;
                for (int i = 0; i < iterations + 1; i++)
                {
                    hue += (double)m_histogram[i] / m_total;
                }

                //green = pow(255, hue);
                //green = hue * 255;
                red = startColor.r + colorDiff.r * hue;
                green = startColor.g + colorDiff.g * hue;
                blue = startColor.b + colorDiff.b * hue;

            }

            m_bitmap.setPixel(x, y, red, green, blue);
        }
    }

}

void FractalCreator::addZoom(const Zoom& zoom)
{
	m_zoomList.add(zoom);
}

void FractalCreator::addRange(const double& rangeEnd, const RGB& rgb)
{
    m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    m_colors.push_back(rgb);


    if (m_bGotFirstRange)  m_rangeTotals.push_back(0);

    m_bGotFirstRange = true;
}

void FractalCreator::writeBitmap(string name)
{
    m_bitmap.write(name);
}

void FractalCreator::run(string name)
{
    //addZoom(Zoom(295, m_height - 202, 0.1));
    //addZoom(Zoom(312, m_height - 304, 0.1));

    calculateIterations();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractal();

    writeBitmap(name);

}
