#pragma once
#include <iostream>
#include "Node.h"
///Автор: Колосова Е.К.
///Класс описывающий тип двусявязный список.  Реализованы функции добавления в начало, середину,
///конец; удаление из начала, конца, середины; поиска; сортировки; нахождения максимума;
///очистки списка

template <class T>
class DoublyLinkedList : public Node<T>
{
	//поля:
	private:
		Node<T> *head; //указатель на голову
		Node<T> *end;  //указатель на конец
		size_t size;   //размер списка
	
	//методы:
	public:

		///Конструктор без параметров
		DoublyLinkedList() {
			head = nullptr;
			end = nullptr;
			size = 0;
		}

		///Деструктор
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
			if (head == nullptr) // если список пустой
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

		///Возвращает размер списка
		size_t get_size() const{
			return size;
		}

		///Возвращает указатель на голову списка
		Node<T>* get_head() const{
			return head;
		}

		///Возвращает указатель на конец списка
		Node<T>* get_end() const{
			return end;
		}

		
		///Удаление последнего элемента
		void delLast() {
			if (head == nullptr && end == nullptr) // если список пустой
			{
				throw std::invalid_argument("The list contains no elements");
			}
			Node<T> *temp = end;
			end = end->prev;
			if (end != nullptr) end->next = nullptr;
			else head = nullptr;
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
		long long Search(T key) const{
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
			head = nullptr;
			size = 0;
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

		///Возвращает номер максимального элемента в массиве и сам элемент через параметр max
		size_t Max(T& max) const{
			if (head == nullptr && end == nullptr) // если список пустой
			{
				throw std::invalid_argument("The list contains no elements");
			}

			Node<T>* cur = head;
			max = cur->data;
			size_t index = 0;
			for (size_t i = 1; i < size; i++) {
				cur = cur->next;
				if (cur->data > max) {
					max = cur->data;
					index = i;
				}
			}
			return index;
		}

		///Сортировка выбором списка
		void Sort() {
			if (head == nullptr && end == nullptr) // если список пустой
			{
				throw std::invalid_argument("The list contains no elements");
			}

			Node<T>* cur = head;
			T max_value=0;
			size_t j = 0;
			size_t size1 = size;
			DoublyLinkedList<T> L;
			DoublyLinkedList<T> L1;
			for (size_t i = 0; i <size1; i++) {
				j = Max(max_value);
				L.addFirst(max_value);
				if (j == 0) delFirst();
				else del(j - 1);
			}
			head = L.get_head();
			size = L.get_size();
			end = L.get_end();
			L = L1;
		}

		///Добавляет список L в конец списка и очищает L
		void Concat(DoublyLinkedList<T>& L) {
			DoublyLinkedList<T> L1;
			if (L.get_head() != nullptr) {
				Node<T>* cur = L.get_head();
				for (size_t i = 0; i < L.get_size(); i++) {
					if (head == nullptr) addFirst(cur->data);
					else addLast(cur->data);
					cur = cur->next;
				}
				DoublyLinkedList<T> L1;
				L = L1;
			}
		}
};

void Test_addLast();
void Test_Sort();
void Test_Concat();
void Test_Max();
void Test_addFirst();
void Test_add();
void Test_delFirst();
void Test_delLast();
void Test_del();
void Test_Search();

/// Тестирует функции класса двусявзный список
void Test();

