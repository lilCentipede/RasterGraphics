#pragma once
#include "Image.h"
#include "ColorPixel.h"
class PPM : public Image
{
private:
	ColorPixel** pixel;
	ColorPixel** copyofPixel();
	void deletecopyofPixel(ColorPixel**);
public:
	PPM(unsigned int w = 0, unsigned int h = 0, const char* n = "", unsigned int mC = 0);
	PPM(const PPM& other);
	PPM& operator=(const PPM& other);
	~PPM();
	void createPixels(unsigned int, unsigned int);
	void deletePixels();
	void copyPixels(const PPM&);
	void readPixels(std::istream& in);
	void readPixels();
	void printPixels(std::ostream& out);
	void printPixels();
	void rotate(std::string direction);
	void grayscale();
	void monochrome();
	void negative();
	Image* getCopy();
	friend std::istream& operator>>(std::istream& in, PPM& pp);
	friend std::ostream& operator<<(std::ostream& out, PPM& pp);
};

