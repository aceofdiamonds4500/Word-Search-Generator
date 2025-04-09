#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Word{
private:
   vector<char> word;
   unsigned int length;
   typedef tuple<int,int> STARTPOS;
   typedef tuple<int,int> WORD_DIR;

public:
   Word(string inputWord);

   void setWord(string inputWord);
   vector<char> getWord();
   char getLetter(int idx) const;
   size_t getLength() const;
   string toString() const;
};

#endif
