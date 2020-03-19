#include<iostream>
#include<cmath>

using namespace std;

//Write me a function that can take in a range of integer. Function will run from min to max.
//if the current index is a multiple of 3 print Fizz, if it's a multiple of 5 print Buzz. If it's a multiple of both print FizzBuzz

void FizzBuzz(int min, int max)
{
	bool alreadyPrinted = false;
	for (int i = min; i <= max; i++)
	{
		alreadyPrinted = false;
		if (i % 3 == 0) //Check if it's a multiple of 3.
		{
			cout << "Fizz";
			alreadyPrinted = true;
		}
		if (i % 5 == 0)//Check if it's a multiple of 5.
		{
			cout << "Buzz";
			alreadyPrinted = true;
		}
		if (!alreadyPrinted)
		{
			cout << i;
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	int min;
	int max;
	cout << "Enter a Minimum Number: ";
	cin >> min;
	cout << "Enter a Maximum Number: ";
	cin >> max;

	FizzBuzz(min, max);

	return 0;
}