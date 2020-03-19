#include <iostream>
#include <string>

using namespace std;

class Drink
{
	string m_Name;
	float m_Price;
	int m_Quantity;

public:

	Drink()
	{
		m_Name = "Unassigned";
		m_Price = 0.0f;
		m_Quantity = 0;
	}

	Drink(string name, float price, int quantity)
	{
		m_Name = name;
		m_Price = price;
		m_Quantity = quantity;
	}

	~Drink() {}

	void SetName(string name)
	{
		m_Name = name;
	}

	string GetName()
	{
		return m_Name;
	}

	void SetPrice(float price)
	{
		m_Price = price;
	}

	float GetPrice()
	{
		return m_Price;
	}

	void SetQuantity(int quantity)
	{
		m_Quantity = quantity;
	}

	int GetQuantity()
	{
		return m_Quantity;
	}

	void ResetValues()
	{
		//reinitialize the slot.
		m_Name = "Unassigned";
		m_Price = 0.0f;
		m_Quantity = 0;
	}

	void SetDetails(Drink& oldDrink)
	{
		m_Name = oldDrink.GetName();
		m_Price = oldDrink.GetPrice();
		m_Quantity = oldDrink.GetQuantity();
	}

	Drink operator=(Drink& oldDrink)
	{
		Drink a;
		a.SetName(oldDrink.GetName());
		a.SetPrice(oldDrink.GetPrice());
		a.SetQuantity(oldDrink.GetQuantity());
		return a;
	}
};

class VendingMachine
{
	const int DEFAULT_SIZE = 4;
	const int INCREMENT_VALUE = 2;

	Drink* m_Inventory;
	int m_CurrentAmountOfDrink;
	int m_InventorySize = DEFAULT_SIZE;


public:

	VendingMachine()
	{
		m_Inventory = new Drink[m_InventorySize];
		m_CurrentAmountOfDrink = 0;
	}

	~VendingMachine()
	{
		delete[] m_Inventory;
	}

	// To resize, I need to have the current size, new size
	void InventoryResize(int newSize)
	{
		if (newSize > 0)
		{
			//Create new array.
			Drink* newInventory = new Drink[newSize];
			int tempSize = m_InventorySize;

			cout << "Inventory will be resize from " << m_InventorySize << " to " << newSize << ".\n";

			//Check if new array is smaller.
			if (newSize < m_InventorySize)
			{
				cout << m_InventorySize - newSize << " has been removed since the new size is shorter then the old size.\n";
				tempSize = newSize;
			}

			//Copy from old array to new array.
			for (int i = 0; i < tempSize; i++)
			{
				newInventory[i].SetDetails(m_Inventory[i]);
			}

			//Cleanup old array.
			delete[] m_Inventory;

			//Update Vending Machine new array.
			m_Inventory = newInventory;
			m_InventorySize = newSize;
		}
		else
		{
			cout << "ERROR: The Size is invalid. \n";
		}
	}

	void AddNewDrink(string name, float price, int quantity)
	{
		if (m_CurrentAmountOfDrink < m_InventorySize)
		{
			m_Inventory[m_CurrentAmountOfDrink].SetName(name);
			m_Inventory[m_CurrentAmountOfDrink].SetPrice(price);
			m_Inventory[m_CurrentAmountOfDrink].SetQuantity(quantity);
			m_CurrentAmountOfDrink++;
			cout << "Successfully added " << name << " at $" << price << " with " << quantity << " quantity. \n";
		}
		else
		{
			InventoryResize(m_InventorySize + INCREMENT_VALUE);
		}
	}

	void VendItem(int index, float& wallet)
	{
		if (m_CurrentAmountOfDrink <= 0)
		{
			cout << "ERROR: There is no drink inside. \n";
		}
		else
		{
			//Check choice validity
			if (index >= 0 && index < m_InventorySize)
			{
				//Check price
				if (wallet >= m_Inventory[index].GetPrice())
				{
					//Check quantity
					if (m_Inventory[index].GetQuantity() > 0)
					{
						m_Inventory[index].SetQuantity(m_Inventory[index].GetQuantity() - 1);
						wallet -= m_Inventory[index].GetPrice();
						cout << "Here is your " << m_Inventory[index].GetName() << ", $" << m_Inventory[index].GetPrice() << " deducted. You left $" << wallet << endl;
						//Here is your coke, $1.5 deducted. You left $4.5
					}
					else
					{
						cout << "ERROR: The " << m_Inventory[index].GetName() << " you have selected is out of stock. \n";
						//Error : There is no more coke left.
					}
				}
				else
				{
					cout << "ERROR: You don't have enough money for " << m_Inventory[index].GetName() << ". This cost $" << m_Inventory[index].GetPrice() << ", but you only have $" << wallet << endl;
					//Error: You don't have enough money left. $0.9
				}
			}
			else
			{
				cout << "ERROR: " << index << " is not a valid option. \n";
				//Error : Your choice is invalid.
			}
		}
	}

	void TopUpDrinkQuantity(int index, int quantity)
	{
		//Check choice validity
		if (index >= 0 && index < m_InventorySize)
		{
			//Check quantity
			if (quantity > 0)
			{
				m_Inventory[index].SetQuantity(quantity + m_Inventory[index].GetQuantity());
				cout << m_Inventory[index].GetName() << " now has " << m_Inventory[index].GetQuantity() << " quantity. \n";
			}
		}
	}

	void RemoveDrink(int index)
	{
		if (index >= 0 && index < m_InventorySize)
		{
			m_Inventory[index].ResetValues();
		}
		else
		{
			cout << "ERROR: " << index + 1 << " is not a valid option. \n";
		}
	}

	bool CheckDrinkIsFilled(int index)
	{
		if (index >= 0 && index < m_InventorySize)
		{
			if (m_Inventory[index].GetName().compare("Unassigned") == 0)
			{
				cout << "ERROR: " << index + 1 << " is unassigned. \n";
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			cout << "ERROR: " << index + 1 << " is not a valid option. \n";
			return false;
		}
	}

	void PrintQuery(int index)
	{
		if (index >= 0 && index < m_InventorySize)
		{
			cout << m_Inventory[index].GetName() << ", $" << m_Inventory[index].GetPrice() << ", " << m_Inventory[index].GetQuantity() << " quantity left. \n";
		}
		else
		{
			cout << "Error: the selection you have chosen is invalid. \n";
		}

	}

	int GetInventorySize()
	{
		return m_InventorySize;
	}

	void PrintChoice(int option)
	{
		cout << "Is " << m_Inventory[option].GetName() << " the drink you want? It costs" << " $" << m_Inventory[option].GetPrice() << ". Y / N" << endl;
	}
};

int main()
{
	bool isRunning = true;
	int choice;
	float wallet = 10.0f;
	VendingMachine vendingMachine;

	while (isRunning)
	{
		system("cls");
		//show menu
		cout << " Vending Machine System \n\n";
		cout << "You have $" << wallet << ". What would you like to do? \n";
		cout << "1. Buy \n2. Query \n3. Topup \n4. Add new drinks \n5. Remove existing drink(s) \n6. Exit \n\n";
		cin >> choice;
		cout << "You have selected: " << choice << endl;

		switch (choice)
		{
		case 1://Buy
		{
			int option;
			char confirmation;

			VendingMachine.PrintInventoryItems();
			cout << "What would you like to buy? \n";
			cin >> option;

			if (vendingMachine.CheckDrinkIsFilled(option - 1))
			{
				vendingMachine.PrintChoice(option - 1);	//Is Coke the drink you want($1.50) ? (You have $4.00)
				cin >> confirmation; //Y / N
				if (confirmation == 'Y')
				{
					vendingMachine.VendItem(option - 1, wallet);
				}
				else
				{
					cout << " Thank you for your time. \n";
				}
			}
		}
		break;
		case 2://Query
		{
			int option;

			cout << "Which drink would you like to check? \n";
			cin >> option;

			if (vendingMachine.CheckDrinkIsFilled(option - 1))
			{
				vendingMachine.PrintQuery(option - 1);
			}
		}
		break;
		case 3://Topup
		{
			int option;
			int quantity;

			cout << "Which drink do you want to top up? \n";
			cin >> option;

			if (option > 0 && option <= vendingMachine.GetInventorySize())
			{
				cout << "What is the quantity you want to add? \n";
				cin >> quantity;

				if (quantity > 0)
				{
					vendingMachine.TopUpDrinkQuantity(option - 1, quantity);
				}
				else
				{
					cout << "Error: the quantiy you have chosen is invalid. \n";
				}
			}
			else
			{
				cout << "Error: the option you have chosen is invalid. \n";
			}

		}
		break;
		case 4://Add new drinks
		{
			string name;
			float price;
			int quantity;

			cout << "Enter a name: ";
			cin >> name;
			cout << "Enter a price: ";
			cin >> price;
			cout << "Enter the quantity: ";
			cin >> quantity;

			vendingMachine.AddNewDrink(name, price, quantity);
		}
		break;
		case 5://Remove existing drink(s)
		{
			int option;
			char confirmation;

			cout << "What would you like to remove? \n";
			cin >> option;

			if (vendingMachine.CheckDrinkIsFilled(option - 1))
			{
				vendingMachine.PrintChoice(option - 1);
				cin >> confirmation; //Y / N
				if (confirmation == 'Y')
				{
					vendingMachine.RemoveDrink(option - 1);
					cout << "Drink " << option << " has been removed. \n";
				}
				else
				{
					cout << " Thank you for your time. \n";
				}
			}

		}
		break;
		case 6://Exit5
		{
			isRunning = false;
		}
		break;
		}
		system("PAUSE");
	}
	system("PAUSE");
	return 0;
}