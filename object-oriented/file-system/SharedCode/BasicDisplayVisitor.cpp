// definitions of basic display visitor here
#include "AbstractFileVisitor.h"
#include "BasicDisplayVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"

void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
	vector<char> contents = file->read();
	for (char c : contents) {
		cout << c;
	}
}
void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
	vector<char> contents = file->read();
	char size = file->getSizeChar();
	int dimension = file->charToInt(size);
	for (int i = (dimension - 1); i >= 0; i--) {
		for (int j = 0; j < dimension; j++) {
			cout << contents[file->coordToIndex(j, i)];
		}
		cout << endl;
	}
}

