// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\CopyCommand.h"
#include "..\..\\SharedCode\DisplayCommand.h"
#include "..\..\\SharedCode\RemoveCommand.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\CatCommand.h"
#include "..\..\\SharedCode\LSCommand.h"
#include "..\..\\SharedCode\MacroCommand.h"
#include "..\..\\SharedCode\RenameParsingStrategy.h"


int main()
{
	/*Update main to create a MacroCommand object configured with a
	RenameParsingStrategy object as its AbstractParsingStrategy and a CopyCommand as well as a RemoveCommand object as its command 
	objects. Add the MacroCommand to the CommandPrompt so it will be invoked when the user provides “rn” as input*/

	/*update main to configure the command prompt with each of the above commands. Test your commands thoroughly. In your ReadMe.txt
	file, document the tests you ran as well as any errors/bugs you encountered while working. 
	Also, at the top of your Readme.txt, list each group member’s name and describe how the work was split between the group members. 
	Note: Make sure to avoid memory leaks, double deletions, etc.*/

	SimpleFileSystem* fileSys = new SimpleFileSystem;
	SimpleFileFactory* fileFac = new SimpleFileFactory;
	MacroCommand* macro = new MacroCommand(fileSys);
	RenameParsingStrategy* strat = new RenameParsingStrategy;
	CopyCommand* copy = new CopyCommand(fileSys);
	RemoveCommand* remove = new RemoveCommand(fileSys);
	TouchCommand* touch = new TouchCommand(fileSys, fileFac);
	DisplayCommand* display = new DisplayCommand(fileSys);
	CatCommand* cat = new CatCommand(fileSys);
	LSCommand* ls = new LSCommand(fileSys);

	CommandPrompt cmd;

	macro->setParseStrategy(strat);
	macro->addCommand(copy);
	macro->addCommand(remove);

	cmd.addCommand("rn", macro);
	cmd.addCommand("cp", copy);
	cmd.addCommand("ls", ls);
	cmd.addCommand("ds", display);
	cmd.addCommand("touch", touch);
	cmd.addCommand("cat", cat);
	cmd.addCommand("rm", remove);

	return cmd.run();
}


