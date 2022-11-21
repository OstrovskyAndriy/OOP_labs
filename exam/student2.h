#ifndef STUDENT2_H
#define STUDENT2_H

#include <QString>
#include "student.h"

class Student2:public Student
{
    int gradebook;
    int age;
public:
    Student2();

    Student2(QString fullName, QString group,int oop,int engl,int db,int gradebook, int age);

    void getData(QString &fullName, QString &group,int &oop,int &engl,int &db,int &gradebook, int &age);

    void setData(QString &fullName, QString &group,int &oop,int &engl,int &db,int &gradebook, int &age);

};

#endif // STUDENT2_H
