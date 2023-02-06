#include "EmptyCircBuffer.h"
#include <iostream>

int main(){
    
    CircBuffer buffer(3);
    std::cout << "this is the writeHead BEFORE: " << buffer.getWriteHead() << std::endl;
    buffer.input(0.44);
    std::cout << "this is the writeHead: " << buffer.getWriteHead() << std::endl;

    std::cout << "this is the writeHead BEFORE: " << buffer.getWriteHead() << std::endl;
    buffer.input(0.66);
    std::cout << "this is the writeHead: " << buffer.getWriteHead() << std::endl;
    
    std::cout << "this is the writeHead BEFORE: " << buffer.getWriteHead() << std::endl;
    buffer.input(0.69);
    std::cout << "this is the writeHead: " << buffer.getWriteHead() << std::endl;
    
    std::cout << "this is the writeHead BEFORE: " << buffer.getWriteHead() << std::endl;
    buffer.input(0.111);
    std::cout << "this is the writeHead: " << buffer.getWriteHead() << std::endl;
    return 0;
}