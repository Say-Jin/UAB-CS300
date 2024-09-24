#ifndef user_h
#define user_h

#include <string>
#include <vector>
using namespace std;

class User {
    private:
        string userName;
        string email;
        vector<string> friendList;

    public:
    User();

    // setters
    void setUserName(string s);
    void setEmail(string s);
    void setFriendList(vector<string> v);
    // getters
    string getUserName();
    string getEmail();
    vector<string> getFriendList();

    // functions
    void addFriend(string s);
    void removeFriend(string s);
    int numFriends(vector<string> v);
    string getFriendAt(int i);
};

#endif