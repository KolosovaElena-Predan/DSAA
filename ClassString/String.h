#pragma once
#include <iostream>
#include "KMP.h"
class String
{
	//����: 
	private:
		
		char* str; //������ �� ��������
		size_t size; //������ �������

	//������:
	public:


		///����������� c ���������� s - ������ ��������, �������� �� ��������� nullptr
		String(const char* s = nullptr);

		///����������� �����������
		String(const String& p);

		///����������
		~String();

		///��������������� ��������� [] ��� ��������� � �������� � �������� n
		char& operator[] (size_t n) const;

		///���������� ������ ������
		size_t lenght() const;

		///��������������� ��������� ������������
		String& operator= (const char* s);

		///��������������� ��������� ������������
		String& operator= (const String& s);

		///���� ������ ������, �� ���������� true, ����� false
		bool isEmpty() const;

		///������� ������
		void Clear();

		///�������� ��������� ��������� ������ � ������� �������� s. ���� ��� �����, �� ���������� true, ����� false
		bool operator== (const char* s) const;

		///�������� ��������� ��������� ������ � ������ s. ���� ��� �����, �� ���������� true, ����� false
		bool operator== (String& s) const;


		///�������� ��������� ������ ������ � ������� �������� s. ���� ������ ������ s, �� ���������� true, ����� false
		bool operator< (char* s) const;

		///�������� ��������� ������ ������ � ������� �������� s. ���� ������ ������ s, �� ���������� true, ����� false
		bool operator> (char* s) const;


		String operator+ (const String& s) const;
		

		String operator+ (char* s) const;

	
		///��������� ������ ��������� ��������� obr
		size_t sfind(const char* obr) const;

		///��������� ������ ��������� ��������� obr
		size_t sfind(String& obr) const;


};

void Test_String();

