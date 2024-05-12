#include "KMP.h"
#include <assert.h>
#include <chrono>

using namespace std::chrono;

///������� ������� ������� ��� ������ s
size_t* prefix_function(const char* s)
{
	size_t* pi = new size_t[strlen(s)];
	pi[0] = 0;
	for (size_t i = 1; i < strlen(s); i++)
	{
		size_t j = pi[i - 1];
		while ((j > 0) && (s[i] != s[j]))
			j = pi[j - 1];
		if (s[i] == s[j])
			++j;
		pi[i] = j;
	}
	return pi;
}

///��������� ������ ������� ��������� ��������� obr � ������ str
size_t find(const char* str, const char* obr)
{
	size_t* pi = prefix_function(obr);
	size_t l = strlen(obr);    // ����� ������, ������� ����
	size_t j = 0; // ���������� ��������� ��������, ��� �� ������ ������������� 
	for (size_t i = 0; str[i]; ++i)
	{
		while ((j > 0) && (str[i] != obr[j]))
			j = pi[j - 1];

		if (str[i] == obr[j]) // ���� ���������� ���������� �������  ����������� ����� ���������� ��������� �� 1
			++j;
		if (j == l)
			return (i - l + 1);
	}
	return -1;
}

void Test(){
assert(find("abcdabl", "abc") == 0);
assert(find("abcdabl", "abl") == 4);
assert(find("abcdabl", "abab") == -1);
assert(find("abcdabl", "abcdablm") == -1);
assert(find("abcdabl", "") == -1); }