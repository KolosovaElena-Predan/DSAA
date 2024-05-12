///�����: �������� �.�.
///����� ����������� ��� �������. ����������� ������� ���������� � �������(enqueue), 
///�������� �� �������(dequeue), �������� �� �� ������ �� ������� (isEmpty), 
/// ����������� �������(size), ����������� �������� �������� �� ������ �������(Peek),
/// ������� ������� (clear)
#include <assert.h>
#include <string>
#include "Queue.h"

///���� ������� ������ Queue
void Test_queue_functions() {
	Test();

	//�������� ������ isEmpty �� ������ �������
	Queue<int> S;
	assert(S.size() == 0);
	assert(S.isEmpty() == true);

	//��������� ������� � �������
	S.enqueue(5);
	assert(S.isEmpty() == false); //��������, ��� ���� ������ �� ������
	assert(S.size() == 1);//���-�� ��������� ����� ����� 1

	//���������� �������
	S.enqueue(3);
	assert(S.size() == 2);
	S.enqueue(9);
	assert(S.size() == 3);
	S.enqueue(8);
	assert(S.size() == 4);
	S.enqueue(12);
	assert(S.size() == 5);

	//������� ����� ��� 5 3 9 8 12
	assert(S.Peek() == 5);
	assert(S.dequeue() == 5);
	assert(S.size() == 4);
	assert(S.Peek() == 3);
	assert(S.dequeue() == 3);
	assert(S.size() == 3);
	assert(S.Peek() == 9);
	assert(S.dequeue() == 9);
	assert(S.size() == 2);
	assert(S.Peek() == 8);
	assert(S.dequeue() == 8);
	assert(S.size() == 1);
	assert(S.Peek() == 12);
	assert(S.dequeue() == 12);
	assert(S.size() == 0);
	assert(S.isEmpty() == true);

	//�������� �� ��, ��� ���� ������� ���������� ��� ������� 
	//������� ������� �� ������ �������
	try {
		int a=S.dequeue();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}
	
	//�������� �� ��, ��� ���� ������� ���������� ��� ������� 
	//������� �������� ������� �������� �� ������ �������
	try {
		int a=S.Peek();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}

	//�������� ������ isEmpty �� ������ �������
	Queue<double> S1;
	assert(S1.size() == 0);
	assert(S1.isEmpty() == true);

	//��������� ������� � �������
	S1.enqueue(-5.7);
	assert(S1.isEmpty() == false); //��������, ��� ���� ������ �� ������
	assert(S1.size() == 1);//���-�� ��������� ����� ����� 1

	//���������� �������
	S1.enqueue(3.233);
	assert(S1.size() == 2);
	S1.enqueue(23.9);
	assert(S1.size() == 3);
	S1.enqueue(8.53);
	assert(S1.size() == 4);
	S1.enqueue(121.2);
	assert(S1.size() == 5);

	S1.Clear();
	assert(S1.size() == 0);

	//�������� �� ��, ��� ���� ������� ���������� ��� ������� 
	//������� ������� �� ������ �������
	try {
		int a = S1.dequeue();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}

	//�������� �� ��, ��� ���� ������� ���������� ��� ������� 
	//������� �������� ������� �������� �� ������ �������
	try {
		int a = S1.Peek();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}


}
