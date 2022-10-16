#include "Faculty.h"

bool Faculty::addStudent()
{
	int item;
	cout << "add student to group (1-yes 2-no): ";
	cin >> item;

	if (item == 1) return true;

	else return false;
}

Faculty::Faculty()
{
	cout << "enter faculty name: ";
	getline(cin, this->facultyName);
	cout << endl;
}

Faculty::Faculty(string facultyName)
{
	this->facultyName = facultyName;
	/*this->groupName = groupName;
	this->speciality = speciality;*/
}

void Faculty::addGroup()
{
	int menuChoice;
	this->groups[this->countOfGrous] = new Group;

	//cout << "add student to group (1-yes 2-no): ";
	
	while ((menuChoice = addStudent())!=false)
	{
		cin.ignore();

		this->groups[this->countOfGrous]->addStudent();	
	}
	cin.ignore();

	countOfGrous++;

	
	/*students[this->countOfGrous] = new Student;
	countOfGrous++;*/
}

void Faculty::showAllGroups()
{
	for (int i = 0; i < countOfGrous; i++)
	{
		cout << *groups[i];
	}
	/*for (int i = 0; i < countOfGrous; i++)
	{
		cout << *students[i];
	}
	cout << endl;*/
}

//ostream& operator<<(ostream& stream, const Faculty& students){
//	return stream << "group: " << students.groupName << "\tspeciality: " << students.speciality << "\tnum of students = " << students.countOfGrous << endl;
//}



ostream& operator<<(ostream& stream, const Faculty& faculty) {
	return stream << "Faculty name:" << faculty.facultyName << "\tnum of groups = " << faculty.countOfGrous << endl;
}



ostream& operator<<(ostream& stream, const Faculty::Group& group)
{
	return stream << "Group name: " << group.groupName << "\tnum of students = " << group.countOfStudents << endl;
}



Faculty::~Faculty()
{
	for (int i = 0; i < countOfGrous; i++)
	{
		delete groups[i];
	}
	/*for (int i = 0; i < countOfGrous; i++)
	{
		delete students[i];
	}*/
}
