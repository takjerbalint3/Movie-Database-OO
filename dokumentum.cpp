
#include "dokumentum.h"


Dokumentum::Dokumentum() {
     this->Type = 'D';
    this->Time = 0;
    this->Year = 0;
    this->Title = " ";
    this->Description = " ";
}

Dokumentum::Dokumentum(char Type, string Title, int Time, int Year, string Description) {
    this->Type = Type;
    this->Time = Time;
    this->Year = Year;
    this->Title = Title;
    this->Description = Description;
}

Dokumentum::~Dokumentum() {

}

ostream & operator<<(ostream & ostream, const Dokumentum & rhs)
{
	ostream << "Cim: [" << rhs.getTitle() << "] \n";
	ostream << "Ev: [" << rhs.getYear() << "] \n";
	ostream << "Ido(perc): [" << rhs.getTime() << "] \n";
    ostream << "Leiras: [" << rhs.getDescription() << "] \n";

	return ostream;
}


void Dokumentum::kiir() const {
    std::cout << *this << std::endl;
}


void Dokumentum::setDescription(const string s) {
    this->Description = s;
}

string Dokumentum::getDescription() const {
    return this->Description;
}

void Dokumentum::setKorhatar( const int k) {

}

int Dokumentum::getKorhatar() const {
    return 0;
}
