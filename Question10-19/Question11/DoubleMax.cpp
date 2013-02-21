/*
*   Author:  Colin Fitzsmions
*   Date:    21/2/2013
*   Problem: http://projecteuler.net/problem=11
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int parseInt(string);

const int GRIDSIZE = 20;

int main(){
    int grid [GRIDSIZE][GRIDSIZE];
    long largest = 1;
    fstream readFile;
    readFile.open("Input.txt");
    string temp;
    
    //Loop takes in inputs from the opened file.
    for(int x = 0; x < GRIDSIZE; x++){
        for(int y = 0; y < GRIDSIZE; y++){
            readFile >> temp;
            grid[x][y] = parseInt(temp);
        }
    }
    readFile.close();
    
    /* 
    *  This loop seems to have 'a lot' of reused code and this is something
    *  I would like to come back to and fix.  The issue I am currently facing
    *  is that as I reduce the size of the code (i.e. Reduce reused code) I
    *  increase the complexity of the loop.
    */
    long tempInt;
    //Loop cycles though the double array
    for(int x = 0; x < GRIDSIZE; x++){
        for(int y = 0; y < GRIDSIZE; y++){
            tempInt = 1;
            
            //Checks numbers horizontaly
            if(x < 20 && y < 17){
                for(int i = 0; i < 4; i++)
                    tempInt *= grid[x][y+i];
                if(tempInt > largest)
                    largest = tempInt;
                tempInt = 1;
                 
            }//Close horizontal check
            
            //Checks numbers verticly
            if(x < 17 && y < 20){
                for(int i = 0; i < 4; i++)
                    tempInt *= grid[x+i][y];
                if(tempInt > largest)
                    largest = tempInt;
                tempInt = 1;
            }//Close vertical check
            
            //Checks numbers diagonaly (falling right)
            if(x < 17 && y < 17){
                for(int i = 0; i < 4; i++)
                    tempInt *= grid[x+i][y+i];
                if(tempInt > largest)
                    largest = tempInt;
                tempInt = 1;
            }//Close right diagonal check

            if(y > 3 && x < 17){
                for(int i = 0; i < 4; i++)
                    tempInt *= grid[x+i][y+(-i)];
                if(tempInt > largest)
                    largest = tempInt;
                tempInt = 1;
            }//Close left diagonal check

        }//Close y loop
    }//Close x loop

    cout << largest << endl;

    return 0;
}
//**************************************//
//Summary:      Breaks a string down into an integer (reduced checks becuase the question
//              only comprises of integers of length 2)
//Parameters:   The string in question
//Return:       An integer representation of the string
//**************************************//
int parseInt(string toParse){
    return (toParse[0]-48) *10 + toParse[1]-48;
}