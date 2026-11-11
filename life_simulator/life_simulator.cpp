#include <iostream>
#include <random>
#include <ctime>
using namespace std;

struct Friends {
	string name;
	int gender;
	//other
};

void zeroToFiveEvent(int &health,int &money,int &happiness ){
	bool sport = false;
	int numberEvents = 7;
	int currentEvent = 0;
	while (true) {
		currentEvent = rand() % numberEvents + 1;
		if (sport == true && currentEvent) {
			continue;
		}
		else {
			break;
		}
	}
	switch (currentEvent) {//friends,skills,sports
	case 1: {
		cout << "You received a toy train from your grandma" << endl;
		cout << "+5 happiness" << endl;
		happiness += 5;
		return;
		break;
	}
	case 2: {
		int choice;
		int hurt = 1;
		while (true) {
			cout << "You see a cat in your backyard" << endl << "Do you pet him?(1.yes 2.no)" << endl;
			cin >> choice;
			hurt = rand() % 2;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Insert a valid coordinate" << endl;
				continue;
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (choice == 2) {
				cout << "You watch the cat play by himself" << endl;
				return;
			}
			else if (choice == 1) {
				if (hurt == 0) {
					cout << "The cat scratched you" << endl;
					cout << "-5 health" << endl;
					health -= 5;
					return;
				}
				else if (hurt == 1) {
					cout << "You play all day with the cat" << endl;
					cout << "+5 happiness" << endl;
					happiness += 5;
					return;
				}
			}
			else {
				cout << "insert a valid action" << endl;
				continue;
			}
		}
		return;
		break;
	}
	case 3: {
		int choice;
		cout << "You play with a child in kindergarden" << endl;
		while (true) {
			cout << "Do you want to become friend?(1.yes 2.no)" << endl;
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Insert a valid coordinate" << endl;
				continue;
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (choice == 1) {
				//adding frieds
				return;
			}
			else if (choice == 2) {
				cout << "You decide to play by yourself" << endl;
				cout << "-5 happiness" << endl;
				happiness -= 5;
				return;
			}
			else {
				cout << "Insert a valid action" << endl;
				continue;
			}
		}
		return;
		break;
	}
	case 4: {
		cout << "You eat a candy from the ground and get sick" << endl;
		cout << "-10 health" << endl;
		health -= 10;
		return;
		break;
	}
	case 5: {
		cout << "You jump in a puddle but fall" << endl;
		cout << "-2 health" << endl;
		health -= 2;
		return;
		break;
	}
	case 6: {
		cout << "You learn to ride the bike" << endl;
		cout << "+1 skill" << endl;
		//adding skill system
		return;
		break;
	}
	case 7: {
		int choice;
		cout << "You go with your dad at a football game." << endl;
		while (true) {
			cout << "Do tou decide to begin playing football?(1.yes 2.no)" << endl;
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Insert a valid coordinate" << endl;
				continue;
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (choice == 1) {
				//adding sport system
				//adding football
				sport = true;
				return;
			}
			else if (choice == 2) {
				cout << "You decide that football isn't your thing" << endl;
				return;
			}
			else {
				cout << "Insert a avlid action" << endl;
				continue;
			}
		}
		return;
		break;
	}
	case 8: {
		int choice;
		cout << "You go with your dad at a basket game." << endl;
		while (true) {
			cout << "Do tou decide to begin playing basket?(1.yes 2.no)" << endl;
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Insert a valid action" << endl;
				continue;
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (choice == 1) {
				//adding sport system
				//adding basket
				sport = true;
				return;
			}
			else if (choice == 2) {
				cout << "You decide that basket isn't your thing" << endl;
				return;
			}
			else {
				cout << "Insert a avlid action" << endl;
				continue;
			}
		}
		return;
		break;
	}
	case 9: {
		int choice;
		cout << "You go with your dad at a volleyball game." << endl;
		while (true) {
			cout << "Do tou decide to begin playing volleyball?(1.yes 2.no)" << endl;
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Insert a valid action" << endl;
				continue;
			}
			else {
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (choice == 1) {
				//adding sport system
				//adding volleyball
				sport = true;
				return;
			}
			else if (choice == 2) {
				cout << "You decide that volleyball isn't your thing" << endl;
				return;
			}
			else {
				cout << "Insert a avlid action" << endl;
				continue;
			}
		}

	}
	default:
		return;
		break;
	}
}





int main() {
	srand(time(nullptr));
	string name;
	int gender;
	int age = 0;
	int health = 100;
	int money = 0;
	int happiness = 50;
	cout << "insert your name: " << endl;
	cin >> name;
	while (true) {
		cout << "male(1) or female(2)" << endl;
		cin >> gender;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Insert a valid coordinate" << endl;
			continue;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (gender == 1 || gender == 2) {
				break;
			}
			else {
				cout << "insert a valid action" << endl;
			}
		}
	}
	system("cls");
	cout << "Welcome to life " << name << endl;
	cout << "Age:       " << age << endl;
	cout << "Health:    " << health << endl;
	cout << "Money:     " << money << endl;
	cout << "Happiness: " << happiness << endl;
	cout << "Press enter to grow one year."<<endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	system("cls");

	while (age < 5) {
		zeroToFiveEvent(health,money, happiness);
		age++;
		cout << "Age:       " << age << endl;
		cout << "Health:    " << health << endl;
		cout << "Money:     " << money << endl;
		cout << "Happiness: " << happiness << endl;
		cout << "Press enter to grow one year."<<endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		system("cls");
	}

	return 0;
}