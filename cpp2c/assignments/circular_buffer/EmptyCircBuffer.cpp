#include "EmptyCircBuffer.h"
#include <iostream>
#include <algorithm>
#include <iterator>

//////////PUBLIC//////////

CircBuffer::CircBuffer(uint size) : currentSize(size), buffer(new float[currentSize])

{ // constructor
    std::cout << "THIS IS THE CONSTRUCTOR" << std::endl;
    wrapValue = currentSize;
    for (uint i = 0; i < sizeof(buffer); i++){
        buffer[i] = 0;
    }

}

CircBuffer::~CircBuffer() { // deconstructor 
    std::cout << "THIS IS THE DECONSTRUCTOR" << std::endl;
    deleteBuffer();
}

void CircBuffer::input(float value){
    buffer[writeHead] = value; // add value to buffer on the writeHead index
    // std::cout << value << " IS THE INPUT" << std::endl;
}

float CircBuffer::output(){ //function for returning a value from the buffer (read)
    std::cout << buffer[readHead] << " IS THE OUTPUT" << std::endl;
    return buffer[readHead];
}

void CircBuffer::setDistance (uint distance){ // set the difference in a number between writehead and readhead (delay)
    currentDistance = distance;
    int readHeadBuffer = writeHead - distance;
    if(readHeadBuffer < 0){
        readHead = readHeadBuffer + currentSize;
    } else {
        readHead = readHeadBuffer;
    }
}


void CircBuffer::incrementHeads(){  // increment both heads with a value
    incrementRead();
    incrementWrite();
    wrapHeader(readHead);
    wrapHeader(writeHead);
}

void CircBuffer::getResetSize(uint size){
    resize = true;
    newSizeBuffer = size;
}

void CircBuffer::resetSize(uint size){
    
    wrapValue = size;
    resizedBuffer = new float[size];
    for (uint i = 0; i < sizeof(resizedBuffer); i++){
        resizedBuffer[i] = buffer[i];
    }
    deleteBuffer();

    buffer = new float[sizeof(resizedBuffer)];
    for (uint i = 0; i < sizeof(resizedBuffer); i++){
        buffer[i] = resizedBuffer[i];
    }
    deleteResizedBuffer();
    setDistance(currentDistance);
    resize = false;    
}


float CircBuffer::getCurrentSize(){
    return currentSize;
}

///////////PRIVATE//////////

inline void CircBuffer::wrapHeader(uint& head){ // function for "wrapping" an index for a header
    if (head >= wrapValue) {
         head = head - wrapValue;
    };
} 

inline void CircBuffer::incrementWrite(){ // add a value to the writeHead
    writeHead += 1;
}

inline void CircBuffer::incrementRead(){ // add a value to the readHead
   
   if(readHead == 0 && resize == true ){
        std::cout << "RESIZE IS TRUUUUUEEEE "<<  std::endl;
        resetSize(newSizeBuffer);
    }
    readHead += 1;
}

void CircBuffer::deleteBuffer(){  // function for deleting the buffer 
    delete[] buffer;
}

void CircBuffer::deleteResizedBuffer(){
    delete[] resizedBuffer;
}


//als writeHead groter is dan buffersize, wrapfunctie word writehead+1 totdat readHead 0 is, 
//dan wordt wrapfunctie weer de buffersize