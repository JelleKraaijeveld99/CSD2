#ifndef _ACC_H_
#define _ACC_H_
#pragma once

#include "colorPercentage.h"
#include <string>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

class Accents : public ColorPercentage {
public:
    //constructor/destructor
    Accents(string path);
    ~Accents();
    //function for calculating all the color percentages
    void calculatePer();
    //find the color of the accent
    void findAccentColor();
    //find the position of the accent
    void findAccentPos();

protected:
    //variable for storing the indicator of the accent
    int accentInd;
    //variable for storing the color of the accent
    string accentColor;
};

#endif
