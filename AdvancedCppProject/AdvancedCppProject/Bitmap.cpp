#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <fstream>

Bitmap::Bitmap(int width, int height)
{
	m_width = width;
	m_height = height;

	m_pPixels = make_unique<uint8_t[]>(width * height * 3);

	for (int i = 0; i < width * height * 3; i++)
	{
		m_pPixels[i] = 0;
	}
}

bool Bitmap::write(string filename)
{
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;
	file.open(filename, ios::out | ios::binary);

	if (!file)
		return false;

	file.write((char*)&fileHeader, sizeof(fileHeader));
	file.write((char*)&infoHeader, sizeof(infoHeader));
	file.write((char*)m_pPixels.get(), m_width * m_height * 3);



	file.close();

	if (!file)
		return false;

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b)
{
	uint8_t* pPixel = m_pPixels.get();
	pPixel += y * m_width * 3 + x * 3;

	pPixel[0] = b;
	pPixel[1] = g;
	pPixel[2] = r;
}
