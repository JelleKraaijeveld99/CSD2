#include "EmptyCircBuffer.h"
#include <iostream>

int main(){
    int buffersize = 6; //initialise the buffersize 
    CircBuffer buffer(buffersize); //make a buffer object with the size of buffersize
    buffer.setDistance(3); //set the distance between the write and the read head (DELAY)
    float valueList[10] = {0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};
    // buffer.setWrapValue(buffer.getCurrentSize()); //set the wrap value to the current size
    
    for(int i=0; i<buffersize; i++){ //forloop to test everything
        buffer.input(valueList[i]); //"write" the value 0.2 in the buffer
        buffer.output(); //"read" a value in the buffer
        buffer.incrementHeads(); //add +1 to both the readHead and writeHead
        if(i == 4){
            buffer.resetSize(4);
        }
    };

    return 0;
}