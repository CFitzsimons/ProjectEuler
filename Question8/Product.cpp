/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=8
*   Date: 17/2/2013
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

short parseShort(char);

int main(){
    ifstream readFile;
    readFile.open("Numbers.txt");
    string number;
    readFile >> number;
    int largest = -1;
    int temp = 1;
    for(string::size_type i = 0; i < number.length()-5; i++){
        for(short k = i; k < i+5;k++)
            temp *= parseShort(number[k]);
        if(temp > largest)
            largest = temp;
        temp = 1;
    }    
    cout << largest;
    
    return 0;
}
/*
*   Name: parseShort
*   Description: Created specificly for the conversion of a singular
*                character to a short value.  Assumes input is correct.
*/
short parseShort(char convert){
    return convert - 48;
}