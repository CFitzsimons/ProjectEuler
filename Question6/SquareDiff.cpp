/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=6
*   Date: 16/2/2013
*/

#include <iostream>
using namespace std;

int main(){
    //SquareNow holds the sum of all numbers 1 to 100 squared.
    int squareNow = 0;
    //squareAfter holds the sum of all numbers 1 to 100.
    int squareAfter = 0;
    //Loop runs twenty times to generate the numbers 1 to 100.
    for(int i = 1; i <= 100; i++){
        squareNow += (i*i);
        squareAfter += i;
    }
    cout << (squareAfter*squareAfter - squareNow);
    return 0;
}