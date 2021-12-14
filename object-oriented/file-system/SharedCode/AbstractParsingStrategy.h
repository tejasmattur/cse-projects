#pragma once

#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
	virtual vector<string> parse(string input) = 0;
};