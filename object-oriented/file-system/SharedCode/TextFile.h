#pragma once

#include "AbstractFile.h"

// TextFile declaration goes here
class TextFile : public AbstractFile {
	private: 
		vector<char> contents;
		string name;
	public:
		TextFile(string filename);
		virtual vector<char> read();
		virtual int write(vector<char> input);
		virtual int append(vector<char> input);
		virtual unsigned int getSize();
		virtual string getName();
		virtual void accept(AbstractFileVisitor* vis);
		virtual string getType();
		virtual AbstractFile* clone();
		virtual void rename(string newname);
};