#pragma once
#include <string>
#include <memory>

using namespace std;

class Bitmap
{
	int m_width = 0;
	int m_height = 0;

	unique_ptr<uint8_t[]> m_pPixels = nullptr;

public:
	Bitmap(int width, int height);

	bool write(string filename);

	void setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
};

