#include "Kater.h"

void Kater::set_Purpose(string purp) {
	this->purpose = purp;
}

void Kater::set_Material(string matery) {
	this->material = matery;
}

void Kater::set_Speed(string speed) {
	this->speed = speed;
}

void Kater::set_People(string people) {
	this->people = people;
}

string Kater::get_Purpose() {
	return this->purpose;
}

string Kater::get_Material () {
	return this->material;
}

string Kater::get_Speed() {
	return this->speed;
}

string Kater::get_People () {
	return this->people;
}




string Kater::entire_info() {

	string str = this->purpose + ","
		+ this->material + ","
		+ this->speed + ","
		+ this->people;

	return str;
}
void Kater::edit_info() {
	cout << "Choose param to edit:\n1 - Purpose\n2 - Material\n3 - Speed\n4 - People\n\t5 - Exit" << endl;
	int choice = 0;
	string tmp;
	cin >> choice;
	while (choice < 0 || choice>5) {
		cout << "Incorrect input, enter again" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		cout << "Set new name:" << endl;
		cin >> tmp;
		this->set_Purpose(tmp);
		break;
	case 2:
		cout << "Set new position:" << endl;
		cin >> tmp;
		this->set_Material(tmp);
		break;
	case 3:
		cout << "Set new respons:" << endl;
		cin >> tmp;
		this->set_Speed(tmp);
		break;
	case 4:
		cout << "Set new respons:" << endl;
		cin >> tmp;
		this->set_People(tmp);
		break;


	case 5:
		return;
	default:
		break;
	}
}
