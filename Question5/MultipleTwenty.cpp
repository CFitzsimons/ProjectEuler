/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=5
*   Date: 13/2/2013
*/

#include <iostream>
using namespace std;

bool checkAll(long);

int main(){
    long i = 38;
    // The loop below increments by 38, this was done to
    // speed up the program, checking the least likely divisable
    // number first (19) and ensuring that it is even ontop of
    // this fact (hense the 38, which is 19 + 19).
    do{
        i += 38;    
    }while(!checkAll(i));
    cout << i;
    return 0;
}

/*
* Name: checkAll
* Description: Returns true if all real integers up to 20 divide into
*              the input.
*/
bool checkAll(long checkMe){
    //If we check divisablility by twenty first, we can omit a
    //decent amount of results stright away.
    if(checkMe % 20 == 0){
        for(int i = 18; i > 0; i--){
            if(checkMe % i != 0)
                return false;
        }
        return true;
    }
    return false;
}