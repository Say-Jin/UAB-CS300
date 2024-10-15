#ifndef event_h
#define event_h

#include <iostream>
#include <string>

using namespace std;

class Event {
    protected:
        string eventName;
        string eventDate;
        string location;

    public:
        Event();
        Event(string eventName, string eventDate, string location);
        
        void setEventName(const string& event);
        void setEventDate(const string& date);
        void setLocation(const string& eventLocation);

        const string& getEventName() const;
        const string& getEventDate() const;
        const string& getLocation() const;

        virtual string getDetails() const;
        bool isUpcoming() const;

        virtual ~Event(){}
};

#endif