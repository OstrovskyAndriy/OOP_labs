// lab_11.cpp : 

#include <iostream>
#include <vector>
#include <list>
#include <conio.h>
#include <algorithm>

using namespace std;



int main()
{
    setlocale(LC_ALL, "");
    vector<wchar_t>ABC;
    list<wchar_t>surname;
    wchar_t symbol = '\0';

    /*for (int i = 0; i < 32; i++) {
        ABC.push_back(L'À' + i);
    }*/

    for (int i = 97; i < 123; i++)
    {
        ABC.push_back(i);
    }

    for (const auto it : ABC) {
        wcout << it << " ";
    }cout << endl;


    cout << "enter surname: ";
    while (!_kbhit()) {
        symbol = _getch();
        wcout << symbol;

        if (symbol == '\r') {
            break;
        }

        else if (find(ABC.begin(), ABC.end(), symbol) != ABC.end()) {
            surname.push_back(symbol);
        }

    }

    cout << endl;

    for (const auto it : surname) {
        wcout << it;
    }

    cout << "\nSort surname: " << endl;
    surname.sort();

    for (const auto it : surname) {
        wcout << it;
    }
}
