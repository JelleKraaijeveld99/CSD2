#include "EmptyCircBuffer.h"
#include <iostream>

//////////PUBLIC//////////

CircBuffer::CircBuffer(uint size) : currentSize(size), buffer(new float[currentSize]) { // constructor
    std::cout << "THIS IS THE CONSTRUCTOR" << std::endl;
}

CircBuffer::~CircBuffer() { // deconstructor 
    std::cout << "THIS IS THE DECONSTRUCTOR" << std::endl;
    deleteBuffer();
}

void CircBuffer::input(float value){
    buffer[writeHead] = value; // add value to buffer on the writeHead index
    std::cout << value << " IS THE INPUT" << std::endl;
}

float CircBuffer::output(){ //function for returning a value from the buffer (read)
    std::cout << buffer[readHead] << " IS THE OUTPUT" << std::endl;
    return buffer[readHead];
}

void CircBuffer::setDistance (uint distance){ // set the difference in a number between writehead and readhead (delay)
    int readHeadBuffer = writeHead - distance;
    if(readHeadBuffer < 0){
        readHead = readHeadBuffer + currentSize;
    } else {
        readHead = readHeadBuffer;
    }
}

float CircBuffer::getWriteHead(){
    return writeHead;
}

void CircBuffer::incrementHeads(){ // increment both heads with a value
    incrementRead();
    incrementWrite();
    wrapHeader(readHead);
    wrapHeader(writeHead);
}

///////////PRIVATE//////////

inline void CircBuffer::wrapHeader(uint& head){ // function for "wrapping" an index for a header
    if (head >= currentSize) {
        head = head - currentSize;
    };
} 

inline void CircBuffer::incrementWrite(){ // add a value to the writeHead
    writeHead += 1;
}

inline void CircBuffer::incrementRead(){ // add a value to the readHead
    readHead += 1;
}

void CircBuffer::deleteBuffer(){  // function for deleting the buffer 
    delete[] buffer;
}
