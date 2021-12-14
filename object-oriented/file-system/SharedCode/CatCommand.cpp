#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "CatCommand.h"
using namespace std;


CatCommand::CatCommand(AbstractFileSystem* fs) {
	fileSystem = fs;
}

int CatCommand::execute(string arg) {
	string filename;
	string optional;
	int ret = 10;
	vector<char> fileContents;
	vector<char> output;
	stringstream mystream(arg);
	mystream >> filename;
	bool writeCond = true;
	AbstractFile* file = fileSystem->openFile(filename);
	if (file == nullptr) {
		return 9;
	}
	if (mystream >> optional) {
		if (optional == "-a") {
			writeCond = false;
			fileContents = file->read();
			for (int i = 0; i < fileContents.size(); i++) {
				cout << *next(fileContents.begin(), i);
			}
			cout << endl;
		}
	}
	cout << "Now editing: " << filename << endl;
	string line;
	while (1) {
		getline(cin, line);
		line += "\n";
		if (line == ":q\n") {
			output.clear();
			ret = 0;
			fileSystem->closeFile(file);
			return ret;
		}
		else if (line == ":wq\n") {
			if (writeCond) {
				output.pop_back();
				ret = file->write(output);
			}
			else {
				output.pop_back();
				ret = file->append(output);
			}
			fileSystem->closeFile(file);
			return ret;
		}
		else {
			for (char c : line) {
				output.push_back(c);
			}
		}
	}
	fileSystem->closeFile(file);
	cout << endl << endl;
	return ret;

	
}

void CatCommand::displayInfo() {
	string message = "Cat writes or appends user input to a specified file. Usage: cat <filename> [-a] (use -a to append) \n";
	cout << message << endl;

}