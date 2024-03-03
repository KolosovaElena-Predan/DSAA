///Автор: Колосова Е.К. ВМК-22

//Напишите программу для поиска второго по величине элемента в списке из N значений. 
//Сколько сравнений делает Ваш алгоритм в наихудшем случае? Результаты тестирования вывести в текстовый файл.

//Кол-во сравнений в лучшем случае равно n - 1

//Кол-во сравнений в худшем случае равно 3(n-1), потому что каждый раз 
// выполняется ещё два сравнения ((arr[i] > max2) и (arr[i] != max)) по сравнению с лучшим случаем

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

template <typename T>
/// выводит массив в файл
/// \param arr массив
/// \param n размер массива
/// \param FileName файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
void arr_output_to_file(const T* arr, unsigned n, const std::string& FileName) {
    std::ofstream file;
    file.open(FileName, std::ios::app);
    if (file.is_open()) {
        for (unsigned i = 0; i < n; i++) {
            file << arr[i];
            if (i != n - 1)
                file << "; ";
        }
    }
    else
        throw std::invalid_argument("File not found");
    file.close();

}

template <typename T>
///Возвращает минимум в массиве arr из n элементов
T min(const T* arr, unsigned n) {
    T m = arr[0];
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] < m) {
            m = arr[i];
        }
    }
    return m;
}

template <typename T>
///Возвращает второй максимум в массиве arr из n элементов
T two_max(const T* arr, unsigned n) {
    T max = arr[0];
    T max2 = min(arr, n);
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max2 = max;
            max = arr[i];
        }
        else {
            if ((arr[i] > max2) && (arr[i] != max)) {
                max2 = arr[i];
            }
        }
    }
    return max2;
}

void Test_min(){

    double* arr = new double[3] {1, 3, 2};
    assert(min(arr, 3) == 1);
    delete[] arr;

    double* arr1 = new double[3] {3, 2, 1};
    assert(min(arr1, 3) == 1);
    delete[] arr1;

    double* arr2 = new double[3] {2, 1, 3};
    assert(min(arr2, 3) == 1);
    delete[] arr2;

    int* arr3 = new int[5] {10, 16, 7, 96, 15};
    assert(min(arr3, 5) == 7);
    delete[] arr3;

    char* arr4 = new char[7] {'c', 'n', 'j', 's', 'q', 'h', 'b'};
    assert(min(arr4, 7) == 'b');
    delete[] arr4;
}

void Test_two_max() {

    double* arr = new double[3] {1, 3, 2};
    assert(two_max(arr, 3) == 2);
    delete[] arr;

    double* arr1 = new double[3] {3, 2, 1};
    assert(two_max(arr1, 3) == 2);
    delete[] arr1;

    double* arr2 = new double[3] {2, 1, 3};
    assert(two_max(arr2, 3) == 2);
    delete[] arr2;

    int* arr3 = new int[5] {10, 16, 7, 96, 15};
    assert(two_max(arr3, 5) == 16);
    delete[] arr3;

    char* arr4 = new char[7] {'c', 'n', 'j', 's', 'q', 'h', 'b'};
    assert(two_max(arr4, 7) == 'q');
    delete[] arr4;
}


int main()
{
    Test_min();
    Test_two_max();
    int n = 10; //размер массива
    //double* arr = new double[n] {1, 2, 3};
    //double* arr = new double[n] {1, 3, 2};
    //double* arr = new double[n] {2, 1, 3};
    //double* arr = new double[n] {2, 3, 1}; 
    //double* arr = new double[n] {3, 1, 2}; 
    //double* arr = new double[n] {3, 2, 1}; 

    //double* arr = new double[n] {1, 2, 3, 4};
    //double* arr = new double[n] {1, 2, 4, 3}; 
    //double* arr = new double[n] {1, 3, 2, 4}; 
    //double* arr = new double[n] {1, 3, 4, 2};
    //double* arr = new double[n] {1, 4, 2, 3};
    //double* arr = new double[n] {1, 4, 3, 2};
    //double* arr = new double[n] {2, 1, 3, 4};
    //double* arr = new double[n] {2, 1, 4, 3};
    //double* arr = new double[n] {2, 3, 1, 4};
    //double* arr = new double[n] {2, 3, 4, 1};
    //double* arr = new double[n] {2, 4, 1, 3};
    //double* arr = new double[n] {2, 4, 3, 1};
    //double* arr = new double[n] {3, 1, 2, 4};
    //double* arr = new double[n] {3, 1, 4, 2};
    //double* arr = new double[n] {3, 2, 1, 4};
    //double* arr = new double[n] {3, 2, 4, 1};
    //double* arr = new double[n] {3, 4, 1, 2};
    //double* arr = new double[n] {3, 4, 2, 1};
    //double* arr = new double[n] {4, 1, 2, 3};
    //double* arr = new double[n] {4, 1, 3, 2};
    //double* arr = new double[n] {4, 2, 1, 3};
    //double* arr = new double[n] {4, 2, 3, 1};
    //double* arr = new double[n] {4, 3, 1, 2};
    double* arr = new double[n] {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    double max = arr[0]; //максимум
    double min1 = min(arr, n); //минимум
    int c = 0; //счётчик сравнений

    /*///нахождение минимума
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        c = c + 1;
    }*/

    double max2 = min1;

    //находим максимум и второе число после него и считаем сравнения
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max2 = max;
            max = arr[i];
            c = c + 1;
        }
        else {
            if ((arr[i] > max2) && (arr[i] != max)) {
                max2 = arr[i];
            }
            c = c + 3;
        }
    }

    std::ofstream file;
    file.open("2.txt", std::ios::app);
    file << std::endl<< std::endl<< "Кол-во сравнений: " << c << std::endl<< "Второй максимум: " <<max2<< std::endl << "Массив:";
    file.close();

    arr_output_to_file(arr, n, "2.txt");

    std::cout << max2;
}

