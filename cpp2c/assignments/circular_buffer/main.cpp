#include "EmptyCircBuffer.h"
#include <iostream>



int main(){
    int buffersize = 10; //initialise the buffersize 
    CircBuffer buffer(buffersize); //make a buffer object with the size of buffersize
    buffer.setDistance(3); //set the distance between the write and the read head (DELAY)
    float valueList[10] = {1,2,3,4,5,6,7,8,9,10};

    
    for(int i=0; i<10; i++){ //forloop to test everything
        buffer.input(valueList[i % 10]); //"write" the value 0.2 in the buffer
        buffer.output(); //"read" a value in the buffer
        buffer.incrementHeads(); //add +1 to both the readHead and writeHead
        if(i==7){
            buffer.getResetSize(4);
        }

        if(i==20){
            buffer.getResetSize(14);
        }

    };

    // int test = msToSamples(1000,48000);
    // std::cout << test << "LOOOK" << std::endl;
    return 0;
}