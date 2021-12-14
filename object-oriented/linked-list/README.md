# Linked List Implementations

Doubly Linked List C++ implementation. Unit tests ensure that all Linked List operations work correctly.

Test code:

list<int>* original = new list<int>();
original->push_back(1);
original->push_back(2);
original->push_back(3);
list<int> copy = *original;
cout << "Original Back Value: " << original->back() << endl;
cout << "Copy Back Value: " << copy.back() << endl;
original->pop_back();
cout << "Original Back Value Post Orig Back Pop: " << original->back() << endl;
cout << "Copy Back Value Post Orig Back Pop: " << copy.back() << endl;
cout << "Memory Address Orig: " << original << endl;
cout << "Memory Address Copy: " << &copy << endl;
return 0;

Output:

Original Back Value: 3
Copy Back Value: 3
Original Back Value Post Orig Back Pop: 2
Copy Back Value Post Orig Back Pop: 3
Memory Address Orig: 000001C624D9F820
Memory Address Copy: 00000069830FF4B8

This code tests if a copy initialized with list assignment operator = is deep or shallow. I do this by creating a pointer to a new list. This initializes the memory othe heap, which is important to determine if the copy holds the same heap address. Iit does, then the copy is shallow. I push a few values into my original list, and theinitialize my copy. I print out the back values of both before making any edits tshow that they are the same list. I then pop the back value of only the original listI then print out the back values again. As expected for a deep copy constructor, thback values are different. This indicates that although the object stored at thoriginal list's allocated memory was edited, the object stored at the copy list'allocated memory remains unaltered (which entails that they are stored at differenmemory locations). To verify, I print the hexadecimal memories of both, and show thathey are different. Based on the justifications given above, std::list provides a deecopy constructor.

my_list_iterator is a bidirectional iterator, as it can be incremented and decremented. It is not a random access iterator, the next broadest iterator category, because it does not support an offset dereference operator[] or comparison operators < and > (as well as some other operators).

Test Code:

cout << "Q2\n" << endl;
my_list list = my_list();
bool randomSorted;
bool orderedSorted;
string sortedQ = "List Sorted?\n";
string negation = "";
//random order list
for (int i = 0; i < 10; i++) {
int temp = rand() & 100;
list.push_back(temp);
}
randomSorted = is_sorted(list.begin(), list.end());
if (!randomSorted) {
negation = "not ";
}
cout << "Random " << sortedQ << randomSorted << endl;
cout << "The Random List is " + negation + "sorted.\n" << endl;
negation = "";
list.clear();
//sorted order list
//list will be {0, 1, 2, ... , 9}
for (int i = 0; i < 10; i++) {
list.push_back(i);
}
orderedSorted = is_sorted(list.begin(), list.end());
if (!orderedSorted) {
negation = "not ";
}
cout << "Ordered " << sortedQ << orderedSorted << endl;
cout << "The Ordered List is " + negation + "sorted.\n" << endl;
negation = "";
return 0;

output:

Random List Sorted?
0
The Random List is not sorte
Ordered List Sorted?
1
The Ordered List is sorted.

It would not be possible to use std::sort to sort the my_list class. I did not make my own comparison operator '<' or '>', which is necessary for the std::sort algorithm to compare nodes and reorder them as necessary. To verify this, I wrote a brief block of code attempting to do something like sort((list.begin(), list.end()), and my program would not compile.
