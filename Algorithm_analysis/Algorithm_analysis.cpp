///Автор: Колосова Е.К. ВМК-22

//Напишите программу для поиска второго по величине элемента в списке из N значений. 
//Сколько сравнений делает Ваш алгоритм в наихудшем случае? Результаты тестирования вывести в текстовый файл.


#include <iostream>
#include <fstream>
#include <string> 

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




int main()
{
    int n = 3;
    double* arr = new double[n] {1, 2, 3};
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
    //double* arr = new double[n] {4, 3, 2, 1};


    double max = arr[0]; //максимум
    double min = arr[0]; //минимум
    int c = 0; //счётчик сравнений

    ///нахождение минимума
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        c = c + 1;
    }

    double max2 = min;

    //находим максимум и второе число после него
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
            c = c + 2;
        }
    }

    std::ofstream file;
    file.open("2.txt", std::ios::app);
    file << std::endl<< std::endl<< "Кол-во сравнений: " << c << std::endl<< "Массив:";
    file.close();

    arr_output_to_file(arr, n, "2.txt");

    std::cout << max2;
}

