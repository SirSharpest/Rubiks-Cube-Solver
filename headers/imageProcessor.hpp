//
// Created by nathan on 24/02/16.
//

#ifndef RUBKIS_IMAGEPROCESSOR_HPP
#define RUBKIS_IMAGEPROCESSOR_HPP

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>



class imageProcessor {

public:

    /*
     * Starts up the processor
     * Currently just testing openCV runs correctly
     * at displaying an image
     */
    bool init();


private:

    cv::Mat src;
    cv::Mat dst;

};


#endif //RUBKIS_IMAGEPROCESSOR_HPP
