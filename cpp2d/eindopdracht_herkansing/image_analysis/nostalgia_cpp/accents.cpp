#include "accents.h"

Accents::Accents(std::string path) : ColorPercentage(path) {
    pathToImg = path;
    srcImg = imread(pathToImg);
}

Accents::~Accents() {

}

void Accents::calculatePer() {
    rgbToHsv();
    colorMask();
    pixelColors();
    percentageColors();
}

void Accents::findAccentColor() {

}

void Accents::findAccentPos() {

}

