// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\PasswordProxy.h"

int main()
{
	TextFile* myfile = new TextFile("myfile.txt");
	vector<char> text = { 'a', 'b', 'c', 'd', ' ', 'r', 'a', 'n', 'd', 'o', 'm', '.' };
	PasswordProxy* protectedmyfile = new PasswordProxy(myfile, "password");
	protectedmyfile->write(text);
	vector<char> toprint = protectedmyfile->read();
	for (char c : toprint) {
		cout << c;
	}
	return 0;
}

