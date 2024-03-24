//����� �������� �.�.
#include <iostream>
#include <vector>
#include <cassert>

//��� ����������� ������������� ���������� ���������� ������ ���� ����� � ����� �������(��� A)
//� ���������(��� B).��� �� �������� ������������ ���������� ����������.
//����� ��������� ������� � ����������, ��������� ������������ ������������ �������.
//������ ��������� �������������, ���� � ��� ������ ���� ����� ���� ����������� ���� A.
//��� ��������� ���������� ����������� N ���������� ����� ���������� ������.
//������ ������� ������ ���� ����� 0 < N < 31. 
//������ �������� ������ ���� ����� � ���������� ���������� ��������� ������������ ������.

//https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/tasks/task_s1_dynamic_programming.md

/// ������� ���-�� ���������� ��������� ������������ ������
/// \param n ���-�� ����������� � ������
/// \param mem ������ ���������� ���������
/// \return ���-�� ���������� ��������� ������������ ������
size_t Explosiveness(size_t n, std::vector<long long>& mem) { //������������ ����������(��� ����������� ������-����)
    if (mem[n] != 0) return mem[n];

    if (n == 0) {
        mem[0] = 1;
        return mem[n];
    }
    if (n == 1) {
        mem[1] = 2;
        return mem[n];
    }
    if (n == 2) {
        mem[2] = 4;
        return mem[n];
    }
    
    else {
        mem[n] = Explosiveness(n - 1, mem) + Explosiveness(n - 2, mem) + Explosiveness(n - 3, mem);
        return mem[n];
    }
}

///���� ������� Explosiveness
void Test_Explosiveness() {
    size_t n = 5;
    std::vector<long long> mem(n + 2, 0);
    assert(Explosiveness(n, mem) == 24);

    size_t n1 = 1;
    std::vector<long long> mem1(n1 + 2, 0);
    assert(Explosiveness(n1, mem1) == 2);

    size_t n2 = 30;
    std::vector<long long> mem2(n2 + 2, 0);
    assert(Explosiveness(n2, mem2) == 98950096);


}