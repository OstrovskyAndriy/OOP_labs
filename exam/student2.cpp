#include "student2.h"

Student2::Student2()
{

}

Student2::Student2(QString fullName, QString group, int oop, int engl, int db, int gradebook, int age):Student(fullName,group,oop,engl,db){
    this->gradebook=gradebook;
    this->age=age;
}

void Student2::getData(QString &fullName, QString &group, int &oop, int &engl, int &db, int &gradebook, int &age)
{
    Student::getData(fullName,group,oop,engl,db);
    gradebook=this->gradebook;
    age=this->age;
}

void Student2::setData(QString &fullName, QString &group, int &oop, int &engl, int &db, int &gradebook, int &age)
{
    Student::setData(fullName,group,oop,engl,db);
    this->gradebook=gradebook;
    this->age=age;
}
