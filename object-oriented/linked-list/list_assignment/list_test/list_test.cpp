#include "CppUnitTest.h"
#include "../list_assignment/ListNode.h"
#include "../list_assignment/my_list.h"
#include "../list_assignment/my_list_iterator.h"
#include<cstdlib>
#include<list>
#include<ctime>

using namespace std;


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// NOTES: At first, there will be many errors in the tests. This is because the my_list class, my_list_iterator classes are not yet declared or defined. My suggestion would be:
// 1. comment out all tests to begin with. Comment out each TEST_CLASS.
// 2. as you declare the full my_list class from part 1, go ahead and define each function to do nothing or return some default value. Then uncomment the TEST_CLASS for part 1.
// at this point, the test should compile, however they should fail. As you implement the required functionality, tests should start to pass.
// 3. once you are passing all or most of the part 1 tests, move on to part 2 or part 3. These parts can be worked on interchangeably. Uncomment the tests for each part once you have declared and defined
// the required functions for each class
// 4. part 4 cannot be completed until after part 3 is complete.


namespace ListTests
{
	// tests for part 1: my_list basics
	
	TEST_CLASS(MyListTests)
	{
	public:

		TEST_METHOD(defaultconstruction)
		{
			try {
				ListNode::refCounts.clear();
				my_list l;
				Assert::AreEqual((unsigned int)0, l.get_size());
				Assert::IsNull(l.get_first());
				Assert::IsNull(l.get_last());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(pushback_single) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				srand(time(NULL));
				int i = rand() % 100;
				l.push_back(i);
				Assert::AreEqual((unsigned int)1, l.get_size());
				Assert::IsNotNull(l.get_first());
				Assert::IsNotNull(l.get_last());
				Assert::AreEqual((void*)l.get_first(), (void*)l.get_last());
				Assert::AreEqual(i, l.get_first()->getValue());
				Assert::AreEqual(i, l.front());
				Assert::AreEqual(i, l.back());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(pushfront_single) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				srand(time(NULL));
				int i = rand() % 100;
				l.push_front(i);
				Assert::AreEqual((unsigned int)1, l.get_size());
				Assert::IsNotNull(l.get_first());
				Assert::IsNotNull(l.get_last());
				Assert::AreEqual((void*)l.get_first(), (void*)l.get_last());
				Assert::AreEqual(i, l.get_first()->getValue());
				Assert::AreEqual(i, l.front());
				Assert::AreEqual(i, l.back());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(popfront_single) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				srand(time(NULL));
				int i = rand() % 100;
				l.push_front(i);
				Assert::AreEqual((unsigned int)1, l.get_size());
				Assert::IsNotNull(l.get_first());
				Assert::IsNotNull(l.get_last());
				Assert::AreEqual((void*)l.get_first(), (void*)l.get_last());
				Assert::AreEqual(i, l.get_first()->getValue());
				Assert::AreEqual(i, l.front());
				Assert::AreEqual(i, l.back());
				l.pop_front();
				Assert::AreEqual((unsigned int)0, l.get_size());
				Assert::IsNull(l.get_first());
				Assert::IsNull(l.get_last());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(popback_single) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				srand(time(NULL));
				int i = rand() % 100;
				l.push_back(i);
				Assert::AreEqual((unsigned int)1, l.get_size());
				Assert::IsNotNull(l.get_first());
				Assert::IsNotNull(l.get_last());
				Assert::AreEqual((void*)l.get_first(), (void*)l.get_last());
				Assert::AreEqual(i, l.get_first()->getValue());
				Assert::AreEqual(i, l.front());
				Assert::AreEqual(i, l.back());
				l.pop_back();
				Assert::AreEqual((unsigned int)0, l.get_size());
				Assert::IsNull(l.get_first());
				Assert::IsNull(l.get_last());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(popback_popfront_empty) {
			try {
				ListNode::refCounts.clear();
				auto func = [] { my_list l; l.pop_back(); };
				auto func2 = [] { my_list l; l.pop_front(); };
				Assert::ExpectException<std::exception>(func);
				Assert::ExpectException<std::exception>(func2);
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(front_empty) {
			ListNode::refCounts.clear();
			auto func = [] { my_list l; l.front(); };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(back_empty) {
			ListNode::refCounts.clear();
			auto func = [] { my_list l; l.back(); };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(testlinks_pushback) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				srand(time(NULL));
				int i1 = rand() % 100;
				int i2 = rand() % 100;
				l.push_back(i1);
				l.push_back(i2);
				ListNode* fr = l.get_first();
				ListNode* la = l.get_last();
				Assert::AreEqual(i1, fr->getValue());
				Assert::AreEqual(i2, la->getValue());
				Assert::AreEqual((void*)la, (void*)fr->getNext());
				Assert::AreEqual((void*)fr, (void*)la->getPrevious());
				Assert::IsNull(fr->getPrevious());
				Assert::IsNull(la->getNext());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(testlinks_pushfront) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				srand(time(NULL));
				int i1 = rand() % 100;
				int i2 = rand() % 100;
				l.push_front(i1);
				l.push_front(i2);
				ListNode* fr = l.get_first();
				ListNode* la = l.get_last();
				Assert::AreEqual(i2, fr->getValue());
				Assert::AreEqual(i1, la->getValue());
				Assert::AreEqual((void*)la, (void*)fr->getNext());
				Assert::AreEqual((void*)fr, (void*)la->getPrevious());
				Assert::IsNull(fr->getPrevious());
				Assert::IsNull(la->getNext());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(testlinks_popfront) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				srand(time(NULL));
				int i1 = rand() % 100;
				int i2 = rand() % 100;
				l.push_back(i1);
				l.push_back(i2);
				ListNode* fr = l.get_first();
				ListNode* la = l.get_last();
				ListNode* la_prev = la->getPrevious();
				ListNode* la_next = la->getNext();
				ListNode* fr_next = fr->getNext();
				ListNode* fr_prev = fr->getPrevious();
				Assert::AreEqual(i1, fr->getValue());
				Assert::AreEqual(i2, la->getValue());
				Assert::AreEqual((void*)la, (void*)fr->getNext());
				Assert::AreEqual((void*)fr, (void*)la->getPrevious());
				Assert::IsNull(fr->getPrevious());
				Assert::IsNull(la->getNext());
				l.pop_front();
				fr = l.get_first();
				la = l.get_last();
				Assert::AreEqual(i2, fr->getValue());
				Assert::AreEqual((void*)fr_next, (void*)fr);
				Assert::IsNull(fr_next->getPrevious());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(testlinks_popback) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				srand(time(NULL));
				int i1 = rand() % 100;
				int i2 = rand() % 100;
				l.push_back(i1);
				l.push_back(i2);
				ListNode* fr = l.get_first();
				ListNode* la = l.get_last();
				ListNode* la_prev = la->getPrevious();
				ListNode* la_next = la->getNext();
				ListNode* fr_next = fr->getNext();
				ListNode* fr_prev = fr->getPrevious();
				Assert::AreEqual(i1, fr->getValue());
				Assert::AreEqual(i2, la->getValue());
				Assert::AreEqual((void*)la, (void*)fr->getNext());
				Assert::AreEqual((void*)fr, (void*)la->getPrevious());
				Assert::IsNull(fr->getPrevious());
				Assert::IsNull(la->getNext());
				l.pop_back();
				fr = l.get_first();
				la = l.get_last();
				Assert::AreEqual(i1, fr->getValue());
				Assert::AreEqual((void*)la_prev, (void*)la);
				Assert::IsNull(la_prev->getNext());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(large_random_push_pop_back) {
			try {
				ListNode::refCounts.clear();
				unsigned int n = 1000;
				int pushthreshhold = 7;
				my_list l;
				list<int> l_stl;
				srand(time(NULL));
				for (unsigned int i = 0; i < n; ++i) {
					int pushorpop = rand() % 10;
					int value = rand() % 1000;
					if (pushorpop < pushthreshhold) {
						l.push_back(value);
						l_stl.push_back(value);
					}
					else {
						if (l.get_size() > 0) {
							int l_back = l.back();
							int l_stl_back = l_stl.back();
							Assert::AreEqual(l_stl_back, l_back);
							l.pop_back();
							l_stl.pop_back();
						}
					}
				}
				Assert::AreEqual((unsigned int)l_stl.size(), l.get_size());
				while (l_stl.size() > 0) {
					Assert::AreEqual(l_stl.back(), l.back());
					l_stl.pop_back();
					l.pop_back();
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(large_random_push_pop_front) {
			try {
				ListNode::refCounts.clear();
				unsigned int n = 1000;
				srand(time(NULL));
				int pushthreshhold = 7;
				my_list l;
				list<int> l_stl;
				for (unsigned int i = 0; i < n; ++i) {
					int pushorpop = rand() % 10;
					int value = rand() % 1000;
					if (pushorpop < pushthreshhold) {
						l.push_front(value);
						l_stl.push_front(value);
					}
					else {
						if (l.get_size() > 0) {
							int l_front = l.front();
							int l_stl_front = l_stl.front();
							Assert::AreEqual(l_stl_front, l_front);
							l.pop_front();
							l_stl.pop_front();
						}
					}
				}
				Assert::AreEqual((unsigned int)l_stl.size(), l.get_size());
				while (l_stl.size() > 0) {
					Assert::AreEqual(l_stl.front(), l.front());
					l_stl.pop_front();
					l.pop_front();
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(large_random_mixed) {
			try {
				ListNode::refCounts.clear();
				unsigned int n = 1000;
				int pushthreshhold = 7;
				srand(time(NULL));
				my_list l;
				list<int> l_stl;
				for (unsigned int i = 0; i < n; ++i) {
					int pushorpop = rand() % 10;
					int frontorback = rand() % 2;
					int value = rand() % 1000;
					if (pushorpop < pushthreshhold) {
						if (frontorback == 0) {
							l.push_front(value);
							l_stl.push_front(value);
						}
						else {
							l.push_back(value);
							l_stl.push_back(value);
						}
					}
					else {
						if (l.get_size() > 0) {
							if (frontorback == 0) {
								int l_front = l.front();
								int l_stl_front = l_stl.front();
								Assert::AreEqual(l_stl_front, l_front);
								l.pop_front();
								l_stl.pop_front();
							}
							else {
								int l_back = l.back();
								int l_stl_back = l_stl.back();
								Assert::AreEqual(l_stl_back, l_back);
								l.pop_back();
								l_stl.pop_back();
							}
						}
					}
				}
				Assert::AreEqual((unsigned int)l_stl.size(), l.get_size());
				while (l_stl.size() > 0) {
					Assert::AreEqual(l_stl.front(), l.front());
					l_stl.pop_front();
					l.pop_front();
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(cleartest) {
			try {
				ListNode::refCounts.clear();
				my_list l;
				l.push_back(1);
				l.push_back(2);
				l.push_front(3);
				l.clear();
				Assert::AreEqual((unsigned int)0, l.get_size());
				Assert::IsNull(l.get_first());
				Assert::IsNull(l.get_last());
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(checkforleaks) {
			try {
				ListNode::refCounts.clear();
				my_list* l = new my_list;
				srand(time(NULL));
				unsigned int n = 1000;
				int pushthreshhold = 7;
				for (unsigned int i = 0; i < n; ++i) {
					int pushorpop = rand() % 10;
					int frontorback = rand() % 2;
					int value = rand() % 1000;
					if (pushorpop < pushthreshhold) {
						if (frontorback == 0) {
							l->push_front(value);
						}
						else {
							l->push_back(value);
						}
					}
					else {
						if (l->get_size() > 0) {
							if (frontorback == 0) {
								int l_front = l->front();
								l->pop_front();
							}
							else {
								int l_back = l->back();
								l->pop_back();
							}
						}
					}
				}
				delete l;
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}
	};
	


	// tests for part 2: copy control
	TEST_CLASS(MyListCopyControlTests) {

		TEST_METHOD(copyempty) {
			ListNode::refCounts.clear();
			try {
				my_list l;
				my_list l_copy(l);
				Assert::AreEqual((unsigned int)0, l_copy.get_size());
				Assert::IsNull(l_copy.get_first());
				Assert::IsNull(l_copy.get_last());
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}
		TEST_METHOD(copyconstructor) {
			ListNode::refCounts.clear();

			try {
				srand(time(NULL));
				my_list* l = new my_list;
				int n = 100;
				for (int i = 0; i < n; ++i) {
					l->push_back(rand() % 100);
				}
				my_list* l_copy = new my_list(*l);
				Assert::AreEqual(l->get_size(), l_copy->get_size());
				Assert::AreNotEqual((void*)l->get_first(), (void*)l_copy->get_first());
				Assert::AreNotEqual((void*)l->get_last(), (void*)l_copy->get_last());
				for (int i = 0; i < n; ++i) {
					Assert::AreEqual(l->front(), l_copy->front());
					Assert::AreNotEqual(&(l->front()), &(l_copy->front()));
					l->pop_front();
					l_copy->pop_front();
				}
				delete l;
				delete l_copy;
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(copyassign_empty) {
			ListNode::refCounts.clear();
			try {
				my_list* l = new my_list;
				my_list* l_copy = new my_list;
				l_copy->push_back(1);
				*l_copy = *l;
				Assert::AreEqual((unsigned int)0, l_copy->get_size());
				Assert::IsNull(l_copy->get_first());
				Assert::IsNull(l_copy->get_last());
				delete l;
				delete l_copy;
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(copyassign) {
			ListNode::refCounts.clear();

			try {
				srand(time(NULL));
				my_list* l = new my_list;
				int n = 100;
				for (int i = 0; i < n; ++i) {
					l->push_back(rand() % 100);
				}
				my_list* l_copy = new my_list;
				for (int i = 0; i < n; ++i) {
					l_copy->push_back(rand() % 100);
				}
				*l_copy = *l;
				Assert::AreEqual(l->get_size(), l_copy->get_size());
				Assert::AreNotEqual((void*)l->get_first(), (void*)l_copy->get_first());
				Assert::AreNotEqual((void*)l->get_last(), (void*)l_copy->get_last());
				for (int i = 0; i < n; ++i) {
					Assert::AreEqual(l->front(), l_copy->front());
					Assert::AreNotEqual(&(l->front()), &(l_copy->front()));
					l->pop_front();
					l_copy->pop_front();
				}
				delete l;
				delete l_copy;
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(selfassign) {
			ListNode::refCounts.clear();

			try {
				srand(time(NULL));
				my_list* l = new my_list;
				int n = 100;
				for (int i = 0; i < n; ++i) {
					l->push_back(rand() % 100);
				}
				ListNode* first = l->get_first();
				ListNode* last = l->get_last();
				unsigned int size = l->get_size();
				*l = *l;
				Assert::AreEqual(size, l->get_size());
				Assert::AreEqual((void*)first, (void*)l->get_first());
				Assert::AreEqual((void*)last, (void*)l->get_last());
				delete l;
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}
	};


	


	
	// tests for part 3: my_list_iterator
	TEST_CLASS(MyListIteratorTests)
	{
	public:
		TEST_METHOD(constructbegin)
		{
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i = rand() % 100;
			l.push_back(i);
			my_list_iterator l_it(&l, false);
			Assert::AreEqual((void*)l.get_first(), (void*)l_it.get_mem());
			Assert::AreEqual(i, l_it.get_mem()->getValue());
		}

		TEST_METHOD(constructbeginempty) {
			ListNode::refCounts.clear();
			my_list l;
			my_list_iterator l_it(&l, false);
			Assert::IsNull(l_it.get_mem());
		}

		TEST_METHOD(constructend) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i = rand() % 100;
			l.push_back(i);
			my_list_iterator l_it(&l, true);
			Assert::IsNull(l_it.get_mem());
			Assert::IsTrue(l_it.is_end());
		}

		TEST_METHOD(dereferencevalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i = rand() % 100;
			l.push_back(i);
			my_list_iterator l_it(&l, false);
			Assert::AreEqual((void*)l.get_first(), (void*)l_it.get_mem());
			Assert::AreEqual(i, *l_it);
		}

		TEST_METHOD(dereferenceinvalid) {
			ListNode::refCounts.clear();
			auto func = [] { my_list l; my_list_iterator l_it(&l, false); *l_it; };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(dereferenceend) {
			ListNode::refCounts.clear();
			auto func = [] { my_list l; l.push_back(10); my_list_iterator l_it(&l, true); *l_it; };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(incrementvalidtovalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			my_list_iterator l_it(&l, false);
			++l_it;
			Assert::AreEqual(i2, *l_it);
		}

		TEST_METHOD(decrementvalidtovalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			my_list_iterator l_it(&l, false);
			++l_it;
			Assert::AreEqual(i2, *l_it);
			--l_it;
			Assert::AreEqual(i1, *l_it);
		}

		TEST_METHOD(incrementvalidtoend) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			my_list_iterator l_it(&l, false);
			++l_it;
			Assert::AreEqual(i2, *l_it);
			++l_it;
			Assert::IsNull(l_it.get_mem());
			Assert::IsTrue(l_it.is_end());
		}

		TEST_METHOD(decrementvalidtoinvalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			auto func = [] {my_list l; l.push_back(rand() % 100); auto it = l.begin(); --it; };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(incrementfromendtoinvalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			auto func = [] { my_list l; l.push_back(rand() % 100); my_list_iterator l_it(&l, true); ++l_it; };
			Assert::ExpectException<std::exception>(func);

			auto func2 = [] { my_list l; my_list_iterator l_it(&l, false); ++l_it; };
			Assert::ExpectException<std::exception>(func2);
		}

		TEST_METHOD(decrementfromendtovalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			my_list_iterator l_it(&l, true);
			--l_it;
			Assert::IsNotNull(l_it.get_mem());
			Assert::IsFalse(l_it.is_end());
			Assert::AreEqual(i2, *l_it);
		}

		TEST_METHOD(compareequal) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			my_list_iterator l_it(&l, true);
			--l_it;
			my_list_iterator l_it2(&l, false);
			++l_it2;
			Assert::IsTrue(l_it == l_it2);
			Assert::IsFalse(l_it != l_it2);
		}

		TEST_METHOD(comparenotequal) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			my_list_iterator l_it(&l, true);
			--l_it;
			my_list_iterator l_it2(&l, false);
			Assert::IsFalse(l_it == l_it2);
			Assert::IsTrue(l_it != l_it2);
		}

		TEST_METHOD(comparedifferentlist) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			auto func = [] { my_list l; my_list l2; l.push_back(rand() % 100); l2.push_back(rand() % 100); auto it = l.begin(); auto it2 = l2.begin(); bool comp = it == it2; };
			Assert::ExpectException<std::exception>(func);
			auto func2 = [] { my_list l; my_list l2; l.push_back(rand() % 100); l2.push_back(rand() % 100); auto it = l.begin(); auto it2 = l2.begin(); bool comp = it != it2; };
			Assert::ExpectException<std::exception>(func2);
		}

		TEST_METHOD(compareend) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			l.push_back(i1);
			my_list_iterator l_it(&l, true);
			my_list_iterator l_it2(&l, false);
			++l_it2;
			Assert::IsTrue(l_it.is_end());
			Assert::IsTrue(l_it2.is_end());
			Assert::IsTrue(l_it == l_it2);
			Assert::IsFalse(l_it != l_it2);
		}

		TEST_METHOD(comparevalidwithend) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			l.push_back(i1);
			my_list_iterator l_it(&l, true);
			my_list_iterator l_it2(&l, false);
			Assert::IsFalse(l_it == l_it2);
			Assert::IsTrue(l_it != l_it2);
		}

		TEST_METHOD(traverserangeandmemoryissues) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			int n = 1000;
			try {
				my_list* l = new my_list;
				std::list<int>* l_std = new std::list<int>;
				for (int i = 0; i < n; ++i) {
					int j = rand() % 100;
					l->push_back(j);
					l_std->push_back(j);
				}
				my_list_iterator l_it(l, false);
				my_list_iterator l_it_end(l, true);
				auto it_std = l_std->begin();
				while (l_it != l_it_end) {
					Assert::AreEqual(*it_std, *l_it);
					++it_std;
					++l_it;
				}
				delete l;
				delete l_std;
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}
	};




	
	// tests for part 4: my_list + my_list_iterator
	TEST_CLASS(MyListPlusIteratorTests)
	{
		TEST_METHOD(beginendtraversalplusmemoryissues) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			int n = 1000;
			try {
				my_list* l = new my_list;
				std::list<int>* l_std = new std::list<int>;
				for (int i = 0; i < n; ++i) {
					int j = rand() % 100;
					l->push_back(j);
					l_std->push_back(j);
				}
				auto l_it = l->begin();
				auto l_it_end = l->end();
				auto it_std = l_std->begin();
				while (l_it != l_it_end) {
					Assert::AreEqual(*it_std, *l_it);
					++it_std;
					++l_it;
				}
				delete l;
				delete l_std;
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}

		TEST_METHOD(testinsertfront) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			int i3 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			auto it = l.begin();
			it = l.insert(it, i3);
			Assert::AreEqual(i3, l.front());
			Assert::AreEqual((unsigned int)3, l.get_size());
			Assert::AreEqual(i3, *it);
			auto it2 = l.begin();
			Assert::AreEqual((void*)it2.get_mem(), (void*)it.get_mem());
			++it2;
			++it;
			Assert::AreEqual(i1, *it);
			Assert::AreEqual(i1, *it2);
		}

		TEST_METHOD(testinsertlast) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			int i3 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			auto it = l.end();
			it = l.insert(it, i3);
			Assert::AreEqual(i3, l.back());
			Assert::AreEqual((unsigned int)3, l.get_size());
			Assert::AreEqual(i3, *it);
			auto it2 = l.end();
			--it2;
			Assert::AreEqual((void*)it2.get_mem(), (void*)it.get_mem());
			--it;
			Assert::AreEqual(i2, *it);
			++it;
			++it;
			Assert::IsTrue(it.is_end());
		}

		TEST_METHOD(insertvalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			int i3 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			auto it = l.begin();
			++it;
			it = l.insert(it, i3);
			auto it2 = l.begin();
			auto it3 = l.end();
			++it2;
			--it3;
			--it3;
			Assert::AreEqual(i3, *it);
			Assert::AreEqual(i3, *it2);
			Assert::AreEqual(i3, *it3);
			Assert::AreEqual((unsigned int)3, l.get_size());
			++it;
			++it2;
			Assert::AreEqual((void*)it2.get_mem(), (void*)it.get_mem());
			Assert::AreEqual(i2, *it);
		}

		TEST_METHOD(insertempty) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i = rand() % 100;
			auto it = l.insert(l.begin(), i);
			Assert::AreEqual(i, *it);
			Assert::AreEqual((void*)it.get_mem(), (void*)l.get_first());
		}

		TEST_METHOD(testinsertinvalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));

			// different lists
			auto func = [] { my_list l; l.push_back(1); my_list l2; l2.push_back(1);  auto it = l.begin(); l2.insert(it, 2);  };
			Assert::ExpectException<std::exception>(func);
		}

		TEST_METHOD(erasesinglefront) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			auto it = l.begin();
			it = l.erase(it);
			Assert::AreEqual((unsigned int)1, l.get_size());
			Assert::IsTrue(l.begin() == it);
			Assert::AreEqual(i2, l.front());
			Assert::AreEqual(i2, *it);
			++it;
			Assert::IsTrue(l.end() == it);
		}

		TEST_METHOD(erasesinglelast) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			auto it = l.end();
			--it;
			it = l.erase(it);
			Assert::AreEqual((unsigned int)1, l.get_size());
			Assert::IsTrue(it == l.end());
			--it;
			auto it2 = l.begin();
			Assert::AreEqual(*it2, *it);
			Assert::IsTrue(it2 == it);
			Assert::AreEqual(i1, *it);
		}

		TEST_METHOD(erasesinglevalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			my_list l;
			int i1 = rand() % 100;
			int i2 = rand() % 100;
			int i3 = rand() % 100;
			l.push_back(i1);
			l.push_back(i2);
			l.push_back(i3);
			auto it = l.begin();
			++it;
			it = l.erase(it);
			Assert::AreEqual((unsigned int)2, l.get_size());
			auto it2 = l.begin();
			auto it3 = l.end();
			--it3;
			Assert::IsTrue(it == it3);
			Assert::AreEqual(i1, *it2);
			Assert::AreEqual(i3, *it);
			--it;
			Assert::AreEqual(i1, *it);
			++it;
			++it;
			Assert::IsTrue(it.is_end());
		}

		TEST_METHOD(erasesingleinvalid) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			// end iterator, invalid iterator, 
			auto func = [] { my_list l; l.push_back(1); l.erase(l.end()); };
			Assert::ExpectException<std::exception>(func);
			// different lists
			auto func2 = [] { my_list l; my_list l2; l.push_back(1); l2.push_back(1); l.erase(l2.begin()); };
			Assert::ExpectException<std::exception>(func2);

			// empty list
			auto func3 = [] {my_list l; l.erase(l.begin()); };
			Assert::ExpectException<std::exception>(func3);
		}

		TEST_METHOD(inserterasecheckmemoryissues) {
			ListNode::refCounts.clear();
			srand(time(NULL));
			try {
				int n = 1000;
				my_list* l = new my_list;
				std::list<int>* l_std = new std::list<int>;
				for (int i = 0; i < n; ++i) {
					int j = rand() % 100;
					l->push_back(j);
					l_std->push_back(j);
				}
				int e = rand() % 750 + 100;
				int i = rand() % 750 + 100;
				int v = rand() % 100;
				int v2 = rand() % 100;
				auto it = l->begin();
				auto it_std = l_std->begin();
				int j = 0;
				while (j < e) {
					++it;
					++j;
				}
				std::advance(it_std, e);
				l->erase(it);
				l_std->erase(it_std);
				it = l->begin();
				it_std = l_std->begin();
				j = 0;
				while (j < i) {
					++it;
					++j;
				}
				std::advance(it_std, i);
				l->insert(it, v);
				l_std->insert(it_std, v);
				l->erase(l->begin());
				l_std->erase(l_std->begin());
				l->insert(l->end(), v2);
				l_std->insert(l_std->end(), v2);
				it = l->begin();
				it_std = l_std->begin();
				while (it != l->end()) {
					Assert::AreEqual(*it_std, *it);
					++it;
					++it_std;
				}
				delete l_std;
				delete l;
				for (auto node : ListNode::refCounts) {
					if (node.second) {
						Assert::Fail(L"memory leak");
					}
				}
			}
			catch (std::exception& e) {
				std::string message(e.what());
				std::wstring mes(message.begin(), message.end());
				Assert::Fail(mes.c_str());
			}
			catch (...)
			{
				Assert::Fail(L"unknown exception");
			}
		}
	};

	
} 