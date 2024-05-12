///�����: �������� �.�.
///����� ����������� ��� �������. ����������� ������� ���������� � �������(enqueue), 
///�������� �� �������(dequeue), �������� �� �� ������ �� ������� (isEmpty), 
/// ����������� �������(size), ����������� �������� �������� �� ������ �������(Peek),
/// ������� ������� (clear)
#pragma once
#include "DoublyLinkedList.h"
#include <iostream>
template <class T>
class Queue
{
	private:
		DoublyLinkedList<T> elements; //�������� �������
		Node<T> * front; //��������� �� ������ ������� �������
		Node<T>* rear; //��������� �� ��������� ������� �������

	public:

		///���c������� ��� ����������
		Queue(){
			elements.clear();
			front = nullptr;
			rear = nullptr;
		}

		///���������� �������� ���-�� ��������� � �������
		size_t size() const{
			return elements.get_size();
		}

		///���� ������� �����, �� ���������� true, ����� false
		bool isEmpty() const{
			if (elements.get_size() == 0) return true;
			else return false;
		}

		///��������� ������� � �������
		void enqueue(T value) {
			if (!isEmpty()) elements.addLast(value);
			else elements.addFirst(value);
			front = elements.get_head();
			rear = elements.get_end();
		}

		///������� ������� �� �������
		///������� ���������� invalid_argument, ���� ������� �� �������� ���������
		T dequeue() {
			if (!isEmpty()) {
				T del_element = front->data;
				elements.delFirst();
				front = elements.get_head();
				return del_element;
			}
			else throw std::invalid_argument("The queue contains no elements");
		}

		///���������� �������� �������
		///������� ���������� invalid_argument, ���� ������� �� �������� ���������
		T Peek() const{
			if (!isEmpty()) return front->data;
			else throw std::invalid_argument("The queue contains no elements");
		}

		///������� �������
		void Clear() {
			if (!isEmpty()) {
				elements.clear();
			}
			front = nullptr;
			rear = nullptr;
		}

};

///���� ������� ������ Queue
void Test_queue_functions();

