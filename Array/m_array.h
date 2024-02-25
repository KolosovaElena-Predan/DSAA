//����� �������� �.�.
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
void array_fill_randomly(T* arr, unsigned n, T min, T max);

template <typename T>
/// ������� ������ � ����
/// \param arr ������
/// \param n ������ �������
/// \param FileName ����, ���� ��������� ������
/// \return ������, �� � ���� ���������� ������
void output_to_file(const T* arr, unsigned n, const std::string& FileName);

template <typename T>
/// ��������� ������������ �� ������ �� �����������
/// \param arr ������
/// \param n ������ �������
/// \return ������, �� � ���� ���������� ������
bool checking_for_increasing(const T* arr, unsigned n);

template <typename T>
/// ��������� ������������ �� ������ �� ��������
/// \param arr ������
/// \param n ������ �������
/// \return ������, �� � ���� ���������� ������
bool checking_for_descending(const T* arr, unsigned n);

/// ���� ������� checking_for_increasing
void Test_checking_for_increasing();

/// ���� ������� checking_for_descending
void Test_�hecking_for_descending();


template <typename T>
/// ������� ��������� ������� � ������� ������� ����������������� ������
/// \param arr ������
/// \param n ������ �������
/// \param key �������, ������� ���������� �����
/// \return ������ ��������� key � arr; ���� ��� ���, �� -1
int Search(T* arr, unsigned n, T key);


/// ��������� ������� Search
void Test_Search();


template <typename T>
/// ������� ��������� ������� � ������� ������� ��������� ������
/// \param arr ������
/// \param n ������ �������
/// \param key �������, ������� ���������� �����
/// \return ������ ��������� key � arr; ���� ��� ���, �� -1
int Search_bin(T* arr, unsigned n, T key);

/// ��������� ������� Search_bin 
void Test_Search_bin();

template <typename T>
/// ����������� ���������� �� �����������
/// \param arr ������
/// \param n ������ �������
/// \return ������, �� ��������� �� ����������� arr
void Bubble_sort(T* arr, unsigned n);


/// ��������� ������� Bubble_sort
void Test_Bubble_sort();


///���� ���� ������� ������
void Test_function();