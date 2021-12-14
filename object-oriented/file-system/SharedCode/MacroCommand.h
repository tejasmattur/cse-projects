#pragma once

#include <vector>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractParsingStrategy.h"

enum {
	mSuccess = 0,

};


class MacroCommand : public AbstractCommand {
private:
	vector<AbstractCommand*> commands;
	AbstractParsingStrategy* macroParse;
	AbstractFileSystem* fileSystem;
public:
	MacroCommand(AbstractFileSystem* fs);
	virtual int execute(string args) override;
	virtual void displayInfo() override;
	void addCommand(AbstractCommand* com);
	void setParseStrategy(AbstractParsingStrategy* strat);
};