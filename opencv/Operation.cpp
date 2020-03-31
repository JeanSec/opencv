#include<opencv2/opencv.hpp>
#include "Operation.h"
using namespace std;
using namespace cv;
#include <iostream>
#include <chrono>


Operation::Operation() 
{
	height = 0;
	width = 0;
	opimg = NULL;
	opimg_src = NULL;
}

Operation::Operation(cv::Mat& img) 
{
	opimg_src = img;
	height = img.rows;
	width = img.cols;
	opimg = cv::Mat(height, width, CV_8UC1, Scalar(0, 0, 0));
}

Operation::~Operation() 
{
}

bool Operation::op_get_src_img(cv::Mat& img)
{
	img = opimg_src; //copie à revoir ou reference ok ?
	return true;
}
bool Operation::op_get_current_img(cv::Mat& img)
{
	img = opimg;//copie à revoir ou reference ok ?
	return true;
}

bool Operation::op_add_img_src(cv::Mat& img)
{
	opimg_src = img;//copie à revoir ou reference ok ?
	return true;
}
bool Operation::op_rgbtogray(cv::Mat& img, cv::Mat& gray)
{
	//convert a rgb image to gray
	//New grayscale image = ( (0.3 * R) + (0.59 * G) + (0.11 * B) )
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Point3_<uchar>* p = img.ptr<Point3_<uchar> >(i, j);
			opimg.at<uchar>(i, j) = (0.3 * p->z) + (0.59 * p->y) + (0.11 * p->x);
			//grayptr->at<uchar>(i, j) = ((p->z) + (p->y) + (p->x))/3;
		}
	}
	gray = opimg; //a revoir car copie de matrice
	return true;
}

bool Operation::op_blur(cv::Mat& img, cv::Mat& blur)
{
	//blur an image with a convolution(gaussian kernel)
	/// Declare variables
	Mat src, dst, kernel;
	Mat img_blur(height, width, CV_8UC1, Scalar(0, 0, 0));
	Point anchor;
	double delta;
	int ddepth, kernel_size;
	/// Initialize arguments for the filter
	anchor = Point(-1, -1);
	delta = 0;
	ddepth = -1;
	kernel_size = 5;
	kernel = 1.0f/159.0f*(Mat_<double>(5, 5) << 2, 4, 5, 4, 2, 
												4, 9, 12, 9, 4, 
												5, 12, 15, 12, 5, 
												4, 9, 12, 9, 4, 
												2, 4, 5, 4, 2);

	/// Apply filter
	filter2D(img, img_blur, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
	blur = img_blur;  //a revoir car copie de matrice
	opimg = img_blur; //a revoir car copie de matrice
	return true;
}