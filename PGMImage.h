#pragma once
#include <iostream>
#include <cstring>
#include "Image.h"
class PGM : public Image
{
private:
	int** pixel;
	int** copyofPixel();
	void deletecopyofPixel(int**);
public:
	PGM(unsigned int w = 0, unsigned int h = 0, const char* n = "", unsigned int mC = 0);
	PGM(const PGM& other);
	PGM& operator=(const PGM& other);
	~PGM();
	void createPixels(unsigned int, unsigned int);
	void deletePixels();
	void copyPixels(const PGM&);
	void readPixels(std::istream& in);
	void readPixels();
	void printPixels(std::ostream& out);
	void printPixels();
	void rotate(std::string direction);
	void grayscale();
	void monochrome();
	friend std::istream& operator>>(std::istream& in, PGM& pg);
	friend std::ostream& operator<<(std::ostream& out, PGM& pg);
};

