#include <iostream>
using namespace std;

long double subFact(long double, long double);

int main(){
    const int size = 20;
    long double total = subFact(size*2, size);
    cout << total/subFact(size, 1) << endl;
    
    return 0;
}


//Just a quick method to calculate the factorial of a
//given number.
//Quite specific to reduce the number of iterations
//on factorial subtraction
long double subFact(long double num, long double toSub){
    if(num == toSub)
        return 1;
    else
        return subFact(num-1, toSub) * num;
}

//137846528820