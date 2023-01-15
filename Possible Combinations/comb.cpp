//
//  main.cpp
//  BruteForce
//
//  Created by Rahul Verma on 11/01/23.
//

#include<iostream>
#include<string.h>
using namespace std;

int main(int argc, const char * argv[]) {
    
    char start = 97, end = 122;
    short int length;
    
    cout<<"Enter start: ";
    cin >> start;
    cout<<"Enter stop: ";
    cin >> stop;
    cout<<"Enter length: ";
    cin >> length;

    char array[length];
    char run = start;
    
    cout<<"Generated passwords: "<<endl;
    
    //initially
    for(int i=0; i<length; i++){
        array[i] = start;
    }
    
    //assigening last character to ptr for changing its value
    short int ptr = length;
    
    while(true){
        array[ptr] = run; //will update the first position of array
        run = run + 1;
        cout<<array<<endl;
        
        /*
            if value of first position goes 0 to 9 then it will change pointer to the next position in array and update its value by 1 before this it again updates
            value of first position to the 0.
            eg. on first position the value reaches to end(9) the next value of 9 is 10 for this first we to have again updates the first position value to 0 and then
                next positions value by 1.
        
           000
           001
           002
             .
             .
             .
           009
           010
        */
        if(run == end){
            array[ptr] = start;
            run = start;
            ptr = ptr - 1;
            array[ptr] = array[ptr] + 1; //updating next positions value by 1.
            if(array[ptr] > end){ //if value reaches at end it again updates to start value
                array[ptr] = start;
            }
            /*this part repeats the same prcedure that we are doing in first "if" constiotion but it just allows the functionality to move array pointer to next array position
              and check wether its values reaches it's end or not if it reaches it updates that poistions value by 1.
            */
            while(true){
                if(array[ptr] == end){ //checking its position if its end then
                    ptr = ptr - 1; //pointer values decrease by 1.
                    array[ptr] = array[ptr] + 1; //and increase the value by 1 of its value
                    if(array[ptr] > end){//if value reaches at end it again updates to start value
                        array[ptr] = start;
                    }
                }
                else if(array[ptr] != end){//if it's value not reaches at end then
                    ptr = length - 1; //the pointer value set to the length - 1
                    break; //and loop breaks
                }
            }
            ptr = ptr + 1; //pointer again goes to the first position of array from last.
        }
        if(array[0] == end){ //if on array[0]'s value reaches its end value the prgram stops.
            break;
        }
    }
    return 0;
}

/*
the idea behind is that, numbers are the possible combinations of digits and we are seeing the evey character present in computer keyboard and we are placing
them as numbers placed in appropriate manner.
after every cycle completion pointr shifts to left and update the nearest left value by 1


0000
0001
0002
0003
.
.
.
0009
0010
0011
 .
 .
 .
0099
0100


aaaa
aaab
aaac
aaad
.
.
.
aaba
aabb
aabc
aabd
.
.
.
aaca
aacb
aacc
.
.
.
zzzz
*/
