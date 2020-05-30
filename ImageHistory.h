#pragma once
#include <vector>
#include <fstream>
#include "Image.h"
#include "PBMImage.h"
#include "PGMImage.h"
#include "PPMImage.h"
class ImageHistory
{
private:
	std::string name;
	std::vector<Image*> changes;
	std::vector<std::string> list_of_changes;
	void deleteHistory();
public:
	ImageHistory(Image* i);
	ImageHistory(std::string n,Image* i);
	ImageHistory(const ImageHistory& other);
	ImageHistory& operator=(const ImageHistory& other);
	~ImageHistory();
	bool anyChanges();
	void addChange(std::string command);
	void undoChange();
	std:: string getName() { return name; }
	Image* getLastChange()const ;
	Image* getOriginal() const ;
	void printChanges();
	void save();
};

