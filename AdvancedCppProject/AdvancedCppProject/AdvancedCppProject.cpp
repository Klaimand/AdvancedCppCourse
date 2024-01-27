
#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;


    Bitmap bitmap(WIDTH, HEIGHT);
    

    double min =  99999.0;
    double max = -99999.0;

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            double xFractal = ((double)x / WIDTH - 0.5) * 2.0;
            double yFractal = ((double)y / HEIGHT - 0.5) * 2.0;

            int iterations = Mandelbrot::getIteration(xFractal, yFractal);

            uint8_t red = (uint8_t)(256 * ((double)iterations / Mandelbrot::MAX_ITERATIONS));

            bitmap.setPixel(x, y, red, red, red/2);

            if (red < min) min = red;
            else if (red > max) max = red;
        }
    }

    cout << min << " : " << max << endl;


    bitmap.write("test.bmp");

    cout << "Finished" << endl;

    return 0;
}
