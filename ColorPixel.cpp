#include "ColorPixel.h"
ColorPixel::ColorPixel(unsigned int mC, unsigned int r, unsigned int g, unsigned int b) : MaxColor(mC), red(r), green(g), blue(b) {}
ColorPixel::ColorPixel(const ColorPixel& other) {
	MaxColor = other.MaxColor;
	red = other.red;
	green = other.green;
	blue = other.blue;
}
ColorPixel& ColorPixel::operator=(const ColorPixel& other) {
	if (this != &other) {
		MaxColor = other.MaxColor;
		red = other.red;
		green = other.green;
		blue = other.blue;
	}
	return *this;
}
void ColorPixel::grayscale() {
	red = round(red * 0.299 + green * 0.587 + blue * 0.114);
	green = round(red * 0.299 + green * 0.587 + blue * 0.114);
	blue = round(red * 0.299 + green * 0.587 + blue * 0.114);
}
void ColorPixel::monochrome() {
	grayscale();
	if (red <= MaxColor/2) { red = 0; green = 0; blue = 0; }
	else { red = MaxColor; green = MaxColor; blue = MaxColor; }
}
void ColorPixel::negative() {
	red = MaxColor - red;
	green = MaxColor - green;
	blue = MaxColor - blue;
}
void ColorPixel::setColors(unsigned int r, unsigned int g, unsigned int b) {
	assert(r <= MaxColor && green <= MaxColor && blue <= MaxColor);
	red = r; green = g; blue = b;
}
void ColorPixel::setMaxColor(unsigned int mC) {
	MaxColor = mC;
}
void ColorPixel::setMaxColorandColors(unsigned int mC) {
	setMaxColor(mC);
	red = green = blue = MaxColor;
}
void ColorPixel::setMaxColorandColors(unsigned int mC, unsigned int r, unsigned int g, unsigned int b) {
	setMaxColor(mC);
	setColors(r, g, b);
}
std::ostream& operator<<(std::ostream& out, const ColorPixel& cp) {
	out << cp.red << " " << cp.green << " " << cp.blue << " ";
	return out;
}
std::istream& operator>>(std::istream& in, ColorPixel& cp) {
	in >> cp.red;
	in >> cp.green;
	in >> cp.blue;
	return in;
}
