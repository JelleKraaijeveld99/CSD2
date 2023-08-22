#ifndef _FEATA_H_
#define _FEATA_H_
#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include <utility>
#include "osc.h"
#include <lo/lo.h>

using namespace std;
using namespace cv;


class FeatureAnalyser {
public:
    //constructor and deconstructor
    FeatureAnalyser(string path);
    ~FeatureAnalyser();

    //function that might come in handy in the subclasses
    void rgbToHsv();

    //setter
    void setSrcImg(string path);

protected:
    string pathToImg;

    //variable to store the source image
    Mat srcImg;
    //variable to store the gray image
    Mat grayImg;
    //variable to store the thresh image
    Mat threshImg;
   
    //total amount of pixels in the picture
    int pixelAmount = 0;

    //all colors to be analysed
    int lightGreen = 0;
    int darkGreen = 0;
    int red = 0;
    int darkBlue = 0;
    int lightBlue = 0;
    int orange = 0;
    int yellow = 0;

    //the percentages of the colors
    float perRed = 0.0;
    float perLightBlue = 0.0;
    float perDarkBlue = 0.0;
    float perDarkGreen = 0.0;
    float perLightGreen = 0.0;
    float perOrange = 0.0;
    float perYellow = 0.0;
};

#endif