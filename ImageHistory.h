#pragma once
#include <vector>
#include "Image.h"
class ImageHistory
{
private:
	std::string name;
	std::vector<Image*> changes;
public:
	ImageHistory(Image* i);
	ImageHistory(std::string n,Image* i);
	ImageHistory(const ImageHistory& other);
	ImageHistory& operator=(const ImageHistory& other);
	~ImageHistory();
	void addChange(std::string command);
	void undoChange();
	std:: string getName() { return name; }
	Image* getLastChange()const ;
	Image* getOriginal() const ;
};

