///����� �������� �.�.
///����� ��� �������� ������ ���� ����. 
/// ������������ ��� ...
#pragma once
#include <iostream>
#include "DoublyLinkedList.h"


template <typename T>
class Stack
{
//����:
private:
	DoublyLinkedList<T> elements; //������ ���������
	Node<T> * top;//��������� �� ������� �����

//������:
public:

	///����������� ��� ����������
	Stack() {
		elements.clear(); //������� ������ ���������
		top = elements.get_head(); //������������ ��������� �� ������� ����� �� ������ ������ ���������
	}
	
	~Stack() {
		Clear();
		delete top;
	}

	///���� ���� ����, �� ���������� true, ����� false
	bool isEmpty() {
		if (elements.get_size() == 0) return true;
		else return false;
	}
	
	///������� ������� ������� ����� � ���������� ��� ��������
	///������� ���������� invalid_argument, ���� ���� �� �������� ���������
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


	///��������� ������� � ����
	void Push(T value) {
		if (!isEmpty()) elements.addLast(value);
		else elements.addFirst(value);
		top = elements.get_end();

	}

	///���������� �������� �������
	///������� ���������� invalid_argument, ���� ���� �� �������� ���������
	T Peek() {
		if (!isEmpty()) return top->data;
		else throw std::invalid_argument("The stack contains no elements");
	}

	///������� �����
	void Clear() {
		if (!isEmpty()) {
			elements.clear();
		}
		top=nullptr;
	}
};

void Test_Stack_Function();


