#include "featureAnalyser.h"

FeatureAnalyser::FeatureAnalyser(std::string path) {
    //set the path to the image to path
    pathToImg = path;
    srcImg = imread(pathToImg);
    namedWindow("[sourceImage]", WINDOW_NORMAL);
    setWindowProperty("[sourceImage]", WND_PROP_AUTOSIZE, WINDOW_AUTOSIZE);
    imshow("[sourceImage]",srcImg);
}

FeatureAnalyser::~FeatureAnalyser() {

}

void FeatureAnalyser::setSrcImg(std::string path) {
    pathToImg = path;
    srcImg = imread(pathToImg);
}

void FeatureAnalyser::rgbToHsv() {
    //variable for the hsv img
    Mat hsv;
    cvtColor(srcImg, hsv, cv::COLOR_BGR2HSV );
    //split the hsv values into the 3 channels
    split(hsv, hsvChannels);
    
//    imshow("hue", hsvChannels[0]);
//    imshow("saturation", hsvChannels[1]);
//    imshow("value", hsvChannels[2]);
//    imshow("generated", srcImg);
}