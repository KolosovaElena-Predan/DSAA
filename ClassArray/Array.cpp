#include <iostream>
#include <assert.h>
#include "Array.h"
///Тест метода Search
void Test_Search() {
	Array<int> A(4); 
	A.resize(4);
	for (int i = 0; i < 4; i++) {
		A[i] = i;
	}
	assert(A.Search(0) == 0);
	assert(A.Search(2) == 2);
	assert(A.Search(3) == 3);
	assert(A.Search(5) == -1);

	Array<double> A1(7);
	A1.resize(7);
	for (int i = 0; i < 7; i++) {
		A1[i] = i*(-1.5);
	}
	assert(A1.Search(0) == 0);
	assert(A1.Search(-9) == 6);
	assert(A1.Search(-6) == 4);
	assert(A1.Search(-567) == -1);

	Array<char> A2(3);
	A2.resize(3);
	A2[0] = 'f';
	A2[1] = 'l';
	A2[2] = 'm';
	assert(A2.Search('f') == 0);
	assert(A2.Search('l') == 1);
	assert(A2.Search('m') == 2);
	assert(A2.Search('w') == -1);


}

///Тест метода Sort
void Test_Sort() {
	//когда массив уже отстортирован
	Array<int> A(8);
	A.resize(3);
	for (int i = 0; i < 3; i++) {
		A[i] = i;
	}
	A.Sort();
	assert(A[0] == 0);
	assert(A[1] == 1);
	assert(A[2] == 2);

	//когда отсортирован в обратном порядке
	for (int i = 0; i < 3; i++) {
		A[i] = i * (-1.0);
	}
	A.Sort();
	assert(A[0] == -2);
	assert(A[1] == -1);
	assert(A[2] == 0);


	//когда до середины ворастает, а потом убывает
	Array<double> A1(7);
	A1.resize(6);
	A1[0] = 0;
	A1[1] = 3.56;
	A1[2] = 9.1;
	A1[3] = 14.23;
	A1[4] = 7.735;
	A1[5] = 3.56;
	A1.Sort();
	assert(A1[0] == 0);
	assert(A1[1] == 3.56);
	assert(A1[2] == 3.56);
	assert(A1[3] == 7.735);
	assert(A1[4] == 9.1);
	assert(A1[5] == 14.23);

	//когда убывает, возрастает, убывает, возрастает
	Array<char> A2(7);
	A2.resize(6);
	A2[0] = 'f';
	A2[1] = 'a';
	A2[2] = 'c';
	A2[3] = 'b';
	A2[4] = 'a';
	A2[5] = 'l';
	A2.Sort();
	assert(A2[0] == 'a');
	assert(A2[1] == 'a');
	assert(A2[2] == 'b');
	assert(A2[3] == 'c');
	assert(A2[4] == 'f');
	assert(A2[5] == 'l');
}

///Тест метода add
void Test_add() {
	//вставка, когда есть свободная ячейка памяти в массиве
	Array<int>A(12);
	A.resize(5);
	A.add(7);
	assert(A[5] == 7);

	A.resize(11);
	A.add(6);
	assert(A[11] == 6);

	//вставка, когда нет свободной ячейки памяти в массиве
	A.add(18);
	assert(A[12] == 18);

	//вставка, когда память под массив изначально не выделена
	Array<double>B;
	B.add(15.6);
	assert(B[0] == 15.6);
}

///Тест метода del
void Test_del() {
	try {
		//удаление, когда есть что удалять и last больше, чем size/2
		Array<int>A(12);
		A.resize(9);
		A.del();
		assert(A.lenght() == 8);

		Array<double>A1(6);
		A1.resize(6);
		A1.del();
		assert(A1.lenght() == 5);

		Array<char>A2(20);
		A2.resize(19);
		A2.del();
		assert(A2.lenght() == 18);

		//удаление, когда есть что удалять и last меньше, чем size/2
		A.resize(5);
		A.del();
		assert(A.lenght() == 4);

		A1.resize(2);
		A1.del();
		assert(A1.lenght() == 1);

		A2.resize(1);
		A2.del();
		assert(A2.lenght() == 0);


	}
	catch (const std::invalid_argument& error) {
		std::cout << error.what();
	}
}


///Вызывает тесты всех методов класса
void Test() {
	Test_add();
	Test_Sort();
	Test_Search();
	Test_del();
}