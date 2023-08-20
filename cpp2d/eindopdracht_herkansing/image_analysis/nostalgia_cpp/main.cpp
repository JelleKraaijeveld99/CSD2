#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include "analyse.h"
#include "featureAnalyser.h"
#include <filesystem>

using namespace cv;

int main() {
    //initialise
    Analyse analyse;
    FeatureAnalyser FeatureAnalyser("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/CodingHKU/cpp2d/eindopdracht_herkansing/image_analysis/nostalgia_cpp/crayon_features_1.jpg");
    //function for calculating the percentage of each color in the picture
//    analyse.colorAnalyse("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/CodingHKU/cpp2d/eindopdracht_herkansing/image_analysis/nostalgia_cpp/crayon_features_1.jpg");
//    //let the program wait
//    analyse.colorPercentage();
//    analyse.sendPercentageOSC();
    waitKey(0);
    destroyAllWindows();
    return 0;
}

