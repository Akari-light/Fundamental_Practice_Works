#include<iostream>
#include<cmath>
#define PI 3.14159265358979323846

using namespace std;

/*I want you to write a class that is called rectangle
this rec constructor can pass in Width and Length
write Getter Setter
Write Get area & perimeter
is square(boolean)
*/

class Rectangle
{
	float m_Length;
	float m_Width;

public:

	Rectangle() {}

	Rectangle(float length, float width)
	{
		m_Length = length;
		m_Width = width;
	}

	~Rectangle() {}

	float SetLength(float length)
	{
		m_Length = length;
	}

	float SetWidth(float width)
	{
		m_Width = width;
	}

	float GetLength()
	{
		return m_Length;
	}

	float GetWidth()
	{
		return m_Width;
	}

	float GetArea()
	{
		return m_Length * m_Width;
	}

	float GetPerimeter()
	{
		return 2.0f * (m_Length + m_Width);
	}

	bool lsSquare()
	{
		return (m_Width == m_Length);
	}
};

class Circle
{
	//private
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
		return PI * pow(m_Radius, 2.0f);
	}

	float GetCircumference()
	{
		return  2.0f * PI * m_Radius;
	}
};

class Triangle
{
	float m_Height;
	float m_Base;

public:

	Triangle() {}

	Triangle(int height, int base)
	{
		m_Height = height;
		m_Base = base;
	}

	~Triangle() {}

	float SetHeight(int height)
	{
		m_Height = height;
	}

	float SetBase(int base)
	{
		m_Base = base;
	}

	float GetHeight()
	{
		return m_Height;
	}

	float GetBase()
	{
		return m_Base;
	}

	float GetArea()
	{
		return  0.5f * m_Base * m_Height;
	}
};

int main()
{
	Rectangle rectangle1(2.1f, 2.0f);

	cout << rectangle1.GetArea() << endl;
	cout << rectangle1.GetPerimeter() << endl;
	cout << rectangle1.lsSquare() << endl;

	system("PAUSE");
	return 0;
}