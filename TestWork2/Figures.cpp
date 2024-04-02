#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include "Figures.h"	

Circle::Circle(double radius) 
	{this->radius = radius; CalculateArea(); CalculatePerimeter();};
Circle::Circle() { this->radius = 0; area = 0; perimetr = 0; };
double Circle::GetRadius() const { return radius; };
double Circle::GetArea() { return area; };
double Circle::GetPerimetr() { return perimetr; };
void Circle::CalculateArea()  { area = M_PI * radius * radius;  }
void Circle::CalculatePerimeter()  { perimetr = M_PI * radius;  }
void Circle::Display() 
	{ std::cout << "Окружность с радиусом " << radius << ", площадь = " << area << ", периметр = " << perimetr << std::endl; }
void Circle::SaveToFile(std::ofstream& file) {
	file << "c" << std::endl;
	file << GetRadius() << std::endl;
	//file << GetArea() << std::endl;
	//file << GetPerimetr() << std::endl;
}
void Circle::LoadFromFile(std::ifstream& file) {
	file >> radius;
}

Rectangle::Rectangle(double width, double height) 
	{this->width = width; this->height = height; CalculateArea(); CalculatePerimeter();};
double Rectangle::GetWidth() const { return width; };
double Rectangle::GetRecHeight() const { return height; };
double Rectangle::GetRecArea() { return area; };
double Rectangle::GetRecPer() { return perimetr; };
void Rectangle::CalculateArea() { area =  width * height; }
void Rectangle::CalculatePerimeter() { perimetr = (width + height) * 2; }
void Rectangle::Display() 
	{std::cout << "Прямоугольник со сторонами " << width << " и " << height << ", площадь = " << area << ", периметр = " << perimetr << std::endl; }
void Rectangle::SaveToFile(std::ofstream& file) {
	file << "r" << std::endl;
	file << GetWidth() << std::endl;
	file << GetRecHeight() << std::endl;
	//file << GetRecArea() << std::endl;
	//file << GetRecPer() << std::endl;
}
void Rectangle::LoadFromFile(std::ifstream& file) {
	file >> width >> height;
}

Trapecium::Trapecium(double upperBase, double lowerBase, double height) 
	{this->upperBase = upperBase; this->lowerBase = lowerBase; this->height = height; CalculateArea(); CalculatePerimeter();};
double Trapecium::GetUpperBase() const { return upperBase; };
double Trapecium::GetLowerBase() const { return lowerBase; };
double Trapecium::GetHeight() const { return height; };
double Trapecium::GetTrArea() { return area; };
double Trapecium::GetTrPer() { return perimetr; };
void Trapecium::CalculateArea() { area = (upperBase + lowerBase) / 2 * height; };
void Trapecium::CalculatePerimeter() { perimetr = upperBase + lowerBase + 2 * height; };
void Trapecium::Display() 
	{std::cout << "Трапеция с основаниями " << upperBase << " и " << lowerBase << ", высотой " << height << ", площадь = " << area << ", периметр = " << perimetr << std::endl; }
void Trapecium::SaveToFile(std::ofstream& file) {
	file << "t" << std::endl;
	file << GetUpperBase() << std::endl;
	file << GetLowerBase() << std::endl;
	file << GetHeight() << std::endl;
	//file << GetTrArea() << std::endl;
	//file << GetTrPer() << std::endl;
}
void Trapecium::LoadFromFile(std::ifstream& file) {
	file >> upperBase >> lowerBase >> height;
}