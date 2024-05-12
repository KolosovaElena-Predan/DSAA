///Автор: Колосова Е.К.
///Класс описывающий тип очередь. Реализованы функции добавление в очередь(enqueue), 
///удаление из очереди(dequeue), проверка на то пустая ли очередь (isEmpty), 
/// возвращение размера(size), возвращение значения элемента из начала очереди(Peek),
/// очистка очереди (clear)
#pragma once
#include "DoublyLinkedList.h"
#include <iostream>
template <class T>
class Queue
{
	private:
		DoublyLinkedList<T> elements; //элементы очереди
		Node<T> * front; //указатель на первый элемент очереди
		Node<T>* rear; //указатель на последний элемент очереди

	public:

		///Конcтруктор без параметров
		Queue(){
			elements.clear();
			front = nullptr;
			rear = nullptr;
		}

		///Возвращает значение кол-ва элементов в очереди
		size_t size() const{
			return elements.get_size();
		}

		///Если очередь пуста, то возвращает true, иначе false
		bool isEmpty() const{
			if (elements.get_size() == 0) return true;
			else return false;
		}

		///Добавляет элемент в очередь
		void enqueue(T value) {
			if (!isEmpty()) elements.addLast(value);
			else elements.addFirst(value);
			front = elements.get_head();
			rear = elements.get_end();
		}

		///Удалить элемент из очереди
		///Бросает исключение invalid_argument, если очередь не содержит элементов
		T dequeue() {
			if (!isEmpty()) {
				T del_element = front->data;
				elements.delFirst();
				front = elements.get_head();
				return del_element;
			}
			else throw std::invalid_argument("The queue contains no elements");
		}

		///Возвращает значение вершины
		///Бросает исключение invalid_argument, если очередь не содержит элементов
		T Peek() const{
			if (!isEmpty()) return front->data;
			else throw std::invalid_argument("The queue contains no elements");
		}

		///Очистка очереди
		void Clear() {
			if (!isEmpty()) {
				elements.clear();
			}
			front = nullptr;
			rear = nullptr;
		}

};

///Тест функций класса Queue
void Test_queue_functions();

