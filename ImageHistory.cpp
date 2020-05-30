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
	for (unsigned int i = 0; i < other.changes.size(); i++) {
		Image* im = other.changes[i]->getCopy();
		changes.push_back(im);
	}
	list_of_changes = other.list_of_changes;

}
ImageHistory& ImageHistory::operator=(const ImageHistory& other) {
	if (this != &other) {
		name = other.name;
		for (unsigned int i = 0; i < other.changes.size(); i++) {
			Image* im = other.changes[i]->getCopy();
			changes.push_back(im);
		}
		/*for (Image* i : other.changes) {
			changes.push_back(i);
		}*/
	}
	list_of_changes = other.list_of_changes;
	return *this;
}
void ImageHistory::deleteHistory() {
	for (unsigned int i = 0; i < changes.size(); i++) {
		delete changes[i];
	}
	changes.clear();
}
ImageHistory::~ImageHistory(){
	deleteHistory();
}
bool ImageHistory::anyChanges() {
	return (list_of_changes.size() != 0);
}
void ImageHistory::undoChange() {
	if (list_of_changes.size() <= 0) {
		throw std::exception("No changes to be undone");
	}
		delete changes.back();
		//changes.back() = nullptr;
		changes.pop_back();
		list_of_changes.pop_back();
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
		list_of_changes.push_back("monochrome");
	}
	else if (command == "grayscale") {
		Image* i = changes.back()->getCopy();
		i->grayscale();
		changes.push_back(i);
		list_of_changes.push_back("grayscale");
	}
	else if (command == "negative") {
		Image* i = changes.back()->getCopy();
		i->negative();
		changes.push_back(i);
		list_of_changes.push_back("negative");
	}
	else if (command == "rotateleft") {
		Image* i = changes.back()->getCopy();
		i->rotate("left");
		changes.push_back(i);
		list_of_changes.push_back("rotate left");
	}
	else if (command == "rotateright") {
		Image* i = changes.back()->getCopy();
		i->rotate("right");
		changes.push_back(i);
		list_of_changes.push_back("rotate right");
	}
	else std::cout << "Invalid command!\n";

}
void ImageHistory::printChanges() {
	std::cout << "Changes over \"" << name << "\" are:\n";
	if (anyChanges()){
		for (unsigned int i = 0; i < list_of_changes.size(); i++) 
				std::cout << i + 1 << '.' << list_of_changes[i] << '\n';
		}
	else std::cout << "none\n";
}
void ImageHistory::save() {
	Image* i = changes.back()->getCopy();
	deleteHistory();
	list_of_changes.clear();
	changes.push_back(i);
	std::fstream out(i->getName(), std::ios::out);
	i->save(out);
	out.close();
}