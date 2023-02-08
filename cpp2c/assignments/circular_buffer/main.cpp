#include "EmptyCircBuffer.h"
#include <iostream>

int main(){
    int buffersize = 10; //initialise the buffersize 
    CircBuffer buffer(buffersize); //make a buffer object with the size of buffersize
    buffer.setDistance(4); //set the distance between the write and the read head (DELAY)
    
    for(int i=0; i<buffersize*2; i++){ //forloop to test everything
    buffer.input(0.2); //"write" the value 0.2 in the buffer
    buffer.output(); //"read" a value in the buffer
    buffer.incrementHeads(); //add +1 to both the readHead and writeHead
    };

    return 0;
}