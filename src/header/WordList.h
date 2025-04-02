#ifndef WORDLIST_H
#define WORDLIST_H

#include <iostream>
#include <vector>
#include "Word.h"
using namespace std;

class WordList{
private:
   vector<Word> wordList;
   size_t wordCount;
public:
   WordList(vector<Word> wordList);
   void addWord(Word word);
   string toString() const;
};
#endif
