#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum {
	tSuccess = 0,
	fileExists = 1,
	fileNoExist = 2,
	fileNotCreated = 3,
	fileCreated = 4,
	invalidCommand = 5,
};


class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
public:
	TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff);
	virtual int execute(string filename) override;
	virtual void displayInfo() override;
};