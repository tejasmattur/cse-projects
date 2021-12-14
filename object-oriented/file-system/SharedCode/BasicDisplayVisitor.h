#pragma once
// declaration of BasicDisplayVisitor here
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
class BasicDisplayVisitor : public AbstractFileVisitor {
	public:
		void visit_TextFile(TextFile* file);
		void visit_ImageFile(ImageFile* file);
};