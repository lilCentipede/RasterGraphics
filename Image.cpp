#include "Image.h"
Image::Image() : width(0),height(0),maxColor(0){
    magicNumber = "";
    name = "";
}
Image::Image(const char* mN, unsigned int w, unsigned int h, const char* n, unsigned int mC) : width(w), height(h),maxColor(mC) {
    magicNumber = mN;
    name = n;
}
Image::Image (std::string mN, unsigned int w, unsigned int h, std::string n, unsigned int mC) : width(w), height(h), maxColor(mC) {
    magicNumber = mN;
    name = n;
}
Image::Image(const Image& other)  {
        magicNumber = other.magicNumber;
        width = other.width;
        height = other.height;
        name = other.name;
        maxColor = other.maxColor;
}
Image& Image::operator=(const Image& other) {
    if (this != &other) {
        magicNumber = other.magicNumber;
        width = other.width;
        height = other.height;
        name = other.name;
        maxColor = other.maxColor;
    }
    return *this;
}
Image::~Image() {}
void Image::getInfo() {
    std::cout << "Width:" << width << "\nHeight: " << height << "\nName: " << name << "\nMaximal Number for Color: " << maxColor;
}
void Image::setMagicNumber(const char* mN) {
    magicNumber = mN;
}
void Image::setName(std::string n) {
    name = n;
}
void Image::setWidth(int w) {
    width = w;
}
void Image::setHeight(int h) {
    height = h;
}
Image* Image::getCopy() {
    return nullptr;
}