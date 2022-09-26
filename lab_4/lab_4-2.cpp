#include <iostream>
#include<string>

using namespace std;


class Sales {
	static float totalPrice[3];
	static int month ;
public:
	void putPrice(float price) {
		totalPrice[month] += price;
	}
	void getAllPrice() {
		for (int i = 0; i < month+1; i++)
		{
			cout << i + 1 << "  -  " << totalPrice[i] << endl;;
		}
	}

	void changeMonth() {
		month++;
	}
};

int Sales::month = 0;
float Sales::totalPrice[3]{ 0,0,0 };

//Sales sales;

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

	Sales sales;
};




class Book : public Publication, public Sales {
	int nOfPages;
public:

	Book() {
		nOfPages = 0;
	}

	Book(string name, float price, int nOfPages) : Publication(name, price) {
		this->nOfPages = nOfPages;
		sales.putPrice(price);

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
};



class Type : public Publication, public Sales {
	float time;
public:

	Type() {
		time = 0;
	}

	Type(string name, float price, float time) : Publication(name, price) {
		this->time = time;
		sales.putPrice(price);
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
	Sales allPrice;
	Book book("Harry Potter", 12.2, 1000);

	//book.getData();

	Type audioBook("HarryPotter", 3, 10.5);

	//audioBook.getData();

	Type audioBook2("HarryPotter", 2.5, 10.5);
	//audioBook2.putData();
	//audioBook2.getData();

	allPrice.changeMonth();

	Book book2("Harry Potter", 12.2, 1000);
	Type audioBook3("HarryPotter", 5.32, 10.5);
	Type audioBook4("HarryPotter", 12.4, 20.5);
	allPrice.changeMonth();

	Book book3("Harry Potter", 19.2, 1000);
	Type audioBook5("HarryPotter", 1.32, 10.5);
	Type audioBook6("HarryPotter", 10.4, 20.5);
	allPrice.getAllPrice();

}