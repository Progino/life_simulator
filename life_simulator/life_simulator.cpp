#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <limits>
using namespace std;

struct Person {
	string name;
	int gender;//1 male, 2 female
	int age;
};
string maleNames[25]{ "Liam", "Noah", "Oliver", "James", "Elijah",
  "Mateo", "Theodore", "Henry", "Lucas", "William",
  "Benjamin", "Alexander", "Daniel", "Jackson", "Sebastian",
  "Jack", "Owen", "Samuel", "Julian", "Asher",
  "Leo", "Luke", "Gabriel", "Atlas", "Finn" };
string femaleNames[25]{ "Olivia", "Emma", "Charlotte", "Amelia", "Sophia",
  "Mia", "Isabella", "Ava", "Evelyn", "Luna",
  "Harper", "Camila", "Sofia", "Scarlett", "Elizabeth",
  "Eleanor", "Emily", "Chloe", "Mila", "Violet",
  "Penelope", "Gianna", "Aria", "Abigail", "Ella" };
vector<string> skills;
bool death = false;

int happinessDeathControl(int happiness, int& health) {
	if (happiness <= 0) {
		happiness = 0;
		health--;
		cout << "You are depressed" << endl;
		cout << "-1 health" << endl;
	}
	else if (happiness >= 100) {
		happiness = 100;
	}
	if (health > 100) {
		health = 100;
		return health;
	}
	else if (health <= 0) {
		death = true;
		return 0;
	}
	else {
		return happiness;
	}
}

int generatePerson(Person p[], int position,int age) {
	string name;
	int gender;
	int newAge = age;
	int n;
	gender = rand() % 2 + 1;
	if (gender == 1) {
		n = rand() % 25;
		name = maleNames[n];
	}
	else if (gender == 2) {
		n = rand() % 25;
		name = femaleNames[n];
	}
	n = rand() % 5 - 2;
	newAge += n;
	if (newAge < 0) newAge = 0;

	p[position].name = name;
	p[position].gender = gender;
	p[position].age = newAge;
	position++;
	return position;
}

void recap0To5(string name, int age, int health, int money, int happiness, vector<string> skills, string sport, Person friends[], int fPosition) {
	cout << "           " << name << endl;
	cout << "Age:       " << age << endl;
	cout << "Health:    " << health << endl;
	cout << "Money:     " << money << endl;
	cout << "Happiness: " << happiness << endl;
	if (!skills.empty()) {
		cout << "Skills:    " << skills[0] << endl;
		for (int i = 1;i < skills.size();i++) {
			cout << "           " << skills[i] << endl;
		}
	}

	if (sport != "") {
		cout << "sport:     " << sport << endl;
	}
	if (friends[0].name != "") {
		cout << "friends:   " << friends[0].name << endl;;
		for (int i = 1;i < fPosition; i++) {
			cout << "           " << friends[i].name << endl;
		}
	}
}

int menu0To5() {
	int choice;
	while (true) {
		cout << "1. got to the park(+5 happiness)" << endl;
		cout << "2. go to the doctor(+10 health) " << endl;
		cout << "3. see stats" << endl;
		cout << "4. grow one year" << endl;
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Insert a valid action" << endl;
			continue;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return choice;
		}
	}
}


void zeroToFiveEvent(int &health,int &money,int &happiness, int age,Person f[],int &position,string &sp) {
	int numberEvents = 10;
	int currentEvent = 0;
	while (true) {
		currentEvent = rand() % numberEvents + 1;
		if (sp != "" && (currentEvent >= 7 && currentEvent <=9)) {
			continue;
		}
		else {
			break;
		}
	}
	switch (currentEvent) {
	case 1: {
		cout << "You received a toy train from your grandma" << endl;
		cout << "+5 happiness" << endl;
		happiness += 5;
		happiness = happinessDeathControl(happiness, health);
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
				happiness = happinessDeathControl(happiness, health);
				return;
			}
			else if (choice == 1) {
				if (hurt == 0) {
					cout << "The cat scratched you" << endl;
					cout << "-5 health" << endl;
					health -= 5;
					happiness = happinessDeathControl(happiness, health);
					return;
				}
				else if (hurt == 1) {
					cout << "You play all day with the cat" << endl;
					cout << "+5 happiness" << endl;
					happiness += 5;
					happiness = happinessDeathControl(happiness, health);
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
				if (position < 10) {
					position = generatePerson(f, position, age);
					cout << "You made a friend:" << endl;
					cout << "Name: " << f[position - 1].name << endl;
					cout << "Age:  " << f[position - 1].age << endl << endl;
					cout << "+5 happiness" << endl;
					happiness += 5;
					happiness = happinessDeathControl(happiness, health);
				}
				else {
					cout << "You can't keep up with all of your friends" << endl;
					cout << "So you forget immediatley about him/her" << endl;
					happiness = happinessDeathControl(happiness, health);
				}
				return;
			}
			else if (choice == 2) {
				cout << "You decide to play by yourself" << endl;
				cout << "-5 happiness" << endl;
				happiness -= 5;
				happiness = happinessDeathControl(happiness, health);
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
		happiness = happinessDeathControl(happiness, health);
		return;
		break;
	}
	case 5: {
		cout << "You jump in a puddle but fall" << endl;
		cout << "-2 health" << endl;
		health -= 2;
		happiness = happinessDeathControl(happiness, health);
		return;
		break;
	}
	case 6: {
		cout << "You learn to ride the bike" << endl;
		cout << "+1 skill" << endl;
		happiness = happinessDeathControl(happiness, health);
		bool alreadyLearned = false;
		for (int i = 0;i < skills.size();i++) {
			if (skills[i] == "bike") {
				alreadyLearned = true;
				break;
			}
		}
		if (!alreadyLearned) {
			skills.push_back("bike");
		}
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
				cout << "You start playing football" << endl;
				sp = "football";
				happiness = happinessDeathControl(happiness, health);
				return;
			}
			else if (choice == 2) {
				cout << "You decide that football isn't your thing" << endl;
				happiness = happinessDeathControl(happiness, health);
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
				cout << "You start playing basketball" << endl;
				happiness = happinessDeathControl(happiness, health);
				sp = "basket";
				return;
			}
			else if (choice == 2) {
				cout << "You decide that basket isn't your thing" << endl;
				happiness = happinessDeathControl(happiness, health);
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
				cout << "You start playing volleyball" << endl;
				happiness = happinessDeathControl(happiness, health);
				sp = "volleyball";
				return;
			}
			else if (choice == 2) {
				cout << "You decide that volleyball isn't your thing" << endl;
				happiness = happinessDeathControl(happiness, health);
				return;
			}
			else {
				cout << "Insert a avlid action" << endl;
				continue;
			}
		}

	}
	case 10: {
		int choice;
		cout << "You see a pencilcase full of colored pens." << endl;
		while (true) {
			cout << "Do you take them?(1.yes 2.no)" << endl;
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
				bool alreadyLearned = false;
				for (int i = 0;i < skills.size();i++) {
					if (skills[i] == "drawing") {
						alreadyLearned = true;
						break;
					}
				}
				if (!alreadyLearned) {
					cout << "You learn to draw" << endl;
					cout << "+1 skill" << endl;
					skills.push_back("drawing");
					happiness = happinessDeathControl(happiness, health);
				}
				return;
			}
			else if (choice == 2) {
				cout << "You decide not to take them" << endl;
				happiness = happinessDeathControl(happiness, health);
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
	Person friends[10];
	int fPosition = 0;
	string sport;
	cout << "insert your name: " << endl;
	cin >> name;
	while (true) {
		cout << "male(1) or female(2)" << endl;
		cin >> gender;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Insert a valid action" << endl;
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
	while (age <= 5) {
		bool Grow = false;
		zeroToFiveEvent(health, money, happiness, age,friends,fPosition,sport);
		age++;
		bool park = false;
		bool doctor = false;
		while (true) {
			int choice = menu0To5();
			switch (choice) {
			case 1:
				if (!park && !doctor) {
					cout << "+5 happiness" << endl;
					happiness += 5;
					happiness = happinessDeathControl(happiness, health);
					park = true;
				}
				else if(park){
					cout << "You already went to the park" << endl;
					cout << "Wait one year for the next action" << endl << endl;
				}
				else if (doctor) {
					cout << "You alredy went to the doctor" << endl;
					cout << "Wait one year for the next action" << endl << endl;
				}
				break;
			case 2:
				if (!doctor && !park) {
					cout << "+10 health" << endl;
					health += 10;
					happiness = happinessDeathControl(happiness, health);
					doctor = true;
				}
				else if (park) {
					cout << "You already went to the park" << endl;
					cout << "Wait one year for the next action" << endl << endl;
				}
				else if (doctor) {
					cout << "You alredy went to the doctor" << endl;
					cout << "Wait one year for the next action" << endl << endl;
				}
				break;
			case 3:
				cout << "--------------" << endl;
				cout << "Age:       " << age << endl;
				cout << "Health:    " << health << endl;
				cout << "Money:     " << money << endl;
				cout << "Happiness: " << happiness << endl;
				cout << "--------------" << endl;
				break;
			case 4:
				cout << "Press enter to grow a year" << endl;
				Grow = true;
				break;
			default:
				cout << "Insert a valid action"<<endl;
			}
			if (Grow) {
				break;
			}
		}
		if (death == true) {
			cout << "You died" << endl;
			recap0To5(name,age,health,money,happiness,skills,sport,friends,fPosition);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			return 0;
		}
		system("cls");
	}
	cout << "First five years recap" << endl;
	recap0To5(name, age, health, money, happiness, skills, sport, friends, fPosition);
	return 0;
}