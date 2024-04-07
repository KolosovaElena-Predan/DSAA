///Автор Колосова Е.К.
///Класс для создание объкта типа стек. 
/// Используется для ...
#pragma once
#include <iostream>
#include "DoublyLinkedList.h"


template <typename T>
class Stack
{
//Поля:
private:
	DoublyLinkedList<T> elements; //список элементов
	Node<T> * top;//указатель на вершину стека

//Методы:
public:

	///Конструктор без параметров
	Stack() {
		elements.clear(); //очищаем список элементов
		top = elements.get_head(); //переставляем указатель на вершину стека на золову списка элементов
	}
	
	~Stack() {
		Clear();
		delete top;
	}

	///Если стек пуст, то возвращает true, иначе false
	bool isEmpty() {
		if (elements.get_size() == 0) return true;
		else return false;
	}
	
	///Удаляет верхний элемент стека и возвращает его значение
	///Бросает исключение invalid_argument, если стек не содержит элементов
	T Pop() {
		T del_element = top->data;
		if (!isEmpty()) {
			if (elements.get_size() == 1) elements.delFirst();
			else elements.delLast();
			top = elements.get_end();
			return del_element;
		}
		else throw std::invalid_argument("The stack contains no elements");
	}


	///Добавляет элемент в стек
	void Push(T value) {
		if (!isEmpty()) elements.addLast(value);
		else elements.addFirst(value);
		top = elements.get_end();

	}

	///Возвращает значение вершины
	///Бросает исключение invalid_argument, если стек не содержит элементов
	T Peek() {
		if (!isEmpty()) return top->data;
		else throw std::invalid_argument("The stack contains no elements");
	}

	///Очистка стека
	void Clear() {
		if (!isEmpty()) {
			elements.clear();
		}
		top=nullptr;
	}
};

void Test_Stack_Function();


