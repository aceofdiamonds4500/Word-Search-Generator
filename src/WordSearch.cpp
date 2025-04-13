
#include "header/WordSearch.h"
#include "header/WordList.h"
#include <fstream>

using namespace std;

WordSearch::WordSearch(size_t ysize, size_t xsize) : xsize(xsize), ysize(ysize){
   wordsearch.resize(ysize, vector<char>(xsize));
   writtenOver.resize(ysize, vector<bool>(xsize,false));
   char randomLetter;
   srand(time(0));
   
   for(int i = 0; i < ysize; i++){
      for(int j = 0; j < xsize; j++){
         randomLetter = 65 + (rand() % (90 - 65 + 1));
         wordsearch[i][j] = randomLetter;
      }
   }
   
}

bool WordSearch::checkSpace(size_t col, size_t row, char input){   
   if(col < 0 || row < 0 || col >= ysize || row >= xsize)
   {return false;}
   
   if(writtenOver[col][row] == true){
      if(input == wordsearch[col][row]){return true;}
      else{return false;}
   }

   return true;
}

bool WordSearch::setChar(size_t col, size_t row, char input){
   if(col < 0 || row < 0 || col >= ysize || row >= xsize)
   {return false;}
   
   if(writtenOver[col][row] == true){
      if(input == wordsearch[col][row]){return true;}
      else{return false;}
   }
   
   wordsearch[col][row] = input;
   writtenOver[col][row] = true;
   //cout << input;
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
   int tries = xsize * ysize;

   srand(time(0));
   while(wordWritten == false){
      if(tries == 0){return false;}
      randDir = (rand() % 12) + 1;
      randPosX = rand() % xsize;
      randPosY = rand() % ysize;
      //debug
      //cout << randPosX << " posX " << randPosY << " posY" << endl;
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
         case 9:
            if(putNE(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 10:
            if(putSE(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 11:
            if(putNW(word, randPosX, randPosY) == true){wordWritten = true;}
            else{tries--;}
            break;
         case 12:
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

void WordSearch::writeToFile(WordList wordList, const string& filename) const{
   ofstream outputFile(filename);
   if(!outputFile){
      cerr << "File did not open properly." << endl;
      return;
   }
   
   //user disclaimer
   outputFile << "Note: Source Code Pro and other fonts with a constant width is optimal for the best looking word search.\nCopy and paste this to any Word file/Canva project to make your word search printable!" << endl;

   for(const auto &xsize : wordsearch){
      for(char ch : xsize){
	 outputFile << ch << " ";
      }
      outputFile << "\n";
   }
   
   outputFile << wordList.toString(); 
   cout << "Word search written to file \"src\\build\\wordsearch.txt\"!" << endl;
   outputFile.close(); 
}

//[-1][0]
bool WordSearch::putNorth(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int check = posY - word.size();
   if(check <= 0){return false;} 
   for(int i = posY; wordIdx < word.size(); i--){
      if(!checkSpace(i,posX,word[wordIdx])){
         return false;
      }
      wordIdx++;
   }
 
   wordIdx = 0;
   for(int i = posY; wordIdx < word.size(); i--){
      if(!setChar(i,posX,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }
   //cout << " north" << endl;
   return true;
}

//[+1][0]]
bool WordSearch::putSouth(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int check = posY + word.size();
   if(check > ysize){return false;}
   for(int i = posY; wordIdx < word.size(); i++){
      if(!checkSpace(i,posX,word[wordIdx])){
         return false;
      }
      wordIdx++;
   }

   wordIdx = 0;
   for(int i = posY; wordIdx < word.size(); i++){
      if(!setChar(i,posX,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }
   //cout << " south" << endl;
   return true;
}

//[0][+1]
bool WordSearch::putEast(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int check = posX + word.size();
   if(check > xsize){return false;}
   for(int i = posX; wordIdx < word.size(); i++){
      if(!checkSpace(posY,i,word[wordIdx])){
         return false;
      }
      wordIdx++;
   }

   wordIdx = 0;
   for(int i = posX; wordIdx < word.size(); i++){
      if(!setChar(posY,i,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }
   //cout << " east" << endl;
   return true;
}

//[0][-1]
bool WordSearch::putWest(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int check = posX - word.size();
   if(check <= 0){return false;}
   for(int i = posX; wordIdx < word.size(); i--){
      if(!checkSpace(posY,i,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }

   wordIdx = 0;
   for(int i = posX; wordIdx < word.size(); i--){
      if(!setChar(posY,i,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }
   //cout << " west" << endl;
   return true;
}

//[-1][+1]
bool WordSearch::putNE(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int checkY = posY - word.size();
   int checkX = posX + word.size();
   int posYtemp = posY;

   if(checkY <= 0 || checkX > xsize){return false;} 
   for(int i = posX; wordIdx < word.size(); i++){
      posYtemp--;
      if(!checkSpace(posYtemp,i,word[wordIdx])){
         return false;
      }
      wordIdx++;
   }

   wordIdx = 0;
   for(int i = posX; wordIdx < word.size(); i++){
      posY--;
      if(!setChar(posY,i,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }
   //cout << " NE" << endl;
   return true;
}

//[+1][+1]
bool WordSearch::putSE(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int checkY = posY + word.size();
   int checkX = posX + word.size();
   if(checkY > ysize || checkX > xsize){return false;}
   for(int i = posX; wordIdx < word.size(); i++){
      if(!checkSpace(i,i,word[wordIdx])){
         return false;
      }
      wordIdx++;
   }

   wordIdx = 0;
   for(int i = posX; wordIdx < word.size(); i++){
      if(!setChar(i,i,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }
   //cout << " SE" << endl;
   return true;
}

//[-1][-1]
bool WordSearch::putNW(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int checkY = posY - word.size();
   int checkX = posX - word.size();
   if(checkX <= 0 || checkY <= 0){return false;} 
   for(int i = posX; wordIdx < word.size(); i--){
      if(!checkSpace(i,i,word[wordIdx])){
         return false;
      }
      wordIdx++;
   }

   wordIdx = 0;
   for(int i = posX; wordIdx < word.size(); i--){
      if(!setChar(i,i,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }
   //cout << " NW" << endl;
   return true;
}

//[+1][-1]
bool WordSearch::putSW(vector<char> word, int posX, int posY){
   int wordIdx = 0;
   int checkY = posY + word.size();
   int checkX = posX - word.size();
   int posXtemp = posX;

   if(checkY > ysize || checkX <= 0){return false;}
   for(int i = posY; wordIdx < word.size(); i++){
      posXtemp--;
      if(!checkSpace(i,posXtemp,word[wordIdx])){
         return false;
      }
      wordIdx++;
   }
  
   wordIdx = 0;
   for(int i = posY; wordIdx < word.size(); i++){
      posX--;
      if(!setChar(i,posX,word[wordIdx])){ 
         return false;
      }
      wordIdx++;
   }
   //cout << " SW" << endl;
   return true;
}

size_t WordSearch::getYsize() const { return ysize; }
size_t WordSearch::getXsize() const { return xsize; }
