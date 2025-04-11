
#include "header/WordSearch.h"
#include <fstream>

using namespace std;

WordSearch::WordSearch(size_t ysize, size_t xsize) : xsize(xsize), ysize(ysize){
   wordsearch.resize(ysize, vector<char>(xsize));
   char randomLetter;
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
   cout << input;
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
   bool wordWritten = false;
   int randDir = 0;
   int randPosX = 0;
   int randPosY = 0;
   int tries = 8;

   srand(time(0));
   while(wordWritten == false){
      if(tries == 0){return false;}
      randDir = (rand() % 8) + 1;
      randPosX = rand() % xsize;
      randPosY = rand() % ysize;
      switch(randDir){
         case 1:
            if(putNorth(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 2:
            if(putSouth(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 3:
            if(putEast(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 4:
            if(putWest(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 5:
            if(putNE(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 6:
            if(putSE(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 7:
            if(putNW(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 8:
            if(putSW(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         default:
            break;
      }
   }
   return true;
}

// TODO: pls fix to return a string
string WordSearch::toString() const{
   string output = "";
//   for(int i = 0; i < ysize; i++){
//      for(int j = 0; j < xsize; j++){
//         output += wordsearch[i][j] + ' ';
//      }
//      output += "\n";
//   }
//   output += "\0";
   for(const auto &xsize : wordsearch){
      for(char ch : xsize){
	 cout << ch;
         cout << " ";
      }
      cout << endl;
   }

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

//[-1][0]
bool WordSearch::putNorth(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int check = posY - word.size();
   if(check < 0){return false;} 
   for(int i = posY; wordIdx < word.size(); i--){
      if(!setChar(i,posX,word[wordIdx])){cout << check << " north too long" << endl; 
         return false;
      }
      wordIdx++;
   }
   cout << "north" << endl;
   return true;
}

//[+1][0]]
bool WordSearch::putSouth(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   if(posY + word.size() > ysize){return false;}
   for(int i = posY; wordIdx < word.size(); i++){
      if(!setChar(i,posX,word[wordIdx])){cout << "south too long" << endl; 
         return false;
      }
      wordIdx++;
   }
   cout << "south" << endl;
   return true;
}

//[0][+1]
bool WordSearch::putEast(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   if(posX + word.size() > xsize){return false;}
   for(int i = posX; wordIdx < word.size(); i++){
      if(!setChar(posY,i,word[wordIdx])){cout << "east too long" << endl; 
         return false;
      }
      wordIdx++;
   }
   cout << "east" << endl;
   return true;
}

//[0][-1]
bool WordSearch::putWest(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int check = posX - word.size();
   if(check < 0){return false;}
   for(int i = posX; wordIdx < word.size(); i--){
      if(!setChar(posY,i,word[wordIdx])){cout << "west too long" << endl; 
         return false;
      }
      wordIdx++;
   }
   cout << "west" << endl;
   return true;
}

//[-1][+1]
bool WordSearch::putNE(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   if(posY - word.size() < 0 || posX + word.size() > xsize){return false;} 
   for(int i = posX; wordIdx < word.size(); i++){
      posY--;
      if(!setChar(posY,i,word[wordIdx])){cout << "ne too long" << endl; 
         return false;
      }
      wordIdx++;
   }
   cout << "NE" << endl;
   return true;
}

//[+1][+1]
bool WordSearch::putSE(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   if(posY + word.size() > ysize || posX + word.size() > xsize){return false;}
   for(int i = posX; wordIdx < word.size(); i++){
      if(!setChar(i,i,word[wordIdx])){cout << "se too long" << endl; 
         return false;
      }
      wordIdx++;
   }
   cout << "SE" << endl;
   return true;
}

//[-1][-1]
bool WordSearch::putNW(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int checkN = posY - word.size();
   int checkW = posX - word.size();
   if(checkN < 0 || checkW < 0){return false;} 
   for(int i = posX; wordIdx < word.size(); i--){
      if(!setChar(i,i,word[wordIdx])){cout << "nw too long" << endl; 
         return false;
      }
      wordIdx++;
   }
   cout << "NW" << endl;
   return true;
}

//[+1][-1]
bool WordSearch::putSW(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   if(posY + word.size() > ysize || posX - word.size() < 0){return false;}
   for(int i = posY; wordIdx < word.size(); i++){
      posX--;
      if(!setChar(i,posX,word[wordIdx])){cout << "sw too long" << endl; 
         return false;
      }
      wordIdx++;
   }
   cout << "SW" << endl;
   return true;
}

size_t WordSearch::getYsize() const { return ysize; }
size_t WordSearch::getXsize() const { return xsize; }
