#include "DoublyLinkedList.h"
#include <iostream>
#include "assert.h"
void Test_addLast() {
	DoublyLinkedList<int> E;
	E.addLast(5);
	assert(E[0] == 5);
	E.addLast(8);
	assert(E[1] == 8);
	E.addLast(4);
	assert(E[0] == 5);
	assert(E[1] == 8);
	assert(E[2] == 4);

	DoublyLinkedList<double> E1;
	E1.addLast(5.123);
	assert(E1[0] == 5.123);
	E1.addLast(8.9);
	assert(E1[1] == 8.9);

	DoublyLinkedList<char> E2;
	E2.addLast('a');
	assert(E2[0] == 'a');
	E2.addLast('b');
	assert(E2[1] == 'b');
}

void Test_addFirst() {
	DoublyLinkedList<int> E;
	E.addFirst(5);
	assert(E[0] == 5);
	E.addFirst(8);
	assert(E[0] == 8);
	assert(E[1] == 5);

	DoublyLinkedList<double> E1;
	E1.addFirst(5.123);
	assert(E1[0] == 5.123);
	E1.addFirst(8.9);
	assert(E1[0] == 8.9);
	assert(E1[1] == 5.123);

	DoublyLinkedList<char> E2;
	E2.addFirst('a');
	assert(E2[0] == 'a');
	E2.addFirst('b');
	assert(E2[0] == 'b');
	assert(E2[1] == 'a');
}

void Test_add() {
	DoublyLinkedList<int> E;
	E.addFirst(5);
	E.add(8, 0);
	assert(E[0] == 5);
	assert(E[1] == 8);
	E.add(12, 0);
	assert(E[0] == 5);
	assert(E[1] == 12);
	assert(E[2] == 8);

	DoublyLinkedList<double> E1;
	E1.addFirst(5.123);
	E1.add(8.9, 0);
	assert(E1[0] == 5.123);
	assert(E1[1] == 8.9);
	E1.add(12.76, 0);
	assert(E1[0] == 5.123);
	assert(E1[1] == 12.76);
	assert(E1[2] == 8.9);

	DoublyLinkedList<char> E2;
	E2.addFirst('a');
	E2.add('b', 0);
	assert(E2[0] == 'a');
	assert(E2[1] == 'b');
	E2.add('c', 0);
	assert(E2[0] == 'a');
	assert(E2[1] == 'c');
	assert(E2[2] == 'b');
}

void Test_delFirst() {
	DoublyLinkedList<int> E;
	E.addFirst(5);
	E.add(8, 0);
	E.add(12, 0);
	E.addLast(7);
	E.delFirst();
	assert(E[0] == 12);
	assert(E[1] == 8);
	assert(E[2] == 7);

	DoublyLinkedList<double> E1;
	E1.addFirst(5.123);
	E1.add(8.9, 0);
	E1.add(12.76, 0);
	E1.delFirst();
	assert(E1[0] == 12.76);
	assert(E1[1] == 8.9);

	DoublyLinkedList<char> E2;
	E2.addFirst('a');
	E2.add('b', 0);
	E2.add('c', 0);
	E2.delFirst();
	assert(E2[0] == 'c');
	assert(E2[1] == 'b');
}

void Test_delLast() {
	DoublyLinkedList<int> E;
	E.addFirst(5);
	E.add(8, 0);
	E.add(12, 0);
	E.addLast(7);
	E.delLast();
	assert(E[0] == 5);
	assert(E[1] == 12);
	assert(E[2] == 8);

	DoublyLinkedList<double> E1;
	E1.addFirst(5.123);
	E1.add(8.9, 0);
	E1.add(12.76, 0);
	E1.delLast();
	assert(E1[0] == 5.123);
	assert(E1[1] == 12.76);

	DoublyLinkedList<char> E2;
	E2.addFirst('a');
	E2.add('b', 0);
	E2.add('c', 0);
	E2.delLast();
	assert(E2[0] == 'a');
	assert(E2[1] == 'c');
}

void Test_del() {
	DoublyLinkedList<int> E;
	E.addFirst(5);
	E.add(8, 0);
	E.add(12, 0);
	E.del(0);
	assert(E[0] == 5);
	assert(E[1] == 8);
	E.addLast(6);
	E.addLast(7);
	E.del(1);
	assert(E[0] == 5);
	assert(E[1] == 8);
	assert(E[2] == 7);

	DoublyLinkedList<double> E1;
	E1.addFirst(5.123);
	E1.add(8.9, 0);
	E1.add(12.76, 0);
	E1.del(0);
	assert(E1[0] == 5.123);
	assert(E1[1] == 8.9);

	DoublyLinkedList<char> E2;
	E2.addFirst('a');
	E2.add('b', 0);
	E2.add('c', 0);
	E2.del(1);
	assert(E2[0] == 'a');
	assert(E2[1] == 'c');
}


void Test_Search() {
	DoublyLinkedList<int> E;
	E.addFirst(5); //5 12 8 6 7
	E.add(8, 0);
	E.add(12, 0);
	E.addLast(6);
	E.addLast(7);
	assert(E.Search(5) == 0);
	assert(E.Search(12) == 1);
	assert(E.Search(8) == 2);
	assert(E.Search(6) == 3);
	assert(E.Search(7) == 4);
	assert(E.Search(19) == -1);

	DoublyLinkedList<double> E1;
	E1.addFirst(5.123);
	E1.add(8.9, 0);
	E1.add(12.76, 0);
	assert(E1.Search(5.123) == 0);
	assert(E1.Search(12.76) == 1);
	assert(E1.Search(8.9) == 2);
	assert(E1.Search(6.184) == -1);

	DoublyLinkedList<char> E2;
	E2.addFirst('a');
	E2.add('b', 0);
	E2.add('c', 0);
	assert(E2.Search('a') == 0);
	assert(E2.Search('c') == 1);
	assert(E2.Search('b') == 2);
	assert(E2.Search('l') == -1);
}

void Test_Max() {
	DoublyLinkedList<int> E;
	E.addFirst(5);
	E.add(8, 0);
	E.add(12, 1);
	E.addLast(7);
	int n = 0;
	assert(E.Max(n) == 2); //5 8 12 7
	assert(n == 12);

	E.del(1); //5 8 7
	assert(E.Max(n) == 1);
	assert(n == 8);

	E.addLast(16); //5 8 7 16
	assert(E.Max(n) == 3);
	assert(n == 16);

	E.addFirst(20); //20 5 8 7 16
	assert(E.Max(n) == 0);
	assert(n == 20);

}

void Test_Sort(){
	DoublyLinkedList<int> E; //5 8 12 7
	E.addFirst(5);
	E.add(8, 0);
	E.add(12, 1);
	E.addLast(7);
	E.Sort();
	assert(E[0] == 5);
	assert(E[1] == 7);
	assert(E[2] == 8);
	assert(E[3] == 12);

	DoublyLinkedList<int> E1; //10 6 12 17 20
	E1.addFirst(10);
	E1.addLast(6);
	E1.addLast(12);
	E1.addLast(17);
	E1.addLast(20);
	E1.Sort();

	assert(E1[0] == 6);
	assert(E1[1] == 10);
	assert(E1[2] == 12);
	assert(E1[3] == 17);
	assert(E1[4] == 20);


	DoublyLinkedList<double> E2; //1.2 1.3 1.4 1.5 1.6
	E2.addFirst(1.2);
	E2.addLast(1.3);
	E2.addLast(1.4);
	E2.addLast(1.5);
	E2.addLast(1.6);
	E2.Sort();

	assert(E2[0] == 1.2);
	assert(E2[1] == 1.3);
	assert(E2[2] == 1.4);
	assert(E2[3] == 1.5);
	assert(E2[4] == 1.6);


	DoublyLinkedList<double> E3; //1.2 1.3 1.4 1.5 1.2
	E3.addFirst(1.2);
	E3.addLast(1.3);
	E3.addLast(1.4);
	E3.addLast(1.5);
	E3.addLast(1.2);
	E3.Sort();

	assert(E3[0] == 1.2);
	assert(E3[1] == 1.2);
	assert(E3[2] == 1.3);
	assert(E3[3] == 1.4);
	assert(E3[4] == 1.5);


	DoublyLinkedList<double> E4; //1.2 1.3 1.4 1.5 1.2
	E4.addFirst(1.6);
	E4.addLast(1.3);
	E4.addLast(1.4);
	E4.addLast(1.5);
	E4.addLast(1.6);
	E4.Sort();

	assert(E4[0] == 1.3);
	assert(E4[1] == 1.4);
	assert(E4[2] == 1.5);
	assert(E4[3] == 1.6);
	assert(E4[4] == 1.6);
}

void Test_Concat() {

	//когда оба списка содержат какие-то значени€
	DoublyLinkedList<int> E; //5 8 12 7
	E.addFirst(5);
	E.add(8, 0);
	E.add(12, 1);
	E.addLast(7);

	DoublyLinkedList<int> E1; //10 6 12 17 20
	E1.addFirst(10);
	E1.addLast(6);
	E1.addLast(12);
	E1.addLast(17);
	E1.addLast(20);

	E.Concat(E1);

	assert(E[0] == 5);
	assert(E[1] == 8);
	assert(E[2] == 12);
	assert(E[3] == 7);
	assert(E[4] == 10);
	assert(E[5] == 6);
	assert(E[6] == 12);
	assert(E[7] == 17);
	assert(E[8] == 20);
	assert(E.get_size()==9);

	assert(E1.get_size() == 0);
	assert(E1.get_head() == nullptr);


	//когда исходный список пуст
	E1.Concat(E);

	assert(E1[0] == 5);
	assert(E1[1] == 8);
	assert(E1[2] == 12);
	assert(E1[3] == 7);
	assert(E1[4] == 10);
	assert(E1[5] == 6);
	assert(E1[6] == 12);
	assert(E1[7] == 17);
	assert(E1[8] == 20);
	assert(E1.get_size() == 9);

	assert(E.get_size() == 0);
	assert(E.get_head() == nullptr);


	//когда добавл€емый список пуст

	E1.Concat(E);

	assert(E1[0] == 5);
	assert(E1[1] == 8);
	assert(E1[2] == 12);
	assert(E1[3] == 7);
	assert(E1[4] == 10);
	assert(E1[5] == 6);
	assert(E1[6] == 12);
	assert(E1[7] == 17);
	assert(E1[8] == 20);
	assert(E1.get_size() == 9);

	assert(E.get_size() == 0);
	assert(E.get_head() == nullptr);
}

/// “естирует функции класса двус€взный список
void Test() {
	Test_Concat();
	Test_Sort();
	Test_addLast();
	Test_addFirst();
	Test_Search();
	Test_delFirst();
	Test_delLast();
	Test_del();
	Test_add();
	Test_Max();
}