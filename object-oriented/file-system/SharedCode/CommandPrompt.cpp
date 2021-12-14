#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include "CommandPrompt.h"

CommandPrompt::CommandPrompt() : commands({}), system(nullptr), factory(nullptr) {}

void CommandPrompt::setFileSystem(AbstractFileSystem* newSystem) {
	system = newSystem;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* newFactory) {
	factory = newFactory;
}

int CommandPrompt::addCommand(string commandStr, AbstractCommand* commandObj) {
	if (commands.count(commandStr) != 0) {
		return addFail;
	}
	pair<string, AbstractCommand*> commandpair = make_pair(commandStr, commandObj);
	commands.insert(commandpair);
	if (commands.count(commandStr) != 1) {
		return addFail;
	}
	return cpSuccess;
}

void CommandPrompt::listCommands() {
	map<string, AbstractCommand*>::iterator it;
	for (it = commands.begin(); it != commands.end(); ++it) {
		cout << it->first << endl;
	}
}

int CommandPrompt::run() {
	while (true) {
		string input = prompt();
		if (input == "q") {
			return quit;
		}
		else if (input == "help") {
			listCommands();
		}
		else if (checkOneWord(input)) {
			std::map<string, AbstractCommand*>::iterator it;
			it = commands.find(input);
			if (it != commands.end()) {
				int execStatus = it->second->execute("");
				if (execStatus != cpSuccess) {
					cout << "Your command experienced an Error!" << endl;
				}
			}
			else {
				cout << "Command does not exist" << endl;
				//return commandDoesNotExist;
			}
		}
		else {
			istringstream iss(input);
			string firstWord;
			iss >> firstWord;
			if (firstWord == "help") {
				string stringSecond;
				iss >> stringSecond;
				std::map<string, AbstractCommand*>::iterator it;
				it = commands.find(stringSecond);
				if (it != commands.end()) {
					it->second->displayInfo();
				}
				else {
					cout << "Command does not exist" << endl;
					//return commandDoesNotExist;
				}
			}
			else {
				std::map<string, AbstractCommand*>::iterator it;
				it = commands.find(firstWord);
				if (it != commands.end()) {
					string options = input.substr(input.find_first_of(' ') + 1, string::npos);
					if (it->second->execute(options) != cpSuccess) {
						cout << "Your command experienced an Error!" << endl;
					}
				}
				else {
					cout << "Command does not exist" << endl;
					//return commandDoesNotExist;
				}
			}
			
		}

	}
}


string CommandPrompt::prompt() {
	cout << "Enter q to quit" << endl;
	cout << "Enter help for a list of commands" << endl;
	cout << "For information about a specific command: help <command name>" << endl;
	cout << " $ ";
	string input;
	getline(cin, input);
	return input;
}

bool CommandPrompt::checkOneWord(string input) {
	for (char c : input) {
		if (c == ' ') {
			return false;
		}
	}
	return true;
}