/*
*   Author:  Colin Fitzsmions
*   Date:    21/2/2013
*   Probelm: http://projecteuler.net/problem=11
*/

//PROBLEM HAS BEEN TRACKED DOWN TO LEFT DIAGONAL AREA

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
    
    //Loop operates correclty~
    for(int x = 0; x < GRIDSIZE; x++){
        for(int y = 0; y < GRIDSIZE; y++){
            readFile >> temp;
            grid[x][y] = parseInt(temp);
        }
    }
    readFile.close();

    //THIS WAS CONSTRUCTED TO TEST THE GRID OUTPUT
    for(int x = 0; x < GRIDSIZE; x++){
        for(int y = 0; y < GRIDSIZE; y++){
            if(grid[x][y] < 10)
                cout << 0;            
             cout << grid[x][y] << " ";
        }
        cout << endl;
    }

    /* 
    *  This loop seems to have 'a lot' of reused code and this is something
    *  I would like to come back to and fix.  The issue I am currently facing
    *  is that as I reduce the size of the code (i.e. Reduce reused code) I
    *  increase the complexity of the loop.
    */
    long tempInt;
    for(int x = 0; x < GRIDSIZE; x++){
        for(int y = 0; y < GRIDSIZE; y++){
            //cout << x << " " << y << endl; 
            tempInt = 1;
            if(x < 20 && y < 17){
                for(int i = 0; i < 4; i++)
                    tempInt *= grid[x][y+i];
                if(tempInt > largest){
                    largest = tempInt;
                }
                tempInt = 1;
                 
            }//Close horizontal check
            
            if(x < 17 && y < 20){
                for(int i = 0; i < 4; i++)
                    tempInt *= grid[x+i][y];
                if(tempInt > largest){
                    largest = tempInt;
                }
                tempInt = 1;
            }//Close vertical check

            if(x < 17 && y < 17){
                for(int i = 0; i < 4; i++)
                    tempInt *= grid[x+i][y+i];
                if(tempInt > largest){
                    largest = tempInt;
                }
                tempInt = 1;
            }//Close right diagonal check

            if(x > 3 && y < 17){
                for(int i = 0; i < 4; i++)
                    tempInt *= grid[x+(-i)][y+(-i)];
                if(tempInt > largest){
                    cout << x << "" << largest << " " << y << endl;
                    largest = tempInt;
                }
                tempInt = 1;
            }//Close left diagonal check
           
        }//Close y loop
    }//Close x loop

    cout << largest << endl;

    return 0;
}

int parseInt(string toParse){
    return (toParse[0]-48) *10 + toParse[1]-48;
}
