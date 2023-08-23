#include "colorScheme.h"

ColorScheme::ColorScheme(string path) : ColorPercentage(path){
    pathToImg = path;
    srcImg = imread(pathToImg);
};

ColorScheme::~ColorScheme(){

};

void ColorScheme::calculatePer() {
    rgbToHsv();
    colorMask();
    pixelColors();
    percentageColors();
}

void ColorScheme::mainColor() {

    //initialize a variable for the highest value, is lower then all the values in the map
    float highestValue = -1.0f;
    //initialize a variable for the main color
    string mainColor;
    //initialize a variable for the indicator of the main color
    int mainColorIndicator;

    //for loop to find the highest value and return the matching key
    for (const auto& mapPair : colorPerMap){//mapPair is the pair that refers to the key in the map colorPerMap.
        if (get<0>(mapPair.second) > highestValue){//.second refers to the tuple that's part of a certain key. get<0> is the first value of the tuple, get<1> should be the second
            highestValue = get<0>(mapPair.second);
            mainColor = mapPair.first;//.first is the name of the key
            mainColorIndicator = get<1>(mapPair.second);
        }
    }

    mColor = mainColor;
    mColorIndicator = mainColorIndicator;
    std::cout << "the main color of the drawing is: " << mColor << std::endl;
//    std::cout << "the main color indicator of the drawing is: " << mColorIndicator << std::endl;
}

void ColorScheme::subColorsIndicators() {
    int arr = 0;
    for(int i = -1; i <= 1; i++){ //for loop that is going from -2 to 2.
        int result = (mColorIndicator + i - 1 + 10) % 10 + 1; //each step the i in the forloop is added to the mColorIndicator. Using -1 and +1 because my indicators going from 1 to 10 and modulo 0 to 9
        if(result != mColorIndicator){
            sColorIndList[arr] = result;
            arr++;
        }
    }
    sColorIndicator1 = sColorIndList[0];
    sColorIndicator2 = sColorIndList[1];
//    //showing the results
//    for(int v : sColorIndList){
//        std::cout << "this is the list: " << v << std::endl;
//    }

}

void ColorScheme::subColors() {
    string subColor;
    int numberOfSubC = 1;
    for (const auto& mapPair : colorPerMap){
        if (get<1>(mapPair.second) == sColorIndicator1 || get<1>(mapPair.second) == sColorIndicator2  ) {
            subColor = mapPair.first;
            sColors.push_back(subColor);
            std::cout << "this is sub color " << numberOfSubC << ": " << subColor << std::endl;
            numberOfSubC++;
        }
    }
}

void ColorScheme::harmonyFinder() {
    float mainSubPercentage = 0;//total percentage of the main and the subcolors combined
    //for loop to find the highest value and return the matching key
    for (const auto& mapPair : colorPerMap){//mapPair is the pair that refers to the key in the map colorPerMap.
        if (get<1>(mapPair.second) == sColorIndicator1 || get<1>(mapPair.second) == sColorIndicator2 || get<1>(mapPair.second) == mColorIndicator ){//.second refers to the tuple that's part of a certain key. get<0> is the first value of the tuple, get<1> should be the second
            mainSubPercentage = mainSubPercentage + get<0>(mapPair.second);
            std::cout << "this is the percentage of the main and subcolors combined: " << mainSubPercentage << std::endl;
        }
    }

    std::cout << "The total percentage of the main color: " << mColor << " and the sub colors: " << sColors.at(0) << " and " << sColors.at(1) << " combined is: " << mainSubPercentage << "." << std::endl;

    if(mainSubPercentage > 75.0){
        std::cout << "This states that the drawing is most likely to have a harmonic color scheme. " << std::endl;
    }else{
        std::cout << "This states that the drawing is most likely to have a disharmonic color scheme, the colors are more spread out. " << std::endl;
    }
}

