#pragma once
#include <iostream>
#include <cstring>
class Image
{
protected:
	unsigned int width;
	unsigned int height;
	std::string name;
	unsigned int maxColor;
public:
	Image();
	Image(unsigned int c = 0, unsigned int r = 0, const char* n = "",unsigned int mC = 0);
	Image(const Image& other);
	Image& operator=(const Image& other);
	virtual ~Image();
	std::string getName()const { return name; }
	unsigned const int getWidth()const { return width; }
	unsigned const int getHeight()const { return height; }
	unsigned const int getMaxColor()const { return maxColor; }
	void setName(std::string);
	void setWidth(int);
	void setHeight(int);
	void getInfo();
	virtual void readPixels() = 0;
	virtual void printPixels() = 0;
	virtual void grayscale() = 0;
	virtual void monochrome() = 0;
	//virtual void negative() = 0;
	virtual void rotate(std::string direction) = 0;
	//virtual void save(std::ostream&) = 0;
	//virtual void saveAs(std::ostream&) = 0;
};

