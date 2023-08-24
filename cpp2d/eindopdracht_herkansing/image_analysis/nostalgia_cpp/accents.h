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
    void findAccentPos(int hueMin, int hueMax, int indicator);

protected:
    //variable for storing the indicator of the accent
    int accentInd;
    //variable for storing the color of the accent
    string accentColor;
    //a vector in for the accent colors because i dont know how much accents there are at the start
    vector<pair<string,int>> accentColors;
    //a vector to store the x and y coordinates of the colors in according to the indicator of the color
    map<int, tuple<int,int>> accentXY;

};

#endif
