#include<iostream>
#include<cmath>
#include<string>
#define VARSIZE 16

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

string ConvertDecToTarget(int input, int base)
{
	int temporaryStorage = 0;
	string toReturn = "";

	int quotient = input / base;
	int remainder = input % base;
	toReturn += ConvertNumberToHex(remainder);

	//Check if the input can be further divided.
	while (quotient != 0)
	{
		temporaryStorage = quotient / base;
		remainder = quotient % base;
		toReturn += ConvertNumberToHex(remainder);
		quotient = temporaryStorage;
	}

	return toReturn;
}

int ConvertBinaryToDecimal(string input)
{
	int dec_val = 0;
	int power = 0;

	//Extracting characters as digits from last character.
	for (int i = input.length() - 1; i >= 0; i--)
	{
		//Multiply 1 and 2^x.
		dec_val += ((int)input[i] - 48) * (int)pow(2, power);
		power++;
	}

	return dec_val;
}

int HexToDecimal(string hexVal)
{
	int dec_val = 0;
	int base = 16;

	//Initializing multiplicand value, E.g 16^0 
	int power = 0;

	//Extracting characters as digits from last character.
	for (int i = hexVal.length() - 1; i >= 0; i--)
	{
		//If character lies in '0'-'9', converting it to integral 0-9 by subtracting 48 from ASCII value. 
		if (hexVal[i] >= '0' && hexVal[i] <= '9')
		{
			dec_val += (hexVal[i] - 48) * (int)pow(base, power);
			power++;
		}
		//If character lies in 'A'-'F' , converting it to integral 10 - 15 by subtracting 55 from ASCII value. 
		else if (hexVal[i] >= 'A' && hexVal[i] <= 'F')
		{
			dec_val += (hexVal[i] - 55) * (int)pow(base, power);
			power++;
		}
	}
	return dec_val;
}

string ToUpper(string str)
{
	string toReturn = "";

	if (str.length() > 0)
	{
		toReturn = str;
		char currentChar;

		//Check every character in the string for uppercase.
		for (int i = 0; i < str.length(); i++)
		{
			currentChar = toReturn[i];
			//Caps - 65-90 , lowercase 97-122, difference = 32
			if ((int)currentChar >= 97 && (int)currentChar <= 122)
			{
				toReturn[i] = (int)currentChar - 32;
			}
		}
	}

	return toReturn;
}

bool Quit()
{
	cout << "Number System converter is terminating.\n";
	return false;
}

int main()
{
	int choice;
	bool isRunning = true;

	while (isRunning)
	{
		system("cls");
		//Show functions
		cout << "Number System converter. \n\n1.Dec to Hex/Bin\n2.Bin to Dec \n3.Hex to Dec \n4.Hex to Bin \n5.Quit\n\nEnter choice: ";
		cin >> choice;

		cout << "You have selected: " << choice << endl;

		switch (choice)
		{
		case 1://Dec to Hex or Bin.
		{
			int input;
			int base;

			cout << "Enter Decimal: ";
			cin >> input;
			cout << "Enter Base (2 or 16):";
			cin >> base;

			if (base == 2)
			{
				cout << "Binary is: " << ConvertDecToTarget(input, base) << endl;
			}
			else
			{
				cout << "Hex is: " << ConvertDecToTarget(input, base) << endl;
			}

		}
		break;
		case 2://Bin into Dec.
		{
			char binNum[VARSIZE];

			cout << "Enter Binary: ";
			cin >> binNum;

			cout << "Decimal value is: " << ConvertBinaryToDecimal(binNum) << endl;
		}
		break;
		case 3://Hex to Dec.
		{
			char hexNum[VARSIZE];

			cout << "Enter Hexadecimal: ";
			cin >> hexNum;

			cout << "Decimal value is: " << HexToDecimal(ToUpper(hexNum)) << endl;
		}
		break;
		case 4://Hex to Bin.
		{
			char hexNum[VARSIZE];

			cout << "Enter Hexadecimal: ";
			cin >> hexNum;

			cout << "Binary value is: " << ConvertDecToTarget(HexToDecimal(ToUpper(hexNum)), 2) << endl;
		}
		break;
		case 5://To quit.
		{
			isRunning = Quit();
		}
		break;
		}

		system("PAUSE");
	}

	system("PAUSE");
	return 0;
}
