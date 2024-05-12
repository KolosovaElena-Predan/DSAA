///Автор: Колосова Е.К.
///Класс описывающий тип дек.Реализованы функции добавление в начало и в конец, 
///удаление из начала и из конца, проверка на то пустой ли дек (isEmpty), 
/// возвращение размера(size), возвращение значения элемента из начала и конца дека,
/// очистка дека (clear)
/// Реализован на основе класса двусвязный список DoublyLinkedList
#pragma once
#include "DoublyLinkedList.h"
#include <iostream>
template <class T>
class Deque
{
private:
	DoublyLinkedList<T> elements; //элементы дека
	Node<T>* front; //указатель на первый элемент дека
	Node<T>* end; //указатель на последний элемент дека

public:

	///Конcтруктор без параметров
	Deque() {
		elements.clear();
		front = nullptr;
		end = nullptr;
	}

	///Возвращает значение кол-ва элементов в очереди
	size_t size() const {
		return elements.get_size();
	}

	///Если дек пуст, то возвращает true, иначе false
	bool isEmpty() const {
		if (elements.get_size() == 0) return true;
		else return false;
	}

	///Добавляет элемент в конец дека
	void PushBack(T value) {
		if (!isEmpty()) elements.addLast(value);
		else elements.addFirst(value);
		front = elements.get_head();
		end = elements.get_end();
	}

	///Добавляет элемент в начало дека
	void PushFront(T value) {
		elements.addFirst(value);
		/*front = elements.get_head();
		end = elements.get_end();*/

	}

	///Удалить элемент из начала дека
	///Бросает исключение invalid_argument, если очередь не содержит элементов
	T PopFront() {
		if (!isEmpty()) {
			T del_element = front->data;
			elements.delFirst();
			front = elements.get_head();
			return del_element;
		}
		else throw std::invalid_argument("The queue contains no elements");
	}

	///Удалить элемент из конца дека
	///Бросает исключение invalid_argument, если очередь не содержит элементов
	T PopBack() {
		if (!isEmpty()) {
			T del_element = end->data;
			elements.delLast();


			end = elements.get_end();
			return del_element;
		}
		else throw std::invalid_argument("The queue contains no elements");
	}

	///Возвращает значение из начала дека
	///Бросает исключение invalid_argument, если очередь не содержит элементов
	T PeekFront() const {
		if (!isEmpty()) return front->data;
		else throw std::invalid_argument("The queue contains no elements");
	}

	///Возвращает значение из конца дека
	///Бросает исключение invalid_argument, если очередь не содержит элементов
	T PeekBack() const {
		if (!isEmpty()) return end->data;
		else throw std::invalid_argument("The queue contains no elements");
	}

	///Очистка очереди
	void Clear() {
		if (!isEmpty()) {
			elements.clear();
		}
		front = nullptr;
		end = nullptr;
	}

};

///Тест функций класса Deque
void Test_deque_functions();

