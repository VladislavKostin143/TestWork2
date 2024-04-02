#include <iostream>
#include <fstream>
#include "Figures.h"
#include "Functions.h"
#include "FunctionsForFiles.h"

using namespace std;

enum Shape { circle = 1, rectangle, trapecium, end };

void FigureOptions() {
    cout << "Какую фигуру ходите ввести?\n1 - круг;\n2 - прямоугольник;\n3 - трапеция." << endl;
}

void ClearData() {
    for (Figure* fig : MyVectors::Figures) {
        if (fig) {
            delete fig;
            fig = nullptr;
        }
    }
    MyVectors::Figures.clear();
}

bool AskForMore() {
    int choice;
    cout << "Хотите ввести еще фигуру? (да - 1/нет - 2): ";
    choice = CheckForQuestion();
    if (choice == 1) return true;
    else return false;
}

bool AskPermission() {
    cout << "Хотите ли сохранить данные? (да - 1/нет - 2): ";
    int MyAnswer = CheckForQuestion();
    if (MyAnswer == 1) return true;
    else return false;
}

void ConsoleInput() {
    int MyOption;
    string filename;
    ofstream file;
    bool MyExit = false;
    bool more = false;
    double input1, input2, input3;
    while (!MyExit) {
        FigureOptions();
        MyOption = IsInt();
        switch (MyOption) {
        case Shape::circle: {
            cout << "Введите радиус: ";
            input1 = IsDouble();
            MyVectors::Figures.push_back(new Circle(input1));
            more = AskForMore();
            if (more) break;
            else MyExit = true;
            break;
        }
        case Shape::rectangle: {
            cout << "Введите высоту: ";
            input1 = IsDouble();
            cout << "Введите ширину: ";
            input2 = IsDouble();
            MyVectors::Figures.push_back(new Rectangle(input1, input2));
            more = AskForMore();
            if (more) {
                break;
            }
            else {
                MyExit = true;
            }
            break;
        }
        case Shape::trapecium: {
            cout << "Введите верхнее основание: ";
            input1 = IsDouble();
            cout << "Введите нижнее основание: ";
            input2 = IsDouble();
            cout << "Введите высоту: ";
            input3 = IsDouble();
            MyVectors::Figures.push_back(new Trapecium(input1, input2, input3));
            more = AskForMore();
            if (more) {
                break;
            }
            else {
                MyExit = true;
            }
            break;
        }
        default:
            cout << "Пункт отсутствует в меню." << endl;
        }
    }
};

