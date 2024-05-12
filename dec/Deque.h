///�����: �������� �.�.
///����� ����������� ��� ���.����������� ������� ���������� � ������ � � �����, 
///�������� �� ������ � �� �����, �������� �� �� ������ �� ��� (isEmpty), 
/// ����������� �������(size), ����������� �������� �������� �� ������ � ����� ����,
/// ������� ���� (clear)
/// ���������� �� ������ ������ ���������� ������ DoublyLinkedList
#pragma once
#include "DoublyLinkedList.h"
#include <iostream>
template <class T>
class Deque
{
private:
	DoublyLinkedList<T> elements; //�������� ����
	Node<T>* front; //��������� �� ������ ������� ����
	Node<T>* end; //��������� �� ��������� ������� ����

public:

	///���c������� ��� ����������
	Deque() {
		elements.clear();
		front = nullptr;
		end = nullptr;
	}

	///���������� �������� ���-�� ��������� � �������
	size_t size() const {
		return elements.get_size();
	}

	///���� ��� ����, �� ���������� true, ����� false
	bool isEmpty() const {
		if (elements.get_size() == 0) return true;
		else return false;
	}

	///��������� ������� � ����� ����
	void PushBack(T value) {
		if (!isEmpty()) elements.addLast(value);
		else elements.addFirst(value);
		front = elements.get_head();
		end = elements.get_end();
	}

	///��������� ������� � ������ ����
	void PushFront(T value) {
		elements.addFirst(value);
		/*front = elements.get_head();
		end = elements.get_end();*/

	}

	///������� ������� �� ������ ����
	///������� ���������� invalid_argument, ���� ������� �� �������� ���������
	T PopFront() {
		if (!isEmpty()) {
			T del_element = front->data;
			elements.delFirst();
			front = elements.get_head();
			return del_element;
		}
		else throw std::invalid_argument("The queue contains no elements");
	}

	///������� ������� �� ����� ����
	///������� ���������� invalid_argument, ���� ������� �� �������� ���������
	T PopBack() {
		if (!isEmpty()) {
			T del_element = end->data;
			elements.delLast();


			end = elements.get_end();
			return del_element;
		}
		else throw std::invalid_argument("The queue contains no elements");
	}

	///���������� �������� �� ������ ����
	///������� ���������� invalid_argument, ���� ������� �� �������� ���������
	T PeekFront() const {
		if (!isEmpty()) return front->data;
		else throw std::invalid_argument("The queue contains no elements");
	}

	///���������� �������� �� ����� ����
	///������� ���������� invalid_argument, ���� ������� �� �������� ���������
	T PeekBack() const {
		if (!isEmpty()) return end->data;
		else throw std::invalid_argument("The queue contains no elements");
	}

	///������� �������
	void Clear() {
		if (!isEmpty()) {
			elements.clear();
		}
		front = nullptr;
		end = nullptr;
	}

};

///���� ������� ������ Deque
void Test_deque_functions();

