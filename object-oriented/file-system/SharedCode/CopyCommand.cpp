#include <string>
#include <iostream>
#include <sstream>
#include "TextFile.h"
#include "ImageFile.h"
#include "CopyCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
using namespace std;
CopyCommand::CopyCommand(AbstractFileSystem* fs) : fileSystem(fs) {
}

int CopyCommand::execute(string filename) {

	istringstream iss(filename);
	string fname;
	string arg;
	string type;
	iss >> fname;
	bool pwd = false;

	AbstractFile* file = fileSystem->openFile(fname);
	if (file != nullptr) {
		if (iss >> arg) {
			type = file->getType();
			AbstractFile* copy = file->clone();
			string copyname = arg + type;
			copy->rename(copyname);
			int added = fileSystem->addFile(copyname, copy);
			fileSystem->closeFile(file);
			if (added == 1) {
				cout << "File with filename already exists, please enter a unique filename.\n" << endl;
				return cfileExists; //already exists
			}
			else if (added != 0) {
				cout << "Error adding file" << endl;
				return cfileNoExist; //adding null file
			}
			else {
				cout << fname << " successfully copied to " << copyname << ".\n" << endl;
				return cSuccess;
			}
		}
		else {
			cout << "Please enter a valid filename\n" << endl;
			return cfileNoExist;
		}
	}
	return 7;
}

void CopyCommand::displayInfo() {
	string message = "Copy makes a copy of a specified file with a specified new filename. Usage: cp <file_to_copy> <copy_name> \n";
	cout << message << endl;

}

