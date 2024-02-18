// Array.cpp : "Этот файл содержит функции для работы с массивом


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
void array_fill_randomly(T* arr, unsigned n, T min, T max) {
    //srand(time(NULL));
    T Mrange = max - min; //диапазон рандома
    for (unsigned i = 0; i < n; i++)
        arr[i] = (((T)rand() / RAND_MAX) * Mrange) + min;
}

template <typename T>
/// выводит массив в файл
/// \param arr массив
/// \param n размер массива
/// \param FileName файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
void output_to_file(const T* arr, unsigned n, const std::string& FileName) {
    std::ofstream file;
    file.open(FileName);
    if (file.is_open()) {
        for (unsigned i = 0; i < n; i++) {
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
bool checking_for_increasing(const T* arr, unsigned n) {
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

template <typename T>
/// проверяет отсортирован ли массив по убыванию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но в файл выводиться массив
bool checking_for_descending(const T* arr, unsigned n) {
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}

/// Тест функции checking_for_increasing
void Test_checking_for_increasing() {

    double *c = new double[6] {1, 2, 3, 4, 5, 6};
    assert(checking_for_increasing(c, 6) == true);
    delete[] c;

    double *d = new double[6] {1, 6, 3, 5, 5, 6};
    assert(checking_for_increasing(d, 6) == false);
    delete[] d;

    int *a= new int[3] {1, 6, 3};
    assert(checking_for_increasing(a, 3) == false);
    delete[] a;

    int* a1 = new int[3] {-1, 2, 3};
    assert(checking_for_increasing(a1, 3) == true);
    delete[] a1;

    char* n1 = new char[4] {'a', 'b', 'c', 'd'};
    assert(checking_for_increasing(n1, 4) == true);
    delete[] n1;

    char* n2 = new char[4] {'a', 'l', 'c', 'd'};
    assert(checking_for_increasing(n2, 4) == false);
    delete[] n2;

}

/// Тест функции checking_for_descending
void Test_сhecking_for_descending() {

    double* c = new double[6] {6, 5, 4, 3, 2, 1};
    assert(checking_for_descending(c, 6) == true);
    delete[] c;

    double* d = new double[6] {1, 6, 3, 5, 5, 6};
    assert(checking_for_descending(d, 6) == false);
    delete[] d;

    int* a = new int[3] {1, 6, 3};
    assert(checking_for_descending(a, 3) == false);
    delete[] a;

    int* a1 = new int[3] {-1, -2, -6};
    assert(checking_for_descending(a1, 3) == true);
    delete[] a1;

    char* n1 = new char[4] {'d', 'c', 'b', 'a'};
    assert(checking_for_descending(n1, 4) == true);
    delete[] n1;

    char* n2 = new char[4] {'a', 'l', 'c', 'd'};
    assert(checking_for_descending(n2, 4) == false);
    delete[] n2;

}


// определение начального момента времени
auto t0 = steady_clock::now();

//участок кода, время выполнения которого нужно измерить
//...

// определение конечного момента времени
auto t1 = steady_clock::now();

// преобразование времени (обычно наносекунды) в миллисекунды
auto delta = duration_cast<milliseconds>(t1 - t0);






int main()
{
    Test_checking_for_increasing();
    Test_сhecking_for_descending();
}
