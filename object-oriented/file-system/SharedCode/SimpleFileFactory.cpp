// studio 18 - simple file factory definitions
#include "AbstractFile.h"
#include "AbstractFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
#include "SimpleFileFactory.h"

AbstractFile* SimpleFileFactory::createFile(string filename) {
	if (filename.length() < 5) {
		return nullptr;
	}
	int extIndex = filename.length() - 4;
	string filetype = filename.substr(extIndex);
	if (filetype == ".txt") {
		TextFile* createdFile = new TextFile(filename);
		return createdFile;
	}
	else if (filetype == ".img") {
		ImageFile* createdFile = new ImageFile(filename);
		return createdFile;
	}
	else {
		return nullptr;
	}
}