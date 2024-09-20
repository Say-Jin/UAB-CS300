#include <iostream>
#include <string>
#include <vector>
#include "randword.h"

using namespace std;

// Problem #1
string letterShift(string s) {
    char arr[] = "1234567890-QWERTYUIOP[ASDFGHJKL;ZXCVBNM,";
    int lenArr = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < s.size(); i++) {
        bool inArr = false;
        for (int j = 1; j < lenArr; j++) {
            if (s[i] == arr[j]) {
                s[i] = arr[j - 1];
                inArr = true;
                break;
            }
        }
        if (!inArr) {
            s[i] = ' ';
        }
    }
    return s;
}

//Problem #2
/*string lcdDisplayer(int n, int s) {

}*/

//Problem #3
//Helper Function
int reverseN(int n) {
    int reversedN = 0;
    while (n > 0) {
        int newN = n % 10;
        reversedN = reversedN * 10 + newN;
        n /= 10;
    }
    return reversedN;
}

//Problem Function
pair<int, int> reverseAddition(int N) {
    int steps = 0;
    int palindrome = N;

    while (steps <= 100) {
        int revN = reverseN(palindrome);
        if (palindrome == revN) {
            return make_pair(steps, palindrome);
        }
        palindrome += revN;
        steps++;
    }
    return {};
}

//Problem #4
struct Book {
    string title;
    string author;
    int catalogNumber;
    string subHeader;
    string publisher;
    int yearPublished;
    //circulating T or noncirculating F
    bool circulating;

    //Book(string t, string a, int cN, string sH, string p, int yP, bool circ)
    //: title(t), author(a), catalogNumber(cN), subHeader(sH), publisher(p), yearPublished(yP), circulating(circ) {
    //}
}; 

vector<Book> searchBySubject (const Book (&books)[5], string subject) {
    vector<Book> theBooks;

    for (const auto& book : books) {
        if (book.subHeader == subject) {
            theBooks.push_back(book);
        }
    }
    return theBooks;
}

void vectToString(const vector<Book>&vBooks) {
    for (const auto& book : vBooks) {
        cout << book.title << ", " << book.author << ", " << book.catalogNumber << endl;
    }
}

//struct libraryT {
   //vector<Book> libdata;
//};

//Problem #5

string words = InitDictionary("listOfwords.txt");
static string wordsArr[10];

string ChooseRandomWord () {
    int choice = rand() % 10;
    return wordsArr[choice];
    /*for (int i = 0; i < 10;) {
        wordsArr[i] = words[i];
        i++;
    }
    int choice = rand() % 10;
    return wordsArr[choice];*/
}

//hangman

void currentWord(const string &guess, const string &guessedChars) {
    for (char c : guess) {
        if (guessedChars.find(c) != string::npos) {
            cout << c << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void Hangman(const string &guess) {
    string guessedChars;
    int wrongChars = 0;
    const int maxGuesses = 8;

    while (wrongChars < maxGuesses) {
        cout << "Current word: ";
        currentWord(guess, guessedChars);
        cout << "Wrong Guesses: " << wrongChars << "/" << maxGuesses << endl;

        char g;
        cout << "Please enter a letter: ";
        cin >> g;

        if (guessedChars.find(g) != string::npos) {
            cout << "Letter entered previously!" << endl;
            continue;
        }

        guessedChars += g;
        if (guess.find(g) == string::npos) {
            wrongChars++;
            cout << "Wrong Letter!" << endl;
        }

        bool theGuessed = true;
        for (char c : guess) {
            if (guessedChars.find(c) == string::npos) {
                theGuessed = false;
                break;
            }
        }
        if (theGuessed) {
            cout << "You win and guessed the correct word: " << ChooseRandomWord() << endl;
            return;
        }
    }
    cout << "You lose! The word was: " << ChooseRandomWord() << endl;
}

//Main
int main() {
    //Sample Input 1
    string sampleIn1 = "O S, GOMR YPFSU/";
    string sampleOut1 = letterShift(sampleIn1);
    //string sampleIn2 = "O S, GOMR YPFSU/";
    //string sampleOut2 = letterShift(sampleIn2);
    int sampleIn3 = 195;
    auto sampleOut3 = reverseAddition(sampleIn3);
    //string sampleIn4 = "O S, GOMR YPFSU/";
    //string sampleOut4 = letterShift(sampleIn4);
    //string sampleIn5 = "O S, GOMR YPFSU/";
    //string sampleOut5 = letterShift(sampleIn5);

    cout << "Solution to problem #1:" << endl; 
    cout << sampleOut1 << endl;
    //cout << "Solution to problem #2:" << endl; 
    //cout << sampleOut1 << endl;
    cout << "Solution to problem #3:" << endl;
    cout << sampleOut3.first << " " << sampleOut3.second << endl;

    //Problem 4

    Book books[5] = {
        {"The Mockery", "Thomas Jayne", 21, "Literature", "The New York Thymes", 2018, true},
        {"Guilloutine", "Fred Foster", 33, "American Literature", "The Thymes", 2019, true},
        {"Requiem", "Charles Xavier", 78, "Biography", "Open Mind", 2003, true},
        {"The Geist", "Jennifer Lin", 41, "Fiction", "Stomp Express", 2001, true},
        {"Paradiso", "Cas McMartin", 1, "American Literature", "Oceans Way", 1999, false}
    };

    cout << "Solution to problem #4:" << endl; 
    vectToString(searchBySubject(books ,"American Literature"));

    //Problem 5
    srand(static_cast<unsigned>(time(0)));

    stringstream cwords(words);
    string word;
    int i = 0;

    while(getline(cwords, word) && i < 10) {
        wordsArr[i] = word;
        i++;
    }

    cout << "Solution to problem #5:" << endl; 
    //cout << ChooseRandomWord() << endl;
    cout << "Type everything in lowercase!" << endl;
    Hangman(ChooseRandomWord());
    //cout << words << endl;
    //cout << sampleOut1 << endl;
    return 0;
}