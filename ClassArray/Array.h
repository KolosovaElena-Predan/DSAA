///����� �������� �.�.
///����� ��� �������� ������ ���� ������. ������������ ��� ������ �������� � �������, ����������, ������� �������� � �����,
/// �������� ���������� ��������
#pragma once
#include <iostream>
template <typename T>
class Array
{
private:
	//����:

	/// ��������� �� ������ �������
	T *array;

	/// ������ ��������� ��������� ������
	size_t last;

	/// ������ �������
	size_t size;

public:
	///����������� ��� ����������
	Array() {
		size = 0;
		last = 0;
		array = nullptr;
	}

	///�������������� ������ ��� n ��������
	Array(size_t n) {
		if (n > 0) {
			size = n;
			last = 0;
			array = new T[size];
		}
		else throw std::invalid_argument("Invalid size value");
	}

	///���������� ��������� []
	T& operator[](size_t index) {
		if (index <= size) {
			return array[index];
		}
		else throw std::invalid_argument("Invalid index value");
	}

	///��������� ���-�� ��������� � �������
	void resize(size_t new_value) {
		if (new_value <= size) {
			last = new_value;
		}
		else throw std::invalid_argument("Invalid index value");
	}

	///���������� ���-�� ��������� � �������
	size_t lenght() {
		return last;
	}

	///��������� ������� new_element � ����� �������
	void add(T new_element) {
		if (last < size) { //���� ���� ��������� ������ ������
			array[last] = new_element;
			last++;
		}
		else { //���� ��� ��������� ������ ������
			if (size == 0) { //���� ������� � ������� ������������ ��� ����������
				size = size + 1;
				array = new T[size];
			}
			T* a = new T[2 * size];
			memcpy(a, array, sizeof(a));
			size = 2 * size;
			array = new T[size];
			memcpy(array, a, sizeof(array));
			array[last] = new_element;
			last = last + 1;
			delete[] a;
		}
	}

	///������� ��������� ������� �������
	void del() {
		if (last != 0) {
			last = last - 1;
			if (last < size / 2) { //��������� ������ ������, ���������� ��� ������, ���� � �� ����������� ����� ��� � ��� ���� ������ ���������
				size = size / 2;
				array = new T[size];
			}
		}
		else throw std::invalid_argument("The array contains no elements");
	}

	///���������� ������ ������� ��������� �������� key � �������. ���� ������ ���, �� ���������� -1
	long long Search(T key) {
		for (size_t i = 0; i < last; i++) {
			if (array[i] == key) {
				return i;
			}
		}
		return -1;
	}


	///��������� ������ �� �����������(���������� �����)
	void Sort()
	{
		size_t i = 0;
		size_t j = 0;
		size_t step = 0;
		T tmp = 0;
		for (step = last / 2; step > 0; step /= 2)
			for (i = step; i < last; i++)
			{
				tmp = array[i];
				for (j = i; j >= step; j -= step)
				{
					if (tmp < array[j - step])
						array[j] = array[j - step];
					else
						break;
				}
				array[j] = tmp;
			}
	}


	///����������
	~Array() {
		if (array = nullptr)
			delete array;
		else
			delete[] array;
	}



};

///���� ������ Search
void Test_Search();

///���� ������ Sort
void Test_Sort();

///���� ������ add
void Test_add();

///���� ������ del
void Test_del();

///���� �������
void Test();

