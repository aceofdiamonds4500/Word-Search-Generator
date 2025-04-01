#include <stdio.h>
#include <iostream>
#include "WordSearch.h"
#include "Word.h"
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
   string userWord = "";
   bool full = false;

   cout << "Type a word to add to the word search (type \"0\" to finish)" << endl;
   while(full != true){
      cout << "> ";
      cin >> userWord;
      if(userWord == "0"){break;}
      Word newWord(userWord);
      if(userWord == "debug"){newWord.toString();}
      if(WS.addWord(newWord.getWord()) == false){cout << "Word is too long!" << endl;}
   }
   WS.toString();
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


