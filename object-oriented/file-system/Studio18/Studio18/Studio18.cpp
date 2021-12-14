// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"


using namespace std;

int main()
{
	SimpleFileSystem* mySystem = new SimpleFileSystem();
	SimpleFileFactory* myFactory = new SimpleFileFactory();
	string filename1 = "picture.img";
	string filename2 = "badpic.img";
	string filename3 = "text.txt";
	string filename4 = "blah.txt";
	AbstractFile* file1 = myFactory->createFile(filename1);
	AbstractFile* file2 = myFactory->createFile(filename2);
	AbstractFile* file3 = myFactory->createFile(filename3);
	AbstractFile* file4 = myFactory->createFile(filename4);
	mySystem->openFile(filename1);
	mySystem->openFile(filename2);
	mySystem->openFile(filename3);
	mySystem->openFile(filename4);
	vector<char> vect1 = { 'X','X',' ','X','2' };
	vector<char> vect2 = { 'a','X',' ','X','2' };
	vector<char> vect3 = { 'a', 'b', 'c', 'd','e','f','g' };
	vector<char> vect4 = { 'b','l','a','h' };
	file1->write(vect1);
	file2->write(vect2);
	file3->write(vect3);
	file4->write(vect4);
	cout << "This is file 1: " << filename1 << endl;
	file1->read();
	cout << "\n\n";
	cout << "This is file 2: " << filename2 << endl;
	file2->read();
	cout << "\n\n";
	cout << "This is file 3: " << filename3 << endl;
	file3->read();
	cout << "\n\n";
	cout << "This is file 4: " << filename4 << endl;
	file4->read();
	mySystem->closeFile(file1);
	mySystem->closeFile(file2);
	mySystem->closeFile(file3);
	mySystem->closeFile(file4);

	return 0;
}
