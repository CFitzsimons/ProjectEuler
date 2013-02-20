#include <iostream>
#include <cmath>
using namespace std;

short intAt(int, int);
int size(int);
int main(){
    cout << "Enter in the number" << endl;
    int number, loc;
    cin >> number;
    cout << "Enter in the location" << endl;
    cin >> loc;
    
    cout << intAt(number, loc) << endl;
    cout << "Num size is: " << size(number) << endl;
    return 0;
}
int size(int check){
    int size = 1;
    while(check > 10){
        check /= 10;
        size++;
    }
    return size;
}
short intAt(int num, int i){
    int negate = 1;
    if(i < 0){
        cout << "Fatal-Error: IndexOutOfBounds!" << endl;
        return 0;
    }else if(num < 0){
        negate = -1;
        num*-1;
    }
    while(num > pow(10,i+1)){
        cout << num << endl;
        num/=10;
    }
    if(num < 10)
        return num;
    else
        return negate*(num%(num/10));
}