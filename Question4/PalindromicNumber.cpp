/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=4
*   Date: 13/2/2013
*   Note: The program takes a second or two to complete and I
*         feel that it could be written faster.  This is a brute
*         force approach.
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isPal(long);
string parseString(long);

int main(){

    int factorOne = 999, factorTwo = 999;
    long highest = 0;
    while(factorOne != 100){
        //Check if the two factors make a palindrome
        if(isPal(factorOne*factorTwo)){
            //If they do, check if they're the largest one found.
            if(factorOne*factorTwo > highest)
                highest = factorOne*factorTwo;
        }
        //If the two numbers are equal, reset factorTwo and 
        //decrement factorOne
        if(factorOne == factorTwo){
            factorOne--;
            factorTwo = 999;
        }else
            factorTwo--;
    }
    cout << "Highest palindromic value is: " << highest;
    
    return 0;
}
/*
* Name :isPal
* Description: Takes a long integer and checks if it is palindromic.
* - A palindomic number/string is one that reads the same both ways.
*   i.e. 011110 or "racecar"
*/
bool isPal(long toCheck){
  
    string checkStr = parseString(toCheck);
    
    for(int i = 0; i < checkStr.length()/2; i++){
        if(checkStr[i]!=checkStr[(checkStr.length()-1)-i])
            return false;
    }
    //cout << "Exiting with true valuet\n";
    return true;
}
/*
* Name: parseString
* Description: Takes a long integer and converts it to a string.
*/
string parseString(long convert){
    stringstream out;
    out << convert;
    return out.str();
}