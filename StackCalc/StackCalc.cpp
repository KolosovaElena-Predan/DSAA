#include <iostream>
#include <string>
#include <assert.h>
#include "PostfixСalculator.h"



int main()
{
	Test();
}
/*//стековый калькулятор с учётом приоритета знака
Stack <int> Calc;
Stack <char> O;
char m = ' ';
std::string s = "6*6+1";
std::string oper = "";
int n = s.size();
size_t i = 0;
while (i < s.size()){
	if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
		while (s[i] == '0'|| s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			oper = oper + s[i];
			i++;
		}
		Calc.Push(std::stoi(oper));
		oper = "";
	}

	if (s[i] == '+') {
		while (!O.isEmpty() && O.Peek() == '*') {
			mul(Calc);
			m = O.Pop();
		}
		while (!O.isEmpty() && O.Peek() == '/') {
			div(Calc);
			m = O.Pop();
		}
		O.Push('+');
	}

	if (s[i] == '-') {
		while (!O.isEmpty() && O.Peek() == '*') {
			mul(Calc);
			m = O.Pop();
		}
		while (!O.isEmpty() && O.Peek() == '/') {
			div(Calc);
			m = O.Pop();
		}
		O.Push('-');
	}

	if (s[i] == '*') {
		O.Push('*');
	}

	if (s[i] == '/') {
		O.Push('/');
	}
	i++;
}
while (!O.isEmpty()) {
	if (!O.isEmpty()&&O.Peek() == '+') {
		sum(Calc);
		m=O.Pop();
	}
	if (!O.isEmpty()&&O.Peek() == '-') {
		sub(Calc);
		m = O.Pop();
	}
	if (!O.isEmpty()&&O.Peek() == '*') {
		mul(Calc);
		m = O.Pop();
	}
	if (!O.isEmpty()&&O.Peek() == '/') {
		div(Calc);
		m = O.Pop();
	}
}
std::cout << Calc.Peek();*/


