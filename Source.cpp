#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include"JurassicPark.h"
#include"Commands.h"
using namespace std;



int main() {
	//JurassicPark park(10); //за съдаване на нов обект, добре е първо да се извика addFood и после да се добавя динозавър

	JurassicPark park; //за четене на обект от файла
	ifstream file;
	file.open("data.txt");
	file >> park;

	string command;
	while (true) {
		cin >> command;

		if (command == "addDinosaur") {
			addDinosaur(park);
		}
		else if (command == "createCage") {
			createCage(park);
		}
		else if (command == "remove") {
			removeDino(park);
		}
		else if (command == "addFood") {
			addFood(park);
		}
		else if (command == "addStaff") {
			int staffToAdd;
			cout << "Enter the amount of staff to add: ";
			cin >> staffToAdd;
			cout << endl;
			park.addStaff(staffToAdd);
		}
		else if (command == "help") {
			help();
		}
		else if (command == "print") {
			park.print();
		}
		else if (command == "exit") {
			ofstream file;
			file.open("data.txt");
			if (!file.is_open()) {
				cerr << "Error in opening the file!";
				return -1;
			}
			file << park;
			file.close();
			cout << "Bye!";
			return 0;
		}
		else {
			cout << "Invalid command!" << endl;
		}
	}

	return 0;
}