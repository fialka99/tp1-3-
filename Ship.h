#pragma once
#include <string>
#include <typeinfo>


using namespace std;

class Ship {
private:
	string naming;
	string topic;


public:
	string type;
	void set_Name(string to_name);
	void set_Topic(string ttopic);

	string get_Name();
	string get_Topic();


	Ship() {}

	virtual ~Ship() = default;

	Ship(string naming, string topic)
	{
		this->naming = naming;
		this->topic = topic;
	}

	virtual string entire_info() = 0;
	virtual void edit_info() = 0;

};
