#include "Scorer.h"
#include "Dictionary.h"
#include <cctype>

// Implementation of WordCountScorer
int WordCountScorer::calculateScore(
    const vector<string> &words,
    const unordered_map<string, int> &dict) {
  int score = 0;

  for (const auto &word : words) {
    // Look up the word in the dictionary
    auto it = dict.find(word);

    // If the word exists in the dictionary
    if (it != dict.end()) {
      if (it->second > 0) {
        // Word is positive, add 1
        score++;
      } else if (it->second < 0) {
        // Word is negative, subtract 1
        score--;
      }
    }
  }

  return score;
}

// Implementation of WeightedScorer
int WeightedScorer::calculateScore(
    const vector<string> &words,
    const unordered_map<string, int> &dict) {
  int score = 0;

  // Iterate through the vector of words
  for (const auto &word : words) {
    // Look up the word in the dictionary
    auto it = dict.find(word);

    // If the word exists in the dictionary
    if (it != dict.end()) {
      // Add the exact integer weight directly to the score
      score += it->second;
    }
  }

  return score;
}
#include "Scorer.h"
#include <cctype>

// Clean word function
string cleanWord(string word) {
    string cleaned = "";
    for (char c : word) {
        if (isalpha(c)) cleaned += tolower(c);
    }
    return cleaned;
}

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