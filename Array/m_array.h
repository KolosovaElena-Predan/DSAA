//Автор Колосова Е.К.
//Модуль предназначен для работы с массивами. Содердит функции поиска, сортировки, вывода в файл и др.

#include <time.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <assert.h>
#include <chrono>
using namespace std::chrono;

/// заполняет массив случайными числами
/// \param arr массив
/// \param n размер массива
/// \param min минимально возможное число в массиве
/// \param max максимально возможное число в массве
/// \return ничего
template <typename T>
void array_fill_randomly(T* arr, size_t n, T min, T max) { //size_t - беззнаковый целый тип
    //srand(time(NULL));
    T Mrange = max - min; //диапазон рандома
    for (size_t i = 0; i < n; i++)
        arr[i] = (((T)rand() / RAND_MAX) * Mrange) + min;
}


/// выводит массив в файл
/// \param arr массив
/// \param n размер массива
/// \param FileName файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
template <typename T>
void output_to_file(const T* arr, size_t n, const std::string& FileName) {
    std::ofstream file;
    file.open(FileName);
    if (file.is_open()) {
        for (size_t i = 0; i < n; i++) {
            file << arr[i];
            if (i != n - 1)
                file << std::endl;
        }
    }
    else
        throw std::invalid_argument("File not found");
    file.close();

}

template <typename T>
/// проверяет отсортирован ли массив по возрастанию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но в файл выводиться массив
bool checking_for_increasing(const T* arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}


/// проверяет отсортирован ли массив по убыванию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но в файл выводиться массив
template <typename T>
bool checking_for_descending(const T* arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}

/// Тест функции checking_for_increasing
void Test_checking_for_increasing();

/// Тест функции checking_for_descending
void Test_сhecking_for_descending();


//BigO(n), BigΩ(1), Bigθ(n)
/// находит заданнный элемент в массиве методом последовательного поиска
/// \param arr массив
/// \param n размер массива
/// \param key элемент, который необходимо найти
/// \return первое вхождение key в arr; если его нет, то -1
template <typename T>
long long Search(T* arr, size_t n, T key) { //про типы дописать
    for (size_t i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}


/// тест функции Search
void Test_Search();


//BigO(log(n)), BigΩ(1), Bigθ(log(n))
/// находит заданнный элемент в массиве методом бинарного поиска
/// \param arr массив
/// \param n размер массива
/// \param key элемент, который необходимо найти
/// \return первое вхождение key в arr; если его нет, то -1
template <typename T>
int Search_bin(T* arr, size_t n, T key) { // заменить типы и коментарий про возрастание
    //Bubble_sort(arr, n);

    bool flag = false;
    int left = 0; // левая граница
    int right = n - 1; // правая граница
    int middle; //индекс середины массива

    while ((left <= right) && (flag != true)) {
        middle = (left + right) / 2; // определяем индекс середины
        if (arr[middle] == key) {
            flag = true; //проверяем ключ со серединным элементом
            return middle;
        }
        //узнаём какую часть нужно отбросить
        if (arr[middle] > key)
            right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}

/// тест функции Search_bin 
void Test_Search_bin();

/// пузырьковая сортировка по возрастанию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но сортирует по возрастанию arr
template <typename T>
void Bubble_sort(T* arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < (n - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                T b = arr[j]; // промежуточная переменная
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
}


/// тест функци Bubble_sort
void Test_Bubble_sort();

/// находит заданнный элемент в массиве методом интеропляциооного поиска
/// \param arr массив
/// \param n размер массива
/// \param key элемент, который необходимо найти
/// \return первое вхождение key в arr; если его нет, то -1
template <typename T>
int Search_interpol(T* arr, size_t n, T key) {

    bool flag = false;
    int left = 0; // левая граница
    int right = n - 1; // правая граница
    int middle; //индекс середины массива

    while (arr[left] < key && key < arr[right])
    {
        //вычисление интерполяцией следующего элемента, который будет сравниваться с key
        middle = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        
        if (arr[middle] == key)
            return middle;
        //получение новых границ области, если key не найдено
        if (arr[middle] < key)
            left = middle + 1;
        else 
            right = middle - 1;
    }
    if (arr[left] == key)
            return left;
    if (arr[right] == key)
        return right;
    return -1;
}

///тест функции Search_interpol
void Test_Search_interpol();


///функция объединения двух частей массива для функции Merge_sort
/// \param arr массив
/// \param first индекс элемента, с которого начинается слияние
/// \param last индекс элемента, на котором заканчивается слияние
/// \return ничего, но сортирует по возрастанию arr 
template <typename T>
void Merge(T* arr, int first, int last)
{
    int middle, start, final, j;
    int* mas = new int[1000];
    middle = (first + last) / 2; //вычисление индекса среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (j = first; j <= last; j++) 
        if ((start <= middle) && ((final > last) || (arr[start] < arr[final])))
        {
            mas[j] = arr[start];
            start++;
        }
        else
        {
            mas[j] = arr[final];
            final++;
        }
    //возвращение результата в последовательность
    for (j = first; j <= last; j++) 
        arr[j] = mas[j];
    delete[] mas;
};


///сортировка слиянием(рекурсивная)
/// сортировка слиянием по возрастанию
/// \param arr массив
/// \param first индекс элемента, с которого начинается сортировка
/// \param last индекс элемента, на котором заканчивается сортировка
/// \return ничего, но сортирует по возрастанию arr 
template <typename T>
void Merge_sort(T* arr, int first, int last)
{
        if (first < last)
        {
            Merge_sort(arr, first, (first + last) / 2); //сортировка левой части
            Merge_sort(arr, (first + last) / 2 + 1, last); //сортировка правой части
            Merge(arr, first, last); //слияние двух частей
        }
};

///тест функции Merge_sort
void Test_Merge_sort();


///Тест всех функций модуля
void Test_function();
