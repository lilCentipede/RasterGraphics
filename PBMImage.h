#pragma once
#include "Image.h"
class PBM : public Image
{
private:
	int** pixel;
	int** copyofPixel();
	void deletecopyofPixel(int**);
public:
	PBM(const char* mN = "" ,unsigned int w =0, unsigned int h =0, const char* n ="", unsigned int mC = 1);
	PBM(std::string mN = "", unsigned int w = 0, unsigned int h = 0, std::string n = "", unsigned int mC = 1);
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
	void negative();
	Image* getCopy();
	void save(std::ostream& out);
	friend std::istream& operator>>(std::istream& in, PBM& pp);
	friend std::ostream& operator<<(std::ostream& out, PBM& pp);
};

