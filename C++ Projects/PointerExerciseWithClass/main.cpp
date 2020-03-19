#include<iostream>

using namespace std;

class PhoneBookPage
{
	//private
	char m_Initial;
	bool m_Gender;
	int m_Age;

public:
	//Constructor
	PhoneBookPage() {}

	//Destructor
	~PhoneBookPage() {}

	void SetInitial(char initial)
	{
		m_Initial = initial;
	}

	char GetInitial()
	{
		return m_Initial;
	}

	void SetGender(bool gender)
	{
		m_Gender = gender;
	}

	bool GetGender()
	{
		return m_Gender;
	}

	char GetGenderChar()
	{
		if (m_Gender)
		{
			return 'M';
		}
		else
		{
			return 'F';
		}
	}

	void SetAge(int age)
	{
		if (age >= 0)
		{
			m_Age = age;
		}
	}

	int GetAge()
	{
		return m_Age;
	}
};

void PhoneBookSizeCheckResize(int currentOccupiedSize, int& phoneBookSize, PhoneBookPage*& phoneBook)
{
	const int phoneBookIncrementValue = 5;

	if (currentOccupiedSize >= phoneBookSize)
	{
		int newPhoneBookSize = phoneBookSize + phoneBookIncrementValue;
		PhoneBookPage* newPhoneBook = new PhoneBookPage[newPhoneBookSize]();

		for (int i = 0; i < phoneBookSize; i++)
		{
			newPhoneBook[i].SetInitial(phoneBook[i].GetInitial());
			newPhoneBook[i].SetGender(phoneBook[i].GetGender());
			newPhoneBook[i].SetAge(phoneBook[i].GetAge());
		}

		delete[] phoneBook;

		cout << "PhoneBook is now resized from " << phoneBookSize << " to " << newPhoneBookSize << " .\n";
		phoneBook = newPhoneBook;
		phoneBookSize = newPhoneBookSize;
	}
}

void AddNewPerson(int& currentOccupiedSize, int phoneBookSize, PhoneBookPage* phoneBook)
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
		phoneBook[currentOccupiedSize].SetInitial(initial);

		cout << "Is the new person at index " << currentOccupiedSize + 1 << " a Male(m) or Female(f)?\n";
		cin >> reply;
		phoneBook[currentOccupiedSize].SetGender(reply == 'm' || reply == 'M');

		cout << "What is the Age of the new person at index " << currentOccupiedSize + 1 << "?\n";
		cin >> age;
		phoneBook[currentOccupiedSize].SetAge(age);

		cout << phoneBook[currentOccupiedSize].GetInitial() << ", " << phoneBook[currentOccupiedSize].GetGenderChar() << ", " << phoneBook[currentOccupiedSize].GetAge() << endl;
		currentOccupiedSize++;
	}
}

void RetrievePerson(int currentOccupiedSize, PhoneBookPage* phoneBook)
{
	int option;

	cout << "Who's particuars do you want? " << endl;
	cin >> option;

	if (option > 0 && option <= currentOccupiedSize)
	{
		cout << "Index: " << option << " " << phoneBook[option - 1].GetInitial() << ", " << phoneBook[option - 1].GetGenderChar() << ", " << phoneBook[option - 1].GetAge() << endl;
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

void PrintPhoneBook(int currentOccupiedSize, PhoneBookPage* phoneBook)
{
	if (currentOccupiedSize == 0)
	{
		cout << "There is currently no one inside. " << endl;
	}
	else
	{
		for (int i = 0; i < currentOccupiedSize; i++)
		{
			cout << "Person " << i + 1 << " " << phoneBook[i].GetInitial() << ", " << phoneBook[i].GetGenderChar() << ", " << phoneBook[i].GetAge() << endl;
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

	PhoneBookPage* phoneBook = new PhoneBookPage[phoneBookSize]();

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
			PhoneBookSizeCheckResize(currentOccupiedSize, phoneBookSize, phoneBook);
			AddNewPerson(currentOccupiedSize, phoneBookSize, phoneBook);
		}
		break;
		case 2://Retrieve a person.
		{
			RetrievePerson(currentOccupiedSize, phoneBook);
		}
		break;
		case 3://Get amount of person.
		{
			TotalPeopleInPhoneBook(currentOccupiedSize);
		}
		break;
		case 4://Print everyone.
		{
			PrintPhoneBook(currentOccupiedSize, phoneBook);
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

	delete[] phoneBook;

	system("PAUSE");
	return 0;
}
