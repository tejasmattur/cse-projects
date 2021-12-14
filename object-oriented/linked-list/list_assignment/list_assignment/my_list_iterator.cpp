// TODO: define your my_list_iterator here
using namespace std;
#include "ListNode.h"
#include "my_list.h"
#include "my_list_iterator.h"

my_list_iterator::my_list_iterator(my_list* list, bool end) {
	this->list = list;
	if (end) {
		curr_node = nullptr;
		past_end = true;
	}
	else {
		curr_node = list->get_first();
		past_end = false;
	}
}

my_list_iterator::my_list_iterator(const my_list_iterator& in) 
	: curr_node(in.curr_node), list(in.list), past_end(in.past_end) {
	
}

int& my_list_iterator::operator*() {
	if (curr_node == nullptr) {
		throw exception("Invalid state in * operator");
	}
	return curr_node->getValue();
}

bool my_list_iterator::operator==(const my_list_iterator compare_against) const {
	if (list != compare_against.list) {
		throw exception("in == operator pointed to lists are different");
	}
	if (curr_node == compare_against.curr_node) {
		return true;
	}
	else {
		return false;
	}
}

bool my_list_iterator::operator!=(const my_list_iterator compare_against) const {
	if (list != compare_against.list) {
		throw exception("in == operator pointed to lists are different");
	}
	if (curr_node == compare_against.curr_node) {
		return false;
	}
	else {
		return true;
	}
}

my_list_iterator& my_list_iterator::operator++() {
	if (past_end) {
		throw exception("already past the end, cannot increment more");
	}
	if (curr_node == list->get_last()) {
		past_end = true;
	}
	curr_node = curr_node->getNext();
	return *this;
}

my_list_iterator& my_list_iterator::operator--() {
	if (curr_node == list->get_first()) {
		throw exception("Cannot decrement past first.");
	}
	if (past_end) {
		past_end = false;
		curr_node = list->get_last();
	}
	else {
		curr_node = curr_node->getPrevious();
	}
	return *this;
}

ListNode* my_list_iterator::get_mem() {
	return curr_node;
}

bool my_list_iterator::is_end() {
	return past_end;
}