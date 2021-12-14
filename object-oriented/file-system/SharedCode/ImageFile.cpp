// definition of ImageFile class here
#include <iostream>
#include <vector>
#include <string>
#include "ImageFile.h"
#include "AbstractFileVisitor.h"
using namespace std;


ImageFile::ImageFile(string filename) {
	name = filename;
	contents = {};
	size = '\0';
}

unsigned int ImageFile::getSize() {
	return contents.size();
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> input) {
	int dim = charToInt(input[input.size() - 1]);
	contents.clear();
	size = input[input.size() - 1];
	vector<char> temp = input;
	temp.pop_back();
	if ((double) dim * (double) dim != (double) (temp.size())) {
		size = '\0';
		return inconsistentSize; //here is a problem in CAT
	}
	for (char c : temp) {
		if (c != 'X' && c != ' ') {
			contents.clear();
			size = '\0';
			return unsupportedChar;
		} 
		else {
			contents.push_back(c);
		}
	}
	return imgSuccess;
}

int ImageFile::append(vector<char> input) {
	return appendNotSupported;
}

vector<char> ImageFile::read() {
	/*int dimension = charToInt(this->size);
	for (int i = (dimension - 1); i >= 0; i--) {
		for (int j = 0; j < dimension; j++) { 
			cout << contents[coordToIndex(j, i)]; 
		}
		cout << endl; 
	}*/
	return contents;
}

int ImageFile::charToInt(char& c) {
	int sizeInt = c - '0';
	return sizeInt;
}

int ImageFile::coordToIndex(int& x, int& y) {
	int sizeInt = charToInt(size);
	int index = y * sizeInt + x;
	return index;
}

void ImageFile::accept(AbstractFileVisitor* vis) {
	if (vis) {
		vis->visit_ImageFile(this);
	}
}

char ImageFile::getSizeChar() {
	return size;
}

string ImageFile::getType() {
	return ".img";
}

AbstractFile* ImageFile::clone() {
	AbstractFile* t = new ImageFile(*this);
	return t;
}

void ImageFile::rename(string newname) {
	name = newname;
}