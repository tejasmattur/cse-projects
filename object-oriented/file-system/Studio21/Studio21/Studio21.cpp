// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*In main(), dynamically allocate a SimpleFileSystem, a SimpleFileFactory, and a TouchCommand object 
(configured with the file system and file factory objects). Create a variable of type CommandPrompt and configure it 
with the file system, file factory, and touch command object you created. Call run() on the command prompt object and 
test quitting, asking for help, asking for help on the touch command, and executing the touch command. After quitting and 
returning from the run function, you should still have direct access to the FileSystem object in main(). You can verify “touch”
worked correctly by trying to open the file it created. As the answer to this question, describe the tests you ran.*/

#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\AbstractCommand.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include "..\..\\SharedCode\CommandPrompt.h"
int main()
{
	SimpleFileSystem* mySystem = new SimpleFileSystem();
	SimpleFileFactory* myFactory = new SimpleFileFactory();
	TouchCommand* myTC = new TouchCommand(mySystem, myFactory);
	CommandPrompt* myCP = new CommandPrompt();
	myCP->setFileSystem(mySystem);
	myCP->setFileFactory(myFactory);
	myCP->addCommand("touch", myTC);
	myCP->run();
	mySystem->openFile("test.txt");
	return 0;
}

