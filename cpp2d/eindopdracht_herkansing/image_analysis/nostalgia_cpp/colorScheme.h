#ifndef _CSCH_H_
#define _CSCH_H_
#pragma once

#include "colorPercentage.h"
#include <string>
#include <utility>
#include <iostream>

class ColorScheme : public ColorPercentage {
public:
    //function to find the main color of the drawing
    void mainColor();
    //function of finding the subcolors of the drawing
    void subColors();
    //function that returns if the drawing has a harmonic or disharmonic colorscheme
    void harmonyFinder();
    //function that returns the two colors with the biggest contrast
    void biggestContrast();
};

#endif