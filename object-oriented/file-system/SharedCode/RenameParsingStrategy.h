#pragma once

using namespace std;
#include <vector>
#include <string>
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual vector<string> parse(string input);
};