///Автор Колосова Е.К.
///Класс для создание объкта типа массив. Используется для поиска элемента в массиве, сортировки, вставки элемента в конец,
/// удаления последнего элемента
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
	//поля:

	/// указатель на начало массива
	T *array;

	/// индекс последней свободной ячейки
	size_t last;

	/// размер массива
	size_t size;

public:
	///Конструктор без параметров
	Array() {
		size = 0;
		last = 0;
		array = nullptr;
	}

	///Резервирование памяти под n элемнтов.
	///Бросает исключение, invalid_argument если параметр n равен нулю
	Array(size_t n) {
		if (n > 0) {
			size = n;
			last = 0;
			array = new T[size];
		}
		else throw std::invalid_argument("Invalid size value");
	}

	///перегрузка оператора []
	///Бросает исключение, invalid_argument, если  index превышает last
	T& operator[](size_t index) {
		if (index <= last) {
			return array[index];
		}
		else throw std::invalid_argument("Invalid index value");
	}
	

	///Изменение размера массива
	///Бросает исключение, invalid_argument если параметр n равен нулю
	void resize(size_t new_value) {
		if (new_value > 0) {
			T* new_array= new T[new_value]; //для копирования значений
			size_t qelem = 0; //хранит размер 
			size_t l = 0; //хранит первоначальное значение last
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
	

	///Возвращает кол-во элементов в массиве
	size_t lenght() const{
		return last;
	}

	///Возрращает под сколько элементов выделена память в массиве
	size_t get_size() const {
		return size;
	}

	///Добавляет элемент new_element в конец массива
	void add(T new_element) {
		if (last < size) { //если есть свободная ячейка памяти
			array[last] = new_element;
			last++;
		}
		else { //если нет свободной ячейки памяти
			if (size == 0) { //если создано с помощью конструктора без параметров
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

	///Добавляет элемент new_element в позицию index
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

	///Удаляет последний элемент массива
	///Бросает исключение, invalid_argument если массив не содержит элементов
	void del() {
		if (last != 0) {
			last = last - 1;
			if (last < size / 2) { //уменьшает размер памяти, выделенной под массив, если в нём содержиться более чем в два раза меньше элементов
				size = size / 2;
				array = new T[size];
			}
		}
		else throw std::invalid_argument("The array contains no elements");
	}

	///Возвращает индекс первого вхождения значения key в массиве. Если такого нет, то возвращает -1
	long long SearchInArray(T key) const{
		return Search(array, last, key);
	}


	///Сортирует массив по возрастанию(сортировка Шелла)
	void Sort()
	{
		Shell_sort(array, last);
	}


	///Деструктор
	~Array() {
		if (array == nullptr)
			delete array;
		else
			delete[] array;
	}



};

///Тест метода Search
void Test_Search();

///Тест метода Sort
void Test_Sort();

///Тест метода add
void Test_add();

///Тест метода del
void Test_del();

///Тест методов
void Test();

///Тест изменения размера массива
void Test_resize();

