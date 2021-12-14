// TODO: define your my_list class here
using namespace std;
#include "ListNode.h"
#include "my_list.h"
#include "my_list_iterator.h"

my_list::my_list() {
	f = nullptr;
	b = nullptr;
	size = 0;
}

my_list::my_list(const my_list& in) 
	: f(nullptr), b(nullptr), size(0) {
	if (in.f != nullptr) {
		ListNode* copier = in.f;
		while (size < in.size) {
			this->push_back(copier->getValue());
			copier = copier->getNext();
		}
	}
}

my_list& my_list::operator=(const my_list& in) {
	if (&in != this) {
		my_list::~my_list();
		my_list temp(in);
		swap(temp.f, f);
		swap(temp.b, b);
		swap(temp.size, size);
	}
	return *this;
}

my_list::~my_list() {
	this->clear();
} 

unsigned int my_list::get_size() {
	return size;
}

int& my_list::front() {
	if (size == 0) {
		throw exception("my_list is empty");
	} 
	return f->getValue();
}

int& my_list::back() {
	if (size == 0) {
		throw exception("my_list is empty");
	}
	return b->getValue();
}

void my_list::push_back(int val) {
	if (size == 0) {
		ListNode* thing = new ListNode(nullptr, nullptr, val);
		f = thing;
		b = thing;
	}
	else {
		ListNode* thing = new ListNode(nullptr, b, val);
		b->setNext(thing);
		b = thing;
	}
	size++;
}

void my_list::push_front(int val) {
	if (size == 0) {
		ListNode* thing = new ListNode(nullptr, nullptr, val);
		f = thing;
		b = thing;
	}
	else {
		ListNode* thing = new ListNode(f, nullptr, val);
		f->setPrevious(thing);
		f = thing;
	}
	size++;
}

void my_list::pop_back() {
	if (size == 0) {
		throw exception("my_list is empty");
	}
	if (size == 1) {
		delete b;
		f = nullptr;
		b = nullptr;
	}
	else {
		ListNode* newback = b->getPrevious();
		newback->setNext(nullptr);
		delete b;
		b = newback;
	}
	size--;
}

void my_list::pop_front() {
	if (size == 0) {
		throw exception("my_list is empty");
	}
	if (size == 1) {
		delete f;
		f = nullptr;
		b = nullptr;
	}
	else {
		ListNode* newfront = f->getNext();
		newfront->setPrevious(nullptr);
		delete f;
		f = newfront;
	}
	size--;
}

void my_list::clear() {
	while (size > 0) {
		this->pop_front();
	}
}

ListNode* my_list::get_first() {
	return f;
}

ListNode* my_list::get_last() {
	return b;
}

my_list_iterator my_list::begin() {
	if (size == 0) {
		my_list_iterator ret = my_list_iterator(this, true);
		return ret;
	}
	my_list_iterator ret = my_list_iterator(this, false);
	return ret;
}

my_list_iterator my_list::end() {
	my_list_iterator ret = my_list_iterator(this, true);
	return ret;
}

my_list_iterator my_list::insert(my_list_iterator refit, int val) {
	if (refit.is_end()) {
		push_back(val);
		--refit;
		return refit;
	}
	if (refit.get_mem() == f) {
		push_front(val);
		--refit;
		return refit;
	}
	ListNode* orig = refit.get_mem();
	ListNode* origPrev = orig->getPrevious();
	ListNode* insert = new ListNode(orig, origPrev, val);
	origPrev->setNext(insert);
	orig->setPrevious(insert);
	size++;
	--refit;
	return refit;
}

my_list_iterator my_list::erase(my_list_iterator refit) {
	if (refit.is_end() || refit.get_mem() == nullptr || size == 0) {
		throw exception("Cannot erase invalid");
	}
	ListNode* toErase = refit.get_mem();
	ListNode* nextErase = toErase->getNext();
	ListNode* prevErase = toErase->getPrevious();
	if (toErase == f) {
		nextErase->setPrevious(nullptr);
		f = nextErase;
	}
	else if (toErase == b) {
		prevErase->setNext(nullptr);
		b = prevErase;
		--refit;
	}
	else {
		prevErase->setNext(nextErase);
		nextErase->setPrevious(prevErase);
		prevErase->setNext(nextErase);
	}
	size--;
	++refit;
	delete toErase;
	toErase = nullptr;
	return refit;
} 