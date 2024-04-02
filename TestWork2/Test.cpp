#include <iostream>
#include <fstream>
#include "Figures.h"
#include "Functions.h"
#include "FunctionsForFiles.h"
#include "FunctionsForData.h"

void Test() {
    std::ifstream file("test.txt");
    bool check = true;
    if (!file.is_open()) {
        std::cout << "Тестирование провалено. Невозможно открыть файл" << std::endl;
    }
    else {
        Figure* newFigure;
        char identifier;
        while (file >> identifier) {
            if (std::isalpha(identifier)) {
                if (identifier == 'c' || identifier == 'C') {
                    double radius;
                    if (!(file >> radius)) {
                        std::cout << "Тестирование провалено. Неправильное описание круга в файле" << std::endl;
                        check = false;
                        file.clear();
                        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    newFigure = new Circle(abs(radius));
                }
                else if (identifier == 'r' || identifier == 'R') {
                    double width, height;
                    if (!(file >> width >> height)) {
                        std::cout << "Тестирование провалено. Неправильное описание прямоугольника в файле" << std::endl;
                        check = false;
                        file.clear();
                        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    newFigure = new Rectangle(abs(width), abs(height));
                }
                else if (identifier == 't' || identifier == 'T') {
                    double upperBase, lowerBase, height1;
                    if (!(file >> upperBase >> lowerBase >> height1)) {
                        check = false;
                        std::cout << "Тестирование провалено. Неправильное описание трапеции в файле" << std::endl;
                        file.clear();
                        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    newFigure = new Trapecium(abs(upperBase), abs(lowerBase), abs(height1));
                }
                else {
                    std::cout << "Тестирование провалено. Неправильное обозначение фигуры в файле" << std::endl;
                    check = false;
                    file.clear();
                    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                MyVectors::Figures.push_back(newFigure);
            }
            else {
                //std::cout << "Ошибка: Неправильное обозначение фигуры в файле" << std::endl;
                check = false;
                file.clear();
                file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        file.close();
    }
    if (MyVectors::Figures.empty()) {
        check = false;
        std::cout << "Тестирование провалено. Ни одна фигура не была записана" << std::endl;
    }
    if (check) {
        std::cout << "Тестирование прошло успешно." << std::endl;
        ClearData();
    }
}