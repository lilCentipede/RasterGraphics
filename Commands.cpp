#include "Commands.h"
void Commands::load(SessionsManager& smanager, Image* i) {
	smanager.createSession(i);
	std::cout << "Session with ID:" << smanager.getcurrentId() << " started!\n";
}
void Commands::save(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.save();
}
void Commands::help() {
	std::cout << "All possible commands are:\n"
		<< "load <image> ----> creates Session with that image.\n"
		<< "save ----> saves current Session, therefore cannot undo changes\n"
		<< "close ----> closes current Session without saving.\n"
		<< "exit ----> exit from program\n"
		<< "monochrome ----> does monochrome on current Session of images.\n"
		<< "grayscale ----> does grayscale on current Session of images.\n"
		<< "negative ----> does negative on current Session of images.\n"
		<< "rotate left ----> rotates left all images on current Session.\n"
		<< "rotate right ----> rotates right all images on current Session.\n"
		<< "undo ----> undoes last change on current Session.\n"
		<< "add <image> ----> adds image to current Session.\n"
		<< "switch <sessionId> ----> switches to <id> Session.\n";
}
void Commands::exitProgram() {
	std::cout << "Exiting the program..." << std::endl;
	exit(EXIT_SUCCESS);
}
void Commands::grayscale(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.getcurrentSession().addChange("grayscale");
}
void Commands::monochrome(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.getcurrentSession().addChange("monochrome");
}
void Commands::negative(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.getcurrentSession().addChange("negative");
}
void Commands::rotateLeft(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.getcurrentSession().addChange("rotateleft");
}
void Commands::rotateRight(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.getcurrentSession().addChange("rotateright");
}
void Commands::undo(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.getcurrentSession().addChange("undo");
}
void Commands::add(SessionsManager& smanager,Image* i) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.getcurrentSession().addImage(i);
}
void Commands::switchSession(SessionsManager& smanager,unsigned int id) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	if (id > smanager.getSize()) {
		throw std::exception("Session with that id does not exist.");
	}
	smanager.switchsession(id);
	smanager.getcurrentSession().getInfo();
}
void Commands::sessionInfo(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.getcurrentSession().getInfo();
}