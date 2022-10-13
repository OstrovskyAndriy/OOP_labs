// lab_5-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Publication {
	string name;
	float price;

public:

	Publication() {
		name = "";
		price = 0.0;
	}

	Publication(string name, float price) {
		this->name = name;
		this->price = price;
	}

	virtual void getData() {
		cout << "Price = " << price << "\tname: " << name << "\t";
	}

	virtual void putData() {
		cout << "enter name: ";
		getline(cin, name);

		cout << "Enter price: ";
		cin >> price;
	}

	bool virtual isOveersize() = 0;
	
};

class Book : public Publication {
	int nOfPages;
public:

	Book() {
		nOfPages = 0;
	}

	Book(string name, float price, int nOfPages) : Publication(name, price) {
		this->nOfPages = nOfPages;
	}

	void getData() override {
		Publication::getData();
		cout << "Number of pages = " << nOfPages << endl;
	}

	void putData() override {
		Publication::putData();

		cout << "Number of pages = ";
		cin >> nOfPages;
	}

	bool isOveersize() override {
		return nOfPages > 800;
	}
};



class Type : public Publication {
	float time;
public:

	Type() {
		time = 0;
	}

	Type(string name, float price, float time) : Publication(name, price) {
		this->time = time;

	}

	void getData() override {
		Publication::getData();
		cout << "time = " << time << endl;
	}

	void putData() override {
		Publication::putData();
		cout << "time = ";
		cin >> time;
	}

	bool isOveersize() override {
		return time > 90;
	}
};


int menu() {
	int item;
	cout << "1 - add new book" << endl;
	cout << "2 - add new audio book" << endl;
	cin >> item;
	return item;
}


int main()
{
	const int SZIE = 4;
	Publication* publication[SZIE];

	int count = 0;

	int menuChoice;

	while ((menuChoice = menu())) {

		cin.ignore();

		switch (menuChoice)
		{
		case 1:
			publication[count] = new Book;
			publication[count]->putData();
			system("cls");
			break;

		case 2:
			publication[count] = new Type;
			publication[count]->putData();
			system("cls");
		}

		if (count == 3) {
			break;
		}

		count++;
	}

	for (int i = 0; i < SZIE; i++)
	{
		cout << i << ")  ";
		if (!publication[i]->isOveersize()) {
			publication[i]->getData();
		}

		else {
			cout << "publication[" << i << "]" << " is oversize" << endl;
		}

		delete publication[i];
	}
}