#include "student.h"

Student::Student()
{

}

Student::Student(QString fullName, QString group, int oop, int engl, int db)
{
    this->fullName=fullName;
    this->group=group;
    this->OOP=oop;
    this->English=engl;
    this->DB=db;
}

void Student::getData(QString &fullName, QString &group, int &oop, int &engl, int &db)
{
    fullName=this->fullName;
    group=this->group;
    oop=this->OOP;
    engl=this->English;
    db=this->DB;
}

void Student::setData(QString &fullName, QString &group, int &oop, int &engl, int &db)
{
    this->fullName = fullName;
    this->group=group;
    this->OOP=oop;
    this->English=engl;
    this->DB=db;
}


