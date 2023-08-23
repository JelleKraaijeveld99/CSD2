#include "colorScheme.h"

ColorScheme::ColorScheme(string path) : ColorPercentage(path){
    pathToImg = path;
    srcImg = imread(pathToImg);
};

ColorScheme::~ColorScheme(){

};

void ColorScheme::calculatePer() {
    rgbToHsv();
    colorMask();
    pixelColors();
    percentageColors();
}

void ColorScheme::mainColor() {

    //initialize a variable for the highest value
    float highestValue = -1.0f;
    //initialize a variable for the main color
    string mainColor;

    //for loop to find the highest value and return the matching key
    for (const auto& mapPair : colorPerMap){
        if (mapPair.second > highestValue){
            highestValue = mapPair.second;
            mainColor = mapPair.first;
        }
    }

    mColor = mainColor;
    std::cout << "the main color of the drawing is: " << mColor << std::endl;
}

void
