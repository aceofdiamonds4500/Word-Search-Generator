
#include "header/WordSearch.h"
#include <fstream>

using namespace std;

WordSearch::WordSearch(size_t ysize, size_t xsize) : xsize(xsize), ysize(ysize){
   wordsearch.resize(ysize, vector<char>(xsize));
   int randomLetter;
   srand(time(0));
   
   for(int i = 0; i < ysize; i++){
      for(int j = 0; j < xsize; j++){
         randomLetter = 65 + (rand() % (90 - 65 + 1));
         wordsearch[i][j] = randomLetter;
      }
   }
   
}

bool WordSearch::setChar(size_t col, size_t row, char input){
   if(col < 0 || row < 0 || col >= ysize || row >= xsize)
   {return false;}

   wordsearch[col][row] = input;
   return true;
}

char WordSearch::getChar(size_t col, size_t row) const{
   if(col < ysize && row < xsize){
      return wordsearch[col][row];
   } else {
      cerr << "Index out of bounds" << endl;
      return '\0';
   } 
}

bool WordSearch::addWord(vector<char> word){
   for(int i = 0; i < word.size(); i++){
      if(!setChar(i,i,word[i])){
         return false;
      }
   }
   return true;
}

string WordSearch::toString() const{
   string output = "";
   for(int i = 0; i < ysize; i++){
      for(int j = 0; j < xsize; j++){
         output += wordsearch[i][j] + ' ';
      }
      output += "\n";
   }
   output += "\0";
//   for(const auto &xsize : wordsearch){
//      for(char ch : xsize){
//	 output += ch + " ";
//      }
//      output += "\n";
//   }

   return output;
}

void WordSearch::writeToFile(const string& filename) const{
   ofstream outputFile(filename);
   if(!outputFile){
      cerr << "File did not open properly." << endl;
      return;
   }
   for(const auto &xsize : wordsearch){
      for(char ch : xsize){
	 outputFile << ch << " ";
      }
      outputFile << "\n";
   }
   cout << "Word search written to file \"wordsearch.txt\"!" << endl;
   outputFile.close(); 
}

size_t WordSearch::getYsize() const { return ysize; }
size_t WordSearch::getXsize() const { return xsize; }
