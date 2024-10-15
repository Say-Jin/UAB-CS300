#include <iostream>
#include <string>
#include "conference.h"

using namespace std;

Conference::Conference(string eventName, string eventDate, string location, 
string speaker, string topic) : Event(eventName, eventDate, location),
speaker(speaker), topic(topic) {}

string Conference::getDetails() const {
    return Event::getDetails() + " Speaker: " + speaker + " Topic: " + topic;
}

void Conference::setSpeaker(const string& speakerName) {
    speaker = speakerName;
}

void Conference::setTopic(const string& top) {
    topic = top;
}