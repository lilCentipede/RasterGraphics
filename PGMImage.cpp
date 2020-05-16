#include "PGMImage.h"
PGM::PGM(unsigned int w, unsigned int h, const char* n, unsigned int mC) :Image(w, h, n, mC) {
	createPixels(h, w);
}
PGM::PGM(const PGM& other) : Image(other) {
	copyPixels(other);
}
PGM& PGM::operator=(const PGM& other) {
	if (this != &other) {
		Image::operator=(other);
		deletePixels();
		copyPixels(other);
	}
	return *this;
}
PGM::~PGM() {
	deletePixels();
}
void PGM::createPixels(unsigned int h, unsigned int w) {
	pixel = new int* [h];
	for (int i = 0; i < h; i++) {
		pixel[i] = new int[w];
	}
}
void PGM::deletePixels() {
	for (int i = 0; i < height; i++) {
		delete[] pixel[i];
	}
	delete[] pixel;
}
void PGM::copyPixels(const PGM& other) {
	createPixels(other.getHeight(), other.getWidth());
	for (unsigned int i = 0; i < other.getHeight(); i++)
		for (unsigned int j = 0; j < other.getWidth(); j++)
		{
			pixel[i][j] = other.pixel[i][j];
		}
}
void PGM::readPixels() {
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++) {
			std::cin >> pixel[i][j];
		}
}
void PGM::readPixels(std::istream& in) {
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++) {
			if (in) 
				in >> pixel[i][j];
		}
}

void PGM::printPixels() {
	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			std::cout << pixel[i][j] << " ";
		}
		std::cout << '\n';
	}
}
void PGM::printPixels(std::ostream& out) {
	for (unsigned int i = 0; i < height; i++) {
		if (out) {
			for (unsigned int j = 0; j < width; j++) {
				out << pixel[i][j] << " ";
			}
			std::cout << '\n';
		}
	}
}
int** PGM::copyofPixel() {
	int** copyP = new int* [height];
	for (int i = 0; i < height; i++) {
		copyP[i] = new int[width];
	}
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++)
		{
			copyP[i][j] = pixel[i][j];
		}

	return copyP;
}
void PGM::deletecopyofPixel(int** copyP) {
	for (unsigned int i = 0; i < height; i++) {
		delete[] copyP[i];
	}
	delete[] copyP;
}
void PGM::rotate(std::string direction) {
	if (direction == "right") {
		int** copyP = copyofPixel();
		deletePixels();
		createPixels(width, height);
		for (unsigned int i = 0; i < height; i++)
			for (unsigned int j = 0; j < width; j++) {
				pixel[j][i] = copyP[height - i - 1][j];
			}
		deletecopyofPixel(copyP);
		height = height + width;
		width = height - width;
		height = height - width;
		std::cout << "Right rotation successful!\n";
	}
	else if (direction == "left") {
		int** copyP = copyofPixel();
		deletePixels();
		createPixels(width, height);
		for (unsigned int i = 0; i < height; i++)
			for (unsigned int j = 0; j < width; j++) {
				pixel[j][i] = copyP[i][width - j - 1];
			}
		deletecopyofPixel(copyP);
		std::cout << "Left rotation successful!\n";
		height = height + width;
		width = height - width;
		height = height - width;
	}
	else std::cout << "Not a direction";
}
void PGM::grayscale() {
	std::cout << "It is grayscale.\n";
}
void PGM::monochrome() {
	for(unsigned int i = 0;i<height;i++)
		for (unsigned int j = 0; j < width; j++) {
			if (pixel[i][j] <= maxColor / 2) 
				pixel[i][j] = 0;
			else pixel[i][j] = 1;
		}
}
std::istream& operator>>(std::istream& in, PGM& pg) {
	pg.readPixels(in);
	return in;
}
std::ostream& operator<< (std::ostream& out, PGM& pg) {
	pg.printPixels(out);
	return out;
}