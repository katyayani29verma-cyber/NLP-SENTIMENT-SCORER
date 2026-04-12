#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "Scorer.h"
#include "Buffer.h"
#include "Dictionary.h"

using namespace std;

// --------------------------------------------------
// Tokenization Function
// Converts text into words
// --------------------------------------------------
vector<string> tokenize(string text) {
    vector<string> words;
    stringstream ss(text);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    return words;
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {
    try {
        // -------- READ INPUT FILE --------
        ifstream file("../Input_Files/input.txt");

        if (!file) {
            throw runtime_error("Input file not found!");
        }

        // Read full file into string
        stringstream bufferStream;
        bufferStream << file.rdbuf();
        string text = bufferStream.str();

        if (text.empty()) {
            throw runtime_error("Input file is empty!");
        }

        // -------- BUFFER (Person 2) --------
        Buffer buffer(move(text));

        // -------- TOKENIZE --------
        vector<string> words = tokenize(buffer.getData());

        // -------- DICTIONARY (Person 2) --------
        Dictionary dict;
        dict.loadFromFile("../02_Input_Files/dict.txt"); // optional

        // -------- SCORER (Person 1) --------
        int choice;
        cout << "Select Scoring Method:\n1. Word Count\n2. Advanced\nChoice: ";
        cin >> choice;

        Scorer* scorer = nullptr;

        if (choice == 1)
            scorer = new WordCountScorer();
        else
            scorer = new AdvancedScorer();

        // -------- CALCULATE SCORE --------
        int score = scorer->calculateScore(words, dict);

        // -------- OUTPUT --------
        cout << "\nSentiment Score: " << score << endl;

        if (score > 3)
            cout << "Strong Positive " << endl;
        else if (score > 0)
            cout << "Positive " << endl;
        else if (score == 0)
            cout << "Neutral " << endl;
        else if (score < -3)
            cout << "Strong Negative " << endl;
        else
            cout << "Negative " << endl;

        delete scorer;
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}