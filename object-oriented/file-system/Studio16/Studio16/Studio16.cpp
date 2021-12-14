// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\AbstractFile.h"

int main()
{
	string str = "test file";
	TextFile test(str);
	vector<char> toWrite = {'a', 'b', 'c', 'd'};
	test.write(toWrite);
	test.read();
	vector<char> toAppend = { 'z' };
	test.append(toAppend);
	test.read();
	string name = test.getName();
	unsigned int size = test.getSize();
	cout << "File: " << name << " is of contents size " << size << endl;
	return 0;
}


