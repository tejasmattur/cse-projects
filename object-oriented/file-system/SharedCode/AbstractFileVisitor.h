#pragma once
// declaration of the file visitor interface here

class TextFile;
class ImageFile;
class DirectoryFile;

class AbstractFileVisitor {
public:
	virtual void visit_ImageFile(ImageFile* file) = 0;
	virtual void visit_TextFile(TextFile* file) = 0;
};