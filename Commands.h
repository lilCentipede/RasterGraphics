#pragma once
#include <fstream>
#include <stdlib.h> 
#include "SessionsManager.h"
class Commands
{
public:
	void load(SessionsManager& smanager,Image*);
	void close(SessionsManager& smanager);
	void save(SessionsManager& smanager);
	//void saveAs(SessionsManager& smanager);
	void help();
	void exitProgram();
	void grayscale(SessionsManager& smanager);
	void monochrome(SessionsManager& smanager);
	void negative(SessionsManager& smanager);
	void rotateLeft(SessionsManager& smanager);
	void rotateRight(SessionsManager& smanager);
	void undo(SessionsManager& smanager);
	void add(SessionsManager& smanager, Image* i);
	void switchSession (SessionsManager& smanager,unsigned int id);
	void sessionInfo(SessionsManager& smanager);
};

