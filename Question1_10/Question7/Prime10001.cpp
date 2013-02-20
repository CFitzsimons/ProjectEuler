/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=7
*   Date: 16/2/2013
*/
#include <iostream>
using namespace std;

int nextPrime(int [], int toCheck);

int main(){
    int* allPrimes = new int[10001];
    //In order for this implementation to work, I needed to initalize
    //the first two prime numbers. (As 2 does not conform to the standard
    //definition of a prime number being odd)
    allPrimes[0] = 2;
    allPrimes[1] = 3;
    for(int i = 2; i < 10001; i++){
        //Here we pass in the array, as it is, and the number in the furtest
        //point in the array.
        allPrimes[i] = nextPrime(allPrimes, allPrimes[i-1]);
    }
    cout << allPrimes[10000];
    return 0;
}
/*
*   Name: nextPrime
*   Description:
*   Returns the next prime number, given an array of prime numbers and the
*   last known prime number.
*/
int nextPrime(int primes [], int toCheck){
    do{
        //We increment by two here to avoid unnecessary runtime.
        //(As all primes, barring 2 are odd)
        toCheck += 2;
        int i = 1;
        while(toCheck % primes[i] != 0){
            i++;
            if(primes[i] == 0)
                return toCheck;
        }
    }while(true);  
}