#include "Session.h"

Session::Session(unsigned int _id, Image* i) : id(_id) {
	ImageHistory im(i);
	session.push_back(im);
}
Session::Session(unsigned int _id, ImageHistory ihistory) :id(_id) {
	session.push_back(ihistory);
}
Session::Session(const Session& other) {
	id = other.id;
	for (ImageHistory im : other.session) {
		session.push_back(im);
	}
}
Session& Session::operator=(const Session& other) {
	if (this != &other) {
		id = other.id;
		for (ImageHistory im : other.session) {
			session.push_back(im);
		}
	}
	return *this;
}
void Session::addImage(Image* i) {
	ImageHistory im(i);
	session.push_back(im);
}
void Session::addChange(std::string command) {
	for (ImageHistory& im : session) {
		im.addChange(command);
	}
}
ImageHistory Session::getImageByName(std::string n) {
	for (ImageHistory im : session) {
		if (im.getName() == n) return im;
	}
	throw std::exception("No such image!");
}
void Session::undo() {
	for (ImageHistory& im : session) {
		im.undoChange();
	}
}
void Session::sessioninfo() {
	for (ImageHistory& im : session) {
		im.printChanges();
	}
}
void Session::save() {
	for (ImageHistory& im : session) {
		im.save();
	}
}
void Session::getInfo() {
	std::cout << "Current Session's ID: " << id<<'\n';
	std::cout << "Images in current session: \n";
	for (unsigned int i = 0; i < session.size() - 1; i++) {
		std::cout<<session[i].getName()<<',';
	}
	std::cout << session.back().getName()<<'\n';

	for (ImageHistory ih : session) {
		ih.printChanges();
	}
	
}