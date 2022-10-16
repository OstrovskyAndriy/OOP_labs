// lab_7-3.cpp : 

#include <iostream>

using namespace std;

template<class T>
class Arr {
    T* arr;
	int size;
public:
	Arr(const int size)
	{
		this->size = size;
		this->arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = (rand() % 20) * 0.3;
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	T getAvg() {
		T sum = 0;

		for (int i = 0; i < size; i++){
			sum += arr[i];
		}

		return sum / size;
	}

	T amax() {
		T max = arr[0];

		for (int i = 1; i < size; i++) {
			if (arr[i] > max)
				max = arr[i];
		}

		return max;
	}

};

int main()
{
	srand(time(NULL));

	Arr<int> arr1(10);
	cout << "arr1 max = " << arr1.amax() << endl;
	cout << "arr1 avg = " << arr1.getAvg() << endl;

	cout << endl;
	Arr<float> arr2(10);
	cout << "arr2 max = " << arr2.amax() << endl;
	cout << "arr2 avg = " << arr2.getAvg() << endl;

}

