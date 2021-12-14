// Do not modify this file! 

#include "ListNode.h"
#include <iostream>

using namespace std;

map<ListNode*, bool> ListNode::refCounts;

ListNode::ListNode(ListNode* next, ListNode* previous, int value)
	: next(next), previous(previous), value(value)
{

	// for testing purposes
	if (refCounts.find(this) != refCounts.end()) {
		if (refCounts[this]) {
			throw std::exception("this shouldn't happen");
		}
		else {
			refCounts[this] = true;
		}
	}
	else {
		refCounts.insert({ this,true });
	}
}

ListNode::~ListNode()
{
	// for testing purposes
	if (refCounts.find(this) == refCounts.end()) {
		throw std::exception("this shouldn't happen");
	}
	if (refCounts[this] == false) {
		throw std::exception("double deletion");
	}
	refCounts[this] = false;
}


// for debugging, you shouldn't call this in your own code
void ListNode::print()
{
	checkLiveness();
	cout << value << endl;
}

// for testing purposes
void ListNode::checkLiveness() {
	if (refCounts.find(this) == refCounts.end()) {
		throw exception("this shouldn't happen");
	}
	if (refCounts[this] == false) {
		throw exception("use of a dangling pointer");
	}
}


// These are important to you - you will call these function in your own code - checkLiveness() is for testing purposes, you can ignore what it does.
int& ListNode::getValue() {
	checkLiveness();
	return value;
}
ListNode* ListNode::getPrevious() {
	checkLiveness();
	return previous;
}
ListNode* ListNode::getNext() {
	checkLiveness();
	return next;
}
void ListNode::setPrevious(ListNode* new_previous) {
	checkLiveness();
	previous = new_previous;
}
void ListNode::setNext(ListNode* new_next) {
	checkLiveness();
	next = new_next;
}
void ListNode::setValue(int new_value) {
	checkLiveness();
	value = new_value;
}
