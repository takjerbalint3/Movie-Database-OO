#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>


using namespace std;
class Film
{



protected:
    char Type;
    string Title;
    int Time;
    int Year;
public:

	Film();
    virtual ~Film();
	// Setters
    void setTitle(const string  Title);
    void setYear(const int  Year);
    void setType(const char  Type);
    void setTime(const int  Time);
    virtual void kiir() const = 0;
    virtual void setDescription(const string Description) = 0;
    virtual void setKorhatar(int const Korhatar) = 0;
	// Getters
    string getTitle() const ;
	int getYear() const ;
    char getType() const;
    int getTime() const;
    virtual string getDescription() const = 0;
    virtual int getKorhatar() const = 0;


};

#endif
