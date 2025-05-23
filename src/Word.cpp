#include <iostream>
#include <tuple>
#include <vector> 
#include "header/Word.h"
using namespace std;

Word::Word(string inputWord){
   length = inputWord.length();
   word.resize(length);

   for(int i = 0; i < length; i++){
      word[i] = inputWord[i];
   }
}

void Word::setWord(string inputWord){
   length = inputWord.length();
   word.resize(length);

   for(int i = 0; i < length; i++){
      word[i] = inputWord[i];
   }
}

vector<char> Word::getWord(){
   return word;
}

char Word::getLetter(int idx) const{
   return word[idx];
}

size_t Word::getLength() const{
   return length;
}

string Word::toString() const{
   string output = "";
   for(char ch : word){
      output += ch;
   }
   return output;
}
