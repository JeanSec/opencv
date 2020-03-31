#include<opencv2/opencv.hpp>
#include<iostream>
#include "Operation.h"
using namespace std;
using namespace cv;
#include <chrono>

int main()
{
    auto start = std::chrono::steady_clock::now();
    Mat current_img,src;
    Mat gray,blur;
    Mat img = imread("lena.jpg");

    Operation opimage(img);

    opimage.op_rgbtogray(img, gray);
    //opimage.op_get_current_img(current_img);
    namedWindow("image gray", WINDOW_NORMAL);
    imshow("image gray", gray);
    
    //cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    opimage.op_blur(gray, blur);
    namedWindow("image blur", WINDOW_NORMAL);
    imshow("image blur", blur);

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";


    opimage.op_get_current_img(current_img);
    opimage.op_get_src_img(src);
    namedWindow("image src", WINDOW_NORMAL);
    imshow("image src", src);

    namedWindow("image current", WINDOW_NORMAL);
    imshow("image current", current_img);
    //opimage.op_get_img_src(imgptr);
    //imwrite("C:/Dev/opencv/Gray_Image_correct.jpg", *img_gray_ptr);
    
    waitKey(0);
    return 0;
}