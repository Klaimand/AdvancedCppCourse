#pragma once

#include <string>
#include "Zoom.h"

using namespace std;

class FractalCreator
{
public:
	FractalCreator(int width, int height);

	void calculateIterations();

	void drawFractal();

	void addZoom(const Zoom& zoom);

	void writeBitmap(string name);
};

