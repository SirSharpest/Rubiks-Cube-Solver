//
// Created by nathan on 24/02/16.
//

#include "../headers/imageProcessor.hpp"

bool imageProcessor::init() {

    //Read in the demo image data and store it as the variable img
    img = cv::imread("images/demo.png", CV_LOAD_IMAGE_UNCHANGED);

    //Check if reading image has failed
    if(img.empty()){

        std::cout << "Image not found or something like that" << std::endl;
        return false;
    }


    //Create a window
    //Set its size to auto depending on the image
    cv::namedWindow("Rubik's cube", CV_WINDOW_AUTOSIZE);

    //Display window with img in it
    cv::imshow("Rubik's cube", img);

    //Wait for some keypress before moving on
    cv::waitKey(0);

    //Clean up window and erase it
    cv::destroyWindow("Rubik's cube");

    //Return true if it all went well and image was displayed
    return true;

}
