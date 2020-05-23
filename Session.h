#pragma once
#include "ImageHistory.h"
class Session
{
private:
	unsigned int id;
	std::vector<ImageHistory> session;
public:
	Session(unsigned int id = 0, Image* i = nullptr );
	Session(unsigned int id , ImageHistory ihistory);
	Session(const Session& other);
	Session& operator=(const Session& other);
	~Session() {}
	unsigned int getId() const { return id; }
	void addImage(Image* i);
	void addChange(std::string command);
	ImageHistory getImageByName(std::string n);
	void undo();

};

