#include "RGB.h"

RGB::RGB(double r_, double g_, double b_)
{
	r = r_;
	g = g_;
	b = b_;
}

RGB operator- (const RGB& first, const RGB& second)
{
	return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
}