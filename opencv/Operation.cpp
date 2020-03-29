#include<opencv2/opencv.hpp>
#include "Operation.h"
using namespace std;
using namespace cv;
#include <iostream>
#include <chrono>


Operation::Operation() {
}

Operation::~Operation() {
}

bool Operation::rgbtogray(cv::Mat* img, int use_gpu) {
	//convert a rgb image to gray
	//New grayscale image = ( (0.3 * R) + (0.59 * G) + (0.11 * B) )

	int rows = img->rows;
	int cols = img->cols;
	


	Point3_<uchar>* p = img->ptr<Point3_<uchar> >(50, 50);

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