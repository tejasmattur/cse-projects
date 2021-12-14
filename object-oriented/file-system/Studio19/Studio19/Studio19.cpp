// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"


/*In main, try creating and then reading a file. Store the files contents into a local
variable declared in main. Then make an edit to the file’s contents and rewrite the file with the modified contents.
As the answer to this question, describe the tests you ran.*/

int main()
{
	SimpleFileSystem* mySystem = new SimpleFileSystem();
	SimpleFileFactory* myFactory = new SimpleFileFactory();
	string filename1 = "picture.img";
	string filename2 = "text.txt";
	AbstractFile* file1 = myFactory->createFile(filename1);
	AbstractFile* file2 = myFactory->createFile(filename2);
	vector<char> vect1a = { 'X','X',' ','X','2' };
	vector<char> vect2a = { 'a', 'b', 'c', 'd','e','f','g' };
	file1->write(vect1a);
	file2->write(vect2a);
	vector<char> vect1b = file1->read();
	vector<char> vect2b = file2->read();
	vect1b.push_back('b');
	vect2b.push_back('h');
	file1->write(vect1b);
	file2->write(vect2b);
	vector<char> read1 = file1->read();
	vector<char> read2 = file2->read();

	cout << "This is file 1: " << filename1 << endl;
	for (int i = 0; i < read1.size(); i++)
		cout << read1.at(i) << ' ';
	cout << "\n\n";

	cout << "This is file 2: " << filename2 << endl;
	for (int i = 0; i < read2.size(); i++)
		cout << read2.at(i) << ' ';

	return 0;
}
