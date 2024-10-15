#ifndef conference_h
#define conference_h

#include <iostream>
#include <string>
#include "event.h"

using namespace std;

class Conference : public Event {
    private: 
        string speaker;
        string topic;

    public:
        Conference(string eventName, string eventDate, string location,
        string speaker, string topic);


        void setSpeaker(const string& speakName);
        void setTopic(const string& top);

        const string& getSpeaker() const;
        const string& getTopic() const;
        
        string getDetails() const override; 
};

#endif