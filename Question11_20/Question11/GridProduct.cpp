#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int xySize = 20;
int parseInt(char, char);
int getProd(int [xySize][xySize],int, int, int, int);

int main(){
    int grid [xySize][xySize];
//FILE READING HAS BEEN TEST AND FOUND WORKING
    ifstream input;
    input.open("Numbers.txt");
    string next;
    //Populate the array with numbers from the file.
    for(int x = 0; x < xySize; x++){
        for(int y = 0; y < xySize; y++){
            input >> next;
            grid[x][y] = parseInt(next[0], next[1]);
        }//Close y
    }//Close x
//FILE READING END

    int largest = 0;
    int maxX = 16, maxY = 19, movX = 1, movY = 0;
    int i = 0;

    while(i < 2){
        //cout << "Entering while with " << i << endl;
        for(int x = 0; x < maxX; x++){
            for(int y = 0; y < maxY; y++){
                int temp = 1;
                for(int k = 0; k < 4; k++){
                    temp *= grid[x + movX*k][y+movY*k];
                    
                }
                
                if(temp > largest){
                    largest = temp;
                    cout << "Largest found at loc (" << x<<", " << y << ")" << endl;
                }
            }//Close y
        }//Close x
        //cout << "For loops have exited with i at: " << i << endl;
        if(i == 0){
            //cout << "Restarting loop with new vars attempt: " << i << endl;
            maxX = 19; maxY = 16; movX = 0; movY = 1;
        }else if(i == 1){
            //cout << "Restarting loop with new vars attempt: " << i << endl;
            maxX = 16; maxY = 16; movX = 1;
        }
       i++;
    }//While loop seems active, but may not be working for attempts 2 and three.
    //cout << "Exited while with " << i << endl;

    maxX = 16; maxY = 19; movX = -1;movY = -1;
    for(int x = 0; x < maxX; x++){
        for(int y = 04; y < maxY; y++){
            int temp = 1;
            for(int k = 0; k < 4; k++)
                temp *= grid[x + movX*k][y+movY*k];
            cout << temp << endl;
            if(temp > largest){
                    largest = temp;
                    cout << "Largest found at loc (" << x<<", " << y << ")" << endl;
            }
        }
    }

    cout << largest << endl;

    return 0;
}

int parseInt(char left, char right){
    return (left-48)*10 + right-48;
}
