/*
*   Author:     Colin Fitzsimons
*   Problem:    http://projecteuler.net/problem=14
*   Date:       1/8/2013
*   Github:     http://github.com/cfitzsimons
*   Time:       
*/

#include <iostream>
using namespace std;

int collatzNum(int, int []);

int main(){
    int maxChain = 0;
    int max = 0;
    
    //Create a pointer for a dynamic array.
    int* p_knownSeq = new int [1000000];

    for(int i = 1000000; i >= 1; i--){
        int currentChain;
        
        if(p_knownSeq[i] != 0){
            currentChain = p_knownSeq[i];
        }else{
            currentChain = collatzNum(i, p_knownSeq);
            p_knownSeq[i] = currentChain;
        }
        
        //Check if the chain is the longest one found.
        if(currentChain > maxChain){
            max = i;
            maxChain = currentChain;
        }
    }
    
    //MaxChain has to be increased by 1 because the counting starts at 0 here.
    cout << max  << " " << maxChain + 1 << endl;
    return 0;
}

/*
*   Method to calculate the number of items gone though in a Collatz
*   sequence.  
*   Returns the number of chains produced by the number following the Collatz
*   rules:
*       - n -> n/2 (when n is even)
*       - n -> 3n + 1 (when n is odd)
*/
int collatzNum(int toConvert, int* array){
    long long number = toConvert;
    int numItems = 0;
    //Loop until the sequence has been returned to 1
    while(number > 1){
        if(number % 2 != 0){
            number *= 3;
            number++;
            numItems++;
        }else{
            number /= 2;
            numItems++;
        }
        if(number < 1000000 && array[number] != 0){
                numItems += array[number]; //Code repetition?
                break;
        }
        
    }
    return numItems;
}
