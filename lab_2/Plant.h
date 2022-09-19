#pragma once
class Plant
{
    char *species;
    int height;

public:
    Plant();
      

    Plant(char* species, int height);

    Plant(const Plant& other);

    Plant operator =(const Plant& other);

    void setSpecies(char* species);

    char* getSpecies();

    void setHeight(int height);

    int getHeight();

    void print() const;

    void input();

    ~Plant();
};

