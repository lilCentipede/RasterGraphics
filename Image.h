#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <cassert>
const int MAX_MAGIC_NUMBER = 3;
class Image
{
protected:
	std::string magicNumber;
	unsigned int width;
	unsigned int height;
	std::string name;
	unsigned int maxColor;
public:
	Image();
	Image(const char* mN ="",unsigned int w = 0, unsigned int h = 0, const char* n = "",unsigned int mC = 0);
	Image(std::string mN = "", unsigned int w = 0, unsigned int h = 0, std::string n = "", unsigned int mC = 0);
	Image(const Image& other);
	Image& operator=(const Image& other);
	virtual ~Image();
	std::string getName()const { return name; }
	std::string getMagicNumber() const { return magicNumber; }
	unsigned const int getWidth()const { return width; }
	unsigned const int getHeight()const { return height; }
	unsigned const int getMaxColor()const { return maxColor; }
	void setMagicNumber(const char* mN);
	void setName(std::string);
	void setWidth(int);
	void setHeight(int);
	void getInfo();
	virtual Image* getCopy();
	virtual void readPixels() = 0;
	virtual void readPixels(std::istream&) = 0;
	virtual void printPixels() = 0;
	virtual void printPixels(std::ostream&) = 0;
	virtual void grayscale() = 0;
	virtual void monochrome() = 0;
	virtual void negative() = 0;
	virtual void rotate(std::string direction) = 0;
	virtual void save(std::ostream&) = 0;
	//virtual void saveAs(std::ostream&) = 0;
};

