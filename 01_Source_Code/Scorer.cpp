#include "Scorer.h"

// Implementation of WordCountScorer
int WordCountScorer::calculateScore(
    const std::vector<std::string> &words,
    const std::unordered_map<std::string, int> &dict) {
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
    const std::vector<std::string> &words,
    const std::unordered_map<std::string, int> &dict) {
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
