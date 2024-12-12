#include "Parusnik.h"

void Parusnik::set_Type(string type) {
	this->type = type;
}

void Parusnik::set_Name(string name) {
	this->name = name;
}

void Parusnik::set_Position(string pose) {
	this->position = pose;
}

void Parusnik::set_Lenght(string lenght) {
	this->lenght = lenght;
}


string Parusnik::get_Position() {
	return this->position;
}

string Parusnik::get_Lenght() {
	return this->lenght;
}

string Parusnik::get_Name() {
	return this->name;
}

string Parusnik::get_Type() {
	return this->type;
}

string Parusnik::entire_info() {
	string str = this->name + ","
		+ this->type + ","
		+ this->position + ","
		+ this->lenght;

	return str;
}

void Parusnik::edit_info() {
	cout << "Choose param to edit:\n1 - Name\n2 - Type\n3 - Position\n4 - lenght\n\t5 - Exit" << endl;
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
		this->set_Name(tmp);
		break;
	case 2:
		cout << "Set new type:" << endl;
		cin >> tmp;
		this->set_Type(tmp);
		break;
	case 3:
		cout << "Set new position:" << endl;
		cin >> tmp;
		this->set_Position(tmp);
		break;
	case 4:
		cout << "Set new lenght:" << endl;
		cin >> tmp;
		this->set_Lenght(tmp);
		break;
	case 5:
		return;
	default:
		break;
	}
}
