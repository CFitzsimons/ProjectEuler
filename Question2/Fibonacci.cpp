/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=1
*   Date: 10/2/2013
*/
#include <iostream>
using namespace std;

int main(){
    int fibonacci(int, int);
    cout << fibonacci(1,1);
    
    return 0;
}

int fibonacci(int first, int second){
    if(second >= 1000000)
        return 0;
    else{
        int temp = fibonacci(second, first+second);
        if((first) % 2 == 0)
            return temp + first;
        else
            return temp;
    }
}