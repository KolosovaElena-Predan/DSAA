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

		
		///�������� ���������� ��������
		void delLast() {
			if (head == nullptr && end == nullptr) // ���� ������ ������
			{
				throw std::invalid_argument("The list contains no elements");
			}
			Node<T> *temp = end;
			end = end->prev;
			end->next = nullptr;
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
		long long Search(T key) {
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

		
};

void Test_addLast();
void Test_addFirst();
void Test_add();
void Test_delFirst();
void Test_delLast();
void Test_del();
void Test_Search();
void Test();

