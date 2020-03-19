#include<iostream>
#define VARSIZE 5
#include<cmath>


using namespace std;

//Test 3: Creating a function to Print only Even Numbers.
bool CheckEven(int a)
{
	return a % 2 == 0;
}

//Test 4: Printing only Prime NUmbers.
bool CheckPrime(int a)
{
	//a is divisible by 1 and itself with no remainder, a is not equal to 1.
	if (a % 1 == 0 && a % a == 0 && a != 1)
	{
		//a has a remainder when divide by everything.
		for (int i = 2; i < a; i++)
		{
			if (a % i == 0)
			{
				return false;
			}

		}
		return true;
	}

	return false;
}

bool CheckPrimeNo(int a)
{
	return false;
}

//Test 5: Printing Perfect Squares.
bool CheckPerfectSquare(int a)
{
	//a is equal to i*i and i is less then a.
	for (int i = 1; i <= a; i++)
	{
		if (i * i == a)
		{
			return true;
		}
	}
	return false;
}


//Test 1: Writting an array & using for loop.
int main()
{
	int a[VARSIZE] = { 4,5,6,1,7 };

	//for (Run one time; check always; RUN CODE, run everytime)
	for (int i = 0; i < VARSIZE; i++)
	{
		if (CheckPerfectSquare(a[i]))
		{
			cout << a[i] << endl;
		}

	}
	//Test 2: Understanding how to use for loop.
	/*for (int i = VARSIZE-1 ; i >=0; i--)
	{
		cout << a[i] << endl;
		//Type here
	}*/

	cout << "Hello World!" << endl;

	system("PAUSE");
	return 0;
}

