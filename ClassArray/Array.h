///����� �������� �.�.
///����� ��� �������� ������ ���� ������. ������������ ��� ������ �������� � �������, ����������, ������� �������� � �����,
/// �������� ���������� ��������
#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "m_array.h"


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

	///�������������� ������ ��� n ��������.
	///������� ����������, invalid_argument ���� �������� n ����� ����
	Array(size_t n) {
		if (n > 0) {
			size = n;
			last = 0;
			array = new T[size];
		}
		else throw std::invalid_argument("Invalid size value");
	}

	///���������� ��������� []
	///������� ����������, invalid_argument, ����  index ��������� last
	T& operator[](size_t index) {
		if (index <= last) {
			return array[index];
		}
		else throw std::invalid_argument("Invalid index value");
	}
	

	///��������� ������� �������
	///������� ����������, invalid_argument ���� �������� n ����� ����
	void resize(size_t new_value) {
		if (new_value > 0) {
			T* new_array= new T[new_value]; //��� ����������� ��������
			size_t qelem = 0; //������ ������ 
			size_t l = 0; //������ �������������� �������� last
			if (new_value > size) {
				qelem = size;
				l = last;
			}
			else {
				qelem = new_value;
				l = new_value-1;
			}
			std::copy(array, array + qelem, new_array);
			delete[] array;
			array = new_array;
			last = l;
			size = new_value;
		}
		else throw std::invalid_argument("Invalid size value");
	}
	

	///���������� ���-�� ��������� � �������
	size_t lenght() const{
		return last;
	}

	///���������� ��� ������� ��������� �������� ������ � �������
	size_t get_size() const {
		return size;
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

	///��������� ������� new_element � ������� index
	void add(T new_element,  size_t index) {
		if (index=last) { 
			add(new_element);
		}
		else { 
			if (index < last&&last+1<=size) {
				T* a = new T[size];
				memmove(a, array, sizeof(T) * (index - 1));
				a[index] = new_element;
				memmove(a + sizeof(T) * index, array + sizeof(T) * index, sizeof(T) * (last - index));
				last = last + 1;
				memmove(array, a, sizeof(a));
				delete[] a;
			}
		}
	}

	///������� ��������� ������� �������
	///������� ����������, invalid_argument ���� ������ �� �������� ���������
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
	long long SearchInArray(T key) const{
		return Search(array, last, key);
	}


	///��������� ������ �� �����������(���������� �����)
	void Sort()
	{
		Shell_sort(array, last);
	}


	///����������
	~Array() {
		if (array == nullptr)
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

///���� ��������� ������� �������
void Test_resize();

