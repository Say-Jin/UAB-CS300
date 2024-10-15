#include <iostream>
#include <string>
#include "concert.h"

using namespace std;

Concert::Concert(string eventName, string eventDate, string location, 
string bandName, string genre) : Event(eventName, eventDate, location),
bandName(bandName), genre(genre) {}

string Concert::getDetails() const {
    return Event::getDetails() + " Band: " + bandName + " Genre: " + genre;
}

void Concert::setBandName(const string& band) {
    bandName = band;
}

void Concert::setGenre(const string& gen) {
    genre = gen;
}