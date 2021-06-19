#include "Start.h"
std::string getIndexWord(std::string line, int i) {
    std::string res = line;
    assert(i > 0);
    while (i) {
        if (i == 1) {
            int pos = res.find(' ');
            std::string sub = res.substr(0, pos);
            return sub;
        }
        else {
            int pos = res.find(' ');
            res = res.substr(pos + 1);
            i--;
        }

    }
}
int main() {
	startTheProgram();
   /* std::cout<<"first: "<<getIndexWord("Helluuuo cruel world", 1)<<'\n';

    std::cout<<"second: " << getIndexWord("Hello cruuuuuuel world", 2)<<'\n';
    std::string r = getIndexWord("Hello cruel tehe.txt", 3);
    std::cout << "third: " << r;
    std::cout << r.length();*/
  
}