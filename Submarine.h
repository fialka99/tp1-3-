#pragma once
#include "Ship.h"
#include<iostream>
using namespace std;
class Submarine :
    public Ship
{
private:
    string lenght;
    string width;
    string people;
    string time;
    string speed;
    string guns;

public:

    int lines;
    Submarine() { type = typeid(*this).name(); lines = 0; }
    Submarine(string lenght, string width, string people,string time,string speed, string guns) {
        this->lenght = lenght;
        this->width = width;
        this->people = people;
        this->time = time;
        this->speed = speed;
        this->guns = guns;

       
    }

    ~Submarine() {}

    void set_Lenght(string lenght);
    void set_Width(string width);
    void set_People(string people);
    void set_Time(string time);
    void set_Speed(string speed);
    void set_Guns(string guns);

    string get_Lenght();
    string get_Width();
    string get_People();
    string get_Time();
    string get_Speed();
    string get_Guns();


    virtual string entire_info() override;
    virtual void edit_info() override;
};
