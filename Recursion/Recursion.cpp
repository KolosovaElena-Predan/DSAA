///Автор: Колосова Е.К.
//11. Написать функцию C(m,n) вычисления биномиальных коэффициентов.

#include <iostream>
#include <assert.h>

///Вычисляет биномиальный коэффициент
/// \param m кол-во выбираемых объектов
/// \param n кол-во объектов всего
/// \return биномиальный коэффициент C(m, n)
long long C(long long m, long long n) {
    if (m <= n) {
        if (m == 0 || m == n)
            return 1;
        else
            return C(m, n - 1) + C(m - 1, n - 1);
    }
    else 
        throw std::invalid_argument("Invalid argument m");
}

void Test_C() {
    assert(C(2, 4) == 6);
    assert(C(4, 30) == 27405);
    assert(C(1, 25) == 25);
}

int main()
{
    Test_C();
    try {
        std::cout << C(2, 4);
    }
    catch (const std::invalid_argument& error) {
        std::cout << error.what();
    }
}

