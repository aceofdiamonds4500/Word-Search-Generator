#include <iostream>
#include <tuple>
#include <vector>
#include "Word.h"
using namespace std;

Word::Word(string inputWord){
   length = inputWord.length();
   word.resize(length);

   for(int i = 0; i < length; i++){
      word[i] = inputWord[i];
   }
}

void Word::setWord(string inputWord){
   
   word.resize(length);

   for(int i = 0; i < length; i++){
      word[i] = inputWord[i];
   }
}

vector<char> Word::getWord(){
   return word;
}

void Word::toString() const{
   for(char ch : word){
      cout << ch;
   }
   cout << endl;
}
