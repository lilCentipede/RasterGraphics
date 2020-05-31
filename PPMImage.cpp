#include "PPMImage.h"
PPM::PPM(const char* mN ,unsigned int w, unsigned int h, const char* n, unsigned int mC) :Image(mN, w, h, n, mC) {
	createPixels(h, w);
}
PPM::PPM(std::string mN , unsigned int w , unsigned int h , std::string n , unsigned int mC ) : Image(mN, w, h, n, mC) {
	createPixels(h, w);
}
PPM::PPM(const PPM& other) : Image(other) {
	copyPixels(other);
}
PPM& PPM::operator=(const PPM& other) {
	if (this != &other) {
		Image::operator=(other);
		deletePixels();
		copyPixels(other);
	}
	return *this;
}
PPM::~PPM() {
	deletePixels();
}
void PPM::createPixels(unsigned int h, unsigned int w) {
	pixel = new ColorPixel* [h];
	for (unsigned int i = 0; i < h; i++) {
		pixel[i] = new ColorPixel[w];
	}
	for(int i =0;i<h;i++)
		for (int j = 0; j < w; j++) {
			pixel[i][j].setMaxColor(maxColor);
		}

}
void PPM::deletePixels() {
	for (unsigned int i = 0; i < height; i++) {
		delete[] pixel[i];
	}
	delete[] pixel;
}
void PPM::copyPixels(const PPM& other) {
	createPixels(other.getHeight(), other.getWidth());
	for (unsigned int i = 0; i < other.getHeight(); i++)
		for (unsigned int j = 0; j < other.getWidth(); j++)
		{
			pixel[i][j] = other.pixel[i][j];
		}
}
void PPM::readPixels() {
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++) {
			std::cin >> pixel[i][j];
		}
}
void PPM::readPixels(std::istream& in) {
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++) {
			if (in) in >> pixel[i][j];
		}
}
void PPM::printPixels() {
	for (unsigned int i = 0; i <height; i++) {
		for (unsigned int j = 0; j < width; j++) {
			std::cout << pixel[i][j] << " ";
		}
		std::cout << '\n';
	}
}
void PPM::printPixels(std::ostream& out) {
	for (unsigned int i = 0; i < height; i++) {
		if (out) {
			for (unsigned int j = 0; j < width; j++) {
				out << pixel[i][j] << " ";
			}
			out << '\n';
		}
	}
}
ColorPixel** PPM::copyofPixel() {
	ColorPixel** copyP = new ColorPixel* [height];
	for (unsigned int i = 0; i < height; i++) {
		copyP[i] = new ColorPixel[width];
	}
	for (unsigned int i = 0; i < height; i++)
		for (unsigned int j = 0; j < width; j++)
		{
			copyP[i][j] = pixel[i][j];
		}

	return copyP;
}
void PPM::deletecopyofPixel(ColorPixel** copyP) {
	for (unsigned int i = 0; i < height; i++) {
		delete[] copyP[i];
	}
	delete[] copyP;
}
void PPM::rotate(std::string direction) {
	if (direction == "right") {
		ColorPixel** copyP = copyofPixel();
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
		ColorPixel** copyP = copyofPixel();
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
void PPM::grayscale() {
	for(int i =0;i<height;i++)
		for (int j = 0; j < width; j++) {
			pixel[i][j].grayscale();
		}
}
void PPM::monochrome() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			pixel[i][j].monochrome();
		}
}
void PPM::negative() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			pixel[i][j].negative();
		}
}
Image* PPM::getCopy() {
	return new PPM(*this);
}
void PPM::save(std::ostream& out) {
	out << magicNumber << '\n'
			<< width << ' ' << height << '\n'
			<< maxColor << '\n';
	printPixels(out);
}
std::istream& operator>>(std::istream& in, PPM& pp) {
	pp.readPixels(in);
	return in;
}
std::ostream& operator<< (std::ostream& out, PPM& pp) {
	pp.printPixels(out);
	return out;
}