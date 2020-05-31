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
void Commands::saveAs(SessionsManager& smanager,std::string name) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.saveAs(name);
}
void Commands::close(SessionsManager& smanager) {
	if (smanager.getSize() == 0) {
		throw std::exception("No session has been started.");
	}
	smanager.removeCurrentSession();
}
void Commands::help() {
	std::cout << "All possible commands are:\n"
		<< "load <image> ----> creates Session with that file name\n"
		<< "add <image> ----> adds image to current session\n"
		<< "session info ----> gives information on current session\n"
		<< "switch <id> ----> switches to <id> session\n"
		<< "save ----> saves changes in the file\n"
		<< "saveas <image> ----> saves changes under new file name \n"
		<< "close ----> closes current session without saving to the file\n"
		<< "monochrome ----> does monochrome on current session of images\n"
		<< "grayscale ----> does grayscale on current session of images\n"
		<< "negative ----> does negative on current session of images\n"
		<< "rotate left ----> rotates left all images on current session\n"
		<< "rotate right ----> rotates right all images on current session\n"
		<< "undo ----> undoes last change on current session\n"
		<< "exit ----> exits from program\n";
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