#ifndef DOKUMENTUM_H
#define DOKUMENTUM_H


#include <iostream>
#include <ostream>
#include <string>

#include "film.h"

using namespace std;

class Dokumentum: public Film {
    string Description;

    friend std::ostream& operator<<(std::ostream& os, const Dokumentum& rhs);
public:
    Dokumentum();
    Dokumentum(char Type, string Title, int Time, int Year, string Description);
    ~Dokumentum();
    void kiir() const;
    void setDescription(const string Description);
    string getDescription() const ;
    void setKorhatar( const int Korhatar);
    int getKorhatar() const;

};


#endif // Dokumentum_H
