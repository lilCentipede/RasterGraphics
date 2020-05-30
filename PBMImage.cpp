#include "PBMImage.h"
PBM::PBM(const char* mN ,unsigned int w, unsigned int h, const char* n, unsigned int mC) :Image(mN, w, h, n, mC) {
	createPixels(h, w);
}
PBM::PBM(std::string mN , unsigned int w , unsigned int h , std::string n , unsigned int mC ) : Image(mN, w, h, n, mC) {
	createPixels(h, w);
}
PBM::PBM(const PBM& other) : Image(other) {
	copyPixels(other);
}
PBM& PBM::operator=(const PBM& other) {
	if (this != &other) {
		Image::operator=(other);
		deletePixels();
		copyPixels(other);
	}
	return *this;
}
PBM::~PBM() {
	deletePixels();
}
void PBM::createPixels(unsigned int h, unsigned int w) {
	pixel = new int* [h];
	for (unsigned int i = 0; i < h; i++) {
		pixel[i] = new int[w];
	}
}
void PBM::deletePixels() {
	for (unsigned int i = 0; i < height; i++) {
		delete[] pixel[i];
	}
	delete[] pixel;
}
void PBM::copyPixels(const PBM& other) {
	createPixels(other.getHeight(), other.getWidth());
	for (unsigned int i = 0; i < other.getHeight(); i++)
		for (unsigned int j = 0; j < other.getWidth(); j++)
		{
			pixel[i][j] = other.pixel[i][j];
		}
}
void PBM::readPixels() {
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++) {
			std::cin >> pixel[i][j];
		}
}
void PBM::readPixels(std::istream& in) {
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++) {
				in >> pixel[i][j];
		}
}

void PBM::printPixels() {
	for (unsigned int i = 0; i < height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			std::cout << pixel[i][j] << " ";
		}
		std::cout << '\n';
	}
}
void PBM::printPixels(std::ostream& out) {
	for (unsigned int i = 0; i < height; i++) {
		if (out) {
			for (unsigned int j = 0; j < width; j++) {
				out << pixel[i][j] << " ";
			}
			out << '\n';
		}
	}
}
int** PBM::copyofPixel() {
	int** copyP = new int* [height];
	for (unsigned int i = 0; i < height; i++) {
		copyP[i] = new int[width];
	}
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++)
		{
			copyP[i][j] = pixel[i][j];
		}

	return copyP;
}
void PBM::deletecopyofPixel(int** copyP) {
	for (unsigned int i = 0; i < height; i++) {
		delete[] copyP[i];
	}
	delete[] copyP;
}
void PBM::rotate(std::string direction) {
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
		height = height + width;
		width = height - width;
		height = height - width;
	}
	else std::cout << "Not a direction";
}
void PBM::grayscale() {}
void PBM::monochrome() {}
void PBM::negative() {
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++)
			pixel[i][j] = 1 - pixel[i][j];
}

Image* PBM::getCopy() {
	return new PBM(*this);
}

void PBM::save(std::ostream& out) {
	out << magicNumber << '\n'
		<< width << " " << height << '\n';
	printPixels(out);
}
std::istream& operator>>(std::istream& in, PBM& pb) {
	pb.readPixels(in);
	return in;
}
std::ostream& operator<< (std::ostream& out, PBM& pb) {
	pb.printPixels(out);
	return out;
}