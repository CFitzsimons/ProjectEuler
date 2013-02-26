/*
*   Author:  Colin Fitzsimons
*   Date:    26/2/2013
*   Problem: http://projecteuler.net/problem=12
*/

#include <iostream>
using namespace std;

int numFactors(int);

int main(){
    int i = 0, sum = 0;

    //Do while loop only submits triangular numbers.
    do{
        i++;
        sum += i;
    }while(numFactors(sum) <= 500);

    cout << sum << " is the first triangular number to exceed 500 factors"
        << endl;
    return 0;
}
//***************************************//
//Summary:      Get's the number of factors of a number
//Parameters:   The number to be factorized
//Return:       Number of factors in the passed number
//Note:         In it's current iteration the loop could
//              be quite slow when dealing with large numbers.
//**************************************//
int numFactors(int toFact){
    int numFactors = 2; //For 1 and the number itself
    //Loop runs for half the passed value.
    for(int i = 2; i < toFact/2; i++){
        if(toFact  % i == 0)
            numFactors++;
    }
    return numFactors;
}
