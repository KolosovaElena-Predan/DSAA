#pragma once
#include <iostream>
#include "Node.h"

template <class T>
class DoublyLinkedList : public Node<T>
{
	private:
		Node<T> *head;
		Node<T> *end;
		size_t size;

	public:
		DoublyLinkedList() {
			head = nullptr;
			end = nullptr;
			size = 0;
		}

		~DoublyLinkedList() {
			clear();
		}

		
		///Вставка элемента со значением new_value в конец списка
		void addLast(T new_value) {
			if (head == nullptr && end == nullptr) // если список пустой
			{
				Node<T>* temp = new Node<T>; //выделение памяти под новый элемент

				temp->data = new_value; //присваивание значения узлу
				temp->prev = nullptr; //предыдущего элемента нет
				temp->next = nullptr; //следующего элемента нет

				head = temp; //указатель на голову перемещаем на созданный узел
				end = temp; //указатель на конец перемещаем на созданный узел
				size = 1;
				return;
			}

			Node<T>* temp = new Node<T>; //выделение памяти под создаваемый узел
			temp->data = new_value; //присваивание значения узлу
			temp->prev = end; //указатель на предыдущий элемент переставляется на конец списка
			temp->next = nullptr; //следующего элемента нет
			end->next = temp; //переставление указателя на конец на созданный элемент
			end = temp;
			size++;
		}

		///Вставка элемента со значением new_value в голову списка
		void addFirst(T new_value) {
			if (head == nullptr && end == nullptr) // если список пустой
			{
				Node<T>* temp = new Node<T>; //выделение памяти под новый элемент

				temp->data = new_value; //присваивание значения узлу
				temp->prev = nullptr; //предыдущего элемента нет
				temp->next = nullptr; //следующего элемента нет

				head = temp; //указатель на голову перемещаем на созданный узел
				end = temp; //указатель на конец перемещаем на созданный узел
				size = 1;
				return;
			}

			Node<T>* temp = new Node<T>; //выделение памяти под создаваемый узел
			temp->data = new_value; //присваивание значения узлу
			temp->next = head;
			head->prev = temp;
			head=temp;
			size++;
		}
		

		///Вставка элемента со значением new_value после узла с номером index(узлы нумеруются с нуля)
		void add(T new_value, size_t index) {
			if (head == nullptr && end == nullptr) {
			   throw std::invalid_argument("The list contains no elements");
			}

			if (index >= size) {
			   throw std::invalid_argument("Invalid index value");
			}

			else {
				Node<T>* temp = new Node<T>; //выделение памяти под создаваемый узел
				temp->data = new_value; //присваивание значения узлу
				Node<T>* cur;//указатель на текущий элемент
				cur = head;
				for (size_t i = 0; i < index; i++) {
					cur = cur->next;
				}
				temp->next = cur->next;
				cur->next = temp;
				if (temp->next != nullptr) {
					temp->next->prev = temp;
				}
				else end = temp;
				temp->prev = cur;
				size++;
			}
		}

		
		///Удаление первого элемента
		void delFirst() {
			if (head == nullptr && end == nullptr) // если список пустой
			{
				throw std::invalid_argument("The list contains no elements");
			}
			Node<T> *temp = head;
			head = head->next;
			delete temp;
			size--;
		}

		
		///Удаление последнего элемента
		void delLast() {
			if (head == nullptr && end == nullptr) // если список пустой
			{
				throw std::invalid_argument("The list contains no elements");
			}
			Node<T> *temp = end;
			end = end->prev;
			end->next = nullptr;
			delete temp;
			size--;
		}
		

		///Удаление элемента после узла с номером index
		void del(size_t index){
			if (head == nullptr && end == nullptr) // если список пустой
			{
				throw std::invalid_argument("The list contains no elements");
			}

			if (index >= size - 1) {
			    throw std::invalid_argument("Invalid index value");
			}

			Node<T> *cur = head;
			for (size_t i = 0; i < index; i++) {
				cur = cur->next;
			}

			if (cur->next->next == nullptr) delLast();
			else {
				Node<T>* temp = cur->next;
				cur->next = temp->next;
				cur->next->prev = cur;
				temp->next = nullptr;
				temp->prev = nullptr;
				delete temp;
				size--;
			}
		}

		
		///Поиск элемента со значением key в списке
		long long Search(T key) {
			Node<T> *cur = head;
			for (int i = 0; i < size; i++) {
				if (cur->data == key) return i;
				cur = cur->next;
			}
			return - 1;
		}

		///Очистка списка
		void clear() {
			Node<T>* temp;
			while (head)
			{
				temp = head;
				head = head->next;
				delete temp;
			}
			end = nullptr;
		}

		///перегрузка оператора []
		T& operator[](size_t index) {
			if (index < size) {
				Node<T> *cur = head;
				for (int i = 0; i < index; i++) {
					cur = cur->next;
				}
				return cur->data;
			}
			else throw std::invalid_argument("Invalid index value");
		}

		
};

void Test_addLast();
void Test_addFirst();
void Test_add();
void Test_delFirst();
void Test_delLast();
void Test_del();
void Test_Search();
void Test();

