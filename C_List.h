#pragma once
#include <iostream>
#include <fstream>
#include "Ship.h"
#include "Submarine.h"
#include "Kater.h"
#include "Parusnik.h"
#include <string>

using namespace std;




typedef struct Element
{
	Ship* data;
	Element* pNext;
}Element;

class List
{
private:
	Element* Head;
	Element* Tail;
	class file_Mngr {
	public:
		void recovery(List& L);
		void refresh(List& L);
	private:
		List& read_Parusnik(List& L2);
		List& read_Kater(List& L2);
		List& read_Submarine(List& L2);
	};


	int count;
	int cnt_sp, cnt_sc, cnt_ad;

public:
	List();
	~List();

	// (Óäàëÿåòñÿ ãîëîâíîé ýëåìåíò)
	void Del_head();
	// Óäàëåíèå âñåãî ñïèñêà
	void DelAll();

	List& operator++();//äîáàâëåíèå â êîíåö ïðåôèêñ

	friend List& operator--(List& L1);//ïðåôèêñ óäàëåíèå èç êîíöà 

	friend List& operator++(List& L2, int);//äîáàâëåíèå â íà÷àëî ïîñòôèêñ

	List& operator--(int);//óäàëåíèå èç íà÷àëà ïîñòôèêñ

	void Print_list();//Ïå÷àòü ñïèñêà

	// Ïîëó÷åíèå êîëè÷åñòâà ýëåìåíòîâ, íàõîäÿùèõñÿ â ñïèñêå
	int GetCount();

	file_Mngr file_Manager;//âñïîìîãàòåëüíûé êëàññ äëÿ ðàáîòû ñ ôàéëàìè 

	List& delete_elem(int n);
	List& edit_elem(int n);







};
