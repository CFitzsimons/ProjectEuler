/*
*   Author: Colin Fitzsimons
*   Problem: http://projecteuler.net/problem=9
*   Date: 17/2/2013
*/

#include <iostream>
using namespace std;

bool isTrip(int,int,int);

int main(){
    /*
    *   The loops below cycles though all possible numbers until
    *   a solution is found.  Some facts are taken into account here:
    *   1.  a < b < c must be true. Shown by: ( b = a+1 and c = b+1)
    *   2.  In this case, the maximum sum cannot exceed 1000 
    *       shown by the use of ( 1000 - a ) and (1000 - b)
    */
    for(int a = 1; a < 999; a++){
        for(int b = a+1; b < 1000-a; b++){
            for(int c = b+1; c < 1000-b; c++){
                //Do the numbers add up to 1000? If so, check if they are
                //Pythagorean triplets.
                if(a+b+c == 1000 && isTrip(a, b, c)){
                    cout << a*b*c; //Product of the three numbers
                    return 0;
                }
            }//Close c for loop
        }//Close b for loop
    }//Close a for loop
    cout << "Program exiting without solution";
    return 0;
}
/*
*   Name: isTrip
*   Description: Checks if three inputs form a Pythagorean triplet.
*/
bool isTrip(int a, int b, int c){
    //Because of the way the loops are set up we could omit
    //the second part of this return but I choose not to.
    return (a*a + b*b == c*c) && (a < b && b < c);
}
