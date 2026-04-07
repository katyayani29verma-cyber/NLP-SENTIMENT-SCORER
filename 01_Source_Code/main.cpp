#include "Scorer.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  // 1. Setup mock data to test the integration
  unordered_map<string, int> dict = {
      {"good", 2}, {"spectacular", 3}, {"bad", -2}, {"terrible", -5}};
  vector<string> words = {"the",      "service", "was",        "good",
                          "but",      "the",     "food",       "was",
                          "terrible", "and",     "spectacular"};
  // 2. USER INPUT & CONFIGURATION
  int choice;
  cout << "Select Scoring Method:\n1: Word Count (+1/-1)\n2: Weighted "
          "(+weight/-weight)\nChoice: ";
  cin >> choice;

  // 3. POLYMORPHISM
  // We declare a Base Class Pointer and can point to any object derived from
  // Scorer
  Scorer *activeScorer = nullptr;

  // We instantiate the specific derived class dynamically at runtime based on
  // user input
  if (choice == 1) {
    activeScorer = new WordCountScorer();
  } else {
    activeScorer = new WeightedScorer();
  }

  // Dynamic Dispatch: The 'virtual' keyword ensures the correct implementation
  // is resolved at runtime based on the underlying object type.
  int finalScore = activeScorer->calculateScore(words, dict);

  cout << "\nFinal Sentiment Score: " << finalScore << endl;

  // Memory safety cleanup:
  // Deleting the base class pointer triggers the virtual destructor,
  // ensuring no memory leaks occur from derived class objects.
  delete activeScorer;

  return 0;
}
