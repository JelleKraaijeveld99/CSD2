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
    void incrementHeads(); // increment both heads with a value

    //setters and getters
    void setDistance (uint distance);// set the difference in a number between writehead and readhead (delay)
    void getResetSize(uint size); //function for getting what the "new" size is, but waiting to execute when readHead is 0
    float getCurrentSize(); //get the current size of the buffer

private:
    inline void wrapHeader (uint& head); // function for "wrapping" an index for a header
    inline void incrementWrite(); // add a value to the writeHead
    inline void incrementRead(); // add a value to the readHead
    void deleteBuffer(); // function for deleting the buffer 
    void deleteResizedBuffer(); //function for deleting resized buffer
    void resetSize(uint size);//function for actually resetting the size

    uint newSizeBuffer { 0 }; //buffer for saving what the new size is but waiting to make it the current size till readHead is 0
    uint wrapValue { 0 }; //value for wrapping
    uint currentDistance { 0 }; //the distance between the write and readHead
    uint currentSize { 0 }; // variable for the size of the buffer
    uint writeHead { 0 }, readHead { 0 }; //variables for the index of a header

    float* buffer; // empty pointer for a buffer
    float* resizedBuffer; //empty pointer for a buffer if you want to resize 

    
    bool resize = false; //boolean for resizing the buffer when readhead is 0
};  