//
// Created by varora on 22/04/24.
//
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

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
    // optionally save im
    if(k == 's'){
        cv::imwrite("dog.png", img);
    }
    return 0;
}