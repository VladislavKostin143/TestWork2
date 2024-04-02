#include <iostream>
#include <string>

using namespace std;

//T IsValue() {
//	T userInput{};
//	cin >> userInput;
//	if (userInput <= 0 || cin.fail()) {
//		cout << "��������� ���� ������� ���� �� �������� ������, ���� �������� ������ ������ 0.\n��������� ����: ";
//		while (cin.fail()) {
//			cin.clear();
//			cin.ignore(INT_MAX, '\n');
//			cin >> userInput;
//		}
//	}
//	cin.ignore(INT_MAX, '\n');
//	return abs(userInput);
//}

int CheckForQuestion() {
	int x;
	cin >> x;
	while (x < 1 || x > 2 || cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "��������� ���� ������� ���� �� �������� ������, ���� �������� ������ �� ������ 1 ��� 2.\n������� ���������� �����: ";
		cin >> x;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return x;
}

template<typename T>
T IsValue() {
	T x;
	cin >> x;
	while (x <= 0 || cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "��������� ���� ������� ���� �� �������� ������, ���� �������� ������ ������ 0.\n������� ���������� �����: ";
		cin >> x;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return x;
}

int IsInt() {
    return IsValue<int>();
}

double IsDouble() {
    return IsValue<double>();
}
