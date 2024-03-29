#include "Mandelbrot.h"
#include <complex>

using namespace std;

int Mandelbrot::getIteration(double x, double y)
{
    complex<double> z = 0;
    complex<double> c(x, y);

    int iterations = 0;

    while (iterations < MAX_ITERATIONS)
    {
        z = z * z + c;

        if (abs(z) > 2.0)
            break;

        iterations++;

    }

    return iterations;
}
