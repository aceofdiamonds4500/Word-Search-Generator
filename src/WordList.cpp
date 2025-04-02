#include <iostream>
#include <vector>
#include "header/WordList.h"
#include "header/Word.h"
using namespace std;

WordList::WordList(vector<Word> wordVec) : wordList(wordVec){
 
}

void WordList::addWord(Word word){
   wordList.push_back(word);
}

string WordList::toString() const{
   string list = "Words:";
   for(const auto& word : wordList){
      list += word.toString() + " ";
   }
   return list;
}
