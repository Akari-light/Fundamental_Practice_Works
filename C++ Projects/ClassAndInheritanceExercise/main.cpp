#include<iostream>
#include<cmath>
#define PI 3.14159265358979323846f

using namespace std;

//inheritance class
class Shape
{
	float m_Height;
	float m_Width;

public:

	Shape() {}

	Shape(float height, float width)
	{
		m_Height = height;
		m_Width = width;
	}

	~Shape() {}

	float SetHeight(float height)
	{
		m_Height = height;
	}

	float SetWidth(float width)
	{
		m_Width = width;
	}

	float GetHeight()
	{
		return m_Height;
	}

	float GetWidth()
	{
		return m_Width;
	}

	//when the derived(its child) class has the same function, the derived class is prioritize.
	virtual void PrintName()
	{
		cout << "Shape \n";
	}

	//Pure Virtual; force the derived class to write their own exact same function.
	virtual void PrintTest() = 0;
};

//This line essentially means, you telling the computer that. For rectangle, inherit what Shape has, then add my own to it. So I don't have to rewrite.
class Rectangle : public Shape
{
public:

	Rectangle() {}

	Rectangle(float width, float height) : Shape(width, height) {}

	~Rectangle() {}

	float GetArea()
	{
		return GetHeight() * GetWidth();
	}

	float GetPerimeter()
	{
		return 2.0f * (GetHeight() + GetWidth());
	}

	bool lsSquare()
	{
		return (GetHeight() == GetWidth());
	}

	void PrintName()
	{
		cout << "Rectangle \n";
	}

	void PrintTest()
	{
		cout << "Test \n";
	}
};

class Circle : public Shape
{
	float m_Radius;

public:

	Circle() {}

	Circle(float radius)
	{
		m_Radius = radius;
	}

	~Circle() {}

	float SetRadius(float radius)
	{
		m_Radius = radius;
	}

	float GetRadius()
	{
		return m_Radius;
	}

	float GetArea()
	{
		return PI * (float)pow(m_Radius, 2.0f);
	}

	float GetCircumference()
	{
		return  2.0f * PI * m_Radius;
	}

	void PrintName()
	{
		std::cout << "Circle \n";
	}
};

class Triangle : public Shape
{
public:

	Triangle() {}

	Triangle(float width, float height) : Shape(width, height) {}

	~Triangle() {}

	float GetArea()
	{
		return  0.5f * GetWidth() * GetHeight();
	}

	void PrintName()
	{
		cout << "Triangle \n";
	}

	void PrintTest()
	{
		cout << "Test \n";
	}
};

int main()
{
	//polymorphism
	Shape* r1[3];

	r1[0] = new Triangle(2.0f, 2.0f);
	r1[1] = new Rectangle(3.0f, 3.0f);
	r1[2] = new Triangle(4.0f, 1.0f);

	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ". is a ";
		r1[i]->PrintName();
	}

	delete r1[0];
	delete r1[1];
	delete r1[2];

	system("PAUSE");
	return 0;
}