#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include "Functions.h"
#include "Figures.h"

void FileExists() {
    std::string pathToFile; int choiceRewrite = 0;
    std::cout << "������� ���� � �����: ";
    getline(std::cin, pathToFile);
    do {
        if (std::filesystem::exists(pathToFile)) {
            std::cout << "����� ���� ��� ����������.\n1 - ������������\n2 - �������� ����� ����: ";
            choiceRewrite = IsInt();
            if (choiceRewrite == 1) {
                std::ofstream outputFile(pathToFile);
                if (!outputFile.is_open()) {
                    std::cout << "�� ������� ������� ����!" << std::endl;
                    break;
                }
                else {
                    for (auto& fig : MyVectors::Figures) {
                        fig->SaveToFile(outputFile);
                    }
                    outputFile.close();
                    std::cout << "��������� ������ �������� � ����." << std::endl;
                }
                break;
            }
            else if (choiceRewrite == 2) {
                std::cout << "������� ����� ����: ";
                getline(std::cin, pathToFile);
                choiceRewrite = 0;
                continue;
            }
        }
        else {
            std::ofstream outputFile(pathToFile);
            if (!outputFile.is_open()) {
                std::cout << "�� ������� ������� ����." << std::endl;
                break;
            }
            else {
                for (auto& fig : MyVectors::Figures) {
                    fig->SaveToFile(outputFile);
                }
                outputFile.close();
                std::cout << "��������� ������ �������� � ����." << std::endl;
            }
            break;
        }
    } while (choiceRewrite == 0);
}

void LoadFiguresFromFile() {
    std::string filename;
    std::cout << "������� ��� �����: ";
    std::cin >> filename;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "���������� ������� ���� " << filename << " ��� ������." << std::endl;
        return;
    }
    Figure* newFigure;
    char identifier;
    bool check = true;
    while (file >> identifier) {
        if (std::isalpha(identifier)) {
            if (identifier == 'c' || identifier == 'C') {
                double radius;
                if (!(file >> radius)) {
                    std::cout << "������: ������������ �������� ����� � �����" << std::endl;
                    file.clear();
                    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                newFigure = new Circle(abs(radius));
            }
            else if (identifier == 'r' || identifier == 'R') {
                double width, height;
                if (!(file >> width >> height)) {
                    std::cout << "������: ������������ �������� �������������� � �����" << std::endl;
                    file.clear();
                    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                newFigure = new Rectangle(abs(width), abs(height));
            }
            else if (identifier == 't' || identifier == 'T') {
                double upperBase, lowerBase, height1;
                if (!(file >> upperBase >> lowerBase >> height1)) {
                    std::cout << "������: ������������ �������� �������� � �����" << std::endl;
                    file.clear();
                    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                newFigure = new Trapecium(abs(upperBase), abs(lowerBase), abs(height1));
            }
            else {
                std::cout << "������: ������������ ����������� ������ � �����" << std::endl;
                file.clear();
                file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            MyVectors::Figures.push_back(newFigure);
        }
        else {
            //std::cout << "������: ������������ ����������� ������ � �����" << std::endl;
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    file.close();
    if (MyVectors::Figures.empty()) {
        std::cout << "�� ���� ������ �� ���� ��������" << std::endl;
        check = false;
    }
    if (check) {
        std::cout << "���� �������� � ������� ��������." << std::endl;
    }
}