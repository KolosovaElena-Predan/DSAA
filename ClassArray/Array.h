///Автор Колосова Е.К.
///Класс для создание объкта типа массив. Используется для поиска элемента в массиве, сортировки, вставки элемента в конец,
/// удаления последнего элемента
#pragma once
#include <iostream>
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

	///Резервирование памяти под n элемнтов
	Array(size_t n) {
		if (n > 0) {
			size = n;
			last = 0;
			array = new T[size];
		}
		else throw std::invalid_argument("Invalid size value");
	}

	///перегрузка оператора []
	T& operator[](size_t index) {
		if (index <= size) {
			return array[index];
		}
		else throw std::invalid_argument("Invalid index value");
	}

	///Изменение кол-ва элементов в массиве
	void resize(size_t new_value) {
		if (new_value <= size) {
			last = new_value;
		}
		else throw std::invalid_argument("Invalid index value");
	}

	///Возвращает кол-во элементов в массиве
	size_t lenght() {
		return last;
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

	///Удаляет последний элемент массива
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
	long long Search(T key) {
		for (size_t i = 0; i < last; i++) {
			if (array[i] == key) {
				return i;
			}
		}
		return -1;
	}


	///Сортирует массив по возрастанию(сортировка Шелла)
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


	///Деструктор
	~Array() {
		if (array = nullptr)
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

