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
        totalY++;//how many points on the y x-axis
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

    for (int x = 0; x < maskedChannels[0].cols; x++){
        totalX++;//how many points on the x-axis
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

    cout << "this is the average of the X pixels of the point: " << averageX << endl;
    cout << "this is the average of the Y pixels of the point: " << averageY << endl;

    //make a pair of the X and Y coordinates and push them into a vector
    accentCoodinates.push_back(make_pair(averageX, averageY));

    cout << "this is the total of the X pixels: " << totalX << endl;
    cout << "this is the total of the Y pixels: " << totalY << endl;
}

void Accents::showAccentPos(float xCo, float yCo, int xTotal, int yTotal) {
    //first calculate the size of the boxes, I want a 3x3 raster
    int boxWidth = xTotal/3;
    int boxHeight = yTotal/3;

    //column of the point;
    int column = xCo / boxWidth;
    int row = yCo / boxHeight;

    //store a string with the right height or width
    string height;
    string width;

    if(column == 0){
        height = "top ";
    }
    if(column == 1){
        height = "mid ";
    }
    if(column == 2){
        height = "bottom ";
    }

    if(row == 0){
        width = "left";
    }
    if(row == 1){
        width = "mid";
    }
    if(row == 2){
        width = "right";
    }

    cout << "The location of the accent is: " << height << width << endl;
}

void Accents::accentProcess() {
    calculatePer();//calculate all the percentages of the colors
    findAccentColor();//find which colors are the accents
    fillHueMap();//fill the map with matching colors and their min and max hue values

    //we need some variables that are used in the constructors of the functions
    int minValue = 0;
    int maxValue = 0;
    string color = "";
    int indicator = 0;

    for(const auto& accentPair : accentColors){//small for loop that goes through the (multiple) accents
        color = accentPair.first;//the first spot in the accentPair is the color
        indicator = accentPair.second;//the second spot is the indicator of the color
        for(const auto& colorPair : hueValues){//an other for loop that is looking for the min and max hue values in the hueValues map
            if(color == colorPair.first){//checking with an if statements if the color of the accents matches that with the one in the map
                minValue = colorPair.second.first;
                maxValue = colorPair.second.second;
            }
        }
        findAccentPos(minValue,maxValue,indicator);
    }

//    findAccentPos(0,0,1);
//    showAccentPos(1631.15, 1159.69, 3293, 2396);
}