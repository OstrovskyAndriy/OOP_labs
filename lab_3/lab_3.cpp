// lab_3.cpp 

#include <iostream>
#include <limits>
#include <Windows.h>

#include <ostream>
#include <istream>

using namespace std;


class Integer {
	int value = 0;
public:
	Integer() {
		value = 0;
	}

	Integer(int value) :value(value) {

	}

	void setValue(int value) {
		this->value = value;
	}

	int getValue() const {
		return value;
	}

	void printToConsole() {
		cout << value << endl;
	}

	const Integer operator+(const Integer& other) {
		long double result = (double)this->value + (double)other.value;

		if (result > INT_MAX || result < INT_MIN) {
			throw "out of range (add)";
		}

		return (this->value + other.value);
	}

	const Integer operator-(const Integer& other) {
		long double result = (double)this->value - (double)other.value;

		if (result > INT_MAX || result < INT_MIN) {
			throw "out of range (subtract)";
		}

		return (this->value - other.value);
	}

	const Integer operator=(const Integer& other) {
		return (this->value = other.value);
	}

	const Integer operator/(const Integer& other) {
		long double result = (double)this->value / (double)other.value;

		if (result > INT_MAX || result < INT_MIN) {
			throw "out of range (divide)";
		}
		return (this->value / other.value);
	}

	const Integer operator*(const Integer& other) {
		long double result = (double)this->value * (double)other.value;

		if (result > INT_MAX || result < INT_MIN) {
			throw "out of range (multiply)";
		}

		return (this->value * other.value);
	}

	const Integer operator^(unsigned int n) {
		int temp = this->value;
		long double result = (double)this->value;

		for (int i = 1; i < n; i++) {
			result *= result;

			if (result > INT_MAX || result < INT_MIN) {
				throw "out of range (exponentiation)";
			}
		}

		return (this->value = result);
	}

	//оператор >> працює лише з перевизначенням тому потрібно робити дружнім
	friend istream& operator>>(istream& stream, Integer& forInput);

};

ostream& operator<<(ostream& stream, const Integer& forOutput)
{
	return stream << forOutput.getValue();
}

istream& operator>>(istream& stream, Integer& forInput)
{
	stream >> forInput.value;
	return stream;
}

int main()
{
	HANDLE textColor = GetStdHandle(STD_OUTPUT_HANDLE);

	Integer a(123);
	Integer b(123456);
	
	Integer c;
	cout << "a = ";    a.printToConsole();
	cout << "b = ";    b.printToConsole();

	try
	{
		cout << "Cin >> a ";
		cin >> a;
		cout << "a = ";    a.printToConsole();

		cout << "a - b = " << a - b << endl;

		c = a + b;
		cout << "c = a + b ";    c.printToConsole();

		a = 10;
		cout << "a = ";    a.printToConsole();

		cout << "a + 18 = ";   (cout << a + 18) << endl;

		a* b;
		cout << "a * b = "; a.printToConsole();

		a / b;
		cout << "a / b = "; a.printToConsole();
		a = 20000000000;
		cout << "a ^ 3 = " << (a ^ 3) << endl;
	}

	catch (const char*error)
	{
		SetConsoleTextAttribute(textColor, 4);
		cout << error;
		SetConsoleTextAttribute(textColor, 7);
	}

}