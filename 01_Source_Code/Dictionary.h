#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <unordered_map>
#include <string>
using namespace std;

class Dictionary {
    unordered_map<string, int> dict;

public:
    Dictionary();

    void loadFromFile(string filename); // file-based dictionary
    int getScore(string word);
    bool exists(string word);

private:
    string toLower(string word);
};

#endif