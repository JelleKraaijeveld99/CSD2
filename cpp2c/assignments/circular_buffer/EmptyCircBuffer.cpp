#include "EmptyCircBuffer.h"
#include <iostream>

//////////PUBLIC//////////

CircBuffer::CircBuffer(uint size) : currentSize(size), buffer(new float[currentSize]) { // constructor
std::cout << "this is the size: "<< size << std::endl;
std::cout << "this is the current size: "<< currentSize << std::endl;
std::cout << "this is the addres of the buffer: "<< buffer[0] << std::endl;
}

CircBuffer::~CircBuffer() { // deconstructor 
    deleteBuffer();
}

void CircBuffer::input(float value){
    buffer[writeHead] = value; // add value to buffer on the writeHead index
    std::cout << "this is the write header before: "<< writeHead << std::endl;
    std::cout << "this is the added value: "<< buffer[writeHead] << std::endl;
    incrementWrite();
    std::cout << "this is the write header after: "<< writeHead << std::endl;
    wrapHeader(writeHead);
}

float CircBuffer::output(){ //function for returning a value from the buffer (read)

}

void CircBuffer::setDistance (uint distance){ // set the difference in a number between writehead and readhead (delay)

}


void CircBuffer::incrementHeads(){ // increment both heads with a value

}

///////////PRIVATE//////////

inline void CircBuffer::wrapHeader(uint& head){ // function for "wrapping" an index for a header
    if (head > currentSize) {
        head = 0;
    };
} 

inline void CircBuffer::incrementWrite(){ // add a value to the writeHead
    writeHead += 1;
}

inline void CircBuffer::incrementRead(){ // add a value to the readHead
    readHead += 1;
}

void CircBuffer::deleteBuffer(){  // function for deleting the buffer 

}
