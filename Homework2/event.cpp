#include <iostream>
#include <string>
#include "event.h"
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

Event::Event() : eventName(""), eventDate(""), location("") {}

Event::Event(string eventName, string eventDate, string location)
: eventName(eventName), eventDate(eventDate), location(location) {}

void Event::setEventName(const string& event) {
    eventName = event;
}

void Event::setEventDate(const string& date) {
    eventDate = date;
}

void Event::setLocation(const string& eventLocation) {
    location = eventLocation;
}

const string& Event::getEventName() const{
    return eventName;
}

const string& Event::getEventDate() const{
    return eventDate;
}

const string& Event::getLocation() const{
    return location;
}

string Event::getDetails() const{
    return "Event: " + eventName + " Date: " + eventDate + 
    " Location: " + location;
}

bool Event::isUpcoming() const{
    time_t current = time(0);
    tm* currentTm = localtime(&current);

    int month, day, year;
    char delimiter;

    stringstream ss(eventDate);
    ss >> month >> delimiter >> day >> delimiter >> year;

    tm eventTm = {};
    eventTm.tm_year = year - 1900;
    eventTm.tm_mon = month - 1;
    eventTm.tm_mday = day;

    if (eventTm.tm_year > currentTm->tm_year) {
        return true;
    }

    if (eventTm.tm_year == currentTm->tm_year) {
        if (eventTm.tm_mon > currentTm->tm_mon) {
            return true;
        }
        if (eventTm.tm_mon == currentTm->tm_mon && eventTm.tm_mday > currentTm->tm_mday) {
            return true;
        }
    }
    return false;
}