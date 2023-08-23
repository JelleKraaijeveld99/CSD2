#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include "analyse.h"
#include "featureAnalyser.h"
#include "colorPercentage.h"
#include "colorScheme.h"
#include <filesystem>

using namespace cv;

int main() {
    //initialise
//    Analyse analyse;

    FeatureAnalyser FeatureAnalyser("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/CodingHKU/cpp2d/eindopdracht_herkansing/image_analysis/nostalgia_cpp/crayon_features_3.jpg");
    ColorPercentage colorPercentage("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/CodingHKU/cpp2d/eindopdracht_herkansing/image_analysis/nostalgia_cpp/crayon_features_3.jpg");
    ColorScheme colorScheme("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/CodingHKU/cpp2d/eindopdracht_herkansing/image_analysis/nostalgia_cpp/crayon_features_2.jpg");

    //function for calculating the percentage of each color in the picture
//    analyse.colorAnalyse("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/CodingHKU/cpp2d/eindopdracht_herkansing/image_analysis/nostalgia_cpp/crayon_features_1.jpg");
//    //let the program wait
//    analyse.colorPercentage();
//    analyse.sendPercentageOSC();
//    colorPercentage.rgbToHsv();
//    colorPercentage.colorMask();
//    colorPercentage.pixelColors();
//    colorPercentage.percentageColors();
    colorScheme.calculatePer();
    colorScheme.mainColor();
    colorScheme.subColorsIndicators();
    colorScheme.subColors();

    waitKey(0);
    destroyAllWindows();
    return 0;
}

