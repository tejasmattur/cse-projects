#pragma once
//enumerations
enum {
	programName = 0,
	gameName = 1,
	correctNumCommands = 2,
};
enum {
	mainsuccess = 0,
	failCommand = 1,
	failOpen = 2,
	allocationError = 3,
};

//declare functions, to be defined in lab2main.cpp
int usageMsg(char* program);