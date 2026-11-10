#include <iostream>
#include <random>
using namespace std;

void zeroToFiveEvent(int &money,int &happiness ){
	int numberEvents = 5;
	int currentEvent = 0;
	currentEvent = rand() % numberEvents + 1;
	switch (currentEvent) {
	case 1:

		return;
		break;
	case 2:

		return;
		break;
	case 3:

		return;
		break;
	case 4:

		return;
		break;
	case 5:

		return;
		break;
	default:

		return;
		break;
	}
}





int main() {
	string name;
	int gender;
	int age = 0;
	int money = 0;
	int happiness = 0;
	cout << "insert your name: " << endl;
	cin >> name;
	cout << "male(1) or female(2)" << endl;
	cin >> gender;
	system("cls");
	cout << "Welcome to life " << name << endl;
	cout << age;
	cout << money;
	cout << happiness;
	cout << "Press enter to grow one year.";

	while (age <= 5) {
		cout << age;
		cout << money;
		cout << happiness;
		cout << "Press enter to grow one year.";
		zeroToFiveEvent(money,happiness);
		age++;
	}

	return 0;
}