#include <iostream>
using namespace std;

int collatzNum(int);

int main(){
    int maxChain = 0;
    int max = 0;
    for(int i = 0; i <= 1000000; i++){
        int currentChain = collatzNum(i);
        if(currentChain > maxChain){
            max = i;
            maxChain = currentChain;
        }
    }
    cout << max  << " " << maxChain << endl;
}

/*  NOTE TO SELF: Issue may lie with integer length, not formula
*   Method to calculate the number of items gone though in a collatz
*   sequence.  
*   Returns the number of chains produced by the number following the Collatz
*   rules:
*       - n -> n/2 (when n is even)
*       - n -> 3n + 1 (when n is odd)
*/
int collatzNum(int toConvert){
    long long number = toConvert;
    int numItems = 0;
    while(number > 1){
        if(number % 2 == 0)
            number /= 2;
        else{
            number *= 3;
            number++;
        }
        numItems++;
    }
    return numItems + 1;
}

