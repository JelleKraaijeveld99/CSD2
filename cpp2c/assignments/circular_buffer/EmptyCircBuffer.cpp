#include "EmptyCircBuffer.h"

//////////PUBLIC//////////

CircBuffer::CircBuffer(uint size) : currentSize(size), buffer(new float[currentSize]) { // constructor

}

CircBuffer::~CircBuffer() { // deconstructor 
    deleteBuffer();
}

void CircBuffer::input(float value){

}

float CircBuffer::output(){ //function for returning a value from the buffer (read)

}

void CircBuffer::setDistance (uint distance){ // set the difference in a number between writehead and readhead (delay)

}


void CircBuffer::incrementHeads(){ // increment both heads with a value

}

///////////PRIVATE//////////

inline void CircBuffer::wrapHeader(uint& head){ // function for "wrapping" an index for a header

}

inline void CircBuffer::incrementWrite(){ // add a value to the writeHead

}

inline void CircBuffer::incrementRead(){ // add a value to the readHead

}

void CircBuffer::deleteBuffer(){  // function for deleting the buffer 

}
