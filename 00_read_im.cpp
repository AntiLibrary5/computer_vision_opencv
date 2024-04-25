//
// Created by varora on 22/04/24.
//
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    // im path
    std::string image_path = "ims/sample.jpg";
    // read im
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);

    if(img.empty()){
        std::cout << "Could not read the image from: " << image_path << std::endl;
        return 1;
    }
    // show im
    imshow("Display Window", img);
    int k = cv::waitKey(0);
    // optionally save im in grayscale
    if(k == 's'){
        Mat gray;
        cvtColor(img, gray, COLOR_BGR2GRAY);
        cv::imwrite("ims/sample_gray.png", gray);
    }
    return 0;
}