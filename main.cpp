#include <iostream>
#include <fstream>
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"

int main() {
	Image* i;
	PPM pb(3, 2, "letshope", 255);
	std::ifstream in("ColorText.txt");
	pb.readPixels(in);
	pb.printPixels();
	pb.rotate("left");
	pb.printPixels();
	pb.grayscale();
	pb.printPixels();
	
	return 0;
}