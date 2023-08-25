#ifndef _CSCH_H_
#define _CSCH_H_
#pragma once

#include "colorPercentage.h"
#include <string>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;


class ColorScheme : public ColorPercentage {
public:
    //concstructor and destructor
    ColorScheme(string path);
    ~ColorScheme();

    //function that uses the color percentage class to calculate all color percentages needed in color scheme
    void calculatePer();
    //function to find the main color of the drawing
    void mainColor();
    //function of finding the sub colors indicators of the drawing according to the indicator of the main color
    void subColorsIndicators();
    //function of finding the sub colors according to the main color
    void subColors();
    //function that returns if the drawing has a harmonic or disharmonic colorscheme
    void harmonyFinder();

protected:
    //variable to store the main color
    string mColor;
    //variable for storing the indicator of the main and sub colors, going from 1 to 10 each color in the hsv scale has is own value
    int mColorIndicator;
    int sColorIndicator1;
    int sColorIndicator2;
    //vector for the sub colors;
    vector<string> sColors;
    int sColorIndList[2];

};

#endif