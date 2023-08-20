#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include "analyse.h"
#include <filesystem>

using namespace cv;

int main() {
    //initialise
    Analyse analyse;
    //function for calculating the percentage of each color in the picture
    analyse.colorAnalyse("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/nostalgie/image_analysis/nostalgia_cpp/crayontest1.jpg");
    //let the program wait
    waitKey(0);
    destroyAllWindows();
    return 0;
}

