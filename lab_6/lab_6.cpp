// lab_6.cpp : 

#include <iostream>
#include "Student.h"
#include "Faculty.h"
using namespace std;

int main()
{

	Faculty faculty;
	faculty.addGroup();
	cout << endl;
	faculty.addGroup();
	cout << endl;
	cout << faculty << endl;
	faculty.showAllGroups();

	/*Faculty g("CS 223", "computer science");		//закоментований код юзав для перевірки класів
	g.addStudent();
	cout << g << endl;
	g.showListOfStudents();*/

	/*Student st("qwe", "asd", "zxc", 1, 123412);
	Student st2;
	Student* st3 = new Student("qwe3", "asd3", "zxc3", 0, 12342312);

	cout << st;
	cout << st2;
	cout << *st3;
	
	delete st3;*/
}
