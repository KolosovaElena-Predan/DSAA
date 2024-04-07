//Автор Колосова Е.К.
//Модуль предназначен для работы с массивами. Содердит функции поиска, сортировки, вывода в файл и др.

#include <time.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <assert.h>
#include <chrono>
#include <functional>
#include <stack>
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


//BigO(n)-худший случай, Big0(n) - средний случай, BigO(1)-лучший случай
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


//BigO(logn)-худший случай, Big0(logn) - средний случай, BigO(1)-лучший случай
/// находит заданнный элемент в массиве методом бинарного поиска
/// \param arr массив
/// \param n размер массива
/// \param key элемент, который необходимо найти
/// \return первое вхождение key в arr; если его нет, то -1
template <typename T>
long long Search_bin(T* arr, size_t n, T key) { // заменить типы и коментарий про возрастание
    //Bubble_sort(arr, n);

    bool flag = false;
    size_t left = 0; // левая граница
    size_t right = n - 1; // правая граница
    size_t middle; //индекс середины массива

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

//BigO(n^2)-худший случай, BigO(n^2) - средний случай, BigO(n)-лучший случай
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

//BigO(n)-худший случай, Big0(loglogn) - средний случай, BigO(1)-лучший случай
/// находит заданнный элемент в массиве методом интеропляциооного поиска
/// \param arr массив
/// \param n размер массива
/// \param key элемент, который необходимо найти
/// \return первое вхождение key в arr; если его нет, то -1
template <typename T>
long long Search_interpol(T* arr, size_t n, T key) {

    bool flag = false;
    size_t left = 0; // левая граница
    size_t right = n - 1; // правая граница
    size_t middle; //индекс середины массива

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

template <typename T>
/// ищет элемент в массиве, соответствующий функции f
/// \param arr массив
/// \param n размер массива
/// \param f - вызываемая функция(возращаемый тип - bool, параметр соовтествует типу массива)
/// \return первое вхождение в arr; если его нет, то -1
size_t find_predicate(T* arr, size_t n, std::function<bool(T&)> f) {
    for (size_t i = 0; i < n; i++)
        if (f(arr[i]))
            return i;

    return -1;
}

//тест find_predicate
void Test_find_predicate();

///функция объединения двух частей массива для функции Merge_sort
/// \param arr массив
/// \param first индекс элемента, с которого начинается слияние
/// \param last индекс элемента, на котором заканчивается слияние
/// \return ничего, но сортирует по возрастанию arr 
template <typename T>
void Merge(T* arr, size_t first, size_t last)
{
    size_t middle, start, final, j;
    T* mas = new T[last - first + 1];
    middle = (first + last) / 2; //вычисление индекса среднего элемента
    start = first; //начало левой части
    final = middle + 1; //начало правой части
    for (j = 0; j <= last - first; j++)
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
        arr[j] = mas[j - first];
    delete[] mas;

};

///Тест функции Merge
void Test_Merge();


//BigO(n*logn)-худший случай, Big0(n*logn) - средний случай, BigO(n*logn)-лучший случай
///сортировка слиянием(рекурсивная)
/// сортировка слиянием по возрастанию
/// \param arr массив
/// \param first индекс элемента, с которого начинается сортировка
/// \param last индекс элемента, на котором заканчивается сортировка
/// \return ничего, но сортирует по возрастанию arr 
template <typename T>
void Merge_sort(T* arr, size_t first, size_t last)
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

//BigO(n*logn^2)-худший случай, BigO(n*logn^2) - средний случай, BigO(n*logn)-лучший случай
///сортировка Шелла
/// \param arr массив
/// \param n размер массива
/// \return ничего, но сортирует по возрастанию arr 
template <typename T>
void Shell_sort(T* arr, size_t n)
{
    size_t i = 0;
    size_t j = 0;
    size_t step = 0;
    T tmp = 0;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
}

///тест функции Shell_sort
void Test_Shell_sort();

/// Перебрасывает элементы больше опорного в правую часть, а меньше - в левую
/// \param arr массив
/// \param first индекс элемента начала
/// \param last индекс элемента конца
/// \return индекс опорного элемента
template <typename T>
size_t partition(T* arr, size_t first, size_t last) {
    size_t ii = first+rand() % (last - first);
    T a2 = arr[ii];
    arr[ii] = arr[last];
    arr[last] = a2;

    T x = arr[last];
    size_t i = first - 1;
    for (size_t j = first; j < last; j++) {
        if (arr[j] < x) {
            i = i + 1;
            T a = arr[j];
            arr[j] = arr[i];
            arr[i] = a;
        }
    }
    T a1 = arr[last];
    arr[last] = arr[i + 1];
    arr[i + 1] = a1;
    return i + 1;
}

/*///Тест функции partition
void Test_partition();*/


//BigO(n^2)-худший случай, BigO(n*logn) - средний случай, BigO(n*logn)-лучший случай
///быстрая сортировка
/// \param arr массив
/// \param first индекс элемента, с которого начинается сортировка
/// \param last индекс элемента, на котором заканчивается сортировка
/// \return ничего, но сортирует по возрастанию arr 
template <typename T>
void quicksort(T* arr, size_t first, size_t last) {
    if (first < last) {

        size_t p = partition(arr, first, last); //находим индекс опорного элемента

        if (p > 0)
        {
            quicksort(arr, first, p - 1); //сортировка левой части
        }
        if (p < last) {
            quicksort(arr, p + 1, last);//сортировка правой части
        }
    }
}


/*///быстрая сортировка
/// \param arr массив
/// \param first индекс элемента, с которого начинается сортировка
/// \param last индекс элемента, на котором заканчивается сортировка
/// \return ничего, но сортирует по возрастанию arr
template <typename T>
void quicksort(T* array, long long low, long long high)
{
    long long i = low;      //левая граница
    long long j = high;     //правая граница
    T pivot = array[(i + j) / 2];//опорный элемент(в середине)
    T temp; //для замены

    while (i <= j)
    {
        //в левой части оставляем на месте элементы, которые меньше центрального
        while (array[i] < pivot)
            i++;
        //в правой части оставляем на месте элементы, которые больше центрального
        while (array[j] > pivot)
            j--;

        if (i <= j)
        {
            temp = array[i]; //меняем местами элементы
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    //сортируем, пока есть что сортировать
    if (j > low)
        quicksort(array, low, j);

    if (i < high)
        quicksort(array, i, high);
}*/


///тест функции quicksort
void Test_quicksort();



///Тест всех функций модуля
void Test_function();
