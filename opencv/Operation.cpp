#include<opencv2/opencv.hpp>
#include "Operation.h"
using namespace std;
using namespace cv;
#include <iostream>
#include <chrono>


Operation::Operation() {
	height = 0;
	width = 0;
}
Operation::Operation(cv::Mat* imgptr) {
	opimgptr = imgptr;
	height = imgptr->rows;
	width = imgptr->cols;
}
Operation::~Operation() {
}

bool Operation::op_rgbtogray(cv::Mat* grayptr, int use_gpu) {
	//convert a rgb image to gray
	//New grayscale image = ( (0.3 * R) + (0.59 * G) + (0.11 * B) )
	for (int i = 0; i < opimgptr->rows; i++)
	{
		for (int j = 0; j < opimgptr->cols; j++)
		{
			Point3_<uchar>* p = opimgptr->ptr<Point3_<uchar> >(i, j);
			grayptr->at<uchar>(i, j) = (0.3 * p->z) + (0.59 * p->y) + (0.11 * p->x);
		}
	}

	if (use_gpu == 1) 
	{
		int test = 1;
	}
	else
	{
		int test = 1;
	}

	return true;
}