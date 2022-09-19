#include "Plant.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

Plant::Plant()
{
    species = nullptr;
    height = 0;
}

Plant::Plant(char* species, int height)
{
    this->height = height;

    if (this->species != nullptr) {
        delete[]this->species;
    }


    this->species = new char[strlen(species) + 1];
    this->species = _strdup(species);

}

Plant::Plant(const Plant& other)
{
    this->height = other.height;

    this->species = new char[strlen(other.species) + 1];

    this->species = _strdup(other.species);
}

Plant Plant::operator=(const Plant& other)
{
    this->height = other.height;


    if (this->species != nullptr) {         
        delete[]this->species;
        this->species = nullptr;
    }

    this->species = new char[strlen(other.species) + 1];

    this->species = _strdup(other.species);

    return *this;
}



void Plant::setSpecies(char* species)
{
    if (this->species != nullptr) {   
        delete[]this->species;
    }

    this->species = new char[strlen(species) + 1];

    this->species = _strdup(species);
}

char* Plant::getSpecies()
{
    return species;
}

void Plant::setHeight(int height)
{
    this->height = height;

}

int Plant::getHeight()
{
    return height;
}

void Plant::print() const
{
    cout << species << "         " << height << endl;

}

void Plant::input()
{
    cout << "Species: ";

    char* temp = new char[100];
    cin.getline(temp, 100, '\n');

    if (this->species != nullptr) {
        delete[]this->species;
    }

    this->species = new char[strlen(temp) + 1];

    this->species = _strdup(temp);

    delete[]temp;

    cout << "height: ";
    cin >> this->height;
}

Plant::~Plant()
{
    delete[]this->species;
}
