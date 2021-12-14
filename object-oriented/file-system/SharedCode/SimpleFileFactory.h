#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
	public:
		AbstractFile* createFile(string filename);
};