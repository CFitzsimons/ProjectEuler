/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=1
*   Date: 10/2/2013
*/
#include <iostream>
using namespace std;

int main(){
    int sum = 0;
    for(int i = 1; i < 1000; i++){
        if(i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    cout << sum;
    return 0;
}