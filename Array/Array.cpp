// Array.cpp : "Этот файл содержит функции для работы с массивом
//Автор: Колосова Е.К.

#include "m_array.h"

#include <time.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <assert.h>
#include <chrono>
#include <functional>
#include <stack>

using namespace std::chrono;
int main()
{
   Test_function();
   /*long long n = 10;
   double* c=new double[n];
   long long s = 0;
   srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        array_fill_randomly(c, n, 0.0, 1000.0);
        // определение начального момента времени
        auto t0 = steady_clock::now();

        //участок кода, время выполнения которого нужно измерить
        Merge_sort(c, 0, n-1);

        // определение конечного момента времени
        auto t1 = steady_clock::now();

        // преобразование времени (обычно наносекунды) в миллисекунды
        auto delta = duration_cast<nanoseconds>(t1 - t0);

        s = s + delta.count();
    }
    std::cout << s / 10000;*/

}

