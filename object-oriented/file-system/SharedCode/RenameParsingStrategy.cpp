#include "RenameParsingStrategy.h"
#include <sstream>

vector<string> RenameParsingStrategy::parse(string input) {
	istringstream iss(input);
	istringstream iss2(input);
	string both;
	string existing;
	vector<string> rename;
	getline(iss, both);
	rename.push_back(both);
	iss2 >> existing;
	rename.push_back(existing);
	return rename;
}