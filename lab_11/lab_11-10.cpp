
#include <iostream>
#include <string>
#include <ostream>
#include<list>

using namespace std;

class Student {
	string surname;
	string name;
	string fatherName;
	int age;
	string telephoneNumber;

public:
	friend ostream& operator<<(ostream& stream, const Student& st);
	Student()
	{
		surname = name = fatherName = "\0";
		age = 0;
	}

	void getInfo() {
		cout << surname << "\t" << name << "\t" << fatherName << "\t" << age << "\t" << telephoneNumber << endl;
	}

	void printHeader() {
		cout << "surname\tname\tfatherName\tage\ttel.number" << endl;
	}

	void setData() {
		cout << "name: ";
		getline(cin, name);
		cout << "surname: ";
		getline(cin, surname);
		cout << "father name: ";
		getline(cin, fatherName);

		cout << "age: ";
		cin >> age;
		cin.ignore();
		cout << "telephone number: ";
		getline(cin,telephoneNumber);
	}

	int menu() {
		int menuChoice;
		cout << "1 - add student" << endl;
		cout << "2 - show list" << endl;
		cout << "3 - exit" << endl;
		cin >> menuChoice;
		return menuChoice;
	}
};

ostream& operator<<(ostream& stream, const Student& st) {
	stream << st.surname<< st.surname << "\t" << st.name << "\t" << st.fatherName << "\t" << st.age << "\t" << st.telephoneNumber << endl;
	return stream;
}


int main()
{
	list<Student> students;
	Student st;
	int menuItem;

	while ((menuItem=st.menu())!=3)
	{
		cin.ignore();
		switch (menuItem)
		{
		case 1:
			st.setData();
			students.push_back(st);
			system("cls");
			break;

		case 2:
			st.printHeader();

			for (auto& it : students) {
				it.getInfo();
			}
			system("Pause");
			system("cls");
			break;
		}
	}
}

