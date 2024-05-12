#pragma once
#include <iostream>
#include "KMP.h"
class String
{
	//поля: 
	private:
		
		char* str; //массив из символов
		size_t size; //размер массива

	//методы:
	public:


		///Конструктор c параметром s - массив символом, значение по умолчанию nullptr
		String(const char* s = nullptr);

		///Конструктор копирования
		String(const String& p);

		///Деструктор
		~String();

		///Переопределение оператора [] для обращения к элементу с индексом n
		char& operator[] (size_t n) const;

		///Возвращает размер строки
		size_t lenght() const;

		///Переопределение опреатора присваивание
		String& operator= (const char* s);

		///Переопределение опреатора присваивание
		String& operator= (const String& s);

		///Если строка пустая, то возвращает true, иначе false
		bool isEmpty() const;

		///Очищает строку
		void Clear();

		///Оператор сравнения равенство строки и массива символов s. Если они равны, то возвращает true, иначе false
		bool operator== (const char* s) const;

		///Оператор сравнения равенство строки и строки s. Если они равны, то возвращает true, иначе false
		bool operator== (String& s) const;


		///Оператор сравнения меньше строки и массива символов s. Если строка меньше s, то возвращает true, иначе false
		bool operator< (char* s) const;

		///Оператор сравнения больше строки и массива символов s. Если строка больше s, то возвращает true, иначе false
		bool operator> (char* s) const;


		String operator+ (const String& s) const;
		

		String operator+ (char* s) const;

	
		///Возвращет первое вхождение подстроки obr
		size_t sfind(const char* obr) const;

		///Возвращет первое вхождение подстроки obr
		size_t sfind(String& obr) const;


};

void Test_String();

