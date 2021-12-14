#pragma once
// declaration of the interface all file systems provide goes here
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "AbstractFile.h"
using namespace std;

class AbstractFileSystem {
	public:
		virtual int addFile(string filename, AbstractFile* file) = 0;
		//virtual int createFile(string filename) = 0;
		virtual int deleteFile(string filename) = 0;
		virtual AbstractFile* openFile(string filename) = 0;
		virtual int closeFile(AbstractFile* file) = 0;
		virtual set<string> getFileNames() = 0;
};