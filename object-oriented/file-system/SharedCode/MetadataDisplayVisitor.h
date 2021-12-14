#pragma once
// declaration of MetadataDisplayVisitor here
#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
	public:
		void visit_TextFile(TextFile* file);
		void visit_ImageFile(ImageFile* file);
};