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
    cout << "Main.cpp\n����������� ������ � 2.\n������� ������ 4305, ��� ����� ���������. ������� 18\n2024 ���\n" << endl;
    cout << "������� 5. ������� ������� ����� ������, ����������� ������: ����, �������������, ��������.\n���������� ����������� ������� ��� ���������� ������� ����������.\n" << endl;
};

void MenuOptions() {
    cout << "��� ������������� ����� ����� ����� �� ������." << endl;
    cout << "1. ������ � �������;\n2. ��������� �� �����;\n3. �������� ������ ��������;\n4. �������� ������ �������;\n5. ��������� ������������\n6. ����� �� ���������." << endl;
    cout << "�������� �����: ";
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
                    cout << "������ ����.\n" << endl;
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
                    cout << "������ ����.\n" << endl;
                }
                else {
                    ClearData();
                    cout << "������ ������.\n" << endl;
                }
                break;
            case Choice::test:
                Test();
                break;
            case Choice::end:
                cout << "���������� ������" << endl;
                ClearData();
                MyExit = true;
                break;
            default:
                cout << "����� ����������� � ����.\n" << endl;
                break;
        }
    }
}