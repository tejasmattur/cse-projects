#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum {
	lsSuccess = 0,
	openFileFail = 1,
	commandIncorrect = 2,
};


class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
public:
	LSCommand(AbstractFileSystem* fs);
	virtual int execute(string arg) override;
	virtual void displayInfo() override;
	virtual ~LSCommand() = default;
};