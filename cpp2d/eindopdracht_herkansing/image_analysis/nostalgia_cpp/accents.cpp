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
    //the boundaries of when a color is an accent
    float minValue = 2.0f;
    float maxValue = 6.5f;

    //for loop to find the highest value and return the matching key
    for (const auto& mapPair : colorPerMap){//mapPair is the pair that refers to the key in the map colorPerMap.
        if (get<0>(mapPair.second) >= minValue && get<0>(mapPair.second) <= maxValue){//.second refers to the tuple that's part of a certain key. get<0> is the first value of the tuple(percentage), get<1> should be the second(indicator)
            string accent = mapPair.first;
            accentColors.push_back(accent);
            cout << "this is the color of the accent: " << accent << endl;
        }
    }


}

void Accents::findAccentPos() {

}

