
#include "film.h"

using namespace std;


Film::Film() {
    this->Type = ' ';
    this->Time = 0;
    this->Year = 0;
    this->Title = " ";
}


Film::~Film() {

}


void Film::setTime(const int t) {
    this->Time = t;
}

void Film::setType(const char c) {
    this->Type = c;
}

void Film::setTitle(const string title) {
    this->Title = title;
}

void Film::setYear(const int y) {
    this->Year = y;
}

int Film::getTime() const {
    return this->Time;
}

char Film::getType() const {
    return this->Type;
}

string Film::getTitle() const {
    return this->Title;
}

int Film::getYear() const {
    return this->Year;
}
