// definitions of metadata visitor here
#include <iostream>
#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFile.h"
#include "MetadataDisplayVisitor.h"
using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
	string filename = file->getName();
	int size = file->getSize();
	string filetype = "text";
	cout << filename << "\t" << filetype << "\t" << size << endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	string filename = file->getName();
	int size = file->getSize();
	string filetype = "image";
	cout << filename << "\t" << filetype << "\t" << size << endl;
}