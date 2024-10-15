#include <iostream>
#include <string>
#include <vector>
#include "event.h"
#include "concert.h"
#include "conference.h"

using namespace std;

void userMenu() {
    cout << "Event Manager" << endl;
    cout << "*When inputing a date please follow this format MM/DD/YYYY*: " << endl;
    cout << "Please input an option from below: " << endl;
    cout << "1. Create an Event" << endl;
    cout << "2. Create a Concert" << endl;
    cout << "3. Create a Conference" << endl;
    cout << "4. View Events" << endl;
    cout << "5. Exit" << endl;
}

int main() {

    vector<Event*> events;
    int choice;

    while(true) {
        userMenu();
        cin >> choice;

        switch(choice) {
            case 1: {
                string name, date, location;
                cout << "Please enter the Event Name: ";
                cin.ignore();
                getline(cin, date);
                cout << "Please enter the Event Date (MM/DD/YYYY): ";
                getline(cin, date);
                cout << "Please enter the Event Location: ";
                getline(cin, location);
                events.push_back(new Event(name, date, location));
                cout << "The Event was successfully created!" << endl;
                break;
            }
            case 2: {
                string name, date, location, band, genre;
                cout << "Please enter the Concert Name: ";
                cin.ignore();
                getline(cin, date);
                cout << "Please enter the Concert Date (MM/DD/YYYY): ";
                getline(cin, date);
                cout << "Please enter the Concert Location: ";
                getline(cin, location);
                cout << "Please enter the Band Name: ";
                getline(cin, band);
                cout << "Please enter the genre: ";
                getline(cin, genre);
                events.push_back(new Concert(name, date, location, band, genre));
                cout << "The Concert was successfully created!" << endl;
                break;
            }
            case 3: {
                string name, date, location, speaker, topic;
                cout << "Please enter the Conference Name: ";
                cin.ignore();
                getline(cin, date);
                cout << "Please enter the Conference Date (MM/DD/YYYY): ";
                getline(cin, date);
                cout << "Please enter the Conference Location: ";
                getline(cin, location);
                cout << "Please enter the Speaker Name: ";
                getline(cin, speaker);
                cout << "Please enter the Topic: ";
                getline(cin, topic);
                events.push_back(new Conference(name, date, location, speaker, topic));
                cout << "The Concert was successfully created!" << endl;
                break;
            }
            case 4: {
                cout << "Current Events" << endl;
                for(const auto& event : events) {
                    cout << event->getDetails() << endl;
                    cout << "Is Upcoming: " << (event->isUpcoming() ? "Yes" : "No") << endl;
                }
                cout << endl;
                break;
            }
            case 5: {
                cout << "Goodbye and have a good day, until next time..." << endl;

                for(auto event : events) {
                    delete event;
                }
                return 0;
            }
            default: {
                cout << "That's not an option! Please enter a valid option." << endl;
                break;
            }
        }
    }
    for(auto event : events) {
        delete event;
    }
    return 0;
}