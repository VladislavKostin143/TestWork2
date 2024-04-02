#include <iostream>
#include <string>

using namespace std;

//T IsValue() {
//	T userInput{};
//	cin >> userInput;
//	if (userInput <= 0 || cin.fail()) {
//		cout << "¬веденные вами символы либо не €вл€ютс€ числом, либо €вл€ютс€ числом меньше 0.\nѕовторите ввод: ";
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
		cout << "¬веденные вами символы либо не €вл€ютс€ числом, либо €вл€ютс€ числом не равным 1 или 2.\n¬ведите корректное число: ";
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
		cout << "¬веденные вами символы либо не €вл€ютс€ числом, либо €вл€ютс€ числом меньше 0.\n¬ведите корректное число: ";
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
