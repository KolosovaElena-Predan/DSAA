#include <cassert>
#include "String.h"

	///����������� c ���������� s - ������ ��������, �������� �� ��������� nullptr
	String::String(const char* s) {
		if (s != nullptr) {
			char* s1 = new char[strlen(s)];
			memcpy(s1, s, sizeof(char) * strlen(s));
			str = s1;
			size = strlen(s);
		}
		else {
			size = 0;
			str = nullptr;
		}
	}

	///����������� �����������
	String::String(const String& p)
	{
		char* s = new char[p.lenght() + 1];
		memcpy(s, p.str, sizeof(char) * (p.lenght() + 1));
		str = s;
		size = p.lenght();
	}

	///����������
	String::~String() {
		Clear();
	}

	///��������������� ��������� [] ��� ��������� � �������� � �������� n
	char& String::operator[] (size_t n) const {
		if (n <= size) {
			return str[n];
		}
		else throw std::invalid_argument("Invalid index value");

	}

	///���������� ������ ������
	size_t String::lenght() const {
		return size;
	}

	///��������������� ��������� ������������
	String& String::operator= (const char* s) {
		size_t m = strlen(s);
		str = new char[m + 1];
		for (int i = 0; i <= m; i++) {
			str[i] = s[i];
		}
		//memcpy(str, s, sizeof(char)*m);
		size = m;
		return *this;
	}

	///��������������� ��������� ������������
	String& String::operator= (const String& s) {
		size_t m = strlen(s.str);
		str = new char[m + 1];
		for (int i = 0; i <= m; i++) {
			str[i] = s[i];
		}
		//memcpy(str, s, sizeof(char)*m);
		size = m;
		return *this;
	}

	///���� ������ ������, �� ���������� true, ����� false
	bool String::isEmpty() const {
		if (size == 0)
			return true;
		else return false;
	}

	///������� ������
	void String::Clear() {
		size = 0;
		if (str != nullptr)
			delete[] str;
		str = nullptr;
	}

	///�������� ��������� ��������� ������ � ������� �������� s. ���� ��� �����, �� ���������� true, ����� false
	bool String::operator== (const char* s) const {
		/*if (strcmp(str, s) == 0) {
			return true;
		}
		else return false;*/
		size_t i = 0;

		if (s == nullptr && str == nullptr) return true;
		else if (s != nullptr) {
			if (strlen(s) == size) {
				while (i < size) {
					if (s[i] != str[i]) {
						return false;
					}
					i++;
				}
				return true;
			}
			else return false;
		}
	}

	///�������� ��������� ��������� ������ � ������ s. ���� ��� �����, �� ���������� true, ����� false
	bool String::operator== (String& s) const {
		/*if (strcmp(str, s) == 0) {
			return true;
		}
		else return false;*/
		size_t i = 0;

		if (s == nullptr && str == nullptr) return true;
		else if (s.str != nullptr) {
			if (s.lenght() == size) {
				while (i < size) {
					if (s[i] != str[i]) {
						return false;
					}
					i++;
				}
				return true;
			}
			else return false;
		}
	}



	///�������� ��������� ������ ������ � ������� �������� s. ���� ������ ������ s, �� ���������� true, ����� false
	bool String::operator< (char* s) const {
		/*if (strcmp(str, s) < 0) {
			return true;
		}
		else return false;*/

		size_t i = 0;
		while (s[i] != '\0' || str[i] != '\0') {
			if (s[i] == str[i])
				i++;
			else if (str[i] < s[i]) return true;
			else if (str[i] > s[i]) return false;
		}
		if (strlen(s) != 0 && strlen(str) == 0) return true;
		else return false;
	}

	///�������� ��������� ������ ������ � ������� �������� s. ���� ������ ������ s, �� ���������� true, ����� false
	bool String::operator> (char* s) const {
		/*if (strcmp(str, s) > 0) {
			return true;
		}
		else return false;*/

		size_t i = 0;
		while (s[i] != '\0' || str[i] != '\0') {
			if (s[i] == str[i])
				i++;
			else if (str[i] > s[i]) return true;
			else if (str[i] < s[i]) return false;
		}
		if (strlen(s) == 0 && strlen(str) != 0) return true;
		else return false;
	}


	String String::operator+ (const String& s) const{
		String a(s);
		if (s.str == nullptr)
			a.str = s.str;
		else {
			size_t n = s.lenght();
			char* s1 = new char[size + n + 1];
			memcpy(s1, str, sizeof(char) * (size));
			memcpy(s1 + sizeof(char) * (size), s.str, sizeof(char) * (n + 1));
			a.str = s1;
			a.size = size + n;
		}
		return a;

	}

	String String::operator+ (char* s) const{
		String a(s);
		if (s == nullptr)
			a.str = s;
		else {
			size_t n = strlen(s);
			char* s1 = new char[size + n + 1];
			memcpy(s1, str, sizeof(char) * (size));
			memcpy(s1 + sizeof(char) * (size), s, sizeof(char) * (n + 1));
			a.str = s1;
			a.size = size + n;
		}
		return a;
	}

	///��������� ������ ��������� ��������� obr
	size_t String::sfind(const char* obr) const
	{
		return find(str, obr);
	}

	///��������� ������ ��������� ��������� obr
	size_t String::sfind(String& obr) const
	{
		return find(str, obr.str);
	}


void Test_String() {

	String a; //��������
	assert(a.lenght()==0); //���������, ��� ������ �����
	assert(a.isEmpty() == true);
	char* v{ new char[8] { 'a', 'b', 'c', 'd', 'a', 'b', 'l', '\0' } }; 
	a = v; //��������� ������ ��������
	assert(a.lenght() == 7); //��������� ����� ������ 
	assert(a.isEmpty() == false);

	//��������� ����������� ��������
	assert(a[0] == 'a');
	assert(a[1] == 'b');
	assert(a[2] == 'c');
	assert(a[3] == 'd');
	assert(a[4] == 'a');
	assert(a[5] == 'b');
	assert(a[6] == 'l');

	//��������
	a.Clear();

	//���������, ��� �������
	assert(a.lenght() == 0);
	assert(a.isEmpty() == true);

	//�������� ������������
	String b;
	a = v;
	b = a;
	assert(b==v);

	//��������� ����������� ��������
	assert(b[0] == 'a');
	assert(b[1] == 'b');
	assert(b[2] == 'c');
	assert(b[3] == 'd');
	assert(b[4] == 'a');
	assert(b[5] == 'b');
	assert(b[6] == 'l');


	char* v1{ new char[8] { 'a', 'b', 'c', 'd', 'a', 'b', 'j', '\0' } };
	char* v2{ new char[4] { 'a', 'b', 'c', '\0' } };
	char* v3{ new char[8] { 'b', 'b', 'c', 'd', 'a', 'b', 'l', '\0' } };
	char* v4{ new char[8] { 'a', 'b', 'm', 'd', 'a', 'b', 'l', '\0' } };
	char* v5{ new char[5] { 'b', 'b', 'c', 'd', '\0' } };
	char* v6{ new char[5] { 'b', 'b', 'c', 'd', '\0' } };
	char* v7{ new char[4] { 'a', 'b', 'l', '\0' } };
	char* v8{ new char[9] { 'a', 'b', 'm', 'd', 'a', 'b', 'l', 'm', '\0' } };
	char v9[] = "abcdablabc";

	//�������� �������� ��������� �����
	assert(a == v);
	assert(!(a == v1));
	assert(!(a == v1));
	assert(!(a == v1));

	//�������� �������� ��������� ������ � ������
	assert(a > v2);
	assert(a > v1);
	assert(a < v3);
	assert(a < v5);
	assert(!(a < v1));

	//�������� ������ � ������
	assert(a.sfind(v2) == 0);
	assert(a.sfind(v7) == 4);
	assert(a.sfind(v6) == -1);
	assert(a.sfind(v8) == -1);
	assert(a.sfind(v9) == -1);
	assert(a.sfind(b) == 0);


	//�������� ������������
	String c = a + v2;

	assert(a == v);

	assert(c == v9);

	c.Clear();
	b = v2;
	c = a + b;
	assert(a == v);
	assert(b == v2);
	assert(c == v9);


	delete[] v;
	delete[] v1;
	delete[] v2;
	delete[] v3;
	delete[] v4;
	delete[] v5;
	delete[] v6;
	delete[] v7;
	delete[] v8;

	



}