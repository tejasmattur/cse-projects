#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum {
	dSuccess = 0,
	dinvalidCommand = 1,
	dfileNoExist = 2,
	dfileIsOpen = 3,

};


class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	DisplayCommand(AbstractFileSystem* fs);
	virtual int execute(string filename) override;
	virtual void displayInfo() override;
};