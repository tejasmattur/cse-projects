#pragma once
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include "AbstractFileVisitor.h"
class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	CatCommand(AbstractFileSystem* fs);
	virtual int execute(string arg) override;
	virtual void displayInfo() override;
};