// Array.cpp : "Этот файл содержит функции для работы с массивом
//Автор: Колосова Е.К.

#include "m_array.h"

#include <time.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <assert.h>
#include <chrono>
using namespace std::chrono;

int main()
{
    Test_function();

    /*long long n = 100000000;
    long long* c = new long long[n];
    for (long long i = 0; i < n; i++) {
        c[i] = i;
    }
    int l = 10000;
    long long s=0;
    for (int i = 0; i < l; i++) {
        // определение начального момента времени
        auto t0 = steady_clock::now();

        //участок кода, время выполнения которого нужно измерить
        Search(c, n, 5000000000);

        // определение конечного момента времени
        auto t1 = steady_clock::now();

        // преобразование времени (обычно наносекунды) в миллисекунды
        auto delta = duration_cast<milliseconds>(t1 - t0);

        s = s + delta.count();

    }
    std::cout << s / 1000;*/
}
