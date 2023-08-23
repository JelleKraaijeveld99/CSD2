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
    //function of finding the subcolors of the drawing
    void subColors();
    //function that returns if the drawing has a harmonic or disharmonic colorscheme
    void harmonyFinder();
    //function that returns the two colors with the biggest contrast
    void biggestContrast();

protected:
    //variable to store the main color
    string mColor;
    //vector for the sub colors;
    vector<string> sColors;

};

#endif