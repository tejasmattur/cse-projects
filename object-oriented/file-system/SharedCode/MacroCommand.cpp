#include <string>
#include <sstream>
#include "PasswordProxy.h"
#include "MacroCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "RenameParsingStrategy.h"
#include "CopyCommand.h"
#include "RemoveCommand.h"

MacroCommand::MacroCommand(AbstractFileSystem* fs) : fileSystem(fs), macroParse(nullptr){}

int MacroCommand::execute(string args) {
	vector<string> input = macroParse->parse(args);
	if (input.size() == 2) {
		int i = 0;
		int run = 0;
		for (AbstractCommand* c : commands) {
			run = c->execute(input[i]);
			i++;
			if (run != 0) { break; }
		}
		return run;
	}
	return 1;
}

void MacroCommand::addCommand(AbstractCommand* com) {
	commands.push_back(com);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* strat) {
	macroParse = strat;
}

void MacroCommand::displayInfo() {
	string message = "Rename renames an existing file. Usage: rn <filename> <new_name> \n";
	cout << message << endl;

}

