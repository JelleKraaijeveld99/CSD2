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

    colorPerMap["red"] = ((float) red/totalColoredPixels)*100.0;
    colorPerMap["light blue"] = ((float) lightBlue/totalColoredPixels)*100;
    colorPerMap["dark blue"] = ((float) darkBlue/totalColoredPixels)*100;
    colorPerMap["light green"] = ((float) lightGreen/totalColoredPixels)*100;
    colorPerMap["dark green"] = ((float) darkGreen/totalColoredPixels)*100;
    colorPerMap["purple"] = ((float) purple/totalColoredPixels)*100;
    colorPerMap["pink"] = ((float) pink/totalColoredPixels)*100;
    colorPerMap["orange"] = ((float) orange/totalColoredPixels)*100;
    colorPerMap["yellow"] = ((float) yellow/totalColoredPixels)*100;
    colorPerMap["cyan"] = ((float) cyan/totalColoredPixels)*100;

    std::cout << "% of light green pixels: " <<  colorPerMap["light green"] << std::endl;
    std::cout << "% of dark green pixels: " << colorPerMap["dark green"] << std::endl;
    std::cout << "% of red pixels: " << colorPerMap["red"] << std::endl;
    std::cout << "% of light blue pixels: " << colorPerMap["light blue"] << std::endl;
    std::cout << "% of darkblue pixels: " << colorPerMap["dark blue"] << std::endl;
    std::cout << "% of purple pixels: " << colorPerMap["purple"] << std::endl;
    std::cout << "% of pink pixels: " <<  colorPerMap["pink"] << std::endl;
    std::cout << "% of orange pixels: " << colorPerMap["orange"] << std::endl;
    std::cout << "% of yellow pixels: " << colorPerMap["yellow"] << std::endl;
    std::cout << "% of cyan pixels: " << colorPerMap["cyan"]  << std::endl;


}