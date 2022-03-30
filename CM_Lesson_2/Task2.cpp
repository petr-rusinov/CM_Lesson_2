#include <iostream>
#include <vector>
#include "Task1.h"
#include "Task2.h"
using namespace std;


//-------------------------------------------------------------------------------------------------
// ���������� ��������� ������� SortPointers, ������� ��������� ������ ���������� �
// ��������� ��������� �� ���������, �� ������� ��� ���������.
//-------------------------------------------------------------------------------------------------

// SortPointers, ������� 1 �� ���� std::sort
template <class T> void SortPointers(vector<T*>& vec)
{

    sort(vec.begin(), vec.end(), [](T* a, T* b) { return (*a < *b); });
}

//SortPointers, ������� 2 �� ���� ������� Swap, ��������� �����
template <class T> void SortPointers2(vector<T*>& vec)
{
    bool isSwapped;
    do
    {
        isSwapped = false;
        typename vector<T*>::iterator it;
        for (it = vec.begin(); it < vec.end() - 1; ++it)
        {
            if (**(it + 1) < **it)
            {
                Swap<T>((*(it + 1)), *it);
                isSwapped = true;
            }
        }
    } while (isSwapped);
}


void task_2()
{
    cout << endl << "========== TASK 2 ==========" << endl << endl;

    vector<int*> vec;
    vector<int*>::iterator it;

    srand(3);
    for (int i = 0; i < 10; ++i)
    {
        int* num = new int;
        *num = rand() % 100;
        vec.push_back(num);
    }
    for (auto v : vec)
    {
        cout << v << "\t" << *v << endl;
    }
    SortPointers2<int>(vec);
    cout << endl << "Sorted: " << endl;

    for (auto v : vec)
    {
        cout << v << "\t" << *v << endl;
    }
}