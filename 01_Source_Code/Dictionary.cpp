#include "Dictionary.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>

// -------- LOWERCASE FUNCTION --------
string Dictionary::toLower(string word) {
    for (char &c : word) {
        c = tolower(c);
    }
    return word;
}

// -------- CONSTRUCTOR --------
Dictionary::Dictionary() {
    // Fallback dictionary (in case file not used)

    // Positive
    dict["good"] = 2;
    dict["great"] = 3;
    dict["amazing"] = 5;
    dict["awesome"] = 4;
    dict["excellent"] = 5;
    dict["fantastic"] = 5;
    dict["nice"] = 2;
    dict["love"] = 4;
    dict["happy"] = 3;
    dict["wonderful"] = 5;
    dict["perfect"] = 5;
    dict["best"] = 5;
    dict["brilliant"] = 5;
    dict["beautiful"] = 4;
    dict["impressive"] = 4;
    dict["outstanding"] = 5;

    // Negative
    dict["bad"] = -2;
    dict["terrible"] = -5;
    dict["awful"] = -5;
    dict["boring"] = -3;
    dict["worst"] = -5;
    dict["hate"] = -4;
    dict["horrible"] = -5;
    dict["poor"] = -2;
    dict["sad"] = -3;
    dict["angry"] = -3;
    dict["annoying"] = -3;
    dict["disappointing"] = -4;
    dict["ugly"] = -3;
    dict["slow"] = -2;
    dict["fail"] = -4;
    dict["failure"] = -5;
    dict["waste"] = -4;
    dict["broken"] = -4;
    dict["pathetic"] = -5;
}

// -------- LOAD FROM FILE --------
void Dictionary::loadFromFile(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Dictionary file not found. Using default.\n";
        return;
    }

    string word;
    int score;

    while (file >> word >> score) {
        word = toLower(word);
        dict[word] = score;
    }
}

// -------- CHECK WORD --------
bool Dictionary::exists(string word) {
    word = toLower(word);
    return dict.count(word);
}

// -------- GET SCORE --------
int Dictionary::getScore(string word) {
    word = toLower(word);
    return dict[word];
}