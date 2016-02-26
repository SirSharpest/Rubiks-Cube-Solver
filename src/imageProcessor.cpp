//
// Created by nathan on 24/02/16.
//

#include "../headers/imageProcessor.hpp"

bool imageProcessor::init() {

    //Read in the demo image data and store it as the variable img
    src = cv::imread("images/demo.png", 1);
    dst = src.clone();

    //Check if reading image has failed
    if(src.empty()){

        std::cout << "Image not found or something like that" << std::endl;
        return false;
    }


    //Apply a few filters on the image to smooth color bounds
    //and to attempt to remove shine from excess light sources
    cv::blur(src, dst, cv::Size(50,50));
    cv::bilateralFilter(src, dst, 100, 80, 80);

    //Create a window
    //Set its size to auto depending on the image
    cv::namedWindow("Rubik's cube", CV_WINDOW_AUTOSIZE);
    cv::namedWindow("New Rubik's cube", CV_WINDOW_AUTOSIZE);


    //Display window with img in it
    cv::imshow("Rubik's cube", src);
    cv::imshow("New Rubik's cube", dst);

    //Wait for some keypress before moving on
    cv::waitKey(0);

    //Clean up window and erase it
    cv::destroyWindow("Rubik's cube");
    cv::destroyWindow("New Rubik's cube");

    //Return true if it all went well and image was displayed
    return true;

}
