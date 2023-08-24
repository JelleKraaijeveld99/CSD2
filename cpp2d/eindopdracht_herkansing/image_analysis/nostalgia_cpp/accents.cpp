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

    //for loop to find an accent according the min and max percentage of the color
    for (const auto& mapPair : colorPerMap){//mapPair is the pair that refers to the key in the map colorPerMap.
        if (get<0>(mapPair.second) >= minValue && get<0>(mapPair.second) <= maxValue){//.second refers to the tuple that's part of a certain key. get<0> is the first value of the tuple(percentage), get<1> should be the second(indicator)
            string accent = mapPair.first;
            int indicator = get<1>(mapPair.second);
            //make a pair of the accent as a string and the indicator of the color
            accentColors.push_back(make_pair(accent, indicator));
        }
    }
    //check if there are any accents in the vector. If so, cout that there are some accents
    if(accentColors.size() > 0){
        cout << "The drawing seems to have some accents, the colors of the accents are: " << endl;
        for(const auto& pair : accentColors){
            cout << pair.first << endl;
        }
    }else{
        cout << "The drawing doesnt have any clear accents. " << endl;
    }
}

void Accents::findAccentPos(int hueMin, int hueMax, int indicator) {
    //2 lists for storing the x and y coordinates of the accent
    list<int> accentX;
    list<int> accentY;

    //for loop for getting through all the pixels in the picture
    for (int y = 0; y < maskedChannels[0].rows; y++) {
        for (int x = 0; x < maskedChannels[0].cols; x++) {
            uchar hueValue = maskedChannels[0].at<uchar>(y, x);
//            std::cout << "Pixel hue at (" << x << ", " << y << "): " << static_cast<int>(hueValue) << std::endl;
            pixelAmount++;
            if (indicator == 1) {//if the color of the accent is red i have a pre made hue value range because it needs to check 4 values
                //check the pixels that are in the hue range and store the coordinates in a list
                if ((hueValue > 0 && hueValue <= 10) || (hueValue >= 164 && hueValue <= 180)) {
                    accentX.push_back(x);
                    accentY.push_back(y);
                } else {
                    if (hueValue >= hueMin && hueValue <= hueMax) {
                        accentX.push_back(x);
                        accentY.push_back(y);

                    }
                }
            }
        }
    }
    //calculate the average of both lists to get a middlepoint
    float sumX;
    float sumY;

    for (int x: accentX) {
        sumX = sumX + x;
    }

    for (int y: accentY) {
        sumY = sumY + y;
    }

    float averageX = sumX / accentX.size();
    float averageY = sumY / accentY.size();

    cout << "this is the average of the X pixels: " << averageX << endl;
    cout << "this is the average of the Y pixels: " << averageY << endl;
}