//  Define the TextFile class here
using namespace std;
#include <iostream>
#include <string>
#include "TextFile.h"
#include "AbstractFileVisitor.h"


TextFile::TextFile(string filename) {
	name = filename;
	contents = {};
}

unsigned int TextFile::getSize() {
	return contents.size();
}

string TextFile::getName() {
	return name;
}

int TextFile::write(vector<char> input) {
	contents = input;
	return 0;//for now, until later file types added
}

int TextFile::append(vector<char> input) {
	for (char c : input) {
		contents.push_back(c);
	}
	return 0;
}

vector<char> TextFile::read() {
	/*for (char c : contents) {
		cout << c;
	}*/
	return contents;
}

void TextFile::accept(AbstractFileVisitor* vis) {
	vis->visit_TextFile(this);
}

string TextFile::getType() {
	return ".txt";
}

AbstractFile* TextFile::clone() {
	AbstractFile* t = new TextFile(*this);
	return t;
}

void TextFile::rename(string newname) {
	name = newname;
}