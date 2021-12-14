#pragma once
using namespace std;
class AbstractCommand {
	public:
		virtual ~AbstractCommand() = default;
		virtual int execute(string info) = 0;
		virtual void displayInfo() = 0;
};
