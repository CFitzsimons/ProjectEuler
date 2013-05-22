/*
*   Author:  Colin Fitzsimons
*   Date:    22/5/2013
*   Problem: http://projecteuler.net/problem=12
*   Note: Uses a string variable to track the very large integer.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

short parseShort(char c);

int main(){
    fstream numbers;
    //Open file and begin reading.
    numbers.open("Input.txt");
    string allInputs [100];
    for(int i = 0; i < 100; i++){
        getline(numbers, allInputs[i]);
    }
    //Finish file reading.
    
    //Begin calculation
    ostringstream result;
    string sum = "";
    int currentSum = 0;
    //Loop to track index of individual numbers
    for(int i = 49; i >= 0; i--){
        //Loop to track each number provided
        for(int k = 0; k < 100; k++){
            currentSum += parseShort(allInputs[k][i]);
        }        
        //Place the integer into a stream
        result << (int)(currentSum%10);
        //Output the stream and concatonate it.
        sum = result.str() + sum;
        
        //Clear the stream.
        result.str("");
        currentSum = (currentSum/10);  

    }
    result << currentSum;
    sum = result.str() + sum;
    //Flush stream and print result.
    result.flush();
    cout << sum.substr(0,10) << endl;
    return 0;
}

short parseShort(char c){
    //No checking is done here.
    return (int)(c - 48);  
}