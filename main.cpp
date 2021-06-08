#include <iostream>
#include <cctype>
#include <limits>
#include <string>
#include "lista.h"
#include "film.h"
#include "csaladi.h"
#include "dokumentum.h"

using namespace std;


int main()
{

    // Osztályok tesztelése Lista elkészítése előtt.
    Dokumentum * film = new Dokumentum();

    Csaladi * film2 = new Csaladi();

    delete film;

    delete film2;
    //Lista funkciok tesztelese ures listara, kivetelek dobasanak tesztelese.
    LinkedList<Film>* filmek = new LinkedList<Film>();
    try
    {
        filmek->deleteFilm(0);
    }
    catch (const char* p)
    {
        cout << p << endl;
    }
    try
    {
        filmek->listaKiir();
    }
    catch (const char* p)
    {
        cout << p << endl;
    }
    try
    {
        filmek->listaSzur("");
    }
    catch (const char* p)
    {
        cout << p << endl;
    }
    try
    {
        filmek->listaModosit(0,0);
    }
    catch (const char* p)
    {
        cout << p << endl;
    }
    filmek->fajlbeolvas();
    // Tesztprogram a mukodés ellenorzesere, input/outputon lehet ellenorizni.
    while(1) {
        try
        {
        int sz;
        cout << "A muvelet szamanak lenyomasaval vezerelje a programot!\n";
        cout << "1. Filmtar listazasa \n"; //yes
        cout << "2. Film hozzaadasa \n";  //yes
        cout << "3. Film szurese \n"; //yes
        cout << "4. Film torlese \n"; // yes
        cout << "5. Film modositasa \n"; // yes
        cout << "9. Kilepes \n";
        sz = validateInput(sz);
        switch(sz) {
        case 1 :
            {
            try
            {
                filmek->listaKiir();
            }
            catch (const char* p)
            {
                cout << p << endl;
            }
            break;
            }
        case 2 :
            {
            char type;
            cout << "Mi legyen a film tipusa? \n";
            cout << "(C) Csaladi / (D) Dokumentum \n";
            type = validateInput(type);
            type = toupper(type);

            switch(type)  {
                case 'C':
                    {
                        string Title; int Year,  Time,  Korhatar;
                        cout << "Adja meg a film adatait.\n";
                        cout << "Cim( , -vel  elvalasztva):";
                        cin.ignore();
                        getline(cin,Title,',');
                        cout << "Hossz(perc) Ev Korhatar \n";
                        Year = validateInput(Year);
                        Time = validateInput(Time);
                        Korhatar = validateInput(Korhatar);

                        filmek->addFilm(new Csaladi(type,Title,Time,Year,Korhatar));
                        break;
                    }
                case 'D':
                    {
                        string Title; int Year,  Time;  string Description;
                        cout << "Adja meg a film adatait. \n";
                        cout << "Cim( , -vel  elvalasztva):";
                        cin.ignore();
                        getline(cin,Title,',');
                        cout << "Hossz(perc) Ev Leiras \n";
                        Year = validateInput(Year);
                        Time = validateInput(Time);
                        cout << "Leiras( , -vel  elvalasztva)\n";
                        cin.ignore();
                        getline(cin,Description,',');

                        filmek->addFilm(new Dokumentum(type,Title,Time,Year,Description));
                        break;
                    }
                default:
                    {
                        cout << "Rossz tipust adott meg probalja ujra. \n";
                        break;
                    }
                }
            break;
            }
        case 3 :
            {
            int sz;
            cout << "Mire szeretnel szurni? \n";
            cout << "(1)Cim /(2)Tipus\n";
            sz = validateInput(sz);
            switch(sz) {
            case 1:
                {
                  string s;
                  cout << "Add meg a szuresi cimet: \n";
                  s = validateInput(s);
                  filmek->listaSzur(s);
                  break;
                }
            case 2:
                {
                    char c;
                  cout << "Add meg a szuresi tipust: \n";
                  cout << "(C)Csaladi / (D)Dokumentum\n";
                  c = validateInput(c);
                  c = toupper(c);
                  filmek->listaSzur(c);
                  break;
                }
            default :
                {
                    cout << "Csak az 1-es vagy 2-es gomb lenyomasaval tud szurni! \n";
                    cout << "Probalja ujra";
                    break;
                }
            }

            break;
            }
            case 4 :
                {
                    int idx;
                    cout << "Add meg a törlendo film indexet \n";
                    idx = validateInput(idx);
                    try {
                        filmek->deleteFilm(idx);
                    }
                    catch (const char* p){
                        cout << p << endl;
                    }
                    break;
                }

            case 5 :
                {
                   int idx, kat;
                   cout << "Add meg a modositando film indexet\n";
                   idx = validateInput(idx);
                   cout << "Add meg a modositando kategoriat\n";
                   cout << "(1)Cim ; (2)Lejatszasi ido ; (3)Kiadasi ev ; (4) Leiras/Korhatar\n";
                   kat = validateInput(kat);
                   filmek->listaModosit(idx, kat);
                   break;
                }

            case 9 :
                {
                  filmek->fajlbair();
                  delete filmek;
                  exit(0);
                  break;
                }

            }
        }
        catch (const char * p)
        {
            cout << p << endl;
        }

    };
    return 0;
}
