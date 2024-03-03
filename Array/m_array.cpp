//Автор: Колосова Е.К.
//Модуль предназначен для работы с массивами. Содердит функции поиска, сортировки, вывода в файл и др.

#include <time.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <assert.h>
#include <chrono>
#include "m_array.h"
using namespace std::chrono;




/// Тест функции checking_for_increasing
void Test_checking_for_increasing() {

    double* c = new double[6] {1, 2, 3, 4, 5, 6};
    assert(checking_for_increasing(c, 6) == true);
    delete[] c;

    double* d = new double[6] {9, 1, 2, 3, 4, 5};
    assert(checking_for_increasing(d, 6) == false);
    delete[] d;

    double* d1 = new double[6] {1, 2, 3, 4, 6, 5};
    assert(checking_for_increasing(d1, 6) == false);
    delete[] d1;

    double* d2 = new double[6] {1, 2, 3, 1, 5, 6};
    assert(checking_for_increasing(d2, 6) == false);
    delete[] d2;

    int* a = new int[3] {1, 6, 3};
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

    double* d = new double[6] {1, 6, 5, 4, 3, 2};
    assert(checking_for_descending(d, 6) == false);
    delete[] d;

    double* d1 = new double[6] {6, 5, 4, 3, 2, 15};
    assert(checking_for_descending(d1, 6) == false);
    delete[] d1;

    double* d2 = new double[6] {6, 5, 28, 3, 2, 1};
    assert(checking_for_descending(d2, 6) == false);
    delete[] d2;

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



//тест функции Search
void Test_Search() {
    double* c = new double[3] {1, 2, 3};
    assert(Search(c, 3, 1.0) == 0);
    delete[] c;

    double* d = new double[3] {3, 2, 1};
    assert(Search(d, 3, 2.0) == 1);
    delete[] d;

    int* a = new int[3] {1, 6, 3};
    assert(Search(a, 3, 3) == 2);
    delete[] a;

    int* a1 = new int[3] {-1, -2, -6};
    assert(Search(a1, 3, 4) == -1);
    delete[] a1;

    char* n1 = new char[4] {'d', 'c', 'b', 'a'};
    assert(Search(n1, 4, 'c') == 1);
    delete[] n1;
}



///тест фунуции Search_bin
void Test_Search_bin() {
    double* c = new double[3] {1, 2, 3};
    assert(Search_bin(c, 3, 1.0) == 0);
    delete[] c;

    double* c1 = new double[5] {1, 2, 3, 4, 5};
    assert(Search_bin(c1, 5, 3.0) == 2);
    delete[] c1;

    double* c2 = new double[5] {1, 2, 3, 6, 8};
    assert(Search_bin(c2, 5, 8.0) == 4);
    delete[] c2;

    double* c3 = new double[7] {1, 2, 3, 45, 72, 134, 900};
    assert(Search_bin(c3, 7, 4.0) ==-1);
    delete[] c3;

    int* a = new int[4] {1, 2, 3, 4};
    assert(Search_bin(a, 4, 3) == 2);
    delete[] a;

    char* n1 = new char[4] {'a', 'b', 'c', 'd'};
    assert(Search(n1, 4, 'd') == 3);
    delete[] n1;
}


///тест функции Bubble_sort
void Test_Bubble_sort() {
    double* c = new double[3] {3, 2, 1};
    Bubble_sort(c, 3);
    assert(c[0] == 1.0);
    assert(c[1] == 2.0);
    assert(c[2] == 3.0);
    delete[] c;

    double* d = new double[3] {2, 3, 1};
    Bubble_sort(d, 3);
    assert(d[0] == 1.0);
    assert(d[1] == 2.0);
    assert(d[2] == 3.0);
    delete[] d;

    int* a = new int[3] {1, 6, 3};
    Bubble_sort(a, 3);
    assert(a[0] == 1);
    assert(a[1] == 3);
    assert(a[2] == 6);
    delete[] a;

    int* a1 = new int[3] {-1, -2, -6};
    Bubble_sort(a1, 3);
    assert(a1[0] == -6);
    assert(a1[1] == -2);
    assert(a1[2] == -1);
    delete[] a1;

    char* n = new char[4] {'d', 'c', 'b', 'a'};
    Bubble_sort(n, 4);
    assert(n[0] == 'a');
    assert(n[1] == 'b');
    assert(n[2] == 'c');
    assert(n[3] == 'd');
    delete[] n;
}

///тест функции Search_interpol
void Test_Search_interpol() {
    double* c = new double[3] {1, 2, 3};
    assert(Search_interpol(c, 3, 1.0) == 0);
    delete[] c;

    double* c1 = new double[5] {1, 2, 3, 4, 5};
    assert(Search_interpol(c1, 5, 3.0) == 2);
    delete[] c1;

    double* c2 = new double[5] {1, 2, 3, 6, 8};
    assert(Search_interpol(c2, 5, 8.0) == 4);
    delete[] c2;

    double* c3 = new double[7] {1, 2, 3, 45, 72, 134, 900};
    assert(Search_interpol(c3, 7, 4.0) == -1);
    delete[] c3;

    int* a = new int[4] {1, 2, 3, 4};
    assert(Search_interpol(a, 4, 3) == 2);
    delete[] a;

    char* n1 = new char[4] {'a', 'b', 'c', 'd'};
    assert(Search_interpol(n1, 4, 'd') == 3);
    delete[] n1;
}

///тест функции Merge_sort
void Test_Merge_sort() {
    double* c = new double[3] {3, 2, 1};
    Merge_sort(c,0, 2);
    assert(c[0] == 1.0);
    assert(c[1] == 2.0);
    assert(c[2] == 3.0);
    delete[] c;

    double* d = new double[3] {2, 3, 1};
    Merge_sort(d,0, 2);
    assert(d[0] == 1.0);
    assert(d[1] == 2.0);
    assert(d[2] == 3.0);
    delete[] d;

    double* d2 = new double[5] {2, 3, 1, 5, 4};
    Merge_sort(d2,0, 4);
    assert(d2[0] == 1.0);
    assert(d2[1] == 2.0);
    assert(d2[2] == 3.0);
    assert(d2[3] == 4.0);
    assert(d2[4] == 5.0);
    delete[] d2;

    int* a = new int[3] {1, 6, 3};
    Merge_sort(a,0, 2);
    assert(a[0] == 1);
    assert(a[1] == 3);
    assert(a[2] == 6);
    delete[] a;


    int* a1 = new int[3] {-1, -2, -6};
    Merge_sort(a1,0, 2);
    assert(a1[0] == -6);
    assert(a1[1] == -2);
    assert(a1[2] == -1);
    delete[] a1;

    char* n = new char[4] {'d', 'c', 'b', 'a'};
    Merge_sort(n,0, 3);
    assert(n[0] == 'a');
    assert(n[1] == 'b');
    assert(n[2] == 'c');
    assert(n[3] == 'd');
    delete[] n;
}

///Тест всех функций модуля
void Test_function() {
    Test_Bubble_sort();
    Test_Search_bin();
    Test_Search();
    Test_сhecking_for_descending();
    Test_checking_for_increasing();
    Test_Search_interpol();
    Test_Merge_sort();
}
