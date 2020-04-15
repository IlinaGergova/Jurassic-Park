#pragma once
#include"ParkEnumerables.h"

class Dinosaur {
	char*name;
	Gender gender;
	Era era;
	Group group;
	char*kind;
	Food food;

	void copy(const Dinosaur&other);
	void erase();
public:
	Dinosaur(const char* newName = "", Gender newGender = Male, Era newEra = Triassic, Group newGroup = Herbivore, const char* newKind = "", Food newFood = Plants);
	Dinosaur(const Dinosaur&other);
	~Dinosaur();
	Dinosaur&operator=(const Dinosaur&other);

	char*getName()const;
	Gender getGender()const;
	Era getEra() const;
	Group getGroup() const;
	char*getKind()const;
	Food getFood()const;

	friend bool operator==(const Dinosaur&other1,const Dinosaur&other2);
};
