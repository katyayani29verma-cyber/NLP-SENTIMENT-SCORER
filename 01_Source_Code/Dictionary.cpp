#include "Dictionary.h"
#include <fstream>
#include <iostream>
#include <cctype>

// --------------------------------------------------
// Convert word to lowercase
// Ensures case-insensitive matching (GOOD == good)
// --------------------------------------------------
string Dictionary::toLower(string word) {
    for (char &c : word) {
        c = tolower(c);
    }
    return word;
}

// --------------------------------------------------
// Constructor
// - Loads default dictionary (fallback)
// - Used if no external file is provided
// --------------------------------------------------
Dictionary::Dictionary() {

    // -------- POSITIVE WORDS --------
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

    // -------- NEGATIVE WORDS --------
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

// --------------------------------------------------
// Load dictionary from external file
// File format example:
// good 2
// bad -2
// --------------------------------------------------
void Dictionary::loadFromFile(string filename) {
    ifstream file(filename);

    // If file not found → use default dictionary
    if (!file) {
        cout << "Dictionary file not found. Using default dictionary.\n";
        return;
    }

    string word;
    int score;

    // Read word-score pairs from file
    while (file >> word >> score) {
        word = toLower(word);   // normalize word
        dict[word] = score;     // store in map
    }
}

// --------------------------------------------------
// Check if word exists in dictionary
// Returns true (1) or false (0)
// --------------------------------------------------
bool Dictionary::exists(string word) {
    word = toLower(word);       // normalize input
    return dict.count(word);    // fast lookup
}

// --------------------------------------------------
// Get sentiment score of a word
// Assumes word exists before calling
// --------------------------------------------------
int Dictionary::getScore(string word) {
    word = toLower(word);       // normalize input
    return dict[word];          // return score
}