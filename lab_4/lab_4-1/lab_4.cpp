// lab_4-1.cpp : 

#include <iostream>
#include<string>

using namespace std;

class Publication {
	string name;
	float price;

public:

	Publication(){
		name = "";
		price = 0.0;
	}

	Publication(string name,float price){
		this->name=name;
		this->price=price;
	}

	virtual void getData() {
		cout << "Price = " << price << "\tname: " << name<<"\t";
	}

	virtual void putData()  {
		cout << "enter name: ";
		getline(cin, name);

		cout << "Enter price: ";
		cin >> price;
	}
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
		cout << "Number of pages = "<<nOfPages << endl;
	}

	void putData() override {
		Publication::putData();

		cout << "Number of pages = ";
		cin >> nOfPages;
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
};



int main()
{
	Book book("Harry Potter", 12.2, 1000);

	book.getData();

	Type audioBook("HarryPotter", 1, 10.5);

	audioBook.getData();

	Type audioBook2;
	audioBook2.putData();
	audioBook2.getData();
}

