#include <iostream>
#include <vector>
#include "header/WordList.h"
#include "header/Word.h"
using namespace std;

bool operator == (const Word &word1, const Word &word2){
   if(word1.getLength() != word2.getLength()){ return false;}

   for(int i = 0; i < word1.getLength(); i++){
      if(word1.getLetter(i) != word2.getLetter(i)){
         return false;
      }
   }
   return true;
}

WordList::WordList(vector<Word> wordVec) : wordList(wordVec){
 
}

void WordList::addWord(Word word){
   wordList.push_back(word);
}

bool WordList::removeWord(Word removeWord){
   for(int i = 0; i < wordList.size(); i++){
      if(wordList[i] == removeWord){
         wordList.erase(wordList.begin()+i);
         return true;
      }
   }
   return false;
} 

string WordList::toString() const{
   string list = "Words:";
   for(const auto& word : wordList){
      list += word.toString() + " ";
   }
   return list;
}
