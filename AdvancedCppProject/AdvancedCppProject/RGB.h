#pragma once
struct RGB
{
	double r;
	double g;
	double b;

	RGB(double r_, double g_, double b_);

};

RGB operator- (const RGB& first, const RGB& second);

