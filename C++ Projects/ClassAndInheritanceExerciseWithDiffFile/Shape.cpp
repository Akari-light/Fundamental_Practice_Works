#include "Shape.h"
#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846f

using namespace std;

Shape::Shape()
{
}

Shape::Shape(float height, float width)
{
	m_Height = height;
	m_Width = width;
}

Shape::~Shape()
{
}

void Shape::SetHeight(float height)
{
	m_Height = height;

}

void Shape::SetWidth(float width)
{
	m_Width = width;
}

float Shape::GetHeight()
{
	return m_Height;
}

float Shape::GetWidth()
{
	return m_Width;
}

void Shape::PrintName()
{
	cout << "Shape \n";
}

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(float width, float height) : Shape(width, height)
{
}

Rectangle::~Rectangle()
{
}

float Rectangle::GetArea()
{
	return GetHeight() * GetWidth();
}

float Rectangle::GetPerimeter()
{
	return 2.0f * (GetHeight() + GetWidth());
}

bool Rectangle::lsSquare()
{
	return (GetHeight() == GetWidth());
}

void Rectangle::PrintName()
{
	cout << "Rectangle \n";
}

void Rectangle::PrintTest()
{
	cout << "Test \n";
}

Circle::Circle()
{
}

Circle::Circle(float radius)
{
	m_Radius = radius;
}

Circle::~Circle() {}

void Circle::SetRadius(float radius)
{
	m_Radius = radius;
}

float Circle::GetRadius()
{
	return m_Radius;
}

float Circle::GetArea()
{
	return PI * (float)pow(m_Radius, 2.0f);
}

float Circle::GetCircumference()
{
	return  2.0f * PI * m_Radius;
}

void Circle::PrintName()
{
	std::cout << "Circle \n";
}

Triangle::Triangle()
{
}

Triangle::Triangle(float width, float height) : Shape(width, height)
{
}

Triangle::~Triangle()
{
}

float Triangle::GetArea()
{
	return  0.5f * GetWidth() * GetHeight();
}

void Triangle::PrintName()
{
	cout << "Triangle \n";
}

void Triangle::PrintTest()
{
	cout << "Test \n";
}