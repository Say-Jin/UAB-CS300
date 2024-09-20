#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#ifndef _randword_h
#define _randword_h

string InitDictionary(const string &fileName) {
    ifstream file(fileName);

    if (!file) {
        return "Failed to open the selected file.";
    }

    stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

string ChooseRandomWord ();

#endif //_randword_h