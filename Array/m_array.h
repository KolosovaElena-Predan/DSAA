//Автор Колосова Е.К.
//Модуль предназначен для работы с массивами. Содердит функции поиска, сортировки, вывода в файл и др.

#include <time.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <assert.h>
#include <chrono>
using namespace std::chrono;

template <typename T>
/// заполняет массив случайными числами
/// \param arr массив
/// \param n размер массива
/// \param min минимально возможное число в массиве
/// \param max максимально возможное число в массве
/// \return ничего
void array_fill_randomly(T* arr, unsigned n, T min, T max);

template <typename T>
/// выводит массив в файл
/// \param arr массив
/// \param n размер массива
/// \param FileName файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
void output_to_file(const T* arr, unsigned n, const std::string& FileName);

template <typename T>
/// проверяет отсортирован ли массив по возрастанию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но в файл выводиться массив
bool checking_for_increasing(const T* arr, unsigned n);

template <typename T>
/// проверяет отсортирован ли массив по убыванию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но в файл выводиться массив
bool checking_for_descending(const T* arr, unsigned n);

/// Тест функции checking_for_increasing
void Test_checking_for_increasing();

/// Тест функции checking_for_descending
void Test_сhecking_for_descending();


template <typename T>
/// находит заданнный элемент в массиве методом последовательного поиска
/// \param arr массив
/// \param n размер массива
/// \param key элемент, который необходимо найти
/// \return первое вхождение key в arr; если его нет, то -1
int Search(T* arr, unsigned n, T key);


/// Тестирует функцию Search
void Test_Search();


template <typename T>
/// находит заданнный элемент в массиве методом бинарного поиска
/// \param arr массив
/// \param n размер массива
/// \param key элемент, который необходимо найти
/// \return первое вхождение key в arr; если его нет, то -1
int Search_bin(T* arr, unsigned n, T key);

/// Тестирует функцию Search_bin 
void Test_Search_bin();

template <typename T>
/// пузырьковая сортировка по возрастанию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но сортирует по возрастанию arr
void Bubble_sort(T* arr, unsigned n);


/// Тестирует функцию Bubble_sort
void Test_Bubble_sort();


///Тест всех функций модуля
void Test_function();