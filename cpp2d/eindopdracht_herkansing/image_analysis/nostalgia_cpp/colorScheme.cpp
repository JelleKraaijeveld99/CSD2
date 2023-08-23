#include "colorScheme.h"

ColorScheme::ColorScheme(string path) : ColorPercentage(path){
    pathToImg = path;
    srcImg = imread(pathToImg);

    colorPerPointer = new ColorPercentage(pathToImg);
};

ColorScheme::~ColorScheme(){

};

void ColorScheme::calculatePer() {
    colorPerPointer -> rgbToHsv();
    colorPerPointer -> colorMask();
    colorPerPointer -> pixelColors();
    colorPerPointer -> percentageColors();
}

void ColorScheme::mainColor() {

}
