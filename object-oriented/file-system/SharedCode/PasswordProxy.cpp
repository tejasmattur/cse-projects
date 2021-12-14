#include <iostream>
#include <vector>
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractFileVisitor.h"
#include "PasswordProxy.h"

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* infile, string inpassword) {
	file = infile;
	password = inpassword;
}

PasswordProxy::~PasswordProxy() {
	delete file;
	file = nullptr;
}

string PasswordProxy::passwordPrompt() {
	string inputPassword;
	string intakemsg = "Please input your password: ";
	cout << intakemsg << endl;
	cin >> inputPassword;
	//getline(cin, inputPassword);
	return inputPassword;
}

bool PasswordProxy::checkPassword(string inpwd) {
	if (inpwd == password) {
		return true;
	}
	return false;
}

vector<char> PasswordProxy::read() {
	string inpwd = passwordPrompt();
	if (checkPassword(inpwd)) {
		return file->read();
	}
	vector<char> empty = {};
	return empty;
}

int PasswordProxy::write(vector<char> input) {
	string inpwd = passwordPrompt();
	if (checkPassword(inpwd)) {
		return file->write(input);
	}
	return wrongPassword;
}

int PasswordProxy::append(vector<char> input) {
	string inpwd = passwordPrompt();
	if (checkPassword(inpwd)) {
		return file->append(input);
	}
	return wrongPassword;
}

unsigned int PasswordProxy::getSize() {
	return file->getSize();
}

string PasswordProxy::getName() {
	return file->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* vis) {
	string inpwd = passwordPrompt();
	if (checkPassword(inpwd)) {
		file->accept(vis);
	}
}

string PasswordProxy::getType() {
	return file->getType();
}

AbstractFile* PasswordProxy::clone() {
	AbstractFile* clone = file->clone();
	string clonepassword = password;
	PasswordProxy* t = new PasswordProxy(clone, clonepassword);
	return t;
}

void PasswordProxy::rename(string newname) {
	file->rename(newname);
}