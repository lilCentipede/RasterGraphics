#include "SessionsManager.h"
#include "Commands.h"
///includes the commands operating the I/O process
class Core
{
private:
	int numberwords;
	Commands command;
	std::string line;
	
public:
	Core();
	///gets input and saves it
	void getCommand(SessionsManager& sm);
	///can count only to two, work in progress
	///@see getFirstWord() getSecondWord()
	int countWords();
	std::string getFirstWord();
	std::string getSecondWord();
	std::string getIndexWord(int i);
	///interpreters input
	void readCommand(SessionsManager& sm);
	///help-function using input for creating images
	Image* createImage(std::string&);
};
