#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include "analyse.h"
#include "featureAnalyser.h"
#include "colorPercentage.h"
#include "colorScheme.h"
#include "accents.h"
#include <filesystem>

using namespace cv;

int main() {
    //initialise
    ColorScheme colorScheme("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/CodingHKU/cpp2d/eindopdracht_herkansing/image_analysis/nostalgia_cpp/crayon_features_3.jpg");
    Accents accents("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/CodingHKU/cpp2d/eindopdracht_herkansing/image_analysis/nostalgia_cpp/crayon_features_3.jpg");

    colorScheme.calculatePer(); //calculate percentages of the colors
    colorScheme.mainColor(); //find the main color of the drawing
    colorScheme.subColorsIndicators(); //find the sub-color indicators
    colorScheme.subColors(); //find the actual sub colors in text
    colorScheme.harmonyFinder(); //find if the drawing has a harmonic or dis-harmonic colorscheme

    accents.accentProcess();//process function for the accents class, more functions inside

    waitKey(0);
    destroyAllWindows();
    return 0;
}

