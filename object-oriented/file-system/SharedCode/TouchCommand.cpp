#include <string>
#include <sstream>
#include "PasswordProxy.h"
#include "TouchCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"

TouchCommand::TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff) {
	fileSystem = fs;
	fileFactory = ff;
}

int TouchCommand::execute(string filename) {
	istringstream iss(filename);
	string fname;
	string p;
	iss >> fname;
	AbstractFile* file = fileFactory->createFile(fname);
	int added;
	if (file != nullptr) {
		if (iss >> p) {
			if (p == "-p") {
				string password;
				cout << "Enter password: ";
				getline(cin, password);
				PasswordProxy* pass = new PasswordProxy(file, password);
				added = fileSystem->addFile(fname, pass);
			}
			else {
				return invalidCommand; //invalid command
			}
		}
		else {
			added = fileSystem->addFile(fname, file);
		}
		if (added == 1) {
			return fileExists; //already exists
		}
		else if (added == 2) {
			fileSystem->deleteFile(fname);
			return fileNoExist;
		}
		else { 
			cout << fname << " created successfully.\n" << endl;
			return tSuccess; 
		}
	}
	return fileNotCreated;
}

void TouchCommand::displayInfo() {
	string message = "Touch creates a file and can be used as follows: touch <filename> \n";
	cout << message << endl;

}

