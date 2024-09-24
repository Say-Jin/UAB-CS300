#include <iostream>
#include "user.h"
#include <string>
#include <algorithm>

User::User() {
    userName = "";
    email = "";
}

void User::setUserName(string s) {
    userName = s;
}
void User::setEmail(string s) {
    email = s;
}
void User::setFriendList(vector<string> v) {
    friendList = v;
}

string User::getUserName() {
    return userName;
}
string User::getEmail() {
    return email;
}
vector<string> User::getFriendList() {
    return friendList;
}

void User::addFriend(string s) {
    friendList.push_back(s);
}
void User::removeFriend(string s) {
    //for (int i = 0; i < friendList.size(); i++) {
        //if (friendList[i] == s) {
           //friendList[i] = "";
        //}
    //}
    friendList.erase(std::remove(friendList.begin(), friendList.end(), s),
    friendList.end());
}
int User::numFriends(vector<string> friendList) {
    return friendList.size();
}

string User::getFriendAt(int i) {
    if (i < 0 || i >= friendList.size()) {
        return "Error: No friend found\n";
    }
    return friendList[i];
}