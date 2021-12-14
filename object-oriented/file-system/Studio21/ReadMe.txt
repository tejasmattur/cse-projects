It's important to declare a virtual destructor in the base class to make sure that the derived class destructor is called properly when
an object of the derived class type is destoryed through a pointer of the base class type.

Because the command prompt only requires some system, factory, and command objects, it can be easily configured in a variety of ways. 
The command prompt can be easily configured to use a different file system implementation and different file factory implementations
due its previously discussed flexible nature. 

Test Code:
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

H:\332Final\Studio21\x64\Debug> Studio21.exe
Enter q to quit
Enter help for a list of commands
For information about a specific command: help <command name>
 $  help
Command does not exist
Enter q to quit
Enter help for a list of commands
For information about a specific command: help <command name>
 $ q

H:\332Final\Studio21\x64\Debug> Studio21.exe
Enter q to quit
Enter help for a list of commands
For information about a specific command: help <command name>
 $ help
touch
Enter q to quit
Enter help for a list of commands
For information about a specific command: help <command name>
 $ help touch
Touch creates a file and can be used as follows: touch <filename>

Enter q to quit
Enter help for a list of commands
For information about a specific command: help <command name>
 $ touch text.txt
text.txt created successfully.

Enter q to quit
Enter help for a list of commands
For information about a specific command: help <command name>
 $ q

 main tests run as instructed.
