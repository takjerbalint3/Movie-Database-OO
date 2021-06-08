
#include "csaladi.h"


using namespace std;
Csaladi::Csaladi() {
    this->Type = 'C';
    this->Time = 0;
    this->Year = 0;
    this->Title = " ";
    this->Korhatar = 0;
}

Csaladi::Csaladi(char Type, string Title, int Time, int Year, int Korhatar) {
    this->Type = Type;
    this->Time = Time;
    this->Year = Year;
    this->Title = Title;
    this->Korhatar = Korhatar;
}

Csaladi::~Csaladi() {

}

std::ostream & operator<<(std::ostream & os, const Csaladi & rhs)
{
	os << "Cim: [" << rhs.getTitle() << "] \n";
	os << "Ev: [" << rhs.getYear() << "] \n";
	os << "Ido(perc): [" << rhs.getTime() << "] \n";
    os << "Korhatar: [" << rhs.getKorhatar() << "] \n";

	return os;

}


void Csaladi::kiir() const {
    std::cout << *this << std::endl;
}

void Csaladi::setKorhatar(const int k) {
    this->Korhatar = k;
}

int Csaladi::getKorhatar() const {
    return this->Korhatar;
}

void Csaladi::setDescription(const string s) {

}

string Csaladi::getDescription() const {
    return "";
}
