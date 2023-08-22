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
