#include "EmptyCircBuffer.h"
#include <iostream>

int main(){
    
    CircBuffer buffer(3);
    buffer.input(0.44);
    buffer.input(0.66);
    buffer.input(0.69);
    buffer.input(0.111);
    return 0;
}