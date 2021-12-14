// Do not modify this file!

#pragma once
#include <map>

class ListNode {
public:
	ListNode() = delete;
	ListNode(ListNode* next, ListNode* previous, int value);
	~ListNode();

	// for debugging purposes
	void print();

	// getters and setters for important member variables - You should use these in your implementation of my_list and my_list_iterator when needed
	int& getValue();
	ListNode* getPrevious();
	ListNode* getNext();
	void setPrevious(ListNode* new_previous);
	void setNext(ListNode* new_next);
	void setValue(int new_value);

	// for checking for memory issues - double deletion, memory leaks, etc.
	static std::map<ListNode*, bool> refCounts;
private:
	// used for testing
	void checkLiveness();

	ListNode* next;
	ListNode* previous;
	int value;
};
