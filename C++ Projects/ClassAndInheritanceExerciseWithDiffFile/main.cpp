#include <iostream>
#include "Shape.h"

using namespace std;

int main()
{
	//polymorphism
	Shape* r1[4];

	r1[0] = new Triangle(2.0f, 2.0f);
	r1[1] = new Rectangle(2.0f, 2.0f);
	r1[2] = new Triangle(2.0f, 1.0f);
	r1[3] = new Rectangle(1.0f, 4.0f);

	for (int i = 0; i < 3; i++)
	{
		r1[i]->PrintName();
	}

	delete r1[0];
	delete r1[1];
	delete r1[2];
	delete r1[3];

	system("PAUSE");
	return 0;
}