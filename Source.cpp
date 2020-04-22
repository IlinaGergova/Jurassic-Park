#include<iostream>
#include<fstream>
#include<cstring>
#include"JurassicPark.h"
using namespace std;

const int COMMAND_LEN = 12;
 
Dinosaur dinoCreator() {
	bool flag = true;
	while (true) {
		int nameLen;
		cout << "Enter the length of the name: ";
		cin >> nameLen;
		cout << endl;

		char*name = new char[nameLen];
		cout << "Enter the name: ";
		cin >> name;
		cout << endl;

		char commandChar;
		cout << "Enter gender. Options to choose from - 'f' for Female or 'm' for Male: ";
		cin >> commandChar;

		cout << endl;

		Gender gender;
		switch (commandChar) {
			case 'm': gender = Male; break;
			case 'f': gender = Female; break;
			default: cout << "No such gender. Enter dinosaur data again!"; flag = false;
		}
		cout << endl;
		cout << "Enter era. Options to choose from - 't' for Triassic, 'j' for Jurassic or 'c' for Cretaceous: ";
		cin >> commandChar;
		Era era;
		switch (commandChar) {
			case 't': era = Triassic; break;
			case 'j': era = Jurassic; break;
			case 'c': era = Cretaceous; break;
			default: cout << "No such era. Enter dinosaur data again!"; flag = false;
		}

		cout << endl;

		int kindLen;
		cout << "Enter the length of the kind: ";
		cin >> kindLen;

		cout << endl;

		char*kind = new char[kindLen];
		cout << "Enter the kind: ";
		cin >> kind;

		cout << endl;

		cout << "Enter the group. Options to choose from - 'f' for Flying, 'a' for Aquatic, 'h' for Herbivore or 'c' for Carnivore: ";
		cin >> commandChar;

		cout << endl;

		Group group;
		switch (commandChar) {
			case 'f': group = Flying; break;
			case 'a': group = Aquatic; break;
			case 'h': group = Herbivore; break;
			case 'c': group = Carnivore; break;
			default: cout << "No such group. Enter dinosaur data again!"; flag = false;
		}

		cout << "Enter the food. Options to choose from - 'f' for Fish, 'm' for Meat or 'p' for Plants: ";
		cin >> commandChar;

		cout << endl;

		Food food;
		switch (commandChar) {
			case 'f': food = Fish; break;
			case 'm': food = Meat; break;
			case 'p': food = Plants; break;
			default: cout << "No such food. Enter dinosaur data again!"; flag = false;
		}
		if (flag) {
			Dinosaur dino(name, gender, era, group, kind, food);
			return dino;
		}
	}
}

void addDinosaur(JurassicPark & park) {
	Dinosaur dino = dinoCreator();
	park.addAnimalInPark(dino);
}

void removeDino(JurassicPark & park) {
	Dinosaur dino = dinoCreator();
	park.removeAnimal(dino);
}

void createCage(JurassicPark & park) {
	char commandChar;
	cout << "Enter cage size. Options to choose from - 's' for Small, 'm' for Medium or 'l' for Large: ";
	cin >> commandChar;

	cout << endl;
	SizeOfCage size;
	switch (commandChar) {
		case's':size = Small; break;
		case'm':size = Medium; break;
		case'l':size = Large; break;
		default:cout << "No such size. Enter again!"; return;
	}

	cout << "Enter climate. Options to choose from - 'a' for Air, 'l' for Land or 'w' for Water: ";
	cin >> commandChar;

	cout << endl;
	Climate climate;
	switch (commandChar) {
		case'a':climate = Air; break;
		case'l':climate = Land; break;
		case'w':climate = Water; break;
		default:cout << "No such climate. Enter again!"; return;
	}

	park.makeCage(size, climate);
}

void addFood(JurassicPark & park) {
	char commandChar;
	cout << "Enter the food. Options to choose from - 'f' for Fish, 'm' for Meat or 'p' for Plants: ";
	cin >> commandChar;

	cout << endl;

	int foodQuantity;
	cout << "Enter the amount of food: ";
	cin >> foodQuantity;

	cout << endl;

	switch (commandChar) {
		case'f':park.foodDelivery(foodQuantity, 0, 0); break;
		case'm':park.foodDelivery(0, 0, foodQuantity); break;
		case'p':park.foodDelivery(0, foodQuantity, 0); break;
		default:cout << "No such food. Enter again!"; return;
	}
}

void help() {
	cout << "Commands: " << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "addDinosaur - adds a new dinosaur;" << endl;
	cout << "needs -> nameLen, name, gender, era, kindLen, kind, group, food." << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "createCage - creates a new cage;" << endl;
	cout << "needs -> size of cage, climate." << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "remove - removes a dinosaur;" << endl;
	cout << "needs -> nameLen, name, gender, era, kindLen, kind, group, food." << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "addFood - adds food to the park's reserves;" << endl;
	cout << "needs -> food type, quantity." << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "addStaff - adds staff to the park;" << endl;
	cout << "needs -> number of the new staff." << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "print - prints the information of the park." << endl;
	cout << "-----------------------------------------------------------------" << endl;
	cout << "exit - terminates the program." << endl;
	cout << "-----------------------------------------------------------------" << endl;

}

int main() {

	JurassicPark park;
	char command[COMMAND_LEN];
	while (true) {
		cin >> command;
		
		if (strncmp(command, "addDinosaur", COMMAND_LEN) == 0) {
			addDinosaur(park);
		}
		else if (strncmp(command, "createCage", COMMAND_LEN) == 0) {
			createCage(park);
		}
		else if (strncmp(command, "remove", COMMAND_LEN) == 0) {
			removeDino(park);
		}
		else if (strncmp(command, "addFood", COMMAND_LEN) == 0) {
			addFood(park);
		}
		else if (strncmp(command, "addStaff", COMMAND_LEN) == 0) {
			int staffToAdd;
			cout << "Enter the amount of staff to add: ";
			cin >> staffToAdd;
			cout << endl;
			park.addStaff(staffToAdd);
		}
		else if (strncmp(command, "help", COMMAND_LEN) == 0) {
			help();
		}
		else if (strncmp(command, "print", COMMAND_LEN) == 0) {
			park.print();////????
		}
		else if (strncmp(command, "exit", COMMAND_LEN) == 0) {
			cout << "Bye!";
			return 0;
		}
	}
	
	return 0;
}