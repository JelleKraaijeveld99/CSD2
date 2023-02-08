#include "EmptyCircBuffer.h"
#include <iostream>

int main(){
    int buffersize = 10;
    CircBuffer buffer(buffersize);
    // buffer.setDistance(4);
    
    for(int i=0; i<buffersize*2; i++){
    std::cout << "this is the writeHead BEFORE: " << buffer.getWriteHead() << std::endl;
    buffer.input(0.2);
    std::cout << "this is the writeHead: " << buffer.getWriteHead() << std::endl;
    buffer.incrementHeads();
    };

    return 0;
}