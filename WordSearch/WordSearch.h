#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include <iostream>
#include <vector>
using namespace std;

class WordSearch{
private:
   vector<vector<char>> wordsearch;
   size_t xsize;
   size_t ysize;

public:
   WordSearch(size_t ysize, size_t xsize);
   
   bool setChar(size_t ysize, size_t xsize, char input);
   char getChar(size_t ysize, size_t xsize) const;
   bool addWord(vector<char> word);
   string toString() const;
   void writeToFile(const string& filename) const;
      
   size_t getYsize() const;
   size_t getXsize() const; 
};

#endif
