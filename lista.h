#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "film.h"
#include "csaladi.h"
#include "dokumentum.h"

//  Bekeri a valtozot a felhasznalotol, majd ha rossz tipust ad meg, kiirja az outputra hogy figyelmeztesse errol a felhasznalot.
template<typename T>
T &validateInput(T &val)
{
    while (true) {
        if (cin >> val) {
            break;
        } else {
            cout << "Rossz valtozo erteket adott meg, probalja ujra!\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return val;
}


template <typename T>
 struct node {
    T* film;
    node<T>* next;
    };
template <typename T>
class LinkedList {
    node<T>* Head;
    node<T>* Tail;
    int meret;
public:
    LinkedList();
    ~LinkedList() {
        node<T>* current = Head;
        node<T>* next;

        while (current != NULL) {
            next = current->next;
            delete (current->film);
            delete current;
            current = next;
        }

    }

    void addFilm(T *film);
    void deleteFilm(int idx);
    void listaKiir();
    void listaSzur(char c);
    void listaSzur(string s);
    void listaModosit(int idx,int kat);
    void fajlbeolvas();
    void fajlbair();

};
//Lancolt lista konstruktora
template<typename T>
LinkedList<T>::LinkedList() {
    Head = NULL;
    Tail = NULL;
    meret = 0;
}
//Lancolt listabol kitorli a valasztott node-ot.
template<typename T>
void LinkedList<T>::deleteFilm(int idx) {

    int counter = 0;
    //Ha ures a lista kivetel
    if (Head == NULL) {
        throw "A lista ures nem tudunk torolni\n";
    }
    //Ha a kivalasztott idx nagyobb a lista meretenel kivetel
     if(idx > meret) {
        cout << meret << "\n";
        throw "Az index tullepett a lista mereten probalja meg kisebbel\n";
    }
    //Az elso elem kitorlese
    if(idx == 1) {
        node<T>* tmp = Head;
        Head = Head->next;
        delete (tmp->film);
        delete tmp;
    }
    //Az utolso elem torlese
    if(idx == meret) {
        node<T>* tmp = Head;
        if(Head->next == NULL) {
            delete (Head->film);
            delete Head;
        }
        while(tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        delete (tmp->next->film);
        delete (tmp->next);
        tmp->next = NULL;
        Tail = tmp;
        meret--;
    }
    //A lista kozeperol torles
    if (idx  < meret && idx > 1) {
        node<T>* deleteNode = Head->next;
        node<T>* deleteNodeprev = Head;
        while(counter + 1 != idx -1 && Head != NULL) {
            deleteNode=deleteNode->next;
            deleteNodeprev=deleteNodeprev->next;
            counter++;
        }

        deleteNodeprev->next=deleteNode->next;
        delete (deleteNode->film);
        delete deleteNode;
        meret--;
    }

}
//Kiirja a lancoltlista elemeit standard outputra
template<typename T>
void LinkedList<T>::listaKiir() {
    if (Head == NULL) {
        throw "A lista ures adjunk hozza elemeket\n";
    }

    node<T> * kiir =  Head;
    int counter = 1;
    while(kiir!=NULL)
    {
        cout << counter << " ";
        kiir->film->kiir();
        kiir=kiir->next;
        counter++;
    }
}
//Hozzaadja a megadott filmet a lista vegehez
template <typename T>
void LinkedList<T>::addFilm(T *film) {
    T *newfilm(film);
    node<T> *tmp = new node<T>();
    tmp->film = newfilm;
    tmp->next = NULL;
    if(Tail != NULL)
    {
            Tail->next = tmp;
    }
    Tail=tmp;
    meret++;
    if(Head== NULL)
        Head=Tail;
}
//Cimre szures a listaban
template<typename T>
void LinkedList<T>::listaSzur(string s) {
    bool talalat = false;
    if (Head == NULL) {
        throw "A lista ures nem tudunk szurni\n";
    }
    node<T> *tmp = Head;
    while(tmp != NULL)
    {

        if(tmp->film->getTitle()== s)
        {
            tmp->film->kiir();
            talalat = true;
        }
        tmp = tmp->next;
    }
    if(!(talalat)) {
        throw "Nincs talalat\n";
    }
}
//Tipus alapjan szures
template<typename T>
void LinkedList<T>::listaSzur(char c) {
    bool talalat = false;
    if (Head == NULL) {
        throw "A lista ures nem tudunk szurni\n";
    }
    node<T> *tmp = Head;
    while(tmp != NULL)
    {
        if(tmp->film->getType() == c)
        {
            tmp->film->kiir();
            talalat = true;
        }
        tmp = tmp->next;
    }
    if(!(talalat)) {
        throw "Nincs talalat\n";
    }
}

//Listaban modositas a film indexe es kategoriaja alapjan
template<typename T>
void LinkedList<T>::listaModosit(int idx,int kat) {
    int mod; string mod2;
    node<T> *tmp = Head;
    int counter = 1;
    if (Head == NULL) {
        throw "A lista ures nem tudunk modositani\n";

    }
    if (idx <= meret && idx >= 1) {

        while(counter != idx -1 && Head != NULL) {
            tmp = tmp->next;
            counter++;
        }
        tmp = tmp->next;
        char c = tmp->film->getType();
        switch(c) {
        case 'C':
            {
                switch(kat) {
                case 1:
                    {
                        cout << "Mire szeretne modositani a cimet?\n";
                        cout << "Cim veget , -vel jelezze:";
                        cin.ignore();
                        getline(cin,mod2,',');
                        tmp->film->setTitle(mod2);
                        cout << "A film cime modositva:\n";
                        tmp->film->kiir();
                        break;
                    }
                case 2:
                    {
                        cout << "Mire szeretne modositani az idot?\n";
                        mod = validateInput(mod);
                        tmp->film->setTime(mod);
                        cout << "A film ideje modositva:\n";
                        tmp->film->kiir();
                        break;
                    }
                case 3:
                    {
                        cout << "Mire szeretne modositani a kiadas evet?\n";
                        mod = validateInput(mod);
                        tmp->film->setYear(mod);
                        cout << "A kiadasi ido modositva:\n";
                        tmp->film->kiir();
                        break;
                    }
                case 4:
                    {
                        cout << "Mire szeretne modositani a korhatart?\n";
                        mod = validateInput(mod);
                        tmp->film->setKorhatar(mod);
                        cout << "A korhatar modositva:\n";
                        tmp->film->kiir();
                        break;
                    }
                }
                break;
            }
        case 'D':
            {

                switch(kat) {
                case 1:
                    {
                        cout << "Mire szeretne modositani a cimet?\n";
                        cout << "Cim veget , -vel jelezze:";
                        cin.ignore();
                        getline(cin,mod2,',');
                        tmp->film->setTitle(mod2);
                        cout << "A film cime modositva:\n";
                        tmp->film->kiir();
                        break;
                    }
                case 2:
                    {
                        cout << "Mire szeretne modositani az idot?\n";
                        mod = validateInput(mod);
                        tmp->film->setTime(mod);
                        cout << "A film ideje modositva:\n";
                        tmp->film->kiir();
                        break;
                    }
                case 3:
                    {
                        cout << "Mire szeretne modositani a kiadas evet?\n";
                        mod = validateInput(mod);
                        tmp->film->setYear(mod);
                        cout << "A kiadasi ido modositva:\n";
                        tmp->film->kiir();
                        break;
                    }
                case 4:
                    {
                        cout << "Mire szeretne modositani a leirast?\n";
                        cout << "Leiras veget , -vel jelezze:";
                        cin.ignore();
                        getline(cin,mod2,',');
                        tmp->film->setDescription(mod2);
                        cout << "A leiras modositva:\n";
                        tmp->film->kiir();
                        break;
                    }
                }

                break;
            }




        }
    }
    else {
        cout << "Az index tullepett a lista mereten : " << meret << " probalja meg kisebbel\n";
        return;
    }

}

//Beolvassa a fajl tartalmat a listaba
template <typename T>
void LinkedList<T>::fajlbeolvas() {
    fstream input;
    input.open("filmek.txt");

    while(!input.eof()) {
        int korhatar; string descr;
        string rInput;
        getline(input, rInput);

        stringstream sor(rInput);

        getline(sor, rInput, ',');
        char type = rInput[0];

        sor.get();
        getline(sor, rInput, ',');
        string title = rInput;

        sor.get();
        getline(sor, rInput, ',');
        int year = atoi(rInput.c_str());

        sor.get();
        getline(sor, rInput, ',');
        int time = atoi(rInput.c_str());

        switch(type) {
            case('C'):
                {
                    sor.get();
                    getline(sor, rInput, '\n');
                    korhatar = atoi(rInput.c_str());
                    addFilm(new Csaladi(type,title,time,year,korhatar));
                    break;
                }

            case('D'):
                {
                    sor.get();
                    getline(sor, rInput, '\n');
                    descr = rInput;
                    addFilm(new Dokumentum(type,title,time,year,descr));
                    break;
                }
            default:
                break;
        }

    }

    input.close();

}


//Kiirja a lista tartalmat a fajlba
template <typename T>
void LinkedList<T>::fajlbair() {
    char c;
    ofstream myfile;
    myfile.open ("filmek.txt");
    node<T>* tmp = Head;
    while(tmp != NULL) {
        c = tmp->film->getType();
        if(c == 'C') {
            myfile << c << ", " << tmp->film->getTitle() << ", " << tmp->film->getYear() << ", " << tmp->film->getTime() << ", " << tmp->film->getKorhatar() << "\n";
        }
        if(c == 'D') {
            myfile << c << ", " << tmp->film->getTitle() << ", " << tmp->film->getYear() << ", " << tmp->film->getTime() << ", " << tmp->film->getDescription() << "\n";
        }

        tmp = tmp->next;
    }
    myfile.close();

}


#endif // LISTA_H
