#include "ImageHistory.h"
ImageHistory::ImageHistory(Image* i) {
	name = i->getName();
	changes.push_back(i->getCopy());
}
ImageHistory::ImageHistory(std::string n, Image* i) {
	name = n;
	changes.push_back(i->getCopy());
}
ImageHistory::ImageHistory(const ImageHistory& other) {
	name = other.name;
	for (Image* i : other.changes){ 
		Image* im = i->getCopy();
		changes.push_back(im); }
}
ImageHistory& ImageHistory::operator=(const ImageHistory& other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < other.changes.size(); i++) {
			Image* im = other.changes[i]->getCopy();
			changes.push_back(im);
		}
		/*for (Image* i : other.changes) {
			changes.push_back(i);
		}*/
	}
	return *this;
}
ImageHistory::~ImageHistory(){
	for (int i = 0; i < changes.size();i++) {
		delete changes[i];
	}
	changes.clear();
}
void ImageHistory::undoChange() {
	if (changes[1] != nullptr) {
		delete changes.back();
		changes.back() = nullptr;
		changes.pop_back();
		std::cout << "Last change removed!\n";
	}
	else std::cout << "Back to the original\n";
}
Image* ImageHistory::getLastChange()const {
	return changes.back();
}
Image* ImageHistory::getOriginal()const {
	return changes.front();
}
void ImageHistory::addChange(std::string command) {
	if (command == "undo")
		undoChange();
	else if (command == "monochrome") {
		Image* i = changes.back()->getCopy();
		i->monochrome();
		changes.push_back(i);
	}
	else if (command == "grayscale") {
		Image* i = changes.back()->getCopy();
		i->grayscale();
		changes.push_back(i);
	}
	else if (command == "negative") {
		Image* i = changes.back()->getCopy();
		i->negative();
		changes.push_back(i);
	}
	else if (command == "rotateleft") {
		Image* i = changes.back()->getCopy();
		i->rotate("left");
		changes.push_back(i);
	}
	else if (command == "rotateright") {
		Image* i = changes.back()->getCopy();
		i->rotate("right");
		changes.push_back(i);
	}
	else std::cout << "Invalid command!\n";

}