#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum {
	cSuccess = 0,
	cinvalidCommand = 1,
	cfileNoExist = 2,
	cfileIsOpen = 3,
	cfileCantCreate = 4,
	cfileExists = 5,

};

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	CopyCommand(AbstractFileSystem* fs);
	virtual int execute(string filename) override;
	virtual void displayInfo() override;
};