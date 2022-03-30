// CM_Lesson_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
//-------------------------------------------------------------------------------------------------
// Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает
// местами значения, на которые указывают эти указатели(нужно обменивать именно сами
//     указатели, переменные должны оставаться в тех же адресах памяти).
//-------------------------------------------------------------------------------------------------

template <class T>  void Swap(T*& p1, T*& p2)
{
    T* temp = p1;
    p1 = p2;
    p2 = temp;
}

void task_1()
{
    int* i1, * i2;

    i1 = new int{ 10 };
    i2 = new int{ 20 };

    cout << *i1 << " " << *i2 << endl;
    cout << hex << i1 << " " << i2 << endl;

    Swap<int>(i1, i2);
    cout << hex << i1 << " " << i2 << endl;
    cout << dec << *i1 << " " << *i2 << endl;

}

//-------------------------------------------------------------------------------------------------
// Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и
// сортирует указатели по значениям, на которые они указывают.
//-------------------------------------------------------------------------------------------------


template <class T> void SortPointers(vector<T*>& vec)
{

    sort(vec.begin(), vec.end(), [](T* a, T* b) { return (*a < *b); });
}

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
        cout << v <<"\t" << *v << endl;
    }
    SortPointers2<int>(vec);
    cout << endl << "Sorted: " << endl;

    for (auto v : vec)
    {
        cout << v << "\t" << *v << endl;
    }

}



//-------------------------------------------------------------------------------------------------
// Подсчитайте количество гласных букв в книге “Война и мир”.Для подсчета используйте 4
// способа:
//  ○ count_if и find
//  ○ count_if и цикл for
//  ○ цикл for и find
//  ○ 2 цикла for
// Замерьте время каждого способа подсчета и сделайте выводы
void task_3()
{
    ifstream f("warandpeace.txt");
    vector<char> vowels{ 'A', 'E', 'I', 'O', 'U', 'Y' };
    //string vowels = "aeiouy";

    if (f)
    {
        cout << "open success" << endl;
        char ch;
        vector<char> book;
        int cnt = 0;
        while (!f.eof())
        {
            f.get(ch);
            book.push_back(ch);
            ++cnt;
        }

        cout << "read finished" << endl;
        cout << cnt << " bytes read" << endl;
        
        int vowelsCount = 0;
        cout << "Starting count_if()...";
        //count_if и find
        //vowelsCount = count_if(book.begin(), book.end(), [&](char ch)
        //    {
        //        ch = toupper(ch);
        //        if (find(vowels.begin(), vowels.end(), ch) != vowels.end()) 
        //            return true;
        //        else return false;
        //    });
        //count_if и цикл for
        //vowelsCount = count_if(book.begin(), book.end(), [&](char ch)
        //    {
        //        ch = toupper(ch);
        //        for (auto v : vowels)
        //        {
        //            if (ch == v)
        //                return true;
        //        }
        //        return false;
        //    });




        //цикл for и find
        vowelsCount = 0;
        for (auto sym : book)
        {
            sym = toupper(sym);
            if (find(vowels.begin(), vowels.end(), ch) != vowels.end())
                ++vowelsCount;
        }


        //2 цикла for
        //vowelsCount = 0;
        //for (auto sym : book)
        //{
        //    sym = toupper(sym);
        //    for (auto v : vowels)
        //    {
        //        if (sym == v)
        //            ++vowelsCount;
        //    }
        //}

        /*
        vowelsCount = count_if(book.begin(), book.end(), [](char ch) 
                                                                {
                                                                    ch = toupper(ch);
                                                                    if (ch == 'A' || 
                                                                        ch == 'E' || 
                                                                        ch == 'I' || 
                                                                        ch == 'O' || 
                                                                        ch == 'U' || 
                                                                        ch == 'Y') return true;
                                                                    else return false; 
                                                                });*/

        cout << " Finished" << endl;
        cout << "Vowels number: " << vowelsCount << endl;


    }
    else
    {
        cout << "open error!" << endl;
    }
}
//-------------------------------------------------------------------------------------------------

int main()
{
    std::cout << "Hello World!\n";

    //task_1();
    task_2();
    //task_3();
}
