#pragma once
#include "Ship.h"
#include <iostream>

using namespace std;

class Kater :public Ship {
private:
	string purpose;
	string material;
	string speed;
	string people;
public:

	int lines;
	Kater() { type = typeid(*this).name(); lines = 0; }

	Kater(string purp, string matery, string speed, string people) {
		this->purpose = purp;
		this->material = matery;
		this->speed = speed;
		this->people = people;
	}

	~Kater() {}

	void set_Purpose(string purp);
	void set_Material(string matery);
	void set_Speed(string speed);
	void set_People(string people);

	string get_Purpose();
	string get_Material();
	string get_Speed();
	string get_People();

	virtual string entire_info() override;
	virtual void edit_info() override;
};
