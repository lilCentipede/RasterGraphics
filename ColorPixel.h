#pragma once
#include <iostream>
#include <cassert>
class ColorPixel {
private:
	unsigned int MaxColor;
	unsigned int red;
	unsigned int green;
	unsigned int blue;
public:
	ColorPixel(unsigned int mC = 255, unsigned int r = 255, unsigned int g = 255, unsigned int b = 255);
	ColorPixel(const ColorPixel& other);
	ColorPixel& operator=(const ColorPixel& other);
	void grayscale(); //formula
	void monochrome(); //logicly 
	void negative(); //logicly
	void setColors(unsigned int r, unsigned int g, unsigned int b);
	void setMaxColor(unsigned int mC);
	void setMaxColorandColors(unsigned int mC, unsigned int r, unsigned int g, unsigned int b);
	void setMaxColorandColors(unsigned int mC);
	friend std::ostream& operator<<(std::ostream& out, const ColorPixel& cp);
	friend std::istream& operator>>(std::istream& in, ColorPixel& cp);
};

