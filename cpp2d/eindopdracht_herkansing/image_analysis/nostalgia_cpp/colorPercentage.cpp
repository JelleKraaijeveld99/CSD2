#include "colorPercentage.h"

ColorPercentage::ColorPercentage(string path) : FeatureAnalyser(path) {
    pathToImg = path;
    srcImg = imread(pathToImg);
}

ColorPercentage::~ColorPercentage() {

}

void ColorPercentage::rgbToHsv() {
    //variable for the hsv img
    Mat hsv;
    cvtColor(srcImg, hsv, cv::COLOR_BGR2HSV );
    //split the hsv values into the 3 channels
    split(hsv, hsvChannels);

}

void ColorPercentage::colorMask() {
    // apply mask to remove 'too white colors'
    // should result in an image without the polygon
    // create a mask image
    Mat saturationMask;

    // E.G. --> with mask 20 or 10, different results
    int thresholdValue = 100;
    threshold(hsvChannels[1], saturationMask,thresholdValue, 255, THRESH_BINARY_INV );
    saturationMask = 255 - saturationMask;
    threshold(hsvChannels[1], saturationMask,thresholdValue, 255, THRESH_BINARY );
    imshow("saturationMask", saturationMask);

    // apply mask to filter out the color white
    Mat maskedImg;
    srcImg.copyTo(maskedImg, saturationMask);

    Mat hsvMaskedImg;
    cvtColor(maskedImg, hsvMaskedImg, cv::COLOR_BGR2HSV );

    split(hsvMaskedImg,maskedChannels);
    imshow("hue masked", maskedChannels[0]);
}

void ColorPercentage::pixelColors() {
    //for loop for getting through all the pixels in the picture
    for(int y = 0; y <maskedChannels[0].rows; y++) {
        for (int x = 0; x < maskedChannels[0].cols; x++) {
            uchar hueValue = maskedChannels[0].at<uchar>(y, x);
//            std::cout << "Pixel hue at (" << x << ", " << y << "): " << static_cast<int>(hueValue) << std::endl;
            pixelAmount++;

            //check how many pixels are orange
            if(hueValue >= 11 && hueValue <= 25){
                orange++;
            }

            //check how many pixels are yellow
            if(hueValue >= 26 && hueValue <= 38){
                yellow++;
            }

            //check how many pixels are light green
            if(hueValue >= 39 && hueValue <= 45){
                lightGreen++;
            }

            //check how many pixels are dark green
            if(hueValue >= 46 && hueValue <= 80){
                darkGreen++;
            }

            //check how many pixels are cyan
            if(hueValue >= 81 && hueValue <= 89){
                cyan++;
            }

            //check how many pixels are blue
            if(hueValue >= 90 && hueValue <= 100){
                lightBlue++;
            }

            //check how many pixels are blue
            if(hueValue >= 101 && hueValue <= 130){
                darkBlue++;
            }

            //check how many pixels are purple
            if(hueValue >= 131 && hueValue <= 141){
                purple++;
            }

            //check how many pixels are pink
            if(hueValue >= 142 && hueValue <= 163){
                pink++;
            }

            //check how many pixels are red
            if((hueValue > 0 && hueValue <= 10)||(hueValue >= 164 && hueValue <= 180)){
                red++;
            }



//
        }
    }
//    std::cout << "amount of pixels: " << pixelAmount << std::endl;
//    std::cout << "amount of light green pixels: " << lightGreen << std::endl;
//    std::cout << "amount of dark green pixels: " << darkGreen << std::endl;
//    std::cout << "amount of red pixels: " << red << std::endl;
//    std::cout << "amount of light blue pixels: " << lightBlue << std::endl;
//    std::cout << "amount of darkblue pixels: " << darkBlue << std::endl;
//    std::cout << "amount of purple pixels: " << purple << std::endl;
//    std::cout << "amount of pink pixels: " << pink << std::endl;
//    std::cout << "amount of orange pixels: " << orange << std::endl;
//    std::cout << "amount of yellow pixels: " << yellow << std::endl;
//    std::cout << "amount of cyan pixels: " << cyan << std::endl;
}

void ColorPercentage::percentageColors() {
    int totalColoredPixels = red + darkBlue + lightBlue + darkGreen + lightGreen + purple + pink + orange + yellow + cyan;

    //variables for storing the percentages in
    perRed = ((float) red/totalColoredPixels)*100.0;
    perLightBlue = ((float) lightBlue/totalColoredPixels)*100;
    perDarkBlue = ((float) darkBlue/totalColoredPixels)*100;
    perLightGreen = ((float) lightGreen/totalColoredPixels)*100;
    perDarkGreen = ((float) darkGreen/totalColoredPixels)*100;
    perPurple = ((float) purple/totalColoredPixels)*100;
    perPink = ((float) pink/totalColoredPixels)*100;
    perOrange = ((float) orange/totalColoredPixels)*100;
    perYellow = ((float) yellow/totalColoredPixels)*100;
    perCyan = ((float) cyan/totalColoredPixels)*100;

    colorPerMap["red"] = make_tuple(perRed,1);
    colorPerMap["light blue"] = make_tuple(perLightBlue,7);
    colorPerMap["dark blue"] = make_tuple(perDarkBlue,8);
    colorPerMap["light green"] = make_tuple(perLightGreen,4);
    colorPerMap["dark green"] = make_tuple(perDarkGreen,5);
    colorPerMap["purple"] = make_tuple(perPurple,9);
    colorPerMap["pink"] = make_tuple(perPink,10);
    colorPerMap["orange"] = make_tuple(perOrange,2);
    colorPerMap["yellow"] = make_tuple(perYellow,3);
    colorPerMap["cyan"] = make_tuple(perCyan,6);

    std::cout << "% of light green pixels: " <<  get<0>(colorPerMap["light green"]) << std::endl;
    std::cout << "% of dark green pixels: " << get<0>(colorPerMap["dark green"]) << std::endl;
    std::cout << "% of red pixels: " << get<0>(colorPerMap["red"]) << std::endl;
    std::cout << "% of light blue pixels: " << get<0>(colorPerMap["light blue"]) << std::endl;
    std::cout << "% of darkblue pixels: " << get<0>(colorPerMap["dark blue"]) << std::endl;
    std::cout << "% of purple pixels: " << get<0>(colorPerMap["purple"]) << std::endl;
    std::cout << "% of pink pixels: " <<  get<0>(colorPerMap["pink"]) << std::endl;
    std::cout << "% of orange pixels: " << get<0>(colorPerMap["orange"]) << std::endl;
    std::cout << "% of yellow pixels: " << get<0>(colorPerMap["yellow"]) << std::endl;
    std::cout << "% of cyan pixels: " << get<0>(colorPerMap["cyan"])  << std::endl;


}

void ColorPercentage::fillHueMap() {

    hueValues["orange"] = make_pair(11,25);
    hueValues["yellow"] = make_pair(26,38);
    hueValues["light green"] = make_pair(39,45);
    hueValues["dark green"] = make_pair(46,80);
    hueValues["cyan"] = make_pair(81,89);
    hueValues["light blue"] = make_pair(90,100);
    hueValues["dark blue"] = make_pair(101,130);
    hueValues["purple"] = make_pair(131,141);
    hueValues["pink"] = make_pair(142,163);
}