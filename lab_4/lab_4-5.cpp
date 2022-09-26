// lab_4-5.cpp : 

#include <iostream>

using namespace std;

class ThreeNumbers {
public:
	
	virtual void setData()=0;

	virtual void getData()=0;

	virtual void increment()=0;

};

class Data :public  ThreeNumbers {
	int day;
	int month;
	int year;

public:
	Data(){
		day = month = year = 0;
	}

	Data(int day, int month, int year): day(day), month(month), year(year) {
		
	}

	void setData() override {
		cout << "cin >> Day >> Month >> Year " << endl;
		cin >> day >> month >> year;
	}

	void getData()override {
		cout << "day = " << day << " month = " << month << " year = " << year << endl;
	}

	void increment()override {
		day++;
		month++;
		year++;
	}

};

int main()
{
	Data d(2, 10, 2002);
	d.getData();
	d.increment();
	d.getData();
	d.setData();
	d.getData();
}
