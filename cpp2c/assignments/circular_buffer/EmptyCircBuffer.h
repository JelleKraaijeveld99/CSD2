//
// Created by Dean on 05/02/2023.
//

#pragma once

class CircBuffer{
    using uint = unsigned int; //make "unsigned int" shorter

public:
    CircBuffer(uint size); // constructor of the CircBuffer class that expects the size of the buffer, giving that value to currentSize
    ~CircBuffer(); // deconstructor of the CircBuffer class, deleting the buffer
        
    void input (float value); //function for adding the input to the buffer (write)
    float output(); //function for returning a value from the buffer (read)
    void setDistance (uint distance);// set the difference in a number between writehead and readhead (delay)
    float getWriteHead();
    void incrementHeads(); // increment both heads with a value

private:
    inline void wrapHeader (uint& head); // function for "wrapping" an index for a header
    inline void incrementWrite(); // add a value to the writeHead
    inline void incrementRead(); // add a value to the readHead
    void deleteBuffer(); // function for deleting the buffer 

    uint currentSize { 0 }; // variable for the size of the buffer
    uint writeHead { 0 }, readHead { 0 }; //variables for the index of a header
    float* buffer; // empty pointer for a buffer
    
};  