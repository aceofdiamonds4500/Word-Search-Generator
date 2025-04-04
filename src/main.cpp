#include <stdio.h>
#include <iostream>
#include "header/WordSearch.h"
#include "header/Word.h"
#include "header/WordList.h"
using namespace std;

const string filename = "wordsearch.txt";

void customWordSearch()
{

   /**
   /  [0][+1]  travels east
   /  [0][-1]  west
   /  [-1][0]  north
   /  [+1][0]  south
   /  [+1][+1] southeast
   /  [+1][-1] southwest
   /  [-1][-1] northwest
   /  [-1][+1] northeast
   **/

   int dimensions = 0;
   cout << "Insert the x of the word search (min is 12, max is 50)\nEX: 12 = 12x12 grid\n> ";
   cin >> dimensions;
      
   while(dimensions < 12 || dimensions > 50){
      cout << "Invalid input. Try again (Hint: only put 12-50)\n> ";
      cin >> dimensions;
   }
   int xsize = dimensions;

   cout << "Insert the y of the word search (min is 12, max is 50)\nEX: 12 = 12x12 grid\n> ";
   cin >> dimensions;
      
   while(dimensions < 12 || dimensions > 50){
      cout << "Invalid input. Try again (Hint: only put 12-50)\n> ";
      cin >> dimensions;
   }
   int ysize = dimensions;

   WordSearch WS(ysize,xsize);

   //add words
   int input = 0;
   string userWord = "";
   bool full = false;
   Word newWord(userWord);
   vector<Word> initVec = {Word(newWord)};
   WordList wrdList(initVec);

   cout << "Select an option:\n1) Add a word\n2) View the list of words\n3)View the last word you wrote\n0) Finish adding words" << endl;

   while(full != true){
      cout << "> ";
      cin >> input;
      if(input == 1){
         cout << "Word to add: ";
         cin >> userWord;
         newWord.setWord(userWord);
         if(WS.addWord(newWord.getWord()) == false){cout << "Word is too long!" << endl;}
         else{wrdList.addWord(newWord);}
      }
      if(input == 2){
         cout << wrdList.toString() << endl;
      }
      if(input == 3){
         cout << newWord.toString() << endl;
      }
      if(input == 0){
         full = true;
         break;
      }
      if(input < 0 || input > 3){
         cout << "Not valid input." << endl;
      }
   }
   //cout << WS.getChar(0,0);
   cout << WS.toString() << endl;
   WS.writeToFile(filename); 
 
}

int main()
{
   int input = 1;

   cout << "Word Search Creator" << endl;
   while(input != 0)
   {
      cout << "1: Generate a custom word search\n0: quit\n> ";
      cin >> input;

      switch(input){
         case 1:
            customWordSearch();
         case 0:
            break;
         default:
            cout << "That's not valid.." << endl;
            break;
      }
   }
 
   return 0;
}


