//function mapInRange to scale numbers of an input range to an output range 
#include <iostream>

double mapInRange(double factor, double xLow, double xHigh, double yLow, double yHigh){ //dynamic function to calculate a point on y-axes
    double Output = (yLow * (xHigh - factor) + yHigh * (factor - xLow))/(xHigh - xLow);
    return Output;
}

double linearMap(double factor, double low, double high){ //reduce the map in range function to a function that is linear from 0 to 1
  float Output = mapInRange(factor, 0, 1000, low, high); //x1 = 0 and x2 = 1, choose y1 and y2 yourself so its flexible
  return Output;
}

int main(){
    
    float test = linearMap(5000, 0, 48000);
    std::cout << "this is the test: " << test << std::endl;
    return 0;
}