#include "Student.h"

string Student::getType(StType& stType)
{
	switch (stType) {
	case PAYER:
		return "payer";
		break;
	case STATE:
		return "state";
		break;
	}
}

Student::Student()
{
	cout << "\nEnter surname: ";
	getline(cin, this->surname);

	cout << "Enter name: ";
	getline(cin, this->name);

	cout << "Enter father name: ";
	getline(cin, this->fatherName);

	cout << "Enter study type (0 - payer 1 - state) ";

	cin >> this->studyTypeBool;
	stType = static_cast<StType>(studyTypeBool);

	this->studyTypeStr = this->getType(stType);

	cout << "Enter ¹ of grandebook: ";
	cin >> this->gradebook;

	cout << endl;
}

Student::Student(string fatherName, string name, string surname, bool studyTypeBool, int gradebook)
{
	this->fatherName = fatherName;
	this->gradebook = gradebook;
	this->name = name;
	this->studyTypeBool = studyTypeBool;

	this->stType = static_cast<StType>(studyTypeBool);

	this->studyTypeStr = this->getType(stType);

	this->surname = surname;
}

ostream& operator<<(ostream& stream, const Student& forOutput) 
{
	return stream << forOutput.surname << "\t" << forOutput.name << "\t" << forOutput.fatherName
		<< "\t" << forOutput.studyTypeStr << "\t" << forOutput.gradebook << endl;
}
