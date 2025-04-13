# Custom Word Search Generator
> Version: 1.1 4-12-25

## Building and Compiling
Currently, until I can get the right Make config I want, you need to navigate to WordSearch/src/build and run ``make`` to compile, which you can then run ``./WordSearch`` to execute.

## Author
> Nicholas Cieplensky

## Description
  This is my individual project for a Word Search Generator which will allow the user to create word searches. This is the command line executable release, but soon I will attach it to a 

## 1.1 Features
- User can choose what words they wish to add to their word search
- User can choose the dimensions of their word search
- Program prints an output to wordsearch.txt

## Future Features
- Allows the user to pick custom or predetermined (easy, medium, hard) dimensions
- The program will auto-generate where the words go and what direction they travel
- Writes the word search as well as the contained words to a printable file
- An included DLL to implement this code into your projects

## Completion Checklist
~~- Create the framework of the program~~
~~- Create the algorithm~~ Completed!
  - place words in the list randomly,
  - check for collision or overlap with other words,
  - check for the amount of words that can fit in the set dimensions
- Finish the Word object to track its position
~~- Finish the WordList object to contain every word~~
- Create an Easy, Medium, and Hard mode
- Create functionality for WordList class to take files as word list input
 
~~- Compile with a Make file~~
- Add DLL to import functions to Visual Basic
  - make a Windows application using VB.NET

## TO-DO (bug fixes)
- fix the algorithm so it can eventually find a spot instead of having limited tries to find a spot
- add word list to wordsearch.txt
- remove debug from output
