#define _CRT_SECURE_NO_WARNINGS
#include "C_List.h"

List& List::file_Mngr::read_Parusnik(List& L2) {

    fstream f_parus;
    try
    {
        f_parus.open("parusniks.csv", ios::in);
        if (!f_parus.is_open())
            throw "Unable to open parusniks.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return L2;
    }



    string line1;

    char* words;
    //ñ÷èòûâàåì ñòðîêó 
    while (getline(f_parus, line1)) {
        int line_size = line1.size();
        char* s_data = new char[line_size + 4];
        string* sp_info = new string[4];

        strcpy(s_data, line1.c_str());


        //ïîèñê ñëîâ ÷åðåç çàïÿòóþ è çàïîëíÿåì ìàññèâ äëÿ çàïîëíåíèÿ â ïîëÿ îáúåêòà
        try {
            words = strtok(s_data, ",");
            if (!words)
                throw "check data in the file";
            int i = 0;
            while (words != NULL) {
                sp_info[i] = string(words);
                words = strtok(NULL, ",");
                i++;
            }
        }
        catch (const char* exp) {
            cerr << exp << endl;
            return L2;
        }
        Parusnik* parus_f = new Parusnik;
        parus_f->set_Name(sp_info[0]);
        parus_f->set_Type(sp_info[1]);
        parus_f->set_Position(sp_info[2]);
        parus_f->set_Type(sp_info[3]);

        parus_f->lines++;

        //äîáàâëåíèå â ñïèñîê 
        Element* temp = new Element;

        temp->data = parus_f;
        temp->pNext = NULL;

        if (L2.count == 0)
        {
            temp->pNext = nullptr;
            L2.Head = L2.Tail = temp;
        }
        else {
            Element* p = L2.Head;

            while (p->pNext != NULL)
                p = p->pNext;

            p->pNext = temp;
        }
        L2.count++;
        L2.cnt_sp++;
        delete[] s_data;
        delete[] sp_info;
    }




    f_parus.close();
    return L2;
}

List& List::file_Mngr::read_Kater(List& L2) {
    fstream f_kat;
    try
    {
        f_kat.open("katers.csv", ios::in);
        if (!f_kat.is_open())
            throw "Unable to open katers.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return L2;
    }
    string line1;

    char* words;
    //ñ÷èòûâàåì ñòðîêó 
    while (getline(f_kat, line1)) {
        int line_size = line1.size();
        char* s_data = new char[line_size + 3];
        string* sp_info = new string[4];

        strcpy(s_data, line1.c_str());


        //ïîèñê ñëîâ ÷åðåç çàïÿòóþ è çàïîëíÿåì ìàññèâ äëÿ çàïîëíåíèÿ â ïîëÿ îáúåêòà
        try {
            words = strtok(s_data, ",");
            if (!words)
                throw "check data in the file";
            int i = 0;
            while (words != NULL) {
                sp_info[i] = string(words);
                words = strtok(NULL, ",");
                i++;
            }
        }
        catch (const char* exp) {
            cerr << exp << endl;
            return L2;
        }
        Kater* kat_f = new Kater;
        kat_f->set_Purpose(sp_info[0]);
        kat_f->set_Material(sp_info[1]);
        kat_f->set_Speed(sp_info[2]);
        kat_f->set_People(sp_info[3]);

        kat_f->lines++;

        //äîáàâëåíèå â ñïèñîê 
        Element* temp = new Element;

        temp->data = kat_f;
        temp->pNext = NULL;

        if (L2.count == 0)
        {
            temp->pNext = nullptr;
            L2.Head = L2.Tail = temp;
        }
        else {
            Element* p = L2.Head;

            while (p->pNext != NULL)
                p = p->pNext;

            p->pNext = temp;
        }
        L2.count++;
        L2.cnt_sp++;
        delete[] s_data;
        delete[] sp_info;
    }




    f_kat.close();
    return L2;
}

List& List::file_Mngr::read_Submarine(List& L2) {
    fstream f_subm;
    try
    {
        f_subm.open("submarine.csv", ios::in);
        if (!f_subm.is_open())
            throw "Unable to open submarine.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return L2;
    }
    string line1;

    char* words;
    //ñ÷èòûâàåì ñòðîêó 
    while (getline(f_subm, line1)) {
        int line_size = line1.size();
        char* s_data = new char[line_size + 5];
        string* sp_info = new string[6];

        strcpy(s_data, line1.c_str());


        //ïîèñê ñëîâ ÷åðåç çàïÿòóþ è çàïîëíÿåì ìàññèâ äëÿ çàïîëíåíèÿ â ïîëÿ îáúåêòà
        try {
            words = strtok(s_data, ",");
            if (!words)
                throw "check data in the file";
            int i = 0;
            while (words != NULL) {
                sp_info[i] = string(words);
                words = strtok(NULL, ",");
                i++;
            }
        }
        catch (const char* exp) {
            cerr << exp << endl;
            return L2;
        }
        Submarine* submarine_f = new Submarine;
        submarine_f->set_Lenght(sp_info[0]);
        submarine_f->set_Width(sp_info[1]);
        submarine_f->set_People (sp_info[2]);
        submarine_f->set_Time(sp_info[3]);
        submarine_f->set_Speed(sp_info[4]);
        submarine_f->set_Guns(sp_info[5]);
        


        submarine_f->lines++;

        //äîáàâëåíèå â ñïèñîê 
        Element* temp = new Element;

        temp->data = submarine_f;
        temp->pNext = NULL;

        if (L2.count == 0)
        {
            temp->pNext = nullptr;
            L2.Head = L2.Tail = temp;
        }
        else {
            Element* p = L2.Head;

            while (p->pNext != NULL)
                p = p->pNext;

            p->pNext = temp;
        }
        L2.count++;
        L2.cnt_sp++;
        delete[] s_data;
        delete[] sp_info;
    }




    f_subm.close();
    return L2;
}

void List::file_Mngr::recovery(List& L) {
    read_Parusnik(L);
    read_Kater(L);
    read_Submarine(L);
}

void List::file_Mngr::refresh(List& L) {
    fstream f_parus, f_kat, f_subm;
    //speaker refresh
    try
    {
        f_parus.open("parusniks.csv", ios::trunc | ios::out);
        if (!f_parus.is_open())
            throw "Unable to open parusniks.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return;
    }

    if (L.count == 0) {
        cout << "The list is empty" << endl;
        return;
    }

    Element* temp = L.Head;
    while (temp != 0)
    {
        if (temp->data->type == "class Parusnik") {
            f_parus << temp->data->entire_info() << endl;

        }
        temp = temp->pNext;
    }
    f_parus.close();

    ///admin refresh
    try
    {
        f_kat.open("katers.csv", ios::trunc | ios::out);
        if (!f_kat.is_open())
            throw "Unable to open katers.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return;
    }

    if (L.count == 0) {
        cout << "The list is empty" << endl;
        return;
    }

    temp = L.Head;
    while (temp != 0)
    {
        if (temp->data->type == "class Kater") {
            f_kat << temp->data->entire_info() << endl;

        }
        temp = temp->pNext;
    }
    f_kat.close();

    //schedule refresh

    try
    {
        f_subm.open("submarine.csv", ios::trunc | ios::out);
        if (!f_subm.is_open())
            throw "Unable to open submarine.csv file";
    }
    catch (const char* exp)
    {
        cerr << exp << endl;
        return;
    }

    if (L.count == 0) {
        cout << "The list is empty" << endl;
        return;
    }

    temp = L.Head;
    while (temp != 0)
    {
        if (temp->data->type == "class Submarine") {
            f_subm << temp->data->entire_info() << endl;

        }
        temp = temp->pNext;
    }
    f_subm.close();
}
