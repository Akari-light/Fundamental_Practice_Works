#ifndef SHAPE_H
#define SHAPE_H

//inheritance class
class Shape
{
	float m_Height;
	float m_Width;

public:

	Shape();
	Shape(float height, float width);
	~Shape();

	void SetHeight(float height);
	void SetWidth(float width);
	float GetHeight();
	float GetWidth();

	//when the derived(its child) class has the same function, the derived class is prioritize.
	virtual void PrintName();

	//Pure Virtual; force the derived class to write their own exact same function.
	virtual void PrintTest() = 0;
};

//This line essentially means, you telling the computer that. For rectangle, inherit what Shape has, then add my own to it. So I don't have to rewrite. [:public shape]
class Rectangle : public Shape
{
public:

	Rectangle();
	Rectangle(float width, float height);
	~Rectangle();

	float GetArea();
	float GetPerimeter();
	bool lsSquare();
	void PrintName();
	void PrintTest();
};

class Circle : public Shape
{
	float m_Radius;

public:

	Circle();
	Circle(float radius);
	~Circle();

	void SetRadius(float radius);
	float GetRadius();
	float GetArea();
	float GetCircumference();
	void PrintName();
};

class Triangle : public Shape
{
public:

	Triangle();
	Triangle(float width, float height);
	~Triangle();

	float GetArea();
	void PrintName();
	void PrintTest();
};
#endif