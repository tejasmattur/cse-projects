#pragma once
#include "AbstractFile.h"
enum {
	wrongPassword = 1,
};

class PasswordProxy : public AbstractFile {
	private:
		AbstractFile* file;
		string password;
	public:
		PasswordProxy(AbstractFile* infile, string inpassword);
		~PasswordProxy();
		vector<char> read();
		int write(vector<char> input);
		int append(vector<char> input);
		unsigned int getSize();
		string getName();
		void accept(AbstractFileVisitor* vis);
		string getType();
		virtual AbstractFile* clone();
		virtual void rename(string newname);
	protected:
		string passwordPrompt();
		bool checkPassword(string inpassword);
};