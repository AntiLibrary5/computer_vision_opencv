//
// Created by varora on 22/04/24.
//
#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

Mat& ScanImageAndReduceC(Mat& I, const uchar* table);

int main(int argc, char* argv[]){
    // check args
    if (argc < 3)
    {
        cout << "Not enough parameters" << endl;
        return -1;
    }
    // read im
    Mat I, J;
    if( argc == 4 && !strcmp(argv[3], "G"))
        I = imread(argv[1], IMREAD_GRAYSCALE);
    else
        I = imread(argv[1], IMREAD_COLOR);
    // check im
    if (I.empty())
    {
        cout << "The image" << argv[1] << " could not be loaded." << endl;
        return -1;
    }
    // get dividewith arg
    int divideWith = 0;
    stringstream s;
    s << argv[2];
    s >> divideWith;
    if (!s || !divideWith)
    {
        cout << "Invalid number entered for dividing." << endl;
        return -1;
    }
    // lookup table
    uchar table[256];
    for (int i = 0; i < 256; ++i)
        table[i] = (uchar)(divideWith * (i/divideWith));
    // timer
    double t;
    t = (double)getTickCount();
    // color space reduction
    Mat clone_I = I.clone();
    J = ScanImageAndReduceC(clone_I, table);
    t = 1000*((double)getTickCount() - t)/getTickFrequency();
    cout << "Time of reducing with the C operator [] " << t << " milliseconds."<< endl;
    // show im original
    imshow("Original", I);
    cv::waitKey(0);
    // show im after color space reduction
    imshow("After color space reduction", J);
    cv::waitKey(0);
    return 0;
}

Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i, j;
    uchar* p;
    for (i = 0; i <nRows; i++){
        p = I.ptr<uchar>(i);
        for (j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]];
        }
    }
    return I;
}