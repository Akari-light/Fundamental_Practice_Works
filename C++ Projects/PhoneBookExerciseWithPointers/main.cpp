#include<iostream>
#include<string>

using namespace std;

/*
I want you to create a library, like a phone book. To store a person's initial, age and male/female.

In the system, I want to be able to choose between.
"Add New Person"
"Remove Person"
"Get Person Detail"
"Get Number of Person in Total"
*/


char GenderConvertion(bool gender)
{
	if (gender)
	{
		return 'M';
	}
	else
	{
		return 'F';
	}
}

void PhoneBookSizeCheckResize(int currentOccupiedSize, int& phoneBookSize, char*& phoneBookInitials, bool*& phoneBookGender, int*& phoneBookAge)
{
	const int phoneBookIncrementValue = 5;

	if (currentOccupiedSize >= phoneBookSize)//Check if no. of people in the book is = to size.
	{
		int newPhoneBookSize = phoneBookSize + phoneBookIncrementValue;//Create temp. phonebook with new size.
		char* newPhoneBookInitials = new char[newPhoneBookSize];
		bool* newPhoneBookGender = new bool[newPhoneBookSize];
		int* newPhoneBookAge = new int[newPhoneBookSize];

		for (int i = 0; i < phoneBookSize; i++)//Copy old array into new array.
		{
			newPhoneBookInitials[i] = phoneBookInitials[i];
			newPhoneBookGender[i] = phoneBookGender[i];
			newPhoneBookAge[i] = phoneBookAge[i];
		}

		delete[] phoneBookInitials;
		delete[] phoneBookGender;
		delete[] phoneBookAge;

		cout << "PhoneBook is now resized from " << phoneBookSize << " to " << newPhoneBookSize << " .\n";
		phoneBookInitials = newPhoneBookInitials;//Reassigning pointer to the new phonebook.
		phoneBookGender = newPhoneBookGender;
		phoneBookAge = newPhoneBookAge;
		phoneBookSize = newPhoneBookSize;
	}
}

void AddNewPerson(int& currentOccupiedSize, int phoneBookSize, char phoneBookInitials[], bool phoneBookGender[], int phoneBookAge[])
{
	if (currentOccupiedSize >= phoneBookSize)
	{
		cout << "The PhoneBook is full. " << endl;
	}
	else
	{
		int age;
		char initial;
		char reply;

		cout << "What is the Initial of the new person at index " << currentOccupiedSize + 1 << "?\n";
		cin >> initial;
		phoneBookInitials[currentOccupiedSize] = initial;

		cout << "Is the new person at index " << currentOccupiedSize + 1 << " a Male(m) or Female(f)?\n";
		cin >> reply;
		phoneBookGender[currentOccupiedSize] = (reply == 'm');

		cout << "What is the Age of the new person at index " << currentOccupiedSize + 1 << "?\n";
		cin >> age;
		phoneBookAge[currentOccupiedSize] = age;

		cout << phoneBookInitials[currentOccupiedSize] << ", " << GenderConvertion(phoneBookGender[currentOccupiedSize]) << ", " << phoneBookAge[currentOccupiedSize] << endl;
		currentOccupiedSize++;
	}
}

void RetrievePerson(int currentOccupiedSize, char phoneBookInitials[], bool phoneBookGender[], int phoneBookAge[])
{
	int option;

	cout << "Who's particuars do you want? " << endl;
	cin >> option;

	if (option > 0 && option <= currentOccupiedSize)
	{
		cout << "Index " << option << ": " << phoneBookInitials[option - 1] << ", " << GenderConvertion(phoneBookGender[option - 1]) << ", " << phoneBookAge[option - 1] << endl;
	}
	else
	{
		cout << "Invalid. " << endl;
	}
}

void TotalPeopleInPhoneBook(int currentOccupiedSize)
{
	cout << "Currently, there is " << currentOccupiedSize << " person(s)." << endl;
}

void PrintPhoneBook(int currentOccupiedSize, char phoneBookInitials[], bool phoneBookGender[], int phoneBookAge[])
{
	if (currentOccupiedSize == 0)
	{
		cout << "There is currently no one inside. " << endl;
	}
	else
	{
		for (int i = 0; i < currentOccupiedSize; i++)
		{
			cout << "Person " << i + 1 << ": " << phoneBookInitials[i] << ", " << GenderConvertion(phoneBookGender[i]) << ", " << phoneBookAge[i] << endl;
		}
	}
}

bool Quit()
{
	cout << "PhoneBook is terminating. \n ";
	return false;
}

int main()
{
	int phoneBookSize = 2;
	int currentOccupiedSize = 0;

	bool isRunning = true;
	int choice;

	int* phoneBookAge = new int[phoneBookSize]; //Creating a pointer and pointing it to a dynamic memory.
	char* phoneBookInitials = new char[phoneBookSize];
	bool* phoneBookGender = new bool[phoneBookSize];

	while (isRunning)
	{
		system("cls");
		//Show menu
		cout << " Phone Book System\n\n1. Add new person\n2. Get person\n3. Get total amount of people in the phonebook.\n4. Print PhoneBook\n5. Quit\n\nEnter choice: ";
		cin >> choice;

		cout << "You have selected: " << choice << endl;

		switch (choice)
		{
		case 1://Add new person.
		{
			PhoneBookSizeCheckResize(currentOccupiedSize, phoneBookSize, phoneBookInitials, phoneBookGender, phoneBookAge);
			AddNewPerson(currentOccupiedSize, phoneBookSize, phoneBookInitials, phoneBookGender, phoneBookAge);
		}
		break;
		case 2://Retrieve a person.
		{
			RetrievePerson(currentOccupiedSize, phoneBookInitials, phoneBookGender, phoneBookAge);
		}
		break;
		case 3://Get amount of person.
		{
			TotalPeopleInPhoneBook(currentOccupiedSize);
		}
		break;
		case 4://Print everyone.
		{
			PrintPhoneBook(currentOccupiedSize, phoneBookInitials, phoneBookGender, phoneBookAge);
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

	delete[] phoneBookAge;
	delete[] phoneBookGender;
	delete[] phoneBookInitials;

	system("PAUSE");
	return 0;
}
