#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AbstractFileVisitor;
class SimpleFileSystem;

class AbstractFile {
	public:
		virtual ~AbstractFile() = default;
		virtual vector<char> read() = 0;
		virtual int write(vector<char> input) = 0;
		virtual int append(vector<char> input) = 0;
		virtual unsigned int getSize() = 0;
		virtual void rename(string newname) = 0;
		virtual string getName() = 0;
		virtual void accept(AbstractFileVisitor* vis) = 0; 
		virtual string getType() = 0;
		virtual AbstractFile* clone() = 0;
};


