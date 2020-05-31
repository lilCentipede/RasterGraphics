#include "SessionsManager.h"
#include "Commands.h"
#include <string>
class Core
{
private:
	int numberwords ;
	Commands command;
	std::string line;
	
public:
	Core();
	void getCommand(SessionsManager& sm);
	int countWords();
	std::string getFirstWord();
	std::string getSecondWord();
	void readCommand(SessionsManager& sm);
	Image* createImage(std::string&);
};
