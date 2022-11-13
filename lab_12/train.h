#ifndef TRAIN_H
#define TRAIN_H

#include<iostream>
#include<string>
#include <QString>

using namespace std;

class Train
{
    QString destination;
    int trainNumber;
    QString departureTime;
    QString dateAndMonth;
public:
    Train();
    Train(QString destination,int trainNumber,QString departureTime,QString dateAndMonth);

    QString getInfo();
};

#endif // TRAIN_H
