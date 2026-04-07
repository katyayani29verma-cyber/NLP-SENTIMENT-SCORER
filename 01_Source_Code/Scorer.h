#ifndef SCORER_H
#define SCORER_H

#include <vector>
#include <string>
#include "Dictionary.h"   // ✅ IMPORTANT

using namespace std;

// ---------------- BASE CLASS ----------------
class Scorer {
public:
    // Pure virtual function
    virtual int calculateScore(vector<string>& words, Dictionary& dict) = 0;

    virtual ~Scorer() {}
};

// ---------------- WORD COUNT SCORER ----------------
class WordCountScorer : public Scorer {
public:
    int calculateScore(vector<string>& words, Dictionary& dict);
};

// ---------------- ADVANCED SCORER ----------------
class AdvancedScorer : public Scorer {
public:
    int calculateScore(vector<string>& words, Dictionary& dict);
};

#endif