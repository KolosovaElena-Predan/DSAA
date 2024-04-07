#include <assert.h>
#include "Stack.h"


void Test_Stack_Function() {
	Test();

	//�������� ������ isEmpty �� ������ �����
	Stack<int> S;
	assert(S.isEmpty() == true);

	//��������� ������� � ����
	S.Push(5);
	assert(S.isEmpty() == false); //��������, ��� ���� ������ �� ������

	//���������� �����
	S.Push(3);
	S.Push(9);
	S.Push(8);
	S.Push(12);

	assert(S.Peek() == 12);
	assert(S.Pop() == 12);
	assert(S.Peek() == 8);
	assert(S.Pop() == 8);
	assert(S.Peek() == 9);
	assert(S.Pop() == 9);
	assert(S.Peek() == 3);
	assert(S.Pop() == 3);
	assert(S.Peek() == 5);
	assert(S.Pop() == 5);
	assert(S.isEmpty() == true);
}