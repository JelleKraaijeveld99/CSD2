#include "colorPercentage.h"

ColorPercentage::ColorPercentage(string path) : FeatureAnalyser(path) {

}

ColorPercentage::~ColorPercentage() {

}

void ColorPercentage::rgbToHsv() {
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

void ColorPercentage::colorMask() {
    // apply mask to remove 'too white colors'
    // should result in an image without the polygon
    // create a mask image
    Mat saturationMask;

    // E.G. --> with mask 20 or 10, different results
    int thresholdValue = 20;
    threshold(hsvChannels[1], saturationMask,thresholdValue, 255, THRESH_BINARY_INV );
    saturationMask = 255 - saturationMask;
//    threshold(hsvChannels[1], saturationMask,thresholdValue, 255, THRESH_BINARY );
////    imshow("saturationMask", saturationMask);
//
//    // apply mask to filter out the color white
//    Mat maskedImg;
//    srcImg.copyTo(maskedImg, saturationMask);
//
//    Mat hsvMaskedImg;
//    cvtColor(maskedImg, hsvMaskedImg, cv::COLOR_BGR2HSV );
//
//    split(hsvMaskedImg,maskedChannels);
//    imshow("hue masked", maskedChannels[0]);
}