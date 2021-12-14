#pragma once
// TODO: declare your my_list_iterator class here
class my_list_iterator {
	private:
		ListNode* curr_node;
		my_list* list;
		bool past_end;
	public:
		my_list_iterator(my_list* list, bool end);
		my_list_iterator(const my_list_iterator& in);
		int& operator*();
		bool operator==(const my_list_iterator compare_against) const;
		bool operator!=(const my_list_iterator compare_against) const;
		my_list_iterator& operator++();
		my_list_iterator& operator--();
		ListNode* get_mem();
		bool is_end();
};