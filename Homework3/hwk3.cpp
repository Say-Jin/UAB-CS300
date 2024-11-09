#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

//Problem #1
string permutations(string a, string b) {
    map<char, int> alphabetical;
    string x = "";

    for(int i = 0; i < a.length(); i++) {
        alphabetical[a[i]]++;
    }

    for(int j = 0; j < b.length(); j++)
        if(alphabetical[b[j]] > 0){
            alphabetical[b[j]]++;
        }

    for(const auto& pair : alphabetical) {
        if(pair.second > 1) {
            x += pair.first;
        }
    }
    
    return x;
}

//Problem #2
int blackMail(int r, vector<int>& s) {
    if(r == 0) {
        return 0;
    }
    else {
        sort(s.begin(), s.end());
        int idealStreet = s[r/2];
        int distance = 0;
        for(int i = 0; i < r; i++) {
            distance += abs(s[i] - idealStreet);
        }
        return distance;
    }
}