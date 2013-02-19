/*
*   Author:     Colin Fitzsimons
*   Problem:    http://projecteuler.net/problem=10
*   Date:       19/2/2013
*/

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void storePrime(vector<int>&,int&, int);
long long vecSum(vector<int>&, int);

int main(){
    int size = 0;
    vector<int> primes(1000);
    primes[0] = 2;
    size++;
    for(vector<int>::size_type i = 3; i < 2000000; i += 2){
        for(int k = 0; k <= size; k++){
            //We only need to check the factors below the sqrt of
            //i becuase a prime numbers factors cannot exceed that.
            if(primes[k] > sqrt(i)){
                storePrime(primes, size, i);
                break;
            }else if(i % primes[k] == 0){
                break;
            }
        }//Close k loop
    }//Close i loop
    cout << vecSum(primes, size) << endl;
    return 0;
}


//**************************************//
//Summary:      Stores a prime number at the end of passsed vector
//Parameters:   Takes in an integer vector reference, it's size and
//              the int to be appended.
//Return:       Void
//**************************************//
void storePrime(vector<int>& allPrimes, int& size, int toAdd){
    if(size==allPrimes.size())
        allPrimes.resize(allPrimes.size()*2);
        
    allPrimes[size] = toAdd;
    size++;
}
//**************************************//
//Summary:      Get's the sum of all elements in a vector
//Parameters:   Vector reference and it's size
//Return:       Sum of all the vector elements
//**************************************//
long long vecSum(vector<int>& allPrimes, int size){
    //unsigned long long total = 0;
    long long total = 0;
    for(int i = 0; i < size; i++)
        total += allPrimes[i];
    return total;
 }