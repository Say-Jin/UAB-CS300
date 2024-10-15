#ifndef concert_h
#define concert_h

#include <iostream>
#include <string>
#include "event.h"

using namespace std;

class Concert : public Event {
    private: 
        string bandName;
        string genre;

    public:
        Concert(string eventName, string eventDate, string location,
        string bandName, string genre);


        void setBandName(const string& band);
        void setGenre(const string& gen);

        const string& getBandName() const;
        const string& getGenre() const;

        string getDetails() const override;
};

#endif