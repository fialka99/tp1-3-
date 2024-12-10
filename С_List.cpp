#define _CRT_SECURE_NO_WARNINGS
#include "C_List.h"
#include <iostream>


List::List()
{
    // Èçíà÷àëüíî ñïèñîê ïóñò
    Head = Tail = NULL;
    count = 0;
    cnt_sp = cnt_ad = cnt_sc = 0;
}

List::~List()
{
    // Âûçîâ ôóíêöèè óäàëåíèÿ
    DelAll();
}

int List::GetCount()
{
    return count;
}

List& List::operator++()//äîáàâëåíèå â êîíåö ïðåôèêñ
{
    string buffer;
    int choice = 0;
    cout << "Adding to the end\nChoose type\n1 - Parusnik\n2 - Kater\n3 - Submarine\n\t4-Exit" << endl;
    cin >> choice;
    Element* temp = new Element;

    if (choice == 1) {
        Parusnik* my_data = new Parusnik;
        fstream f_parus;
        f_parus.open("parusniks.csv", ios::out | (cnt_sp ? ios::app : ios::trunc));


        //çàïîëíåíèå íîâîãî îáúåêòà

        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);

        cout << "\nEnter type: ";
        cin >> buffer;
        my_data->set_Type(buffer);

        cout << "\nEnter position(war or no war): ";
        cin >> buffer;
        my_data->set_Position(buffer);

        cout << "\nEnter lenght: ";
        cin >> buffer;
        my_data->set_Lenght(buffer);

        temp->data = my_data;

        f_parus << my_data->entire_info() << endl;
        f_parus.close();
        my_data->lines++;
        cnt_sp++;
    }
    else if (choice == 2) {
        Kater* my_data = new Kater;
        fstream f_kat;
        f_kat.open("katers.csv", ios::out | (cnt_ad ? ios::app : ios::trunc));
        cout << "\nEnter the purpose: ";
        cin >> buffer;
        my_data->set_Purpose(buffer);


        cout << "\nEnter material: ";
        cin >> buffer;
        my_data->set_Material(buffer);

        cout << "\nEnter speed: ";
        cin >> buffer;
        my_data->set_Speed(buffer);
        
        cout << "\nEnter people: ";
        cin >> buffer;
        my_data->set_People(buffer);


        temp->data = my_data;

        f_kat << my_data->entire_info() << endl;
        f_kat.close();
        my_data->lines++;
        cnt_ad++;
    }
    else if (choice == 3) {
        Submarine* my_data = new Submarine;
        fstream f_subm;
        f_subm.open("submarine.csv", ios::out | (cnt_sc ? ios::app : ios::trunc));
        cout << "\nEnter lenght: ";
        cin >> buffer;
        my_data->set_Lenght(buffer);

        cout << "\nEnter width: ";
        cin >> buffer;
        my_data->set_Width(buffer);
        

        cout << "\nEnter kolvo people: ";
        cin >> buffer;
        my_data->set_People(buffer);

        cout << "\nEnter time under water: ";
        cin >> buffer;
        my_data->set_Time(buffer);

        cout << "\nEnter speed: ";
        cin >> buffer;
        my_data->set_Speed(buffer);

        cout << "\nEnter ammonation: ";
        cin >> buffer;
        my_data->set_Guns(buffer);

        temp->data = my_data;
        f_subm << my_data->entire_info() << endl;
        f_subm.close();
        my_data->lines++;
        cnt_sc++;
    }


    // ñîçäàíèå íîâîãî ýëåìåíòà


    // çàïîëíåíèå äàííûìè
   // temp->data = my_data;
    // ñëåäóþùèé ýëåìåíò îòñóòñòâóåò
    temp->pNext = NULL;

    if (count == 0)
    {
        temp->pNext = nullptr;
        Head = Tail = temp;
    }
    else {
        Element* p = Head;

        while (p->pNext != NULL)
            p = p->pNext;

        p->pNext = temp;
    }
    count++;
    return *this;
}

List& operator--(List& L1) {//óäàëåíèå èç êîíöà ïðåôèêñ ôðåíä

    if (L1.count == 0) {
        cout << "List is empty" << endl;
        return L1;
    }

    else if (L1.count == 1)
    {
        Element* temp = L1.Head;
        delete temp;
        L1.Head = L1.Tail = NULL;
        cout << "Now this list is empty" << endl;
    }
    else {

        Element* one = L1.Head;
        Element* two = L1.Head->pNext;
        while (two->pNext != NULL) {
            two = two->pNext;
            one = one->pNext;
        }
        one->pNext = NULL;
        delete two;
    }
    L1.count--;
    L1.file_Manager.refresh(L1);
    return L1;
}

List& List::operator--(int) {//óäàëåíèå èç íà÷àëà ïîñòôèêñ

    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }
    // çàïîìèíàåì àäðåñ ãîëîâíîãî ýëåìåíòà
    Element* temp = Head;
    // ïåðåáðàñûâàåì ãîëîâó íà ñëåäóþùèé ýëåìåíò
    Head = Head->pNext;
    // óäàëÿåì áûâøèé ãîëîâíîé ýëåìåíò
    delete temp;
    if (count == 1)
        cout << "Now this list is empty" << endl;

    count--;
    this->file_Manager.refresh(*this);
    return *this;
}

List& operator++(List& L2, int)//äîáàâëåíèå â íà÷àëî ïîñòôèêñ ôðåíä
{
    string buffer;
    int choice = 0;
    cout << "Adding to the head\nChoose type\n1 - Parusnik\n2 - Kater\n3 - Submarine\n\t4-Exit" << endl;
    cin >> choice;
    Element* temp = new Element;
    if (choice == 1) {
        Parusnik* my_data = new Parusnik;
        fstream f_parus;
        f_parus.open("parusniks.csv", ios::out | (L2.cnt_sp ? ios::app : ios::trunc));
        //çàïîëíåíèå íîâîãî îáúåêòà

        cout << "\nEnter the name: ";
        cin >> buffer;
        my_data->set_Name(buffer);

        cout << "\nEnter topic type parusnik: ";
        cin >> buffer;
        my_data->set_Type(buffer);

        cout << "\nEnter position(mir or no): ";
        cin >> buffer;
        my_data->set_Position(buffer);

        cout << "\nEnter lenght: ";
        cin >> buffer;
        my_data->set_Lenght(buffer);

        temp->data = my_data;

        f_parus << my_data->entire_info() << endl;
        f_parus.close();
        my_data->lines++;
        L2.cnt_sp++;
    }
    else if (choice == 2) {
        Kater* my_data = new Kater;
        fstream f_kat;
        f_kat.open("katers.csv", ios::out | (L2.cnt_ad ? ios::app : ios::trunc));
        cout << "\nEnter the purpose: ";
        cin >> buffer;
        my_data->set_Purpose(buffer);


        cout << "\nEnter material of the ship: ";
        cin >> buffer;
        my_data->set_Material(buffer);

        cout << "\nEnter speed: ";
        cin >> buffer;
        my_data->set_Speed(buffer);

        cout << "\nEnter kolvo people: ";
        cin >> buffer;
        my_data->set_People(buffer);

        temp->data = my_data;

        f_kat << my_data->entire_info() << endl;
        f_kat.close();
        my_data->lines++;
        L2.cnt_ad++;
    }
    else if (choice == 3) {
        Submarine* my_data = new Submarine;
        fstream f_subm;
        f_subm.open("submarine.csv", ios::out | (L2.cnt_sc ? ios::app : ios::trunc));
        cout << "\nEnter lenght: ";
        cin >> buffer;
        my_data->set_Lenght(buffer);

        cout << "\nEnter width: ";
        cin >> buffer;
        my_data->set_Width(buffer);
        
        cout << "\nEnter people: ";
        cin >> buffer;
        my_data->set_People(buffer);

        cout << "\nEnter time underwater: ";
        cin >> buffer;
        my_data->set_Time(buffer);

        cout << "\nEnter speed: ";
        cin >> buffer;
        my_data->set_Speed(buffer);

        cout << "\nEnter guns: ";
        cin >> buffer;
        my_data->set_Guns(buffer);

        temp->data = my_data;
        f_subm << my_data->entire_info() << endl;
        f_subm.close();
        my_data->lines++;
        L2.cnt_sc++;
    }



    if (L2.Head == NULL)
    {
        temp->pNext = NULL;
        L2.Head = L2.Tail = temp;
    }
    else  if (L2.Head != NULL)
    {
        temp->pNext = L2.Head;
        L2.Head = temp;
    }
    L2.count++;
    return L2;
}

void List::Del_head()
{
    // çàïîìèíàåì àäðåñ ãîëîâíîãî ýëåìåíòà
    Element* temp = Head;
    // ïåðåáðàñûâàåì ãîëîâó íà ñëåäóþùèé ýëåìåíò
    Head = Head->pNext;
    // óäàëÿåì áûâøèé ãîëîâíîé ýëåìåíò
    delete temp;
}

void List::DelAll()
{
    // Ïîêà åùå åñòü ýëåìåíòû
    while (Head != 0)
        // Óäàëÿåì ýëåìåíòû ïî îäíîìó
        Del_head();
}

void List::Print_list()
{
    // çàïîìèíàåì àäðåñ ãîëîâíîãî ýëåìåíòà
    Element* temp = Head;
    // Ïîêà åùå åñòü ýëåìåíòû

    if (count == 0) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "Head of the list" << endl;
    int i = 0;
    while (temp != 0)
    {
        // Âûâîäèì äàííûå
        cout << i + 1 << " - " << temp->data->entire_info() << " " << endl;;
        // Ïåðåõîäèì íà ñëåäóþùèé ýëåìåíò
        temp = temp->pNext;
        i++;
    }

    cout << "Tail of the list\n\n" << endl;
}


List& List::delete_elem(int n) {
    if (count == 0) {
        cout << "List is empty" << endl;
        return *this;
    }

    if ((Head != NULL) && (n < count) && (n >= 0)) // åñëè ïî ýòîìó íîìåðó ÷òî-òî ëåæèò è ýòîò ýëåìåíò âíóòðè ñïèñêà
    {
        // Mass - îáúåêòû, êîòîðûå õðàíÿòñÿ â ñïèñêå
        Element* temp = Head, * helping = Head;

        for (int i = 0; i < n; i++)
        {
            helping = temp; // ïðåäûäóùåå çíà÷åíèå temp
            temp = temp->pNext;
        }

        if (temp == Head) // åñëè ýëåìåíò êîòîðûé íàäî óäàëèòü ïåðâûé
        {
            Head = temp->pNext;
        }
        else
        {
            helping->pNext = temp->pNext;
        }
        cout << "you've deleted " << temp->data->get_Name() << endl;
        delete temp;
        this->file_Manager.refresh(*this);
        count--; // óìåíüøàåì ðàçìåð ñïèñêà
        return *this;
    }
    else {
        cout << "An error occured, please check your data " << endl;
        return *this;
    }
}

List& List::edit_elem(int n) {
    // çàïîìèíàåì àäðåñ ãîëîâíîãî ýëåìåíòà
    Element* temp = Head;
    // Ïîêà åùå åñòü ýëåìåíòû

    if (count == 0) {
        cout << "The list is empty" << endl;
        return *this;
    }

    int i = 0;
    while (i <= n)
    {
        if (i == n) {
            temp->data->edit_info();

            break;
        }
        temp = temp->pNext;
        i++;
    }
    return *this;

}
