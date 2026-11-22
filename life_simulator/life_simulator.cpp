#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
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
string abilities[8]{ "cycling","art","archeology","math","music","reading","drama","sea"};

struct Player {
	string name;
	int gender = 1;
	int age = 0;
	int health = 100;
	int money = 0;
	int happiness = 50;
	int iq = 0;
	string sport = "";
	vector<string> skills;
	vector<Person> friends;
	bool death = false;
};



void happinessDeathControl(Player& p) {
	if (p.happiness <= 0) {
		p.happiness = 0;
		p.health--;
		cout << "You are depressed" << endl;
		cout << "-1 health" << endl;
	}
	else if (p.happiness >= 100) {
		p.happiness = 100;
	}
	if (p.health > 100) {
		p.health = 100;
		return;
	}
	else if (p.health <= 0) {
		p.death = true;
		return;
	}
	else {
		return;
	}
}

void update(Player &p, int h, int he, int m, int i) {
	if (h != 0) {
		if (h < 0) {
			cout << h << " happiness" << endl;
		}
		else if (h > 0) {
			cout << "+" << h << " happiness" << endl;
		}
		p.happiness += h;
	}
	if (he != 0) {
		if (he < 0) {
			cout << he << " health" << endl;
		}
		else if (he > 0) {
			cout << "+" << he << " health" << endl;
		}
		p.health += he;
	}
	if (m != 0) {
		if (m < 0) {
			cout << m << " dollars" << endl;
		}
		else if (m > 0) {
			cout << "+" << m << " dollars" << endl;
		}
		p.money += m;
		if (p.money < 0) {
			p.money = 0;
		}
	}
	if (i != 0) {
		if (i < 0) {
			cout << i << " iq" << endl;
		}
		else if (i > 0) {
			cout << "+" << i << " iq" << endl;
		}
		p.iq += i;
		if (p.iq < 0) {
			p.iq = 0;
		}
	}
	happinessDeathControl(p);
	return;
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

void addSkills(Player &p,string skill) {
	bool alreadyLearned = false;
	for (int i = 0;i < p.skills.size();i++) {
		if (p.skills[i] == skill) {
			return;
		}
	}
	p.skills.push_back(skill);
	cout << "+1 skill (" << skill << ")" << endl;
}

Person generatePerson(int age) {
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

	Person newPerson;
	newPerson.name = name;
	newPerson.gender = gender;
	newPerson.age = newAge;
	return newPerson;
}

void addFriend(Player &p) {
	if (p.friends.size() < 10) {
		Person newFriend = generatePerson(p.age);
		p.friends.push_back(newFriend);

		cout << "You made a friend:" << endl;
		cout << "Name: " << newFriend.name << endl;
		cout << "Age:  " << newFriend.age << endl << endl;
	}
	else {
		cout << "You can't keep up with all of your friends" << endl;
		cout << "So you forget immediately about him/her" << endl;
	}
}

void recap(const Player &p) {
	cout << "           " << p.name << endl;
	cout << "Age:       " << p.age << endl;
	cout << "Health:    " << p.health << endl;
	cout << "Happiness: " << p.happiness << endl;
	if (p.age > 5) {
		cout << "money      " << p.money << endl;
		cout << "iq         " << p.iq << endl;
	}
	if (!p.skills.empty()) {
		cout << "Skills:    " << p.skills[0] << endl;
		for (int i = 1;i < p.skills.size();i++) {
			cout << "           " << p.skills[i] << endl;
		}
	}

	if (p.sport != "") {
		cout << "sport:     " << p.sport << endl;
	}
	if (!p.friends.empty()) {
		cout << "Friends:   " << p.friends[0].name << endl;
		for (int i = 1; i < p.friends.size(); i++) {
			cout << "           " << p.friends[i].name << endl;
		}
	}
	cout << endl;
}

void stats(const Player& p) {
	cout << "--------------" << endl;
	cout << "Age:       " << p.age << endl;
	cout << "Health:    " << p.health << endl;
	if (p.age > 5) {
		cout << "IQ         " << p.iq << endl;
		cout << "Money:     " << p.money << endl;
	}
	cout << "Happiness: " << p.happiness << endl;
	cout << "--------------" << endl;
}

void menu(Player& p, string happinessS, string healthS) {
	bool happinessDone = false;
	bool healthDone = false;
	while (true) {
		bool grow = false;
		int choice;
		cout << endl;
		cout << "1. go to the " << happinessS << " (+5 happiness)" << endl;
		cout << "2. go to the " << healthS << " (+10 health) " << endl;
		cout << "3. see stats" << endl;
		cout << "4. grow one year" << endl;
		choice = inputControl(1, 4);
		switch (choice) {
		case 1:
			if (!happinessDone && !healthDone) {
				update(p, 5, 0, 0, 0);
				happinessDone = true;
			}
			else if (happinessDone) {
				cout << "You already went to the "<<happinessS << endl;
				cout << "Wait one year for the next action" << endl << endl;
			}
			else if (healthDone) {
				cout << "You already went to the "<<healthS << endl;
				cout << "Wait one year for the next action" << endl << endl;
			}
			break;
		case 2:
			if (!happinessDone && !healthDone) {
				update(p, 0, 10, 0, 0);
				if (p.health > 100) {
					p.health = 100;
				}
				healthDone = true;
			}
			else if (happinessDone) {
				cout << "You already went to the "<<happinessS << endl;
				cout << "Wait one year for the next action" << endl << endl;
			}
			else if (healthDone) {
				cout << "You already went to the "<<healthS << endl;
				cout << "Wait one year for the next action" << endl << endl;
			}
			break;
		case 3:
			stats(p);
			break;
		case 4:
			grow = true;
			break;
		}
		if (grow) {
			break;
		}
	}
	return;
}

void zeroToFiveEvent(Player &p) {
	int numberEvents = 10;
	int currentEvent = 0;
	while (true) {
		currentEvent = rand() % numberEvents + 1;
		if (p.sport != "" && (currentEvent >= 7 && currentEvent <=9)) {
			continue;
		}
		else {
			break;
		}
	}
	switch (currentEvent) {
	case 1: {
		cout << "You received a toy train from your grandma" << endl;
		update(p, 5, 0, 0, 0);
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
			happinessDeathControl(p);
			return;
		}
		else if (choice == 1) {
			if (hurt == 0) {
				cout << "The cat scratched you" << endl;
				update(p, 0, -5, 0, 0);
				return;
			}
			else if (hurt == 1) {
				cout << "You play all day with the cat" << endl;
				update(p, 5, 0, 0,  0);
				return;
			}
		}
	}
	case 3: {
		int choice;
		cout << "You play with a child in kindergarten" << endl;
		cout << "Do you want to become friends?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
		if (choice == 1) {
			addFriend(p);
			cout << endl;
			update(p, 5, 0, 0, 0);
			return;
		}
		else if (choice == 2) {
			cout << "You decide to play by yourself" << endl;
			update(p, 5, 0, 0, 0);
			return;
		}
	}
	case 4: {
		cout << "You eat a candy from the ground and get sick" << endl;
		update(p, 0,-10, 0, 0);
		return;
	}
	case 5: {
		cout << "You jump in a puddle but fall" << endl;
		update(p, 0, -2, 0, 0);
		return;
	}
	case 6: {
		cout << "You learn to ride the bike" << endl;
		addSkills(p,"cycling");
		happinessDeathControl(p);
		return;
	}
	case 7: {
		int choice;
		cout << "You go with your dad at a football game." << endl;
		cout << "Do you decide to begin playing football?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
		if (choice == 1) {
			cout << "You start playing football" << endl;
			p.sport = "football";
			happinessDeathControl(p);
			return;
		}
		else if (choice == 2) {
			cout << "You decide that football isn't your thing" << endl;
			happinessDeathControl(p);
			return;
		}
	}
	case 8: {
		int choice;
		cout << "You go with your dad at a basketball game." << endl;
		cout << "Do you decide to begin playing basketball?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
		if (choice == 1) {
			cout << "You start playing basketball" << endl;
			happinessDeathControl(p);
			p.sport = "basket";
			return;
		}
		else if (choice == 2) {
			cout << "You decide that basketball isn't your thing" << endl;
			happinessDeathControl(p);
			return;
		}
	}
	case 9: {
		int choice;
		cout << "You go with your dad at a volleyball game." << endl;
		cout << "Do you decide to begin playing volleyball?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
		if (choice == 1) {
			cout << "You start playing volleyball" << endl;
			happinessDeathControl(p);
			p.sport = "volleyball";
			return;
		}
		else if (choice == 2) {
			cout << "You decide that volleyball isn't your thing" << endl;
			happinessDeathControl(p);
			return;
		}
	}
	case 10: {
		int choice;
		cout << "You see a pencilcase full of colored pens." << endl;
		cout << "Do you take them?(1.yes 2.no)" << endl;
		choice = inputControl(1,2);
		if (choice == 1) {
			cout << "You learn to draw" << endl;
			addSkills(p,"art");
			happinessDeathControl(p);
			return;
		}
		else if (choice == 2) {
			cout << "You decide not to take them" << endl;
			happinessDeathControl(p);
			return;
		}
	}
	default:
		return;
	}
}

int mathProblem() {
	int firstN = 0;
	int secondN = 0;
	int result = 0;
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
		firstN = 0;
		secondN = 1;
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
		firstN = 4;
		secondN = 3;
		while (firstN % secondN != 0) {
			firstN = rand() % 10 + 1;
			secondN = rand() % 10 + 1;
		}
		result = firstN / secondN;
	}
	cout << firstN << " " << sign << " " << secondN << " = ?" << endl;
	return result;
}

int logicProblem() {
	int problem = rand() % 2;
	switch (problem) {
	case 0: {
		int startN = rand() % 10 + 1;
		int add = rand() % 4 + 1;
		int result = startN;
		for (int i = 0;i < 5; i++) {
			cout << startN << " ";
			startN += add;
			result += add;
		}
		cout << "?" << endl;
		return result;
		}
	case 1: {
		int startN = rand() % 10 + 1;
		int add = rand() % 4 + 1;
		int result = startN;
		for (int i = 0;i < 5; i++) {
			cout << startN << " ";
			startN += add;
			result += add;
			add++;
		}
		cout << "?" << endl;
		return result;
	}
	}
	return 0;
}

int symbolProblem() {
	int firstN = 3;
	int secondN = 4;
	int result = 0;
	int signI = rand() % 4;
	string sign;
	if (signI == 0) {
		sign = "+";
		firstN = rand() % 200;
		secondN = rand() % 200;
		result = firstN + secondN;
	}
	else if (signI == 1) {
		sign = "-";
		while (firstN < secondN) {
			firstN = rand() % 200;
			secondN = rand() % 200;
		}
		result = firstN - secondN;
	}
	else if (signI == 2) {
		sign = "X";
		firstN = rand() % 11;
		secondN = rand() % 11;
		result = firstN * secondN;
	}
	else if (signI == 3) {
		sign = "/";
		while (firstN % secondN != 0) {
			firstN = rand() % 10 + 1;
			secondN = rand() % 10 + 1;
		}
		result = firstN / secondN;
	}
	cout << "Find the value of Y" << endl << endl;
	cout << " Y " << sign << " " << secondN << " = " << result << endl;
	return firstN;
}

int racePosition(int pos) {
	if (pos == 1) {
		int pos = rand() % 5 + 1;
		cout << "You got " << pos << endl;
		return pos;
	}
	else if (pos == 2) {
		int pos = rand() % 15 + 6;
		cout << "You got " << pos << endl;
		return pos;
	}
	else if (pos == 3) {
		int pos = rand() % 20 + 21;
		cout << "You got " << pos << endl;
		return pos;
	}
	return 0;
}

void school(Player &p) {
	//elementary 6-11, middle school 11-14	, highschool 14-18
	int numberEvents = 9;
	int currentEvent = 0;
	currentEvent = rand() % numberEvents + 1;
	if (p.age >= 6 && p.age <= 11) {
		switch (currentEvent) {
		case 1: {
			int choice;
			cout << "The teacher makes you change seat" << endl;
			cout << "Do you talk with your new seatmate?(1.yes 2.no)" << endl;
			choice = inputControl(1,2);
			if (choice == 1) {
				addFriend(p);
				cout << endl;
				update(p, 5, 0, 0, 0);
				return;
			}
			else if (choice == 2) {
				cout << "You decide to stay silent and focus on the lesson" << endl;
				update(p, 0, 0, 0, 1);
				return;
			}
		}
		case 2: {
			cout << "Today is the birthday of one of your classmate" << endl;
			cout << "And they brought cake for everyone" << endl;
			update(p, 5, 0, 0, 0);
			return;
		}
		case 3: {
			int choice;
			cout << "Today you go on a trip to a museum" << endl;
			cout << "The museum is about dinosaurs" << endl;
			cout << "Are you interested?(1.yes 2.no)" << endl;
			choice = inputControl(1,2);
			if (choice == 1) {
				addSkills(p,"archeology");
				update(p ,0, 0, 0, 5);
				return;
			}
			else if (choice == 2) {
				cout << "You just watch bones for an entire day" << endl;
				update(p, 0, 0, 0, 1);
				return;
			}
		}
		case 4: {
			cout << "Today there is a math test" << endl;
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
				addSkills(p,"math");
				update(p, 0, 0, 0, 7);
				return;
			}
			else if (score >= 3 && score <= 4) {
				update(p, 0, 0, 0, 3);
				return;
			}
			else if (score <= 2) {
				update(p, -4, 0, 0, 0);
				return;
			}
		}
		case 5: {
			cout << "You go to the toilet but the door locks you in" << endl;
			update(p, -7, 0, 0, 0);
			return;
		}
		case 6: {
			string capital;
			cout << "You get called at the blackboard" << endl;
			cout << "What is the capital of France?" << endl;
			getline(cin, capital);
			if (capital == "Paris" || capital == "paris") {
				cout << "You got it correctly" << endl;
				update(p, 0, 0, 0, 2);
				return;
			}
			else {
				cout << "Wrong. The answer was 'Paris'" << endl;
				update(p, 0, 0, 0, -1);
				return;
			}
		}
		case 7: {
			cout << "You got a flu and had to stay home" << endl;
			update(p, 0, -8, 0, 0);
			return;
		}
		case 8: {
			string place;
			cout << "At recess you decide to play with someone" << endl;
			cout << "where do you want to play?" << endl;
			getline(cin, place);
			if (p.friends.empty()) {
				cout << "You go to play at the " << place << "." << endl;
				cout << "You make a new friend" << endl;
				addFriend(p);
				cout << endl;
				update(p, 5, 0, 0, 0);
				return;
			}
			else {
				int person = rand() % p.friends.size();
				cout << "You go to play at the " << place << "." << endl;
				cout << "You play all recess with " << p.friends[person].name << endl;
				return;
			}
		}
		case 9: {
			int rank = rand() % 5 + 1;
			if (p.sport != "") {
				cout << "The school is hosting a " << p.sport << " tournament" << endl;
				switch (rank) {
				case 1:
					cout << "You win the entire tournament" << endl;
					update(p, 15, 0, 20, 0);
					return;
				case 2:
					cout << "You got second" << endl;
					update(p, 6, 0, 10, 0);
					return;
				case 3:
					cout << "You got third" << endl;
					update(p, 10, 0, 5, 0);
					return;
				case 4:
					cout << "You got fifth" << endl;
					update(p, 2, 0, 0, 0);
					return;
				case 5:
					cout << "You got last" << endl;
					update(p, -10, 0, 0, 0);
					return;
				}
			}
			else {
				cout << "The school host a basketball tournament" << endl;
				if (!p.friends.empty()) {
					cout << "You watch it with your friend " << p.friends[rand() % p.friends.size()].name << endl;
					update(p, 10, 0, 0, 0);
				}
				else {
					cout << "You watch it from the stands" << endl;
					update(p, 5, 0, 0, 0);
				}
				return;
			}
		}
		}
	}
	else if (p.age >= 12 && p.age <= 14) {
		while (true) {
			currentEvent = rand() % numberEvents + 1;
			if (p.skills.empty() && (currentEvent >= 6 && currentEvent <= 8)) {
				continue;
			}
			else {
				break;
			}
		} 
		switch (currentEvent) {
		case 1: {
			cout << "A school bully corners you in the hallway and demands your lunch money." << endl;
			cout << "What do you do?" << endl;
			cout << "1. You give him the money" << endl;
			cout << "2. you try escaping" << endl;;
			cout << "3. You call your friends" << endl;
			int choice = inputControl(1, 3);
			if (choice == 1) {
				if (p.money <= 0) {
					cout << "You don't have money so the bully slaps you" << endl;
					update(p, -5, -1, 0, 0);
					return;
				}
				else if (p.money <= 5 && p.money >0) {
					cout << "You give him " << p.money << " dollars" << endl;
					p.money = 0;
					return;
				}
				else if (p.money > 5) {
					update(p, 0, 0,-5, 0);
					return;
				}
			}
			else if (choice == 2) {
				int escape = rand() % 2;
				if (escape == 0) {
					cout << "You managed to escape" << endl;
					update(p, 1, 0, 0, 0);
					return;
				}
				else if (escape == 1) {
					cout << "You didn't escape in time and the bully punched you" << endl;
					update(p, -10, -5, 0, 0);
					if (p.money <= 5 && p.money > 0) {
						cout << "He takes from you " << p.money << " dollars" << endl;
						p.money = 0;
					}
					else if (p.money > 5) {
						cout << "He takes from you 5 dollars" << endl;
						update(p, 0, 0, -5, 0);
					}

				}
				return;
			}
			else if (choice == 3) {
				if (p.friends.empty()) {
					cout << "You don't have friends that can defend you" << endl;
					update(p, -5, 0, 0, 0);
					if (p.money <= 5 && p.money > 0) {
						cout << "He takes from you " << p.money << " dollars" << endl;
						p.money = 0;
					}
					else if (p.money > 5) {
						cout << "He takes from you 5 dollars" << endl;
						update(p, 0, 0, -5, 0);
					}
					return;
				}
				else {
					int defend = rand() % 2;
					if (p.friends.size() == 1) {
						if (defend == 0) {
							cout << "Your friend " << p.friends[0].name << " defends you" << endl;
							update(p, 3, 0, 0, 0);
							return;
						}
						else if (defend == 1) {
							cout << "your friend isn't enough" << endl;
							if (p.money <= 5 && p.money > 0) {
								cout << "The bully takes from you " << p.money << " dollars" << endl;
								p.money = 0;
							}
							else if (p.money > 5) {
								cout << "the bully takes from you 5 dollars" << endl;
								update(p, 0, 0, -5, 0);
							}
							update(p, -5, 0, 0, 0);
							return;
						}
					}
					else {
						if (defend == 0) {
							cout << "Your friends ";
							for (int i = 0; i < p.friends.size(); i++) {
								cout << p.friends[i].name << ", ";
							}
							cout << " defend you" << endl;
							update(p, 3, 0, 0, 0);
							return;
						}
						else if (defend == 1) {
							cout << "Your friends aren't enough to get the bully away" << endl;
							if (p.money <= 5 && p.money > 0) {
								cout << "The bully takes from you " << p.money << " dollars" << endl;
								p.money = 0;
							}
							else if (p.money > 5) {
								cout << "the bully takes from you 5 dollars" << endl;
								update(p, 0, 0, -5, 0);
							}
							update(p, -10, 0, 0, 0);
							return;
						}
					}
				}
			}
		}
		case 2: {
			cout << "Today is the school Cross Country race" << endl;
			cout << "The race will be 2 miles" << endl;
			cout << "1. Start fast(high risk)" << endl;
			cout << "2. Keep a steady pace(low risk)" << endl;
			int start = inputControl(1, 2);
			if (start == 1) {
				int stamina = rand() % 10 + 1;
				if (stamina >= 0 && stamina <= 8) {
					cout << "After 1.5 miles you get exhausted" << endl;
					racePosition(3);
					return;
				}
				else if (stamina >= 9) {
					cout << "You manage to resist until the end" << endl;
					racePosition(1);
					update(p, 5, 0, 0, 0);
					return;
				}
			}
			else if (start == 2) {
				cout << "You keep your pace" << endl;
				racePosition(2);
				return;
			}
		}
		case 3: {
			cout << "You ask your Mom for an allowance" << endl;
			cout << "How do you ask?" << endl;
			cout << "1. You ask politely" << endl;
			cout << "2. You complain that all your friends have it" << endl;
			cout << "3. You ask by saying that you have good scores" << endl;
			int choice = inputControl(1, 3);
			switch (choice) {
			case 1: {
				int allowance = rand() % 10;
				if (allowance <= 8) {
					cout << "Your Mom accepts a gives you 20 dollars" << endl;
					update(p, 0, 0, 20, 0);
					return;
				}
				else if (allowance >= 9) {
					cout << "Your Mom says that you are still too small" << endl;
					return;
				}
			}
			case 2: {
				int allowance = rand() % 10;
				if (allowance <= 8) {
					cout << "Your mom gets angry at you" << endl;
					update(p, -4, 0, 0, 0);
					return;
				}
				else if (allowance >= 9) {
					cout << "Your Mom accepts and gives you 10 dollars" << endl;
					update(p, 0, 0, 10, 0);
					return;
				}
			}
			case 3: {
				if (p.iq >= 10) {
					cout << "Your mom accepts and gives you 25 dollars" << endl;
					update(p, 0, 0, 25, 0);
					return;
				}
				else {
					cout << "Your scores aren't high enough" << endl;
					return;
				}
			}
			}
		}
		case 4: {
			cout << "Today you have a logic test" << endl;
			cout << "Are you ready?" << endl;
			cin.get();
			int score = 0;
			for (int i = 0;i < 5;i++) {
				int type = rand() % 2;
				switch (type) {
				case 0: {
					{
						int result = logicProblem();
						int answer = inputControl(0, 400);
						if (result == answer) {
							cout << "Correct" << endl;
							score++;
						}
						else {
							cout << "Wrong" << endl;
						}
					}
					break;
				}
				case 1: {
					int result = symbolProblem();
					int answer = inputControl(0, 400);
					if (result == answer) {
						cout << "Correct" << endl;
						score++;
					}
					else {
						cout << "Wrong" << endl;
					}
					break;
				}
				}
			}
			cout << score << "/5" << endl;
			if (score == 5) {
				update(p, 0, 0, 0, 10);
				return;
			}
			else if (score < 5 && score > 2) {
				update(p, 0, 0, 0, 5);
				return;
			}
			else {
				update(p, 0, 0, 0, -5);
				return;
			}
		}
		case 5: {
			cout << "Your school is organising afternoon clubs" << endl;
			cout << "What club do you want to participate in" << endl << endl;
			cout << "1. music club" << endl;
			cout << "2. art club" << endl;
			cout << "3. math club" << endl;
			cout << "4. book club" << endl;
			cout << "5. drama club" << endl;
			cout << "6. none" << endl;
			int club = inputControl(1, 6);
			switch (club) {
			case 1: {
				cout << "You join the music club" << endl;
				addSkills(p,"music");
				return;
			}
			case 2: {
				cout << "You join the art club" << endl;
				addSkills(p,"art");
				return;
			}
			case 3: {
				cout << "You join the math club" << endl;
				addSkills(p,"math");
				return;
			}
			case 4: {
				cout << "You join the book club" << endl;
				addSkills(p,"reading");
				return;
			}
			case 5: {
				cout << "You join the drama club" << endl;
				addSkills(p,"drama");
				return;
			}
			case 6: {
				cout << "You decide not to bother with clubs" << endl;
				return;
			}
			}
		}
		case 6: {
			cout << "Today is your birthday" << endl;
			string gift = abilities[rand() % (sizeof(abilities) / sizeof(abilities[0]))];
			int pi = -1;
			for (int i = 0; i < (sizeof(abilities) / sizeof(abilities[0]));i++) {
				if (gift == abilities[i]) {
					pi = i;
					break;
				}
			}
			while (true) {
				switch (pi) {
				case -1: {
					pi = rand() % (sizeof(abilities) / sizeof(abilities[0]));
					break;
				}
				case 0: {
					cout << "You receive from your friends a new saddle" << endl;
					addSkills(p,"cycling");
					update(p, 10, 0, 0, 0);
					return;
				}
				case 1: {
					cout << "You receive from your friends new brushes" << endl;
					addSkills(p,"art");
					update(p, 10, 0, 0, 0);
					return;
				}
				case 2: {
					cout << "You receive from your friends some old fossils" << endl;
					addSkills(p,"archeology");
					update(p, 10, 0, 0, 0);
					return;
				}
				case 3: {
					cout << "You receive from your friends the newest calculator model" << endl;
					addSkills(p,"math");
					update(p, 10, 0, 0, 0);
					return;
				}
				case 4: {
					cout << "You receive from your friends new headphones" << endl;
					addSkills(p,"music");
					update(p, 10, 0, 0, 0);
					return;
				}
				case 5: {
					cout << "You receive from your friends new books" << endl;
					addSkills(p,"reading");
					update(p, 10, 0, 0, 0);
					return;
				}
				case 6: {
					cout << "You receive from your friends a theatre ticket" << endl;
					addSkills(p,"drama");
					update(p, 10, 0, 0, 0);
					return;
				}
				case 7: {
					cout << "You receive a small aquarium with a red fish" << endl;
					cout << "What do you call him?" << endl;
					string fish;
					getline(cin, fish);
					cout << "You call him " << fish << endl;
					update(p, 10, 0, 0, 0);
					return;
				}
				}
			}
		}
		case 7: {
			string event = p.skills[rand() % p.skills.size()];
			int pi = -1;
			for (int i = 0; i < (sizeof(abilities) / sizeof(abilities[0]));i++) {
				if (event == abilities[i]) {
					pi = i;
					break;
				}
			}
			while (true) {
				switch (pi) {
				case -1: {
					pi = rand() % (sizeof(abilities) / sizeof(abilities[0]));
					break;
				}
				case 0: {
					cout << "You participate in a bike race" << endl;
					cout << "What do you do" << endl;
					cout << "1. you stay with the pack" << endl;
					cout << "2. you remain in the pack and wait the last sprint" << endl;
					int race = inputControl(1, 2);
					if (race == 1) {
						cout << "You decide to go all out in the final sprint" << endl;
						racePosition(2);
						cout << "You get 20 dollars as a prize" << endl;
						update(p, 0, 0, 20, 0);
						return;
					}
					else if (race == 2) {
						int fail = rand() % 10 + 1;
						if (fail <= 8) {
							cout << "You get exhausted before the finish line and get caught" << endl;
							racePosition(3);
							cout << "You get 5 dollars as a prize" << endl;
							update(p, 0, 0, 5, 0);
							return;
						}
						else if (fail >= 9) {
							cout << "You manage to finish in the front" << endl;
							racePosition(1);
							cout << "You get 50 dollars as a prize"<<endl;
							update(p, 10, 0, 50, 0);
							addSkills(p,"cycling");
							return;
						}
					}
				}
				case 1: {
					cout << "You participate in an art contest" << endl;
					cout << "What do you decide to paint" << endl;
					cout << "1. nature" << endl;
					cout << "2. abstract" << endl;
					cout << "3. skyline" << endl;
					cout << "4. portrait" << endl;
					inputControl(1, 4);
					int art = racePosition(rand() % 3 + 1);
					if (art <= 5) {
						cout << "An expert decides to buy your painting for 50 dollars" << endl;
						update(p, 0, 0, 50, 0);
						addSkills(p,"art");
						return;
					}
					else {
						cout << "An expert decides to buy your painting for 5 dollars" << endl;
						update(p, 0, 0, 5, 0);
						return;
					}
				}
				case 2: {
					cout << "You get called to go to a real fossil site" << endl;
					int fossil = rand() % 3;
					switch (fossil) {
					case 0: {
						cout << "You find a common fish fossil" << endl;
						cout << "They decide to buy it from you for 5 dollars" << endl;
						update(p, 0, 0, 5, 0);
						break;
					}
					case 1: {
						cout << "You find a rare tooth of a dinosaur" << endl;
						cout << "They decide to buy it from you for 15 dollars" << endl;
						update(p, 0, 0, 15, 0);
						break;
					}
					case 2: {
						cout << "You find an entire t-rex skull" << endl;
						cout << "They decide to buy it from you for 100 dollars" << endl;
						cout << "You get to choose the name of that new t-rex" << endl;
						cout << "name: " << endl;
						string tRex;
						getline(cin, tRex);
						cout << "The t-rex new name is " << tRex << endl;
						update(p, 0, 0, 100, 0);
						break;
					}
					}
					addSkills(p,"archeology");
					return;
				}
				case 3: {
					cout << "You participate in a math competition" << endl;
					if (p.iq <= 5) {
						cout << "Your iq is too low" << endl;
						racePosition(3);
						cout << "You get 5 dollars as a prize" << endl;
						update(p, 0, 0, 5, 0);
						return;
					}
					else if (p.iq >= 6 && p.iq <= 15) {
						cout << "You have an average iq" << endl;
						racePosition(2);
						cout << "You get 10 dollars as a prize" << endl;
						update(p, 0, 0, 10, 0);
						return;
					}
					else if (p.iq > 15) {
						cout << "Your iq is above average" << endl;
						racePosition(1);
						cout << "You get 50 dollars as a prize" << endl;
						update(p, 5, 0, 50, 0);
						addSkills(p,"math");
						return;
					}
				}
				case 4: {
					cout << "You win a contest to be in first row to your favourite singer/band" << endl;
					cout << "What singer/band would you like to see?" << endl;
					string band;
					getline(cin, band);
					cout << "You went to the " << band << " concert" << endl;
					addSkills(p,"music");
					return;
				}
				case 5: {
					cout << "You get called to write a book for a contest" << endl;
					int book = rand() % 3;
					switch (book) {
					case 0: {
						cout << "You write a kids book" << endl;
						cout << "An experts decides to pay it 5 dollars" << endl;
						update(p, 0, 0, 5, 0);
						break;
					}
					case 1: {
						cout << "You write a fantasy book" << endl;
						cout << "An experts decides to pay it 15 dollars" << endl;
						update(p, 0, 0, 15, 0);
						break;
					}
					case 2: {
						cout << "You write a real masterpiece" << endl;
						cout << "An experts decides to pay it 100 dollars" << endl;
						update(p, 0, 0, 100, 0);
						break;
					}
					}
					addSkills(p,"reading");
					return;
				}
				case 6: {
					cout << "You go to an audition for a movie" << endl;
					int movie = rand() % 3;
					switch (movie) {
					case 0: {
						cout << "You get the part of an extra" << endl;
						cout << "They pay you 5 dollars" << endl;
						update(p, 0, 0, 5, 0);
						break;
					}
					case 1: {
						cout << "You get the part of a side character" << endl;
						cout << "They pay you 15 dollars" << endl;
						update(p, 0, 0, 15, 0);
						break;
					}
					case 2: {
						cout << "You get the protagonist role" << endl;
						cout << "They pay you 100 dollars" << endl;
						update(p, 0, 0, 100, 0);
						break;
					}
					}
					addSkills(p,"drama");
					return;
				}
				case 7: {
					cout << "You get to participate in a training session with dolphins" << endl;
					cout << "what do you do?" << endl;
					cout << "1. you feed the dolphins" << endl;
					cout << "2. you teach a new trick to the dolphins" << endl;
					cout << "3. you swim with them" << endl;
					int dolphin = inputControl(1, 3);
					switch (dolphin) {
					case 1: {
						int food = rand() % 2;
						if (food == 0) {
							cout << "The dolphins get along with you" << endl;
							return;
						}
						else {
							cout << "You give them the wrong fish" << endl;
							cout << "You can no longer attend that course" << endl;
							return;
						}
					}
					case 2: {
						int trick = rand() % 5;
						if (trick == 0) {
							cout << "You teach them how to do a flip" << endl;
							cout << "The owner is so impressed that decide to pay you 50 dollars" << endl;
							update(p, 0, 0, 50, 0);
							return;
						}
						else {
							cout << "You try but failed" << endl;
							cout << "You still have a beautiful experience" << endl;
							return;
						}
					}
					case 3: {
						cout << "You didn't notice the sign that said it was prohibited" << endl;
						cout << "You can no longer attend that course" << endl;
						return;
					}
					}
				}
				}
			}
		}
		case 8: {
			cout << "Your school is organising a Christmas play" << endl;
			if (find(p.skills.begin(), p.skills.end(), "drama") == p.skills.end()) {
				cout << "Do you want to participate?(1. yes 2. no)" << endl;
				int act = inputControl(1, 2);
				if (act == 2) {
					return;
				}
			}
			cout << "Which role would you like to do?" << endl;
			cout << "1. protagonist" << endl;
			cout << "2. side character" << endl;
			cout << "3. extra" << endl;
			cout << "4. animal" << endl;
			cout << "5. tree" << endl;
			int role = inputControl(1, 5);
			string roles[5]{ "protagonist","side character","extra","animal","tree" };
			int get = rand() % 2 + 1;
			if (get == 1 || role == 5) {
				cout << "You get accepted as the role of " << roles[role - 1] << endl;
				update(p, 5, 0, 0, 0);
				return;
			}
			else if (get == 2) {
				cout << "You didn't get accepted for the role of " << roles[role - 1] << endl;
				int newRole = rand() % (5 - role) + role;
				cout << "Instead you get the role of " << roles[newRole] << endl;
				return;
			}
		}
		case 9: {
			cout << "You go on a trip to the ocean" << endl;
			cout << "What do you do?" << endl;
			cout << "1. buy souvenirs" << endl;
			cout << "2. try typical food" << endl;
			cout << "3. have a guided tour" << endl;
			cout << "4. just hangout with your friends" << endl;
			int trip = inputControl(1,4);
			switch (trip) {
			case 1: {
				cout << "You have a lot of options" << endl;
				cout << "1. Ocean water 10 dollars (+2 health)" << endl;
				cout << "2. Seashell 5 dollars (+5 happiness)" << endl;
				cout << "3. magnet free" << endl;
				int shop = inputControl(1, 3);
				switch (shop) {
				case 1: {
					if (p.money >= 10) {
						update(p, 0, 2, -10, 0);
						return;
					}
					else {
						cout << "You don't have enough money" << endl;
						return;
					}
				}
				case 2: {
					if (p.money >= 5) {
						update(p, 5, 0, -5 ,0);
						return;
					}
					else {
						cout << "You don't have enough money" << endl;
						return;
					}
				}
				case 3: {
					cout << "You decide to take the free souvenir" << endl;
					return;
				}
				}
			}
			case 2: {
				cout << "You can choose from :" << endl;
				while (true) {
					cout << "1. lobster 20 dollars" << endl;
					cout << "2. crab 15 dollars" << endl;
					cout << "3. sushi 10 dollars" << endl;
					cout << "4. fish 5 dollars" << endl;
					int food = inputControl(1, 4);
					if (food == 1) {
						if (p.money < 20) {
							cout << "You don't have enough money for the lobster" << endl << endl;
							continue;
						}
						else {
							cout << "You eat a delicious lobster" << endl;
							update(p, 0, 0, -20, 0);
							return;
						}
					}
					else if (food == 2) {
						if (p.money < 15) {
							cout << "You don't have enough money for the crab" << endl << endl;
							continue;
						}
						else {
							cout << "You eat a delicious crab" << endl;
							update(p, 0, 0, -15, 0);
							return;
						}
					}
					else if (food == 3) {
						if (p.money < 10) {
							cout << "You don't have enough money for sushi"<<endl<<endl;
							continue;
						}
						else {
							cout << "You eat delicios sushi"<<endl;
							update(p, 0, 0, -10, 0);
							return;
						}
					}
					else if (food == 4) {
						if (p.money < 5) {
							cout << "You don't have enough money fo fish" << endl;
							cout << "You are starving" << endl;
							update(p, -10, -3, 0, 0);
							return;
						}
						else {
							cout << "You eat delicious food" << endl;
							update(p, 0, 0, -5, 0);
							return;
						}
					}
				}
				
			}
			case 3: {
				cout << "The tour let you visit an aquarium" << endl;
				cout << "At the end they test what you have learned" << endl;
				int score = 0;
				cout << "What's the biggest marine animal?" << endl;
				string answer;
				getline(cin, answer);
				if (answer == "Blue whale" || answer == "blue whale" || answer == "bluewhale" || answer == "Bluewhale") {
					cout << "Correct" << endl;
					score++;
				}
				else {
					cout << "Wrong" << endl;
				}
				cout << "How many tentacles does an octopus have?" << endl;
				getline(cin, answer);
				if (answer == "8" || answer == "eight" || answer == "Eight") {
					cout << "Correct" << endl;
					score++;
				}
				else {
					cout << "Wrong" << endl;
				}
				cout << "What marine animal has 5 arms?" << endl;
				getline(cin, answer);
				if (answer == "Starfish" || answer == "starfish") {
					cout << "Correct" << endl;
					score++;
				}
				else {
					cout << "Wrong" << endl;
				}
				cout << endl << "You got " << score << "/3" << endl;
				if (score == 3) {
					addSkills(p,"sea");
					return;
				}
				else {
					return;
				}
			}
			case 4: {
				if (p.friends.empty()) {
					cout << "You don't have friends that can go with you" << endl;
					cout << "So you sit down at a bench alone" << endl;
					update(p, -5, 0, 0, 0);
					return;
				}
				else {
					if (p.friends.size() == 1) {
						cout << "You spend all day with " << p.friends[0].name << endl;
						update(p, 6, 0, 0, 0);
						return;
					}
					else {
						cout << "You spend all day with ";
						for (int i = 0; i < p.friends.size(); i++) {
							cout << p.friends[i].name << ", ";
						}
						cout << endl;
						update(p, 8, 0, 0, 0);
						return;
					}
				}
			}
			}
		}
		}
	}
	else if (p.age >= 15 && p.age <= 18) {
		//work in progress
		return;
	}
}

int main() {
	srand(time(nullptr));
	
	Player p;

	cout << "insert your name: " << endl;
	getline(cin, p.name);
	cout << "male(1) or female(2)" << endl;
	p.gender = inputControl(1,2);
	system("cls");
	cout << "Welcome to life " << p.name << endl<<endl;
	while (p.age <= 5) {
		zeroToFiveEvent(p);
		p.age++;
		menu(p, "grandparents", "doctor");
		if (p.death == true) {
			cout << "You died" << endl;
			recap(p);
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			return 0;
		}
		system("cls");
	}
	cout << "First five years recap" << endl;
	recap(p);
	cout << "Press enter to start school" << endl;
	cin.get();
	system("cls");
	cout << "Welcome to school" << endl<<endl;
	while (p.age >= 6 && p.age <= 11) {
		school(p);
		p.age++;
		menu(p, "park", "doctor");
		if (p.death == true) {
			cout << "You died" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			return 0;
		}
		system("cls");
		
	}
	cout << "You finished elementary school" << endl<<endl;
	recap(p);
	cout << "Press enter to start middle school" << endl;
	cin.get();
	system("cls");
	cout << "Welcome to middle school" << endl << endl;
	while (p.age >= 12 && p.age <= 14) {
		school(p);
		p.age++;
		menu(p, "park", "doctor");
		if (p.death == true) {
			cout << "You died" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.get();
			return 0;
		}
		system("cls");
	}
	cout << "You finished middle school" << endl << endl;
	recap(p);
	cout << "Press enter to start high school" << endl;
	cin.get();
	system("cls");
	cout << "Welcome to high school" << endl << endl;
	cout << "WORK IN PROGRESS";
	cin.get();
	return 0;
}