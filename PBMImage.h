#pragma once
#include "Image.h"
class PBM : public Image
{
private:
	int** pixel;
	int** copyofPixel();
	void deletecopyofPixel(int**);
public:
	PBM(unsigned int w =0, unsigned int h =0, const char* n ="", unsigned int mC = 0);
	PBM(const PBM& other);
	PBM& operator=(const PBM& other);
	~PBM();
	void createPixels(unsigned int , unsigned int);
	void deletePixels();
	void copyPixels(const PBM&);
	void readPixels(std::istream& in);
	void readPixels();
	void printPixels(std::ostream& out);
	void printPixels();
	void rotate(std::string direction);
	void grayscale();
	void monochrome();
	friend std::istream& operator>>(std::istream& in, PBM& pp);
	friend std::ostream& operator<<(std::ostream& out, PBM& pp);
};

