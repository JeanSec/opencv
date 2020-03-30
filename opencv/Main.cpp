#include<opencv2/opencv.hpp>
#include<iostream>
#include "Operation.h"
using namespace std;
using namespace cv;
#include <chrono>

int main()
{
    auto start = std::chrono::steady_clock::now();

    Mat img = imread("lena.jpg");
    Mat* imgptr;
    imgptr = &img;

    Operation opimage(imgptr);

    Mat img_gray(img.rows, img.cols, CV_8UC1, Scalar(0, 0, 0));
    Mat* img_gray_ptr;
    img_gray_ptr = &img_gray;

    opimage.op_rgbtogray(img_gray_ptr,0);
    //cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    namedWindow("image", WINDOW_NORMAL);
    imshow("image", *img_gray_ptr);

    waitKey(0);
    return 0;
}