#pragma once
#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
using namespace std;

enum {
	cpSuccess = 0,
	quit = 1,
	commandDoesNotExist = 2,
	addFail = 3,
};

class CommandPrompt {
	private:
		map<string, AbstractCommand*> commands;
		AbstractFileSystem* system;
		AbstractFileFactory* factory;
	public:
		CommandPrompt();
		void setFileSystem(AbstractFileSystem* newSystem);
		void setFileFactory(AbstractFileFactory* newFactory);
		int addCommand(string commandStr, AbstractCommand* commandObj);
		int run();
		bool checkOneWord(string input);
	protected:
		void listCommands();
		string prompt();
};
