// TestWork2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <Windows.h>
#include "Figures.h"
#include "Menu.h"
#include "FunctionsForData.h"

using namespace std;

vector <Figure*>  MyVectors::Figures = {};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Menu();
}
