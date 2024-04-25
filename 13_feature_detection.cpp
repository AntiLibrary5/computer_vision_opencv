//
// Created by varora on 23/04/24.
//
#include <iostream>
#include<eigen3/Eigen/Core>
#include "opencv2/core.hpp"
#ifdef HAVE_OPENCV_XFEATURES2D
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"

using namespace cv;
using namespace cv::xfeatures2d;
using std::cout;
using std::endl;

int main( int argc, char* argv[] )
{
    CommandLineParser parser( argc, argv, "{@input | ims/sample.jpg | input iamge}" );
    Mat src = imread( samples::findFile( parser.get<String>("@input") ), IMREAD_GRAYSCALE);
    if ( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    // detect hte keypoints with SURF
    int minHessian = 400;
    Ptr<SURF> detector = SURF::create( minHessian );
    std::vector<KeyPoint> keypoints;
    detector->detect( src, keypoints );

    // draw keypoints
    Mat img_keypoints;
    drawKeypoints( src, keypoints, img_keypoints );

    imshow( "SURF keypoints", img_keypoints );

    waitKey();
    return 0;
}
#else
int main()
{
    std::cout << "This tutorial code needs the xfeatures2d contrib module to be run." << std::endl;
    return 0;
}
#endif