#include "Submarine.h"

void Submarine::set_Lenght(string lenght) {
	this->lenght = lenght;
}

void Submarine::set_Width(string width) {
	this->width = width;
}

void Submarine::set_People(string width) {
	this->people = people;
}

void Submarine::set_Time(string time) {
	this->time = time;
}

void Submarine::set_Speed(string speed) {
	this->speed = speed;
}

void Submarine::set_Guns(string guns) {
	this->guns = guns;

}




string Submarine::get_Guns() {
	return this->guns;
}


string Submarine::get_Speed() {
	return this->speed;
}


string Submarine::get_Time() {
	return this->time;
}


string Submarine::get_People() {
	return this->people;
}

string Submarine::get_Lenght() {
	return this->lenght;
}

string Submarine::get_Width() {
	return this->width;
}

string Submarine::entire_info() {

	string str = this->lenght + ","
		+ this->width + "," + this -> people + ","+ this->time + "," + this->speed + "," + this->time + "," + this->guns;


	return str;
}
void Submarine::edit_info() {
	cout << "Choose param to edit:\n1 - Lenght\n2 - Width\n3 - People\n4 - Time\n5 - Speed\n6 - Guns\n7 - Exit" << endl;
	int choice = 0;
	string tmp;
	cin >> choice;
	while (choice < 0 || choice>4) {
		cout << "Incorrect input, enter again" << endl;
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		cout << "Set new lenght:" << endl;
		cin >> tmp;
		this->set_Lenght(tmp);
		break;
	case 2:
		cout << "Set new width:" << endl;
		cin >> tmp;
		this->set_Width(tmp);
		break;

	case 3:
		cout << "Set new kolvo people:" << endl;
		cin >> tmp;
		this->set_People (tmp);
		break;

	case 4:
		cout << "Set new time:" << endl;
		cin >> tmp;
		this->set_Time(tmp);
		break;

	case 5:
		cout << "Set new speed:" << endl;
		cin >> tmp;
		this->set_Speed(tmp);
		break;

	case 6:
		cout << "Set new kolvo guns:" << endl;
		cin >> tmp;
		this->set_Guns(tmp);
		break;

	case 7:
		return;
	default:
		break;
	}
}
