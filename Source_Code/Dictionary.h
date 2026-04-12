#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <unordered_map>
#include <string>
using namespace std;

// --------------------------------------------------
// Dictionary Class
// Purpose:
// - Stores words with sentiment scores
// - Provides fast lookup using unordered_map
// --------------------------------------------------
class Dictionary {
    unordered_map<string, int> dict;  // word → score mapping

public:
    // Constructor (loads default dictionary)
    Dictionary();

    // Load dictionary from file (optional feature)
    void loadFromFile(string filename);

    // Returns score of a word
    int getScore(string word);

    // Checks if word exists in dictionary
    bool exists(string word);

private:
    // Converts word to lowercase (for case-insensitive matching)
    string toLower(string word);
};

#endif