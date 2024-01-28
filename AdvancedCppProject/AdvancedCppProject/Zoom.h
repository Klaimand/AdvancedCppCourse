#pragma once


struct Zoom
{
	int x = 0;
	int y = 0;

	double scale = 0.0;

	Zoom(int x, int y, double scale)
	{
		this->x = x;
		this->y = y;

		this->scale = scale;
	}
};

