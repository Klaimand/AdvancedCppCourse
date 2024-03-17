#include "FractalCreator.h"
#include <assert.h>
#include <iomanip>

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
    cout << m_width << " : " << m_height << endl;

    for (int y = 0; y < m_height; y++)
    {
        //if (y % 50 == 0) cout << (float)y/m_height*100.0f << "%" << endl;

        for (int x = 0; x < m_width; x++)
        {
            if (x % 100 == 0) cout << std::fixed << std::setprecision(1) << "\r" << ((float)y / m_height + (float)x / m_width / m_height) * 100.0f << "%";// << endl;

            auto coords = m_zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIteration(coords.first, coords.second);

            m_fractal[x + y * m_width] = iterations;

            if (iterations < Mandelbrot::MAX_ITERATIONS)
                m_histogram[iterations]++;

        }
    }

    cout << endl;

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
}

void FractalCreator::drawFractal()
{

    //RGB startColor(0, 0, 0);
    //RGB endColor(0, 255, 0);
    //RGB colorDiff = endColor - startColor;

    for (int y = 0; y < m_height; y++)
    {
        for (int x = 0; x < m_width; x++)
        {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = m_fractal[x + y * m_width];

            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_ranges[range];

            RGB& startColor = m_colors[range];
            RGB& endColor = m_colors[range + 1];

            RGB colorDiff = endColor - startColor;

            if (iterations < Mandelbrot::MAX_ITERATIONS)
            {
                //double hue = 0.0;
                int totalPixels = 0;

                for (int i = rangeStart; i <= iterations; i++)
                {
                    totalPixels += m_histogram[i];
                    //hue += (double)m_histogram[i] / m_total;
                }

                //green = pow(255, hue);
                //green = hue * 255;
                red = startColor.r + ((double)totalPixels / rangeTotal) * colorDiff.r;
                green = startColor.g + ((double)totalPixels / rangeTotal) * colorDiff.g;
                blue = startColor.b + ((double)totalPixels / rangeTotal) * colorDiff.b;

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

int FractalCreator::getRange(int iterations) const
{

    int range = 0;

    for (int i = 1; i < m_ranges.size(); i++)
    {
        range = i;

        if (m_ranges[i] > iterations)
        {
            break;
        }
    }

    range--;

    assert(range > -1);
    assert(range < m_ranges.size());

    return range;
}

void FractalCreator::run(string name)
{
    //addZoom(Zoom(295, m_height - 202, 0.1));
    //addZoom(Zoom(312, m_height - 304, 0.1));
    cout << "Calculate iterations..." << endl;
    calculateIterations();

    cout << "Calculate total iterations..." << endl;
    calculateTotalIterations();

    cout << "Calculate Range totals..." << endl;
    calculateRangeTotals();

    cout << "Draw fractal..." << endl;
    drawFractal();

    cout << "Write bitmap..." << endl;
    writeBitmap(name);

}
