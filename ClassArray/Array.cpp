#include <iostream>
#include <assert.h>
#include "Array.h"
///Тест метода SearchInArray
void Test_SearchInArray() {
	Array<int> A(4); 
	for (int i = 0; i < 4; i++) {
		A.add(i);
	}
	assert(A.SearchInArray(0) == 0);
	assert(A.SearchInArray(2) == 2);
	assert(A.SearchInArray(3) == 3);
	assert(A.SearchInArray(5) == -1);

	Array<double> A1(7);
	for (int i = 0; i < 7; i++) {
		A1.add(i*(-1.5));
	}
	assert(A1.SearchInArray(0) == 0);
	assert(A1.SearchInArray(-9) == 6);
	assert(A1.SearchInArray(-6) == 4);
	assert(A1.SearchInArray(-567) == -1);

	Array<char> A2(3);
	A2.add('f');
	A2.add('l');
	A2.add('m');
	assert(A2.SearchInArray('f') == 0);
	assert(A2.SearchInArray('l') == 1);
	assert(A2.SearchInArray('m') == 2);
	assert(A2.SearchInArray('w') == -1);


}

///Тест метода Sort
void Test_Sort() {
	//когда массив уже отстортирован
	Array<int> A(8);
	for (int i = 0; i < 3; i++) {
		A.add(i);
	}
	A.Sort();
	assert(A[0] == 0);
	assert(A[1] == 1);
	assert(A[2] == 2);

	//когда отсортирован в обратном порядке
	for (int i = 0; i < 3; i++) {
		A[i] = i * (-1);
	}
	A.Sort();
	assert(A[0] == -2);
	assert(A[1] == -1);
	assert(A[2] == 0);


	//когда до середины ворастает, а потом убывает
	Array<double> A1(7);
	A1.add(0);
	A1.add(3.56);
	A1.add(9.1);
	A1.add(14.23);
	A1.add(7.735);
	A1.add(3.56);
	A1.Sort();
	assert(A1[0] == 0);
	assert(A1[1] == 3.56);
	assert(A1[2] == 3.56);
	assert(A1[3] == 7.735);
	assert(A1[4] == 9.1);
	assert(A1[5] == 14.23);

	//когда убывает, возрастает, убывает, возрастает
	Array<char> A2(7);
	A2.add('f');
	A2.add('a');
	A2.add('c');
	A2.add('b');
	A2.add('a');
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
	for (int i = 0; i < 5; i++) {
		A.add(0);
	}
	A.add(7);
	assert(A[5] == 7);

	for (int i = 6; i < 11; i++) {
		A.add(0);
	}
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
		for (int i = 0; i < 9; i++) {
			A.add(i);
		}
		A.del();
		assert(A.lenght() == 8);

		Array<double>A1(6);
		for (int i = 0; i < 6; i++) {
			A1.add(i);
		}
		A1.del();
		assert(A1.lenght() == 5);

		Array<char>A2(20);
		for (int i = 0; i < 19; i++) {
			A2.add(i);
		}
		A2.del();
		assert(A2.lenght() == 18);

		//удаление, когда есть что удалять и last меньше, чем size/2
		A.resize(5);
		A.del();
		assert(A.lenght() == 3);

		A1.resize(2);
		A1.del();
		assert(A1.lenght() == 0);



	}
	catch (const std::invalid_argument& error) {
		std::cout << error.what();
	}
}

///Тест изменения размера массива
void Test_resize() {
	try {
		//для типа int
		Array<int>A(10);
		for (int i = 0; i < 9; i++) {
			A.add(i);
		}
		assert(A.get_size() == 10);
		//когда размер массива уменьшается
		A.resize(6);
		assert(A.lenght() == 5);
		assert(A.get_size() == 6);
		assert(A[0] == 0);
		assert(A[1] == 1);
		assert(A[2] == 2);
		assert(A[3] == 3);
		assert(A[4] == 4);
		assert(A[5] == 5);

		//когда размер массива увеличивается
		A.resize(12);
		assert(A.lenght() == 5);
		assert(A.get_size() == 12);
		assert(A[0] == 0);
		assert(A[1] == 1);
		assert(A[2] == 2);
		assert(A[3] == 3);
		assert(A[4] == 4);
		assert(A[5] == 5);

		//для типа double
		Array<double>A1(6);
		assert(A1.get_size() == 6);
		for (int i = 0; i < 6; i++) {
			A1.add(i);
		}
		//когда размер уменьшается
		A1.resize(3);
		assert(A1.get_size() == 3);
		assert(A1.lenght() == 2);
		assert(A1[0] == 0);
		assert(A1[1] == 1);
		assert(A1[2] == 2);

		//когда размер увеличивается
		A1.resize(5);
		assert(A1.get_size() == 5);
		assert(A1.lenght() == 2);
		assert(A1[0] == 0);
		assert(A1[1] == 1);
		assert(A1[2] == 2);

		A1.resize(1);
		assert(A1.get_size() == 1);
		assert(A1.lenght() == 0);
	}
	catch (const std::invalid_argument& error) {
		std::cout << error.what();
	}
}


///Вызывает тесты всех методов класса
void Test() {
	Test_add();
	Test_Sort();
	Test_SearchInArray();
	Test_del();
	Test_resize();
}