#include <iostream>
#include "rectagle.h"
using namespace std;

int main(int argc, char* argv[])
{
    Rectagle first(12, 20);
    Rectagle second(13, 7);

    cout << "first > second " << (first > second) << endl;

    cout << "first < second " << (first < second) << endl;

    cout << "first == second " << (first == second) << endl;
}