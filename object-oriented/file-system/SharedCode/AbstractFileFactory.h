#pragma once
// studio 18 - file factory interface declared here
#include "AbstractFile.h"
#include "AbstractFileSystem.h"

class AbstractFileFactory {
	public:
		virtual AbstractFile* createFile(string filename) = 0;
};