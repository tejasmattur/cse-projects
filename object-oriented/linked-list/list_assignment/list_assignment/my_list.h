#pragma once
// TODO: declare your my_list class here
class my_list_iterator;

class my_list {
	private:
		ListNode* f;
		ListNode* b;
		int size;
	public:
		my_list();
		my_list(const my_list&);
		my_list& operator=(const my_list&);
		~my_list();
		unsigned int get_size();
		int& front();
		int& back();
		void push_back(int in);
		void push_front(int in);
		void pop_back();
		void pop_front();
		void clear();
		ListNode* get_first();
		ListNode* get_last();
		my_list_iterator begin();
		my_list_iterator end();
		my_list_iterator insert(my_list_iterator refit, int index);
		my_list_iterator erase(my_list_iterator refit);
};