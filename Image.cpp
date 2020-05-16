#include "Image.h"
Image::Image() : width(0), height(0), maxColor(0) {
    name ="";
 }
Image::Image(unsigned int w, unsigned int h, const char* n, unsigned int mC) : width(w), height(h),maxColor(mC) {
    name = n;
}
Image::Image(const Image& other)  {
        width = other.width;
        height = other.height;
        name = other.name;
        maxColor = other.maxColor;
}
Image& Image::operator=(const Image& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
        name = other.name;
        maxColor = other.maxColor;
    }
    return *this;
}
Image::~Image() {}
void Image::setName(std::string n) {
    name = n;
}
void Image::setWidth(int w) {
    width = w;
}
void Image::setHeight(int h) {
    height = h;
}
void Image::getInfo() {
    std::cout << "\nWidth: " << width << "Height: " << height  << "\nName: " << name << "Maximal Number for Color: " << maxColor;
}