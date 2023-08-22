#ifndef _COLPER_H_
#define _COLPER_H_
#pragma once

#include "featureAnalyser.h"

class ColorPercentage : public FeatureAnalyser{
public:
    //function for calculating amount of pixels that have certain color
    void pixelColors();
    //function for calculating the percentage pixels of a certain color according to the total amount of colored pixels
    void percentageColors();

protected:

};

#endif