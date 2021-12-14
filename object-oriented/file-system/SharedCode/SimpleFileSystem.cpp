// define methods of SimpleFileSystem class here
#include <iterator>
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

int SimpleFileSystem::addFile(string filename, AbstractFile* file) {
	if (files.count(filename) >= 1) {
		return fileAlreadyExists;
	}
	if (file == nullptr) {
		return fileIsNull;
	}
	pair<string, AbstractFile*> filepair = make_pair(filename, file);
	files.insert(filepair);
	return sfsSuccess;
}
/*
int SimpleFileSystem::createFile(string filename) {
	if (files.count(filename) >= 1) {
		return fileAlreadyExists;
	}
	if (filename.length() < 5) {
		return invalidFileName;
	}
	int extIndex = filename.length() - 4;
	string filetype = filename.substr(extIndex);
	if (filetype == ".txt") {
		TextFile* insertfile = new TextFile(filename);
		pair<string, AbstractFile*> filepair = make_pair(filename, insertfile);
		files.insert(filepair);
		return sfsSuccess;
	}
	else if (filetype == ".img") {
		ImageFile* insertfile = new ImageFile(filename);
		pair<string, AbstractFile*> filepair = make_pair(filename, insertfile);
		files.insert(filepair);
		return sfsSuccess;
	}
	else {
		return invalidFileName;
	}
	return 999; //will not get here
}
*/
int SimpleFileSystem::deleteFile(string filename) {
	auto it = files.find(filename);
	if (it == files.end()) {
		return fileDoesNotExist;
	}
	else {
		AbstractFile* checkOpen = it->second;
		if (openFiles.count(checkOpen) != 0) {
			return fileIsOpen;
		}
		files.erase(filename);
		delete checkOpen;
	}
	return sfsSuccess;
}

AbstractFile* SimpleFileSystem::openFile(string filename) {

	AbstractFile* flr;
	map<string, AbstractFile*>::iterator it;
	it = files.find(filename);
	if (it == files.end()) {
		return nullptr;
	}
	else {
		flr = it->second;
		if (openFiles.find(flr) != openFiles.end()) {
			return nullptr;
		}
	}
	openFiles.insert(flr);
	return flr;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
	set<AbstractFile*>::iterator it;
	it = openFiles.find(file);
	if (it == openFiles.end()) {
		return fileNotOpen;
	}
	openFiles.erase(it);
	return 0;
}

set<string> SimpleFileSystem::getFileNames() {

	set<string> fileNames;
	map<string, AbstractFile*>::iterator it;
	for (it = files.begin(); it != files.end(); ++it) {
		fileNames.insert(it->first);
	}
	return fileNames;

}

