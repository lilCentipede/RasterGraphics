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
	PPM(const char* mN = "",unsigned int w = 0, unsigned int h = 0, const char* n = "", unsigned int mC = 0);
	PPM(std::string mN = "", unsigned int w = 0, unsigned int h = 0, std::string n = "", unsigned int mC = 256);
	PPM(const PPM& other);
	PPM& operator=(const PPM& other);
	~PPM();
	void createPixels(unsigned int, unsigned int);
	void deletePixels();
	void copyPixels(const PPM&);
	void readPixels(std::istream& in);
	void readPixelsBinary(std::istream&);
	void readPixels();
	void printPixels(std::ostream& out);
	void printPixelsBinary(std::ostream&);
	void printPixels();
	void rotate(std::string direction);
	void grayscale();
	void monochrome();
	void negative();
	Image* getCopy();
	void save(std::ostream& out);
	friend std::istream& operator>>(std::istream& in, PPM& pp);
	friend std::ostream& operator<<(std::ostream& out, PPM& pp);
};

