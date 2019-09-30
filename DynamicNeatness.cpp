#include <iostream>
#include <string>
#include "Neatness.h"

using namespace std;

int main()
{ // start main
    PrettyPrinter p1;
    bool running = true; // set a loop control flag
    int paragraphs = 0;
    int maxLength = 0;
    int numWords = 0;
    int* lengths = 0;
    int* lineCosts = 0;
    int* extras = 0;
    string* words = 0;
    cin >> paragraphs; // number of paragraphs in the sample input
    if(paragraphs < 1){running = false;}
    while(running) // main loop
    {
        cin >> maxLength; // maximum character length of a line
        p1.setMaxLength(maxLength);
        cin >> numWords; // number of words in the sample input
        p1.setNumWords(numWords);
        p1.setPenalty(-1);
        // instantiate an array of numWord strings and one of numWord ints
        words = new string[numWords];
        lengths = new int[numWords];
        // now we can get numWord words
        for(int i = 0; i < numWords; i++)
        {
            cin >> words[i];
            // put the word lengths into the lengths array
            lengths[i] = words[i].length();
            cout << words[i] << " " << lengths[i] << endl;
        }
        // now we have the words and their lengths in arrays
        // we can solve the neat printing problem
        // the problem is to find out how many words to print on each line to minimize the use of white space
        // the subproblem is to minimize the amount of white space when printing lines 1 through i
        // int penalty = p1.Penalty(words, 0, numWords-1);
        // cout << "Penalty: " << penalty << endl;
        p1.PRINT_NEATLY(numWords, maxLength, words);
        // all done!
        running = false; // run is done, set the running flag to false
        // clean up the garbage
        words = 0;
        delete words;
        lengths = 0;
        delete lengths;
    }
} // end main