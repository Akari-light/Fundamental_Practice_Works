#include<iostream>
#define VARSIZE 8
#include<cmath>

using namespace std;

const int ASCII_INT_START = 48;
const int ASCII_ALPHABET_START = 65;

char ConvertNumberToHex(int number)
{
	if (number < 10)
	{
		return (ASCII_INT_START + number);
	}
	else
	{
		return (ASCII_ALPHABET_START - 10 + number);
	}

}

void ConvertDecToTarget(int input, char output[], int base, int size)
{
	bool alreadyDone = false;
	int quotient = input / base;
	int remainder = input % base;
	int temporaryStorage;
	int i = 0;
	output[i] = ConvertNumberToHex(remainder);
	while (quotient != 0)
	{
		if (!alreadyDone)
		{
			i = 1;
			temporaryStorage = 0;
		}
		temporaryStorage = quotient / base;
		remainder = quotient % base;
		output[i] = ConvertNumberToHex(remainder);
		i++;
		quotient = temporaryStorage;
		alreadyDone = true;
	}
}




//ERROR: cannot convert Hex to dec.
void TargetToConversion(int input[], int base, int size)
{
	bool alreadyDone = false;
	int power = 0;
	int result;
	int addition;
	int output;
	for (int i = size - 1; i >= 0; i--)
	{
		if (!alreadyDone)
		{
			addition = 0;
			output = 0;
		}
		result = input[i] * (int)pow(base, power);
		output = addition + result;
		addition = output;
		power++;
		alreadyDone = true;
	}
	cout << "Decimal is: " << output << endl;
}

//Reset array back to all '0'
void InitializeArray(char input[], int size)
{
	int userInput = 0;
	for (int i = 0; i < size; i++)
	{
		input[i] = ASCII_INT_START;
	}
}

void PrintArray(char input[], int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		cout << input[i];
	}
	cout << endl;
}


int main()
{
	int decNum[VARSIZE];

	for (int i = 0; i < VARSIZE; i++)
	{
		decNum[i] = 1;
	}

	int input = 255;
	char output[VARSIZE];
	int base = 2;

	InitializeArray(output, VARSIZE);
	ConvertDecToTarget(input, output, base, VARSIZE);
	PrintArray(output, VARSIZE);

	InitializeArray(output, VARSIZE);
	TargetToConversion(decNum, base, VARSIZE);
	PrintArray(output, VARSIZE);

	system("PAUSE");
	return 0;
}