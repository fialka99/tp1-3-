#include "Ship.h"



string Ship::get_Name() {
	return this->naming;
}

string Ship::get_Topic() {
	return this->topic;
}

void Ship::set_Name(string naming) {
	this->naming = naming;
}

void Ship::set_Topic(string topic) {
	this->topic = topic;
}
/*string Shit::entire_info() {
   string str = this->naming + "," + this->topic;
   return str;
}*/
