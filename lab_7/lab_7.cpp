// lab_7.cpp : 

#include <iostream>

using namespace std;

template<typename T>
T getAvg(T *arr, int size) {
	T sum = 0;

	for (int  i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}

template<typename T>
T amax(T* arr, int size) {
	T max = arr[0];

	for (int i = 1; i < size; i++) {
		if(arr[i] > max)
			max = arr[i];
	}

	return max;
}

int main()
{
	const int SIZE = 10;
	srand(time(NULL));

	int intArr[SIZE];
	float floatArr[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		intArr[i] = rand()%20;

		floatArr[i] = (rand() % 20) * 0.5;
	}

	cout << "average int = " << getAvg<int>(intArr, SIZE) << endl;

	cout << "average int = " << getAvg<float>(floatArr, SIZE) << endl;

	cout << "int arr max value = " << amax<int>(intArr, SIZE) << endl;

	cout << "float arr max value = " << amax<float>(floatArr, SIZE) << endl;

}

