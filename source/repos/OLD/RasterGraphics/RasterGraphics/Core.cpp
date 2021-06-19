#include "Core.h"
Core::Core() : numberwords(0){}
void Core::getCommand(SessionsManager& smanager) {
    std::getline(std::cin, line);
    numberwords = countWords();
}
int Core::countWords() {
    if (line[0] != '\0') {
        int count = 1;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] == ' ')
                count++;
        }
        return count;
    }
    throw std::exception("For information about the commands, type: help");
}
std::string Core::getFirstWord() {
    int pos = line.find(' ');
    std::string sub = line.substr(0, pos);
    return sub;
}
std::string Core::getSecondWord() {
    int pos1 = line.find(' ');
    std::cout << pos1 << '\n';
    int pos2 = line.find('\0');
    std::cout << pos2 << '\n';
    std::string sub = line.substr(pos1 + 1,-1 - pos1);
    return sub;
}
std::string Core::getIndexWord(int i) {
    std::string res = line;
    assert(i >0);
    while (i) {
        if (i == 1) {
            int pos = res.find(' ');
            res = res.substr(0, pos);
            return res;
        }
        else {
            int pos = res.find(' ');
            res = res.substr(pos + 1);
            i--;
        }
       
    }
}

void Core::readCommand(SessionsManager& sm) {
    if (numberwords == 1) {
        if (line == "monochrome")
            command.monochrome(sm);
        else if (line == "negative")
            command.negative(sm);
        else if (line == "grayscale")
            command.grayscale(sm);
        else if (line == "undo")
            command.undo(sm);
        else if (line == "save")
            command.save(sm);
        else if (line == "exit")
            command.exitProgram();
        else if (line == "help")
            command.help();
        else if (line == "close")
            command.close(sm);
        else std::cout << "Wrong command!\n";
    }
    else if (numberwords == 2) {
       // std::string first = getFirstWord();
        std::string first = getIndexWord(1);
        //std::string second = getSecondWord();
        std::string second = getIndexWord(2);
        if (first == "load") {
            Image* i = createImage(second);
            command.load(sm, i);
        }
        else if (first == "add") {
            Image* i = createImage(second);
            command.add(sm, i);
        }
        else if (first == "saveas") {
            command.saveAs(sm, second);
        }
        else if (first == "rotate")
        {
            if (second == "right")
                command.rotateRight(sm);
            else if (second == "left")
                command.rotateLeft(sm);
        }
        else if (first == "switch") {
            int id = std::stoi(second);
            command.switchSession(sm, id);
        }
        else if (first == "session" && second == "info")
            command.sessionInfo(sm);
        else std::cout << "Wrong command!\n";
    }
    else std::cout << "Wrong command!\n";
}
Image* Core::createImage(std::string& _name) {
    std::ifstream in(_name);
    if (!in.good())
        throw std::exception("Something is wrong with the file.");
    Image* image;
    std::string magicNumber;
    in >> magicNumber;
    if (magicNumber == "P1") {
        unsigned int width;
        unsigned int height;
        in >> width >> height;
        image = new PBM("P1", width, height, _name);
        image->readPixels(in);
        return image;
    }
    else if (magicNumber == "P2" ) {
        unsigned int width;
        unsigned int height;
        unsigned int maxColor;
        in >> width >> height >> maxColor;
        image = new PGM("P2", width, height, _name, maxColor);
        image->readPixels(in);
        return image;
    }
    else if (magicNumber == "P3") {
        unsigned int width;
        unsigned int height;
        unsigned int maxColor;
        in >> width >> height >> maxColor;
        image = new PPM("P3", width, height, _name, maxColor);
        image->readPixels(in);
        return image;
    }
    else
        throw std::exception("Incorrect image type");
    
}