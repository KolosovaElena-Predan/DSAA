//�����: �������� �.�.
//������ ������������ ��� ������ � ���������. �������� ������� ������, ����������, ������ � ���� � ��.

#include <time.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <assert.h>
#include <chrono>
using namespace std::chrono;


template <typename T>
/// ��������� ������ ���������� �������
/// \param arr ������
/// \param n ������ �������
/// \param min ���������� ��������� ����� � �������
/// \param max ����������� ��������� ����� � ������
/// \return ������
void array_fill_randomly(T* arr, unsigned n, T min, T max) {
    //srand(time(NULL));
    T Mrange = max - min; //�������� �������
    for (unsigned i = 0; i < n; i++)
        arr[i] = (((T)rand() / RAND_MAX) * Mrange) + min;
}

template <typename T>
/// ������� ������ � ����
/// \param arr ������
/// \param n ������ �������
/// \param FileName ����, ���� ��������� ������
/// \return ������, �� � ���� ���������� ������
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
/// ��������� ������������ �� ������ �� �����������
/// \param arr ������
/// \param n ������ �������
/// \return ������, �� � ���� ���������� ������
bool checking_for_increasing(const T* arr, unsigned n) {
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

template <typename T>
/// ��������� ������������ �� ������ �� ��������
/// \param arr ������
/// \param n ������ �������
/// \return ������, �� � ���� ���������� ������
bool checking_for_descending(const T* arr, unsigned n) {
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}

/// ���� ������� checking_for_increasing
void Test_checking_for_increasing() {

    double* c = new double[6] {1, 2, 3, 4, 5, 6};
    assert(checking_for_increasing(c, 6) == true);
    delete[] c;

    double* d = new double[6] {1, 6, 3, 5, 5, 6};
    assert(checking_for_increasing(d, 6) == false);
    delete[] d;

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

/// ���� ������� checking_for_descending
void Test_�hecking_for_descending() {

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



// ����������� ���������� ������� �������
auto t0 = steady_clock::now();

//������� ����, ����� ���������� �������� ����� ��������
//...

// ����������� ��������� ������� �������
auto t1 = steady_clock::now();

// �������������� ������� (������ �����������) � ������������
auto delta = duration_cast<milliseconds>(t1 - t0);


template <typename T>
/// ������� ��������� ������� � ������� ������� ����������������� ������
/// \param arr ������
/// \param n ������ �������
/// \param key �������, ������� ���������� �����
/// \return ������ ��������� key � arr; ���� ��� ���, �� -1
int Search(T* arr, unsigned n, T key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

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


template <typename T>
/// ������� ��������� ������� � ������� ������� ��������� ������
/// \param arr ������
/// \param n ������ �������
/// \param key �������, ������� ���������� �����
/// \return ������ ��������� key � arr; ���� ��� ���, �� -1
int Search_bin(T* arr, unsigned n, T key) {
    //Bubble_sort(arr, n);

    bool flag = false;
    int left = 0; // ����� �������
    int right = n - 1; // ������ �������
    int middle; //������ �������� �������

    while ((left <= right) && (flag != true)) {
        middle = (left + right) / 2; // ���������� ������ ��������
        if (arr[middle] == key) {
            flag = true; //��������� ���� �� ���������� ���������
            return middle;
        }
        //����� ����� ����� ����� ���������
        if (arr[middle] > key)
            right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}

void Test_Search_bin() {
    double* c = new double[3] {1, 2, 3};
    assert(Search_bin(c, 3, 1.0) == 0);
    delete[] c;

    int* a = new int[4] {1, 2, 3, 4};
    assert(Search_bin(a, 4, 3) == 2);
    delete[] a;


    char* n1 = new char[4] {'a', 'b', 'c', 'd'};
    assert(Search(n1, 4, 'd') == 3);
    delete[] n1;
}

template <typename T>
/// ����������� ���������� �� �����������
/// \param arr ������
/// \param n ������ �������
/// \return ������, �� ��������� �� ����������� arr
void Bubble_sort(T* arr, unsigned n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                T b = arr[j]; // ������������� ����������
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
}

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

///���� ���� ������� ������
void Test_function() {
    Test_Bubble_sort();
    Test_Search_bin();
    Test_Search();
    Test_�hecking_for_descending();
    Test_checking_for_increasing();
}