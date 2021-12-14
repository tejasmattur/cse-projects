#pragma once
// declaration of SimpleFileSystem class goes here
#include <map>
#include <set>
#include "AbstractFileSystem.h"
using namespace std;

enum {
	sfsSuccess= 0,
	fileAlreadyExists = 1,
	fileIsNull = 2,
	invalidFileName = 3,
	fileIsOpen = 4,
	fileDoesNotExist = 5,
	fileNotOpen = 6,
};

class SimpleFileSystem : public AbstractFileSystem {
	private:
		map<string, AbstractFile*> files;
		set<AbstractFile*> openFiles;
	public:
		virtual int addFile(string filename, AbstractFile* file);
		//virtual int createFile(string filename);
		virtual int deleteFile(string filename);
		virtual AbstractFile* openFile(string filename);
		virtual int closeFile(AbstractFile* file);
		virtual set<string> getFileNames();
};