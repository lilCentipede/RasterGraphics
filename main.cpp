#include <iostream>
#include <fstream>
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
#include "ImageHistory.h"
#include "Session.h"
#include "SessionsManager.h"
#include "Core.h"

//Core core;
//	SessionsManager smanager;
//	while (true) {
//		core.readCommand(smanager);
//	}
/*std::string string = "Hello Boys";
int pos1 = string.find(' ');
int pos2 = string.find('\0');
std::string sub = string.substr(pos1 + 1, pos2 - pos1);
if (sub == "Boys")
std::cout << sub; */
int main() {
	SessionsManager sm;
	Core core;
	while (true) {
		core.getCommand(sm);
		core.readCommand(sm);		
		/*try {		
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}*/
	}
}