#include "Rectagle.h"
#include <iostream>

using namespace std;

Rectagle::Rectagle(){
    height = 0;
    width = 0;
    S = 0;
}

Rectagle::Rectagle(int height, int width) {
    this->height = height;
    this->width = width;
    S = height * width;
}

bool Rectagle::operator==(Rectagle& other) {
    return (this->S == other.S);
}

bool Rectagle:: operator>(Rectagle& other) {
    return (this->S > other.S);
}

bool Rectagle:: operator<(Rectagle& other) {
    return (this->S < other.S);
}

void Rectagle::printInfo() {
    cout << "height = " << height << "width = " << width << " S = " << S << endl;
}


