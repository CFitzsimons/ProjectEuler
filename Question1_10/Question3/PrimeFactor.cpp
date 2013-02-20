/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=3
*   Date: 10/2/2013
*   Note: I decided to leave in my testing printouts,
*         these we're used to test individual pieces of code.
*/
#include <iostream>
#include <cmath>
using namespace std;

//Method definitions//
bool checkPrime(long);

int main(){
    long long number = 600851475143;
    
    long int root = sqrt(number);
    /*
    * Some considerations are made here:
    * 1. That a prime factor cannot be larger then
    *    then square root of the number in question.
    * 2. That prime numbers, with the exception of 2,
    *    are all odd therefore we can skip over even numbers.
    */
    if(root % 2 == 0)
        root--;
    for(unsigned long i = root; i > 0; i = i - 2){
        //First check: Does i divide evenly into number in question?
        if(number % i == 0){
            //Second check: Is it not disivable by 3 and 5?
            if(i%3!=0 && i%5!=0){
                //cout << "Sending " << i << " for check. \n";
                //Third check: Is the number prime?
                if(checkPrime(i)){
                    cout << i;
                    break;
                }
            }
        }
    }
    return 0;
}
/*
*   Method: checkPrime
*   Description:
*   Takes in a number and systematicly checks if it is prime.
*/
bool checkPrime(long check){
    //cout << "Entering check with number: " << check << "\n";
    long root = sqrt(check);
    for(int i = root -1; i > 1; i--){
        if(check%i == 0)
            return false;
    }
    //cout << "Check failed, returning to main \n";
    return true;
}

