#pragma once
#include"ParkEnumerables.h"
#include<iostream>
#include<string>
using namespace std;

class Dinosaur {
	string name;
	Gender gender;
	Era era;
	Group group;
	string kind;
	Food food;

public:
	Dinosaur(const string newName = "", Gender newGender = Male, Era newEra = Triassic, Group newGroup = Herbivore, const string newKind = "", Food newFood = Plants);

	string getName()const;
	Gender getGender()const;
	Era getEra() const;
	Group getGroup() const;
	string getKind()const;
	Food getFood()const;

	friend bool operator==(const Dinosaur&other1, const Dinosaur&other2);
	friend ostream&operator<<(ostream &os, const Dinosaur &dino);

	void saveDino(ostream& file);
	friend Dinosaur loadDino(istream& file);
};

