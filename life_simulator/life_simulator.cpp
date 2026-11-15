#include <iostream>
#include <string>
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
		return happiness;
	}
	else if (health <= 0) {
		death = true;
		return 0;
	}
	else {
		return happiness;
	}
}

int inputControl(int min,int max){
	int input;
	while (true) {
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Insert a valid action" << endl;
			continue;
		}
		else if(input < min || input > max){
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "insert a valid number" << endl;
			continue;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
	return input;
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
	cout << endl;
}

int menu0To5() {
	int choice;
	cout << endl;
	cout << "1. got to the park(+5 happiness)" << endl;
	cout << "2. go to the doctor(+10 health) " << endl;
	cout << "3. see stats" << endl;
	cout << "4. grow one year" << endl;
	choice = inputControl(1,4);
	return choice;
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
	}
	case 2: {
		int choice;
		int hurt = 1;
		cout << "You see a cat in your backyard" << endl << "Do you pet him?(1.yes 2.no)" << endl;
		hurt = rand() % 2;
		choice = inputControl(1,2);
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
	}
	case 3: {
		int choice;
		cout << "You play with a child in kindergarden" << endl;
		cout << "Do you want to become friend?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
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
	}
	case 4: {
		cout << "You eat a candy from the ground and get sick" << endl;
		cout << "-10 health" << endl;
		health -= 10;
		happiness = happinessDeathControl(happiness, health);
		return;
	}
	case 5: {
		cout << "You jump in a puddle but fall" << endl;
		cout << "-2 health" << endl;
		health -= 2;
		happiness = happinessDeathControl(happiness, health);
		return;
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
	}
	case 7: {
		int choice;
		cout << "You go with your dad at a football game." << endl;
		cout << "Do tou decide to begin playing football?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
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
	}
	case 8: {
		int choice;
		cout << "You go with your dad at a basket game." << endl;
		cout << "Do tou decide to begin playing basket?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
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
	}
	case 9: {
		int choice;
		cout << "You go with your dad at a volleyball game." << endl;
		cout << "Do tou decide to begin playing volleyball?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
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
	}
	case 10: {
		int choice;
		cout << "You see a pencilcase full of colored pens." << endl;
		cout << "Do you take them?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
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
	}
	default:
		return;
	}
}

int mathProblem() {
	int firstN = 4;
	int secondN = 3;
	int result;
	int signI = rand() % 4;
	string sign;
	switch (signI) {
	case 0:
		sign = "+";
		break;
	case 1:
		sign = "-";
		break;
	case 2:
		sign = "x";
		break;
	case 3:
		sign = "/";
		break;
	}
	if (sign == "+" || sign == "-") {
		while(firstN < secondN){
			firstN = rand() % 100;
			secondN = rand() % 100;
		}
		if (sign == "+") {
			result = firstN + secondN;
		}
		else if (sign == "-") {
			result = firstN - secondN;
		}
	}
	else if (sign == "x") {
		firstN = rand() % 10 + 1;
		secondN = rand() % 10 + 1;
		result = firstN * secondN;
	}
	else if (sign == "/") {
		while (firstN % secondN != 0) {
			firstN = rand() % 10 + 1;
			secondN = rand() % 10 + 1;
		}
		result = firstN / secondN;
	}
	cout << firstN << " " << sign << " " << secondN << " = ?" << endl;
	return result;
}

void school(int& health, int& money, int& happiness,int &iq, int age, Person f[], int& position, string& sp) {
	//elementary 6-11, middle school 11-14, highschool 14-
	int numberEvents = 9;
	int currentEvent = 0;
	currentEvent = rand() % numberEvents + 1;
	if (age >= 6 && age <= 11) {
		switch (currentEvent) {
		case 1: {
			int choice;
			cout << "The teacher makes you change seat" << endl;
			cout << "Do you talk with your new seatmate?(1.yes 2.no)" << endl;
			choice = inputControl(1,2);
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
				cout << "You decide to stay silent and focus on the lesson" << endl;
				cout << "+1 iq" << endl;
				iq++;
				happiness = happinessDeathControl(happiness, health);
				return;
			}
		}
		case 2: {
			cout << "Today is the birthday of one of your classmate" << endl;
			cout << "And they brougth cake for everyone" << endl;
			cout << "+5 happiness" << endl;
			happiness += 5;
			happiness = happinessDeathControl(happiness, health);
			return;
		}
		case 3: {
			int choice;
			cout << "Today you go on a trip to a musem" << endl;
			cout << "The museum is about dinosaurs" << endl;
			cout << "Are you interested?(1.yes 2.no)" << endl;
			choice = inputControl(1,2);
			if (choice == 1) {
				cout << "+1 skill (archeology)" << endl;
				cout << "+5 iq" << endl;
				iq += 5;
				happiness = happinessDeathControl(happiness, health);
				bool alreadyLearned = false;
				for (int i = 0;i < skills.size();i++) {
					if (skills[i] == "archeology") {
						alreadyLearned = true;
						break;
					}
				}
				if (!alreadyLearned) {
					skills.push_back("archeology");
				}
				return;
			}
			else if (choice == 2) {
				cout << "You just watch bones for an entire day" << endl;
				cout << "+1 iq" << endl;
				iq++;
				happiness = happinessDeathControl(happiness, health);
				return;
			}
		}
		case 4: {
			cout << "Today ther is a math test" << endl;
			cout << "Are you ready?" << endl;
			cin.get();
			int score = 0;
			for(int i=1;i<=5;i++)  {
				int ans;
				int result = mathProblem();
				ans = inputControl(0,300);
				if (ans == result) {
					cout << "correct" << endl;
					score++;
					continue;
				}
				else {
					cout << "wrong" << endl;
					continue;
				}
			}
			cout << "Your score is: " << score << "/5" << endl;
			if (score == 5) {
				iq += 7;
				cout << "+7 iq" << endl;
				cout << "+1 skill(math)" << endl;
				bool alreadyLearned = false;
				for (int i = 0;i < skills.size();i++) {
					if (skills[i] == "math") {
						alreadyLearned = true;
						break;
					}
				}
				if (!alreadyLearned) {
					skills.push_back("math");
				}
				return;
			}
			else if (score >= 3 && score <= 4) {
				iq += 3;
				cout << "+3 iq" << endl;
				return;
			}
			else if (score <= 2) {
				cout << "-4 happiness" << endl;
				happiness -= 4;
				happiness = happinessDeathControl(happiness, health);
				return;
			}
		}
		case 5: {
			cout << "You go to the toilet but the door locks you in" << endl;
			cout << "-7 happiness" << endl;
			happiness -= 7;
			happiness = happinessDeathControl(happiness, health);
			return;
		}
		case 6: {
			string capital;
			cout << "You get called at the blackboard" << endl;
			cout << "What is the capital of France?" << endl;
			cin >> capital;
			if (capital == "Paris" || capital == "paris") {
				cout << "You got it correctly" << endl;
				cout << "+2 iq" << endl;
				iq += 2;
				return;
			}
			else {
				cout << "Wrong. The answer was 'Paris'" << endl;
				cout << "-1 iq" << endl;
				iq--;
				return;
			}
		}
		case 7: {
			cout << "You got a flue and had to stay home" << endl;
			cout << "-8 health" << endl;
			health -= 8;
			happiness = happinessDeathControl(happiness, health);
			return;
		}
		case 8: {
			string place;
			cout << "At recess you decide to play with someone" << endl;
			cout << "where do you want to play?" << endl;
			cin >> place;
			if (position == 0) {
				cout << "You go to play at the " << place << "." << endl;
				cout << "You make a new friend" << endl;
				position = generatePerson(f, position, age);
				cout << "Your new friend is " << f[position - 1].name << endl;
				return;
			}
			else {
				int person = rand() % position;
				cout << "You go to play at the " << place << "." << endl;
				cout << "You play all recess with " << f[person].name << endl;
				return;
			}
		}
		case 9: {
			int rank = rand() % 5 + 1;
			if (sp != "") {
				cout << "The school host a " << sp << " tournament" << endl;
				switch (rank) {
				case 1:
					cout << "You win the enire tournament" << endl;
					cout << "+15 happiness" << endl;
					cout << "+20 money" << endl;
					happiness += 15;
					money += 20;
					happiness = happinessDeathControl(happiness, health);
					return;
				case 2:
					cout << "You got second" << endl;
					cout << "+6 happiness" << endl;
					cout << "+10 money" << endl;
					happiness += 6;
					money += 10;
					happiness = happinessDeathControl(happiness, health);
					return;
				case 3:
					cout << "You got third" << endl;
					cout << "+10 happiness" << endl;
					cout << "+5 money" << endl;
					happiness += 10;
					money += 5;
					happiness = happinessDeathControl(happiness, health);
					return;
				case 4:
					cout << "You got fifth" << endl;
					cout << "+2 happiness" << endl;
					happiness += 2;
					happiness = happinessDeathControl(happiness, health);
					return;
				case 5:
					cout << "You got last" << endl;
					cout << "-10 happiness" << endl;
					happiness -= 10;
					happiness = happinessDeathControl(happiness, health);
					return;
				}
			}
			else {
				cout << "The school host a basketball tournament" << endl;
				if (position > 0) {
					cout << "You watch it with your friend" << f[rand() % position].name << endl;
					cout << "+10 happiness" << endl;
					happiness += 10;
					happiness = happinessDeathControl(happiness, health);
				}
				else {
					cout << "You watch it from the stands" << endl;
					cout << "+5 happiness" << endl;
					happiness += 5;
					happiness = happinessDeathControl(happiness, health);
				}
				return;
			}
		}
		default:
			return;
		}
	}
	else if (age >= 12 && age <= 14) {
		//work in progress
	}
	else if (age >= 15 && age <= 18) {
		//work in progress
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
	int iq = 0;
	Person friends[10];
	int fPosition = 0;
	string sport;
	cout << "insert your name: " << endl;
	cin >> name;
	cout << "male(1) or female(2)" << endl;
	gender = inputControl(1,2);
	system("cls");
	cout << "Welcome to life " << name << endl<<endl;
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
				else if (park) {
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
	cout << "Press enter to start school" << endl;
	cin.get();
	system("cls");
	cout << "Welcome to school" << endl<<endl;
	while (age >= 6 && age <= 11) {
		bool Grow = false;
		school(health, money, happiness, iq,age, friends, fPosition, sport);
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
				else if (park) {
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
				cout << "IQ         " << iq << endl;
				cout << "Money:     " << money << endl;
				cout << "Happiness: " << happiness << endl;
				cout << "--------------" << endl;
				break;
			case 4:
				cout << "Press enter to grow a year" << endl;
				Grow = true;
				break;
			default:
				cout << "Insert a valid action" << endl;
			}
			if (Grow) {
				break;
			}
		}
		if (death == true) {
			cout << "You died" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			return 0;
		}
		system("cls");
		
	}
	cout << "You finished elementary school" << endl<<endl;
	cout << "Middle school is work in proress" << endl;
	return 0;
}