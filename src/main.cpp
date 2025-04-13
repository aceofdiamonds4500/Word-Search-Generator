#include <stdio.h>
#include <iostream>
#include <limits>
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
  
   while(dimensions < 12 || dimensions > 50){
      if(!(cin >> dimensions)) {
   
         cin.clear();
   
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         //cout << "Invalid input. Try again (Hint: only put 12-50)\n> ";
      }
      cout << "Invalid input. Try again (Hint: only put 12-50)\n> ";
      //cin >> dimensions;
   }
   int xsize = dimensions;

   cout << "Insert the y of the word search (min is 12, max is 50)\nEX: 12 = 12x12 grid\n> ";
   cin >> dimensions;
      
   while(dimensions < 12 || dimensions > 50){
      if(!(cin >> dimensions)) {
   
         cin.clear();
   
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid input. Try again (Hint: only put 12-50)\n> ";
      }
      //cout << "Invalid input. Try again (Hint: only put 12-50)\n> ";
      //cin >> dimensions;
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

   while(full != true){
      cout << "Select an option:\n1) Add a word\n2) View the list of words\n3) View the last word you wrote\n4) Remove a word from the list\n0) Finish adding words" << endl;
      cout << "> ";
      if(!(cin >> input)) {
   
         cin.clear();
   
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "That's not valid.. Please enter a number." << endl;
      }
      else{
         switch(input){
            case 1:
               cout << "Word to add: ";
               cin >> userWord;
               newWord.setWord(userWord);
               if(WS.addWord(newWord.getWord()) == false){cout << "Word not placed!\n(NOTE: try giving the word a few more times - if it doesn't place after 5 tries, it's too big or you've run out of space.)" << endl;}
               else{wrdList.addWord(newWord);}
               break;
            case 2:
               cout << wrdList.toString() << endl;
               break;
            case 3:
               cout << newWord.toString() << endl;
               break;
            case 4:
               cout << "Word to remove: ";
               cin >> userWord;
               if(wrdList.removeWord(userWord) == false){cout << "Word not found!" << endl;}
               else{cout << "Word " + userWord + " removed from list." << endl;}   
               break;
            case 0:
               full = true;
               break;
            default:
               cout << "Not valid input." << endl;
               break;
         }
      }
   }
   //cout << WS.getChar(0,0);
   cout << WS.toString() << endl;
   cout << wrdList.toString() << endl;
   WS.writeToFile(wrdList, filename); 
 
}

int main()
{
   int input = 1;
   bool quit = false;

   cout << "Word Search Creator" << endl;
   while(quit != true)
   {
      cout << "1: Generate a custom word search\n0: quit\n> ";
   
      if(!(cin >> input)) {
   
         cin.clear();
   
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "That's not valid.. Please enter a number." << endl;
      }
      else{

      switch(input){
         case 1:
            customWordSearch();
         case 0:
            quit = true;
            break;
         default:            
            break;
         }
      }
   }
 
   return 0;
}


