//
// Created by varora on 22/04/24.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

static void help(char* progName)
{
    cout << endl
         << "How to filter images (for contrast enhancement) with mask using a custom method and the"
         << "filter2d() method from opencv. " << endl
         << "Usage:" << endl
         << progName << " [image_path -- default ims/sample.jpg] [G -- grayscale] " << endl << endl;
}

void Sharpen(const Mat& I, Mat& Result);

int main(int argc, char* argv[])
{
    help(argv[0]);

    const char* filename = argc >=2 ? argv[1] : "ims/sample.jpg";

    Mat src, dst0, dst1;

    if (argc >= 3 && !strcmp("G", argv[2]))
        src = imread( samples::findFile( filename ), IMREAD_GRAYSCALE);
    else
        src = imread( samples::findFile( filename ), IMREAD_COLOR);

    if (src.empty())
    {
        cerr << "Can't open image [" << filename << "]" << endl;
        return EXIT_FAILURE;
    }

    namedWindow("Input", WINDOW_AUTOSIZE);
    namedWindow("Output", WINDOW_AUTOSIZE);

    // disp src im
    imshow( "Input", src );

    // basic method
    double t = (double)getTickCount();
    Sharpen( src, dst0 );
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "Hand written function time passed in seconds: " << t << endl;
    imshow( "Output", dst0 );
    waitKey();

    // filter2D()
    Mat kernel = (Mat_<char>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    t = (double)getTickCount();
    filter2D( src, dst1, src.depth(), kernel );
    t = ((double)getTickCount() - t)/getTickFrequency();
    cout << "Built-in filter2D time passed in seconds: " << t << endl;
    imshow( "Output", dst1 );
    waitKey();

    return EXIT_SUCCESS;
}

void Sharpen(const Mat& I,Mat& Result)
{
    CV_Assert(I.depth() == CV_8U); // accept only uchar images

    const int nChannels = I.channels();
    Result.create(I.size(), I.type());

    for(int j = 1 ; j < I.rows-1; ++j)
    {
        const uchar* previous = I.ptr<uchar>(j - 1);
        const uchar* current = I.ptr<uchar>(j);
        const uchar* next = I.ptr<uchar>(j + 1);

        uchar* output = Result.ptr<uchar>(j);

        for(int i = nChannels; i < nChannels*(I.cols-1); ++i)
        {
            output[i] = saturate_cast<uchar>(5*current[i] - current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
        }
    }
    Result.row(0).setTo(Scalar(0));
    Result.row(Result.rows-1).setTo(Scalar(0));
    Result.col(0).setTo(Scalar(0));
    Result.col(Result.cols-1).setTo(Scalar(0));
}