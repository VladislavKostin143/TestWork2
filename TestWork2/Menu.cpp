#include <iostream>
#include <clocale>
#include "Functions.h"
#include "FunctionsForData.h"
#include "FunctionsForFiles.h"
#include "Figures.h"
#include "Test.h"

using namespace std;

enum Choice { console = 1, read, show, clear, test, end };

void Welcome() {
    cout << "Main.cpp\nКонтрольная работа № 2.\nСтудент группы 4305, Хан София Андреевна. Вариант 18\n2024 год\n" << endl;
    cout << "Вариант 5. Создать базовый класс фигура, производные классы: круг, прямоугольник, трапеция.\nОпределить виртуальные функции для вычисления площади ипериметра.\n" << endl;
};

void MenuOptions() {
    cout << "Все отрицательные числа будут взяты по модулю." << endl;
    cout << "1. Ввести с консоли;\n2. Прочитать из файла;\n3. Показать список объектов;\n4. Очистить список оъектов;\n5. Запустить тестирование\n6. Выйти из программы." << endl;
    cout << "Сделайте выбор: ";
};

void Menu() {
    setlocale(LC_CTYPE, "Russian");
    int MyChoice;
    bool MyExit = false;
    bool save = false;
    ofstream file;
    string filename;
    Welcome();
    while (!MyExit) {
        MenuOptions();
        MyChoice = IsInt();
        switch (MyChoice) {
            case Choice::console:
                ConsoleInput();
                save = AskPermission();
                if (save) {
                    FileExists();
                }
                break;
            case Choice::read:
                LoadFiguresFromFile();
                //for (Figure* fig : MyVectors::Figures) {
                //    fig->Display();
                //}
                break;
            case Choice::show:
                if (MyVectors::Figures.empty()) {
                    cout << "Список пуст.\n" << endl;
                }
                else {
                    for (Figure* fig : MyVectors::Figures) {
                        fig->Display();
                    }
                    cout << "\n";
                }
                break;
            case Choice::clear:
                if (MyVectors::Figures.empty()) {
                    cout << "Список пуст.\n" << endl;
                }
                else {
                    ClearData();
                    cout << "Список очищен.\n" << endl;
                }
                break;
            case Choice::test:
                Test();
                break;
            case Choice::end:
                cout << "Завершение работы" << endl;
                ClearData();
                MyExit = true;
                break;
            default:
                cout << "Пункт отсутствует в меню.\n" << endl;
                break;
        }
    }
}