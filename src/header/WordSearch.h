#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include <iostream>
#include <vector>
using namespace std;

class WordSearch{
private:
   vector<vector<char>> wordsearch;
   vector<vector<bool>> writtenOver;
   size_t xsize;
   size_t ysize;

public:
   WordSearch(size_t ysize, size_t xsize);

   bool checkSpace(size_t ysize, size_t xsize, char input);   
   bool setChar(size_t ysize, size_t xsize, char input);
   char getChar(size_t ysize, size_t xsize) const;
   bool addWord(vector<char> word);
   string toString() const;
   void writeToFile(const string& filename) const;
      
   bool putNorth(vector<char> word, int posX, int posY);
   bool putSouth(vector<char> word, int posX, int posY);
   bool putEast(vector<char> word, int posX, int posY);
   bool putWest(vector<char> word, int posX, int posY);
   bool putNE(vector<char> word, int posX, int posY);
   bool putSE(vector<char> word, int posX, int posY);
   bool putNW(vector<char> word, int posX, int posY);
   bool putSW(vector<char> word, int posX, int posY);

   size_t getYsize() const;
   size_t getXsize() const; 
};

#endif
