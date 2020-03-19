#include<iostream>
#include<cmath>
#include<string>

using namespace std;

string PrintMagnitude(int scale)
{
	switch (scale)
	{
	case 2:	return "hundred"; break;
	case 3:	return "thousand"; break;
	case 6:	return "million";	break;
	default: return "Out of range.";
	}
}

string PrintTens(int value)
{
	switch (value)
	{
	case 1: return "ten"; break;
	case 2:	return "twenty"; break;
	case 3:	return "thirty"; break;
	case 4:	return "fourty"; break;
	case 5:	return "fifty"; break;
	case 6:	return "sixty"; break;
	case 7: return "seventy"; break;
	case 8: return "eighty"; break;
	case 9:	return "ninety"; break;
	default: return "Out of range.";
	}
}

string PrintNumberBetweenTenToTwenty(int value)
{
	switch (value)
	{
	case 1:	return "eleven"; break;
	case 2:	return "twelve"; break;
	case 3:	return "thirteen"; break;
	case 4:	return "fourteen";	break;
	case 5:	return "fifteen"; break;
	case 6:	return "sixteen"; break;
	case 7:	return "seventeen"; break;
	case 8:	return "eighteen"; break;
	case 9:	return "nineteen"; break;
	default: return "Out of range.";
	}
}

string PrintSingleDigit(int value)
{
	switch (value)
	{
	case 0: return "zero"; break;
	case 1:	return "one"; break;
	case 2:	return "two"; break;
	case 3:	return "three"; break;
	case 4:	return "four"; break;
	case 5:	return "five";	break;
	case 6:	return "six"; break;
	case 7:	return "seven"; break;
	case 8:	return "eight"; break;
	case 9:	return "nine";	break;
	default: return "Out of range.";
	}
}


//Print 1-99.
string PrintDoubleDigit(int value)
{
	string temp = "";
	if (value > 10 && value < 20)
	{
		temp = PrintNumberBetweenTenToTwenty(value % 10);
	}
	else
	{
		if (value >= 10)
		{
			temp += PrintTens(value / 10);
		}
		if (value % 10 != 0)
		{
			if (temp.length() > 0)
			{
				temp += " ";
			}
			temp += PrintSingleDigit(value % 10);
		}
	}

	return temp;
}

//Print 1-999.
string PrintTripleDigit(int value)
{
	string temp = "";
	if (value >= 100)
	{
		temp = PrintSingleDigit(value / 100) + " " + PrintMagnitude(2);
	}
	if (temp.length() > 0 && value % 100 > 0)
	{
		temp += " and ";
	}
	temp += PrintDoubleDigit(value % 100);

	return temp;
}

//Print 1-999 999
string PrintSixDigit(int value)
{
	string temp = "";
	if (value >= 1000)
	{
		temp = PrintTripleDigit(value / 1000) + " " + PrintMagnitude(3);
	}
	if (temp.length() > 0 && value % 1000 > 0)
	{
		temp += ", ";
	}
	temp += PrintTripleDigit(value % 1000);

	return temp;
}

//Print 1-999 999 999.
string PrintNineDigit(int value)
{
	string temp = "";
	if (value >= 1000000)
	{
		temp = PrintSixDigit(value / 1000000) + " " + PrintMagnitude(6);
	}

	if (temp.length() > 0 && value % 1000000 > 0)
	{
		temp += ", ";
	}
	temp += PrintSixDigit(value % 1000000);

	return temp;
}

string ToUpper(string str)
{
	string toReturn = "";

	if (str.length() > 0)
	{
		toReturn = str;
		char a = toReturn[0];
		//Caps - 65-90 , lowercase 97-122, difference = 32
		if ((int)a >= 97 && (int)a <= 122)
		{
			toReturn[0] = (int)a - 32;
		}
	}

	return toReturn;
}
/*
CapFirst(Capitalize first letter)//Already have
ToUpper(All to uppercase)
ToLower(All to lowercase)
CapOnNum(All starting numbers are caps, Fourty thousand and Fifty)
*/

string ConvertToText(int input)
{
	if (input == 0)
	{
		return PrintSingleDigit(input);
	}
	return ToUpper(PrintNineDigit(input));
}

int main()
{
	cout << ConvertToText(0) << "|" << endl;
	cout << ConvertToText(3) << "|" << endl;
	cout << ConvertToText(43) << "|" << endl;
	cout << ConvertToText(12) << "|" << endl;
	cout << ConvertToText(123) << "|" << endl;
	cout << ConvertToText(114) << "|" << endl;
	cout << ConvertToText(9000001) << "|" << endl;//
	cout << ConvertToText(6500021) << "|" << endl;//
	cout << ConvertToText(20000000) << "|" << endl;



	cout << ConvertToText(2000) << "|" << endl;
	cout << ConvertToText(3012) << "|" << endl;//wrong three thousand, twelve
	cout << ConvertToText(3045) << "|" << endl;//
	cout << ConvertToText(2344) << "|" << endl;
	cout << ConvertToText(2001) << "|" << endl;//
	cout << ConvertToText(2030) << "|" << endl;//
	cout << ConvertToText(11000) << "|" << endl;
	cout << ConvertToText(13212) << "|" << endl;
	cout << ConvertToText(41201) << "|" << endl;
	cout << ConvertToText(60000) << "|" << endl;
	cout << ConvertToText(10000) << "|" << endl;
	cout << ConvertToText(120000) << "|" << endl;
	cout << ConvertToText(700530) << "|" << endl;
	cout << ConvertToText(853123) << "|" << endl;
	cout << ConvertToText(123456889) << "|" << endl;

	system("PAUSE");
	return 0;
}