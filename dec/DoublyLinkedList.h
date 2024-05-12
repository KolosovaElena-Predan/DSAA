#pragma once
#include <iostream>
#include "Node.h"
///�����: �������� �.�.
///����� ����������� ��� ����������� ������.  ����������� ������� ���������� � ������, ��������,
///�����; �������� �� ������, �����, ��������; ������; ����������; ���������� ���������;
///������� ������

template <class T>
class DoublyLinkedList : public Node<T>
{
	//����:
	private:
		Node<T> *head; //��������� �� ������
		Node<T> *end;  //��������� �� �����
		size_t size;   //������ ������
	
	//������:
	public:

		///����������� ��� ����������
		DoublyLinkedList() {
			head = nullptr;
			end = nullptr;
			size = 0;
		}

		///����������
		~DoublyLinkedList() {
			clear();
		}

		
		///������� �������� �� ��������� new_value � ����� ������
		void addLast(T new_value) {
			if (head == nullptr && end == nullptr) // ���� ������ ������
			{
				Node<T>* temp = new Node<T>; //��������� ������ ��� ����� �������

				temp->data = new_value; //������������ �������� ����
				temp->prev = nullptr; //����������� �������� ���
				temp->next = nullptr; //���������� �������� ���

				head = temp; //��������� �� ������ ���������� �� ��������� ����
				end = temp; //��������� �� ����� ���������� �� ��������� ����
				size = 1;
				return;
			}

			Node<T>* temp = new Node<T>; //��������� ������ ��� ����������� ����
			temp->data = new_value; //������������ �������� ����
			temp->prev = end; //��������� �� ���������� ������� �������������� �� ����� ������
			temp->next = nullptr; //���������� �������� ���
			end->next = temp; //������������� ��������� �� ����� �� ��������� �������
			end = temp;
			size++;
		}

		///������� �������� �� ��������� new_value � ������ ������
		void addFirst(T new_value) {
			if (head == nullptr) // ���� ������ ������
			{
				Node<T>* temp = new Node<T>; //��������� ������ ��� ����� �������

				temp->data = new_value; //������������ �������� ����
				temp->prev = nullptr; //����������� �������� ���
				temp->next = nullptr; //���������� �������� ���

				head = temp; //��������� �� ������ ���������� �� ��������� ����
				end = temp; //��������� �� ����� ���������� �� ��������� ����
				size = 1;
				return;
			}

			Node<T>* temp = new Node<T>; //��������� ������ ��� ����������� ����
			temp->data = new_value; //������������ �������� ����
			temp->next = head;
			head->prev = temp;
			head=temp;
			size++;
		}
		

		///������� �������� �� ��������� new_value ����� ���� � ������� index(���� ���������� � ����)
		void add(T new_value, size_t index) {
			if (head == nullptr && end == nullptr) {
			   throw std::invalid_argument("The list contains no elements");
			}

			if (index >= size) {
			   throw std::invalid_argument("Invalid index value");
			}

			else {
				Node<T>* temp = new Node<T>; //��������� ������ ��� ����������� ����
				temp->data = new_value; //������������ �������� ����
				Node<T>* cur;//��������� �� ������� �������
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

		
		///�������� ������� ��������
		void delFirst() {
			if (head == nullptr && end == nullptr) // ���� ������ ������
			{
				throw std::invalid_argument("The list contains no elements");
			}
			Node<T> *temp = head;
			head = head->next;
			delete temp;
			size--;
		}

		///���������� ������ ������
		size_t get_size() const{
			return size;
		}

		///���������� ��������� �� ������ ������
		Node<T>* get_head() const{
			return head;
		}

		///���������� ��������� �� ����� ������
		Node<T>* get_end() const{
			return end;
		}

		
		///�������� ���������� ��������
		void delLast() {
			if (head == nullptr && end == nullptr) // ���� ������ ������
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
		

		///�������� �������� ����� ���� � ������� index
		void del(size_t index){
			if (head == nullptr && end == nullptr) // ���� ������ ������
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

		
		///����� �������� �� ��������� key � ������
		long long Search(T key) const{
			Node<T> *cur = head;
			for (int i = 0; i < size; i++) {
				if (cur->data == key) return i;
				cur = cur->next;
			}
			return - 1;
		}

		///������� ������
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

		///���������� ��������� []
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

		///���������� ����� ������������� �������� � ������� � ��� ������� ����� �������� max
		size_t Max(T& max) const{
			if (head == nullptr && end == nullptr) // ���� ������ ������
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

		///���������� ������� ������
		void Sort() {
			if (head == nullptr && end == nullptr) // ���� ������ ������
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

		///��������� ������ L � ����� ������ � ������� L
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

/// ��������� ������� ������ ���������� ������
void Test();

