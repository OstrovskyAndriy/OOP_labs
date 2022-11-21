#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student
{
    QString fullName;
    QString group;
    int OOP;
    int English;
    int DB;
public:
    Student();

    Student(QString fullName,QString group,int oop,int engl,int db);

    virtual void getData(QString &fullName, QString &group,int &oop,int &engl,int &db);

    virtual void setData(QString &fullName, QString &group,int &oop,int &engl,int &db);

};

#endif // STUDENT_H
