// first ex.

#include <iostream>
#include <ostream>
#include <istream>
using namespace std;


class Integer {
	int value=0;
public:
	Integer() {
		value = 0;
	}

	Integer(int value):value(value)	{

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
		return (this->value + other.value);
	}

	const Integer operator=( const Integer& other) {
		return (this->value = other.value);
	}

	//оператор >> працює лише з перевизначенням тому потрібно робити дружнім
	friend istream& operator>>(istream& stream, Integer& forInput);
	
};

ostream& operator<<(ostream& stream, const Integer& forOutput)
{
	return stream << forOutput.getValue();
}

istream& operator>>(istream& stream, Integer &forInput)
{
	stream >> forInput.value;
	return stream;
}

int main()
{
	Integer a(5);
	Integer b(12);
	Integer c;
	cout << "a = ";    a.printToConsole();
	cout << "b = ";    b.printToConsole();

	cout << "Cin >> a ";
	cin >> a;
	cout << "a = ";    a.printToConsole();

	b = a;
	cout << "b = ";    b.printToConsole();

	c = a + b;
	cout << "c = ";    c.printToConsole();

	a = 10;
	cout << "a = ";    a.printToConsole();

	cout << "a = ";   (cout << a + 18) << endl;
}