// lab_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <list>
#include <stdio.h>
#include <string.h>

#include"Plant.h"


using namespace std;


int menu() {
    int item;
    cout << "1 - Add new plant" << endl;
    cout << "2 - Get all plants" << endl;
    cout << "3 - Get info about some plant" << endl;
    cout << "4 - Change plant" << endl;
    cout << "0 - Exit" << endl;
    cin >> item;
    return item;

}


void cleanScreen() {
    system("cls");
}




int main(int argc, char* argv[])
{

    int menuChoice;
    int item;
    int i;

    list<Plant> list;

    Plant plant;

    while ((menuChoice = menu()) != 0) {
        cleanScreen();

        switch (menuChoice) {
        case 1:
            cin.ignore();

            plant.input();
            list.push_back(plant);

            cleanScreen();
            break;
        case 2:

            i = 1;

            cout << "Species \t height" << endl;
            for (auto it = list.begin(); it != list.end(); ++it) {

                cout << i << " - ";

                plant = *it;
                plant.print();
                ++i;
            }

            system("Pause");

            cleanScreen();
            break;
        case 3:

            i = 0;

            cout << "1 - " << list.size() << endl;
            cin >> item;

            cout << "Species \t height" << endl;
            for (auto it = list.begin(); it != list.end(); ++it) {
                plant = *it;
                if (i == item - 1) {
                    plant.print();
                    break;
                }
                ++i;
            }

            system("Pause");

            cleanScreen();
            break;
        case 4:
            i = 1;

            cout << "Species \t height" << endl;
            for (auto it = list.begin(); it != list.end(); ++it) {
                plant = *it;
                cout << i << " - ";
                plant.print();
                ++i;
            }

            cout << "Where change info " << endl;
            cin >> item;


            i = 0;


            for (auto it = list.begin(); it != list.end(); ++it) {
                plant = *it;
                if (i == item - 1) {
                    cout << "Enter new data" << endl;
                    cin.ignore();

                    plant.input();

                    *it = plant;

                    break;
                }
                ++i;
            }

            system("Pause");

            cleanScreen();

            break;
        }
    }

}