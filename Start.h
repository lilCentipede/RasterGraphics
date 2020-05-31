#pragma once
#include <iostream>
#include <fstream>
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
#include "ImageHistory.h"
#include "Session.h"
#include "SessionsManager.h"
#include "Core.h"
void startTheProgram() {
	SessionsManager sm;
	Core core;
	std::cout << "Welcome to this simple Image Editor. Be kind to the program, it's a lil sensitive <3.\nFor instructions on how to use the program, type: help\n";
	while (true) {
		try {
			std::cout << ">>>";
			core.getCommand(sm);
			core.readCommand(sm);
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}