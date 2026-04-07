#include "Scorer.h"
#include "Dictionary.h"
#include <cctype>

// --------------------------------------------------
// Clean word function
// Removes punctuation and converts to lowercase
// --------------------------------------------------
string cleanWord(string word) {
    string cleaned = "";

    for (char c : word) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }

    return cleaned;
}

// --------------------------------------------------
// WORD COUNT SCORER
// +1 for positive, -1 for negative
// --------------------------------------------------
int WordCountScorer::calculateScore(vector<string>& words, Dictionary& dict) {
    int score = 0;

    for (string word : words) {
        if (dict.exists(word)) {
            if (dict.getScore(word) > 0)
                score += 1;
            else
                score -= 1;
        }
    }

    return score;
}

// --------------------------------------------------
// ADVANCED SCORER
// Includes:
// - cleaning
// - negation handling
// - weighted scoring
// --------------------------------------------------
int AdvancedScorer::calculateScore(vector<string>& words, Dictionary& dict) {
    int score = 0;

    for (int i = 0; i < words.size(); i++) {
        string word = cleanWord(words[i]);

        if (word.empty()) continue;

        // NOT handling
        if (word == "not" && i + 1 < words.size()) {
            string next = cleanWord(words[i + 1]);

            if (dict.exists(next)) {
                score -= dict.getScore(next);
                i++;
                continue;
            }
        }

        if (dict.exists(word)) {
            score += dict.getScore(word);
        }
    }

    return score;
}