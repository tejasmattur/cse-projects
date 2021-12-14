#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum {
	rSuccess = 0,
	rfileNoExist = 1,
	rfileIsOpen = 2,
};


class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	RemoveCommand(AbstractFileSystem* fs);
	virtual int execute(string filename) override;
	virtual void displayInfo() override;
};