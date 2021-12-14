#include <string>
#include "RemoveCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"

RemoveCommand::RemoveCommand(AbstractFileSystem* fs) : fileSystem(fs) {
}

int RemoveCommand::execute(string filename) {

	int remove = fileSystem->deleteFile(filename);
	if (remove == 5) {
		return rfileNoExist; //file doesn't exist
	}
	if (remove == 4) {
		return rfileIsOpen; //file is open
	}
	cout << filename << " has been removed \n" << endl;
	return rSuccess;

}

void RemoveCommand::displayInfo() {
	string message = "Remove removes a file and can be used as follows: rm <filename> \n";
	cout << message << endl;

}

