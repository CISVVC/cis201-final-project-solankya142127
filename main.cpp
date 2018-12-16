/*
File: main.cpp
Description: The purpose of this program is to read a text file, in this case Alice in Wonderland, and keep track of the occurrences of every word throughout the text by showing the word, the number of appearances, and the line number(s) that each word occurred on. 
Author: Ankur Solanky
Email: solankya142127@student.vvc.edu
Date Created: Sat Dec 15 22:03:30 PST 2018 
*/

#include "concordance.h"

int main()
{
   Concordance con("alice.txt");
   con.parse();   
   con.print();

   return 0;
}
