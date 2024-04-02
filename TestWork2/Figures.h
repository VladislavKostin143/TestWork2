#pragma once

#ifndef FIGURES_H
#define FIGURES_H

#include <vector>
#include <iostream>
#include <fstream>

class Figure {
public:
    virtual void CalculateArea()  = 0;
    virtual void CalculatePerimeter()  = 0;
    virtual void Display() = 0;
    virtual void SaveToFile(std::ofstream& file) = 0;
    virtual void LoadFromFile(std::ifstream& file) = 0;
    virtual ~Figure() = default;
};

class Circle : public Figure {
private:
    double radius;
    double  area;
    double  perimetr;
public:
    Circle(double radius);
    Circle();
    double GetRadius() const;
    double GetArea();
    double GetPerimetr();
    void CalculateArea()  override;
    void CalculatePerimeter()  override;
    void Display() override;
    void SaveToFile(std::ofstream& file) override;
    void LoadFromFile(std::ifstream& file) override;
};

class Rectangle : public Figure {
private:
    double width;
    double height;
    double area;
    double perimetr;
public:
    Rectangle(double width, double height);
    double GetWidth() const;
    double GetRecHeight() const;
    double GetRecArea();
    double GetRecPer();
    void CalculateArea()  override;
    void CalculatePerimeter()  override;
    void Display() override;
    void SaveToFile(std::ofstream& file) override;
    void LoadFromFile(std::ifstream& file) override;
};

class Trapecium : public Figure {
private:
    double upperBase;
    double lowerBase;
    double height;
    double area;
    double perimetr;
public:
    Trapecium(double upperBase, double lowerBase, double height);
    double GetUpperBase() const;
    double GetLowerBase() const;
    double GetHeight() const;
    double GetTrArea();
    double GetTrPer();
    void CalculateArea()  override;
    void CalculatePerimeter()  override;
    void Display() override;
    void SaveToFile(std::ofstream& file) override;
    void LoadFromFile(std::ifstream& file) override;
};

class MyVectors {
public:
    static std::vector <Figure*> Figures;
};

#endif 