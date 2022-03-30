#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Timer.h"
#include "Task3.h"

using namespace std;

//-------------------------------------------------------------------------------------------------
// Подсчитайте количество гласных букв в книге “Война и мир”.Для подсчета используйте 4
// способа:
//  ○ count_if и find
//  ○ count_if и цикл for
//  ○ цикл for и find
//  ○ 2 цикла for
// Замерьте время каждого способа подсчета и сделайте выводы
const vector<char> vowels{ 'A', 'E', 'I', 'O', 'U', 'Y' };

void count_if_and_find(const vector<char>& book)
{
    //count_if и find
    Timer timer("count_if and find");
    int vowelsCount = count_if(book.begin(), book.end(),
        [&](char ch)
        {
            ch = toupper(ch);
            if (find(vowels.begin(), vowels.end(), ch) != vowels.end())
                return true;
            else return false;
        });
    timer.print();
    cout << "Vowels number: " << vowelsCount << endl;
}

void count_if_and_for(const vector<char>& book)
{
    //count_if и цикл for
    Timer timer("count_if and for");
    int vowelsCount = count_if(book.begin(), book.end(),
        [&](char ch)
        {
            ch = toupper(ch);
            for (auto v : vowels)
            {
                if (ch == v)
                    return true;
            }
            return false;
        });
    timer.print();
    cout << "Vowels number: " << vowelsCount << endl;
}

void for_and_find(const vector<char>& book)
{
    Timer timer("for and find");
    int vowelsCount = 0;
    for (auto sym : book)
    {
        sym = toupper(sym);
        if (find(vowels.begin(), vowels.end(), sym) != vowels.end())
            ++vowelsCount;
    }
    timer.print();
    cout << "Vowels number: " << vowelsCount << endl;
}

void for_and_for(const vector<char>& book)
{
    //2 цикла for
    Timer timer("for and for");
    int vowelsCount = 0;
    for (auto sym : book)
    {
        sym = toupper(sym);
        for (auto v : vowels)
        {
            if (sym == v)
                ++vowelsCount;
        }
    }
    timer.print();
    cout << "Vowels number: " << vowelsCount << endl;
}

void task_3()
{
    cout << endl << "========== TASK 3 ==========" << endl << endl;
    ifstream f("warandpeace.txt");

    if (f)
    {
        cout << "Open success" << endl;
        char ch;
        vector<char> book;
        int cnt = 0;
        cout << "Reading...";
        while (!f.eof())
        {
            f.get(ch);
            book.push_back(ch);
            ++cnt;
        }
        cout << "Finished" << endl;
        cout << cnt << " bytes read" << endl;

        int vowelsCount = 0;
        cout << "Starting counting..." << endl;

        count_if_and_find(book);

        count_if_and_for(book);

        for_and_find(book);

        for_and_for(book);

        cout << "Finished" << endl;
    }
    else
    {
        cout << "Open error!" << endl;
    }
}

