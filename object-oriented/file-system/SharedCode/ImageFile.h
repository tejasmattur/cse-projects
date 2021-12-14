#pragma once
// Image file class declaration here
// TextFile declaration goes here
#include <iostream>
#include <vector>
#include <string>
#include "AbstractFile.h"

enum {
	imgSuccess = 0,
	inconsistentSize = 1,
	unsupportedChar = 2,
	appendNotSupported = 3,
};

class ImageFile : public AbstractFile {
private: // not sure if should be priv, protected, or public
	vector<char> contents;
	string name;
	char size;
public:
	ImageFile(string filename);
	virtual vector<char> read();
	virtual int write(vector<char> input); 
	virtual int append(vector<char> input);
	virtual unsigned int getSize();
	virtual string getName();
	int charToInt(char& c);
	int coordToIndex(int& x, int& y);
	virtual void accept(AbstractFileVisitor* vis);
	char getSizeChar();
	virtual string getType();
	virtual AbstractFile* clone();
	virtual void rename(string newname);
};