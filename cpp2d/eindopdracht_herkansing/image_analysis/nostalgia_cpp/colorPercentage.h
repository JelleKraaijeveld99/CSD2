#ifndef _COLPER_H_
#define _COLPER_H_
#pragma once

#include "featureAnalyser.h"
#include <string>
#include <utility>

class ColorPercentage : public FeatureAnalyser{

public:
    //constructor and destructor
    ColorPercentage(string path);
    ~ColorPercentage();

    //function that might come in handy in the subclasses
    void rgbToHsv();
    //function for masking the colors
    void colorMask();
    //function for calculating amount of pixels that have certain color
    void pixelColors();
    //function for calculating the percentage pixels of a certain color according to the total amount of colored pixels
    void percentageColors();

protected:
    //the hsv channels after masking, only using channel 0 for now because that is the hue value
    Mat maskedChannels[3];
    //store the HSV values in three channels
    Mat hsvChannels[3];
};

#endif