#include "train.h"
#include <QString>
Train::Train()
{

}

Train::Train(QString destination,int trainNumber,QString departureTime,QString dateAndMonth){
    this->dateAndMonth=dateAndMonth;
    this->destination=destination;
    this->trainNumber=trainNumber;
    this->departureTime=departureTime;
}

QString Train::getInfo(){
    return (destination+'\t'+QString::number(this->trainNumber)+'\t'+departureTime+'\t'+dateAndMonth);
}
