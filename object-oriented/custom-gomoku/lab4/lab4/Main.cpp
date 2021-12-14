// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <iostream>
#include <sstream>
#include <vector>
#include <istream>
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include "GameBase.h"
#include "Gomoku.h"
#include "TicTacToe.h"
#include "Main.h"

int usageMsg(char* program) { //Usage message function to tell user proper input
	cout << "Usage: " << program << " TicTacToe or Gomoku" << endl;
	return failCommand;
}

int main(int argc, char* argv[]) {

	GameBase* g;
	if (argc == gameName) { //ensure correct number of arguments
		return usageMsg(argv[programName]);
	}
	try {
		g = GameBase::test(argc, argv);

	}
	catch (const bad_alloc& e) { //catch dynamic memory allocation error
		cout << e.what() << endl;
		return allocationError;
	}

	if (g == nullptr) { //g returns null if input is incorrect
		return usageMsg(argv[programName]);
	}
	
	int returnval = g->play(); //play game
	delete g; //destructor
	return returnval;
}
