#ifndef CSALADI_H
#define CSALADI_H


#include <iostream>
#include <ostream>
#include <string>

#include "film.h"


using namespace std;
class Csaladi: public Film {
    int Korhatar;


    friend std::ostream& operator<<(ostream& ostream, const Csaladi& rhs);

public:
    Csaladi();
    Csaladi(char Type, string Title, int Time, int Year, int Korhatar);
    ~Csaladi();
    void setKorhatar(const int Korhatar);
    int getKorhatar() const;
    void kiir() const;
    void setDescription(const string Description) ;
    string getDescription() const ;


};


#endif // CSALADI_H
