#ifndef _FEATA_H_
#define _FEATA_H_
#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include <utility>
#include "osc.h"
#include <lo/lo.h>
#include <map>
#include <tuple>

using namespace std;
using namespace cv;


class FeatureAnalyser {
public:
    //constructor and deconstructor
    FeatureAnalyser(string path);
    ~FeatureAnalyser();

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
    int cyan = 0;
    int purple = 0;
    int pink = 0;

    float perRed = 0.0f;
    float perOrange = 0.0f;
    float perYellow = 0.0f;
    float perLightGreen = 0.0f;
    float perDarkGreen = 0.0f;
    float perCyan = 0.0f;
    float perLightBlue = 0.0f;
    float perDarkBlue = 0.0f;
    float perPurple = 0.0f;
    float perPink = 0.0f;

    //a map to store all the color percentages and color index in
    map<string, tuple<float,int>> colorPerMap;

};

#endif