#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include "Student.h"

using namespace std;

const int SIZE = 50;

class Faculty
{
	class Group
	{

		string groupName;
		string speciality;
		Student* students[SIZE];
		int countOfStudents = 0;

	public:
		friend ostream& operator<<(ostream& stream, const Group& forOutput);
		Group()
		{
			cout << "enter group name: ";
			getline(cin, groupName);
			cout << "enter group speciality: ";
			getline(cin, speciality);

		}
		Group(string groupName, string speciality) {
			this->groupName = groupName;
			this->speciality = speciality;
		}

		void addStudent() {
			students[this->countOfStudents] = new Student;
			countOfStudents++;
		}

		void showListOfStudents() {
			for (int i = 0; i < countOfStudents; i++)
			{
				cout << *students[i];
			}
			cout << endl;
		}

		~Group() {
			for (int i = 0; i < countOfStudents; i++)
			{
				delete students[i];
			}
		}
	};

	string facultyName;
	int countOfGrous = 0;

	Group* groups[SIZE];

	bool addStudent();

public:
	friend ostream& operator<<(ostream& stream, const Faculty& forOutput);
	friend ostream& operator<<(ostream& stream, const Faculty::Group& forOutput);
	Faculty();

	Faculty(string facultyName);


	void addGroup();

	void showAllGroups();

	~Faculty();
};


