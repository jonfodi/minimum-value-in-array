

#include "pch.h"
#include <iostream>
#include <array>

using namespace std; 

const size_t arraySize{ 5 };

int minValue(array<double, arraySize> b, size_t index, double min) {

	if (index == b.size() - 1)					//ensure function doesnt go out of bounds
	{
		if (b[index] < min)						// compare last element to min
			min = b[index];						// if last element smaller than min, output last element
	}											
	else {
		if (b[index] < min)						//compare the current index to the min value (initially, min is firstElement)
			min = b[index];

		min = minValue(b, index + 1, min);		// call the function on the following index
												//function loops through the whole array 									
												//if the last element is bigger than the current min, output current min 
	}

	return min;
}


int main()
{
	array < double, arraySize > a{};
	double x = 0;
	
	for (int i = 0; i < a.size(); ++i) {
		cout << "Input 5 values in an array. The minimum value will be found" << endl;
		cin >> x;
		a[i] = x;
	}
	
	int min;
	int firstElement = a[0];
	int index = 0;

	min = minValue(a, index, firstElement);

	cout << "the smallest value is " << min << endl;

	return 0;
}

