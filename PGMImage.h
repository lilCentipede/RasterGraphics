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
	PGM(const char* mN = "",unsigned int w = 0, unsigned int h = 0, const char* n = "", unsigned int mC = 0);
	PGM(std::string mN = "", unsigned int w = 0, unsigned int h = 0, std::string n = "", unsigned int mC = 16);
	PGM(const PGM& other);
	PGM& operator=(const PGM& other);
	~PGM();
	Image* getCopy();
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
	void negative();
	void save(std::ostream& out);
	friend std::istream& operator>>(std::istream& in, PGM& pg);
	friend std::ostream& operator<<(std::ostream& out, PGM& pg);
};

