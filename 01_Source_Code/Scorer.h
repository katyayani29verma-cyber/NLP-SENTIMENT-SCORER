#ifndef SCORER_H
#define SCORER_H

#include <string>
#include <unordered_map>
#include <vector>

// 1. ABSTRACTION
// The Scorer class acts as an Abstract Base Class. It defines a generic
// interface
//"contract" without providing the specific implementation.
class Scorer {
public:
  // A virtual destructor is important for memory safety. It ensures that when
  // you delete a derived class object through a base class pointer, the derived
  // class's destructor gets called properly.
  virtual ~Scorer() {}

  // Pure Virtual Function
  // The "= 0" forces this function to be overridden by any derived class.
  // It makes the Scorer class abstract, meaning you cannot instantiate a Scorer
  // object directly.
  virtual int
  calculateScore(const std::vector<std::string> &words,
                 const std::unordered_map<std::string, int> &dict) = 0;
};

// 2. INHERITANCE
// WordCountScorer inherits the Scorer base class.
// It fulfills the contract set by Scorer.
class WordCountScorer : public Scorer {
public:
  // Overriding the pure virtual function from the base class
  int calculateScore(const std::vector<std::string> &words,
                     const std::unordered_map<std::string, int> &dict) override;
};

// 2. INHERITANCE
// WeightedScorer also inherits the Scorer base class, offering an alternative
// scoring strategy.
class WeightedScorer : public Scorer {
public:
  // Overriding the pure virtual function from the base class
  int calculateScore(const std::vector<std::string> &words,
                     const std::unordered_map<std::string, int> &dict) override;
};

#endif
