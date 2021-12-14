#include <string>
#include <sstream>
#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"

DisplayCommand::DisplayCommand(AbstractFileSystem* fs) : fileSystem(fs) {
}

int DisplayCommand::execute(string filename) {

	istringstream iss(filename);
	string fname;
	string arg;
	iss >> fname;
	AbstractFile* file = fileSystem->openFile(fname);

	if (file != nullptr) {
		if (iss >> arg) {
			if (arg == "-d") {
				vector<char> display = file->read();
				fileSystem->closeFile(file);
				vector<char>::iterator it;
				for (it = display.begin(); it != display.end(); ++it) {
					cout << *it;
				}
				cout << endl << endl;
				return dSuccess;
			}
			else {
				return dinvalidCommand;
			}
		}
		else {
			BasicDisplayVisitor* visitor = new BasicDisplayVisitor;
			file->accept(visitor);
			cout << endl << endl;
			fileSystem->closeFile(file);
			return dSuccess;
		}
	} 
	return dfileNoExist;
}

void DisplayCommand::displayInfo() {
	string message = "Display displays file contents and can be used as follows: ds <filename> (formatted), or ds <filename> -d (unformatted) \n" ;
	cout << message << endl;

}

