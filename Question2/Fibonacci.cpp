/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=2
*   Date: 10/2/2013
*/
#include <iostream>
using namespace std;

int fibonacci(int, int);

int main(){
    cout << fibonacci(1,1);
    
    return 0;
}
/*
* Method recurivly calls itself to progress in the fibonacci sequence.
* Once the 'second' value exceeds four-million the program begins to
* return all even value terms until reaching the end.
*/
int fibonacci(int first, int second){
    if(second >= 4000000)
        return first;
    else{
        int temp = fibonacci(second, first+second);
        //Check to see if the number is even
        if((first) % 2 == 0)
            return temp + first;
        else //Don't add anything if it isn't
            return temp;
    }
}
