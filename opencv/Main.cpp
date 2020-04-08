#include<opencv2/opencv.hpp>
#include<iostream>
#include "Operation.h"
using namespace std;
using namespace cv;
#include <chrono>

int main()
{
    Mat current_img,src;
    Mat gray,blur;
    Mat img = imread("C:/Dev/opencv/opencv/images/lena.jpg");
    auto start = std::chrono::steady_clock::now();
    Operation opimage(img);
    
    opimage.op_rgbtogray(img, gray);
    //opimage.op_get_current_img(current_img);
    namedWindow("image gray", WINDOW_NORMAL);
    imshow("image gray", gray);
    
    //cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    opimage.op_blur(gray, blur);
    namedWindow("image blur", WINDOW_NORMAL);
    imshow("image blur", blur);


    opimage.op_get_current_img(current_img);
    opimage.op_get_src_img(src);
    namedWindow("image src", WINDOW_NORMAL);
    imshow("image src", src);

    namedWindow("image current", WINDOW_NORMAL);
    imshow("image current", current_img);
    //opimage.op_get_img_src(imgptr);
    //imwrite("C:/Dev/opencv/Gray_Image_correct.jpg", *img_gray_ptr);
    
    imagelist images_input;

    images_input.push_back(cv::imread("C:/Dev/opencv/opencv/images/scottsdale/imgA.jpg"));
    images_input.push_back(cv::imread("C:/Dev/opencv/opencv/images/scottsdale/imgB.jpg"));
    images_input.push_back(cv::imread("C:/Dev/opencv/opencv/images/scottsdale/imgC.jpg"));

    cv::Mat output;

    opimage.op_stitch(images_input, output);

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    namedWindow("image panorama", WINDOW_NORMAL);
    imshow("image panorama", output);

    cv::imwrite("C:/Dev/opencv/opencv/images/output/panorama.jpg", output);
    cv::imwrite("C:/Dev/opencv/opencv/images/output/blur.jpg", blur);
    cv::imwrite("C:/Dev/opencv/opencv/images/output/gray.jpg", gray);
    waitKey(0);
    return 0;
}


