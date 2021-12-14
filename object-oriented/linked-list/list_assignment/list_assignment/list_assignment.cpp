// list_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <exception>
#include <algorithm>
using namespace std;
#include "ListNode.h"
#include "my_list.h"
#include "my_list_iterator.h"


int main()
{
    //Q1
    cout << "Q1\n" << endl;
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
    cout << "\n\n\n" << endl;

    //Q2
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
}


