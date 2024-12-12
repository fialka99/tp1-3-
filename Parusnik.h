#pragma once
#include "Ship.h"
#include <iostream>
using namespace std;
class Parusnik : public Ship {
private:
	string name,
		type, position,lenght;

public:

	int lines;
	Parusnik() { type = typeid(*this).name(); lines = 0; }

	Parusnik(string name, string type, string position, string lenght) {
		this->name = name;
		this->type = type;
		this->position = position;
		this->lenght = lenght;
	}

	~Parusnik() {}

	void set_Name(string name);
	void set_Type(string type);
	void set_Position(string position);
	void set_Lenght(string lenght);

	string get_Name();
	string get_Type();
	string get_Position();
	string get_Lenght();

	virtual string entire_info() override;
	virtual void edit_info() override;

};
