///Автор: Колосова Е.К.
///Класс описывающий тип дек. Реализованы функции добавление в начало и в конец, 
///удаление из начала и из конца, проверка на то пустой ли дек (isEmpty), 
/// возвращение размера(size), возвращение значения элемента из начала и конца дека,
/// очистка дека (clear)
#include <assert.h>
#include <string>
#include "Deque.h"

///Тест функций класса Deque
void Test_deque_functions() {
	Test();

	//проверка работы isEmpty на пустом деке
	Deque<int> S;
	assert(S.size() == 0);
	assert(S.isEmpty() == true);

	//добавляем элемент в начало дека
	S.PushFront(5);
	assert(S.isEmpty() == false); //проверка, что стек теперь не пустой
	assert(S.size() == 1);//кол-во элементов стало равно 1

	//заполнение дека добавлением в начало
	S.PushFront(3);
	assert(S.size() == 2);
	S.PushFront(9);
	assert(S.size() == 3);
	S.PushFront(8);
	assert(S.size() == 4);
	S.PushFront(12);
	assert(S.size() == 5);

	//дек имеет вид 12 8 9 3 5
	assert(S.PeekFront() == 12);
	assert(S.PopFront() == 12);
	assert(S.size() == 4);
	assert(S.PeekFront() == 8);
	assert(S.PopFront() == 8);
	assert(S.size() == 3);
	assert(S.PeekFront() == 9);
	assert(S.PopFront() == 9);
	assert(S.size() == 2);
	assert(S.PeekFront() == 3);
	assert(S.PopFront() == 3);
	assert(S.size() == 1);
	assert(S.PeekFront() == 5);
	assert(S.PopFront() == 5);
	assert(S.size() == 0);
	assert(S.isEmpty() == true);


	//добавляем элемент в конец дека
	S.PushBack(5);
	assert(S.isEmpty() == false); //проверка, что стек теперь не пустой
	assert(S.size() == 1);//кол-во элементов стало равно 1
	//заполнение дека добавлением в конец
	S.PushBack(3);
	assert(S.size() == 2);
	S.PushBack(9);
	assert(S.size() == 3);
	S.PushBack(8);
	assert(S.size() == 4);
	S.PushBack(12);
	assert(S.size() == 5);

	//дек имеет вид 5 3 9 8 12
	assert(S.PeekBack() == 12);
	assert(S.PopBack() == 12);
	assert(S.size() == 4);
	assert(S.PeekBack() == 8);
	assert(S.PopBack() == 8);
	assert(S.size() == 3);
	assert(S.PeekBack() == 9);
	assert(S.PopBack() == 9);
	assert(S.size() == 2);
	assert(S.PeekBack() == 3);
	assert(S.PopBack() == 3);
	assert(S.size() == 1);
	assert(S.PeekBack() == 5);
	assert(S.PopBack() == 5);
	assert(S.size() == 0);
	assert(S.isEmpty() == true);

	//проверка на то, что было брошено исключение при попытке 
	//удалить элемент из пустой очереди
	try {
		int a = S.PopFront();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}

	//проверка на то, что было брошено исключение при попытке 
	//удалить элемент из пустой очереди
	try {
		int a = S.PopBack();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}

	//проверка на то, что было брошено исключение при попытке 
	//вернуть значение первого элемента из пустой очереди
	try {
		int a = S.PeekFront();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}

	//проверка на то, что было брошено исключение при попытке 
	//вернуть значение первого элемента из пустой очереди
	try {
		int a = S.PeekBack();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}

}
