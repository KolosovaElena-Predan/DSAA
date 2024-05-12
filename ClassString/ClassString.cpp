#include <iostream>
#include "String.h"
#include <chrono>
#include <string>
#include <fstream> // подключаем файлы
using namespace std::chrono;

char* randomstr(size_t n) {
    char symbols[63] = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* a = new char[n];
    for (size_t i = 0; i < n; i++) {
        int random = rand() % (63);
        a[i] = symbols[random];
    }
    return a;
}

char* random_ATCG(size_t n) {
    char symbols[5] = "ATCG";
    char* a = new char[n];
    for (size_t i = 0; i < n; i++) {
        int random = rand() % (5);
        a[i] = symbols[random];
    }
    return a;
}
int main()
{
    Test_String();
    /*Случайная последовательность Время:1143*/
    /*char* a = randomstr(1005000);
    size_t m = 0;
    for (size_t i = 0; i < 100000; i++) {
        char* n = randomstr(1000);
        // определение начального момента времени
        auto t0 = steady_clock::now();

        //участок кода, время выполнения которого нужно измерить
        find(a, n);

        // определение конечного момента времени
        auto t1 = steady_clock::now();

        // преобразование времени (обычно наносекунды) в миллисекунды
        auto delta = duration_cast<nanoseconds>(t1 - t0);

        m = m + delta.count();
    }
    std::cout <<"sr:" << m / 100000;*/

    /*В естественном тексте поиск слов Время:8097*/
    /*std::string s;
    std::string a;
    std::fstream file;
    file.open("1.txt");
    if (file.is_open()) {
        while (std::getline(file, s)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
            a = a + s;
        }
    }
    file.close(); // обязательно закрываем файл что бы не повредить его
    char* a1 = new char[1005000];
    for (size_t i = 0; i < a.length();i++) {
        a1[i] = a[i];
    }
 
    const char* word[500] = { "the", "be", "to", "of", "and", "a", "in", "that", "have", "I",
"it", "for", "not", "on", "with", "he", "as", "you", "do", "at",
"this", "but", "his", "by", "from", "they", "we", "say", "her",
"she", "or", "an", "will", "my", "one", "all", "would", "there",
"their", "what", "so", "up", "out", "if", "about", "who", "get",
"which", "go", "me", "when", "make", "can", "like", "time", "no",
"just", "him", "know", "take", "people", "into", "year", "your",
"good", "some", "could", "them", "see", "other", "than", "then",
"now", "look", "only", "come", "its", "over", "think", "also",
"back", "after", "use", "two", "how", "our", "work", "first",
"well", "way", "even", "new", "want", "because", "any", "these",
"give", "day", "most", "us", "must", "those", "great", "where",
"through", "much", "go", "call", "before", "such", "over", "most",
"may", "should", "down", "while", "before", "though", "through",
"long", "where", "much", "how", "off", "well", "before", "same",
"back", "good", "man", "here", "without", "many", "between", "must",
"high", "own", "right", "end", "old", "big", "never", "real",
"life", "few", "only", "things", "right", "every", "any", "own",
"though", "small", "still", "know", "years", "however", "system",
"program", "set", "best", "shall", "put", "home", "does", "need",
"must", "become", "set", "much", "own", "changing", "better",
"leave", "large", "found", "closer", "new", "power", "same",
"size", "formerly", "work", "wants", "find", "always", "night",
"until", "uct", "school", "city", "played", "husband", "eve",
"children", "becomes", "among", "play", "tonight", "does",
"almost", "results", "least", "church", "possible", "particularly",
"ly", "without", "action", "learning", "children", "manufactured" };


    size_t m = 0;
    for (size_t i = 0; i < 10000; i++) {
        int random = rand() % (211);
        const char* b = word[random];
        char* b1=new char[strlen(b)+1];
        for (size_t i = 0; i < strlen(b); i++) {
            b1[i] = b[i];
        }
        b1[strlen(b)] = '\0';
        // определение начального момента времени
        auto t0 = steady_clock::now();

        //участок кода, время выполнения которого нужно измерить
        find(a1, b1);

        // определение конечного момента времени
        auto t1 = steady_clock::now();

        // преобразование времени (обычно наносекунды) в миллисекунды
        auto delta = duration_cast<nanoseconds>(t1 - t0);
        //std::cout << delta.count()<<"\n";
        m = m + delta.count();
    }
    std::cout << "sr:" << m / 100000;*/


    /*Случайная последовательность ATGC ищем строки длины 3 Время: 180*/
    /*char* a = random_ATCG(1005000);
    size_t m = 0;
    for (size_t i = 0; i < 100000; i++) {
        char* n = random_ATCG(3);
        // определение начального момента времени
        auto t0 = steady_clock::now();

        //участок кода, время выполнения которого нужно измерить
        find(a, n);

        // определение конечного момента времени
        auto t1 = steady_clock::now();

        // преобразование времени (обычно наносекунды) в миллисекунды
        auto delta = duration_cast<nanoseconds>(t1 - t0);

        m = m + delta.count();
    }
    std::cout <<"sr:" << m / 100000;*/
  

}
