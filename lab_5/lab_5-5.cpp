// lab_5-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class ThreeNumbers {
public:	
	virtual void getData()=0;
	virtual void increment()=0;
};

class Data :public  ThreeNumbers {
	int day;
	int month;
	int year;

public:
	Data(){
		cout << "Enter day (1-31): "; cin >> day;
		cout << "Enter month (1-12): "; cin >> month;
		cout << "Enter year: "; cin >> year;
	}

	void getData()override {
		cout << "day = " << day << " month = " << month << " year = " << year << endl;
	}

	void increment()override {
		day >= 31 ? day = 0, month++ : day++;
		month >= 12 ? month = 0, year++ : month++;
		year++;
	}

};

class Time : public ThreeNumbers{
	int hour;
	int minute;
	int second;
public:
	Time(){
		cout << "Enter hour (0-23): "; cin >> hour;
		cout << "Enter minute (0-59): "; cin >> minute;
		cout << "Enter second (0-59): "; cin >> second;

	}

	void getData() override {
		cout << "hour = " << hour << " minute = " << minute << " second = " << second << endl;
	}

	void increment()override {
		hour >= 23 ? hour = 0 : hour++;
		minute >= 59 ? minute = 0, hour++ : minute++;
		second >= 59 ? second = 0, minute++ : second++;
	}
};

int main()
{
	ThreeNumbers* data[2];
	data[0] = new Data;
	data[1] = new Time;
	cout << endl;

	data[0]->getData();
	data[1]->getData();

	cout << "\nincrement" << endl;
	data[0]->increment();
	data[1]->increment();
	cout << endl;

	data[0]->getData();
	data[1]->getData();
}