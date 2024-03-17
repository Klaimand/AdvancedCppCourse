
#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

using namespace std;

int main()
{
    FractalCreator fractalCreator(600, 600);


    fractalCreator.addRange(0.0, RGB(0, 0, 0));
    fractalCreator.addRange(0.3, RGB(200, 50, 200));
    fractalCreator.addRange(0.5, RGB(230, 80, 230));
    fractalCreator.addRange(1.0, RGB(255, 150, 255));

    fractalCreator.addZoom(Zoom(35, 300, 0.01));

    fractalCreator.run("fractal.bmp");

    cout << "Finished" << endl;

    return 0;
}
