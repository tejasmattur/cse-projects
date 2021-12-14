#include <string>
#include "LSCommand.h"
#include "SimpleFileSystem.h"
#include "MetadataDisplayVisitor.h"

LSCommand::LSCommand(AbstractFileSystem* fs) {
	fileSystem = fs;
}

int LSCommand::execute(string arg) {
	set<string> names = fileSystem->getFileNames();
	if (arg == "") {
		int j = 0;
		for (int i = 0; i < names.size(); i++) {
			string first = *next(names.begin(), i);
			cout << first << ' ';
			j++;
			if (j % 2 == 0) {
				cout << endl;
			}
		}
		cout << endl;
		return lsSuccess;
	}
	if (arg == "-m") {
		for (int i = 0; i < names.size(); i++) {
			string name = *next(names.begin(), i);
			AbstractFile* file = fileSystem->openFile(name);
			if (file == nullptr) { // opening file failed
				return openFileFail;
			}
			MetadataDisplayVisitor* visitor = new MetadataDisplayVisitor();
			file->accept(visitor);
			fileSystem->closeFile(file);
		}
		cout << endl;
		return lsSuccess;
	}
	else {
		cout << endl;
		return commandIncorrect;
	}
}

void LSCommand::displayInfo() {
	string message = "LS creates a file and can be used as follows: ls <filename> \n";
	cout << message << endl << endl;


}

