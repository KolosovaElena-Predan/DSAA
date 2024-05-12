#pragma once
#include <iostream>

///Находит префикс функцию для строки s
size_t* prefix_function(const char* s);

///Возвращет индекс первого вхождения подстроки obr в строке str
size_t find(const char* str, const char* obr);

void Test();