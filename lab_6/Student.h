#pragma once
#include <iostream>
#include <string>
#include <ostream>

using namespace std;



class Student
{
	enum StType {
		PAYER = 0,
		STATE = 1
	};

	string fatherName;
	string name;
	string surname;
	bool studyTypeBool;
	string studyTypeStr;
	int gradebook;


	StType stType;
	string getType(StType& stType);

public:
	friend ostream& operator<<(ostream& stream, const Student& forOutput);
	Student();
	Student(string fatherName, string name, string surname,bool studyTupe, int gradebook);

};

