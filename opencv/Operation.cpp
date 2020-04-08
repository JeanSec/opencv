#include<opencv2/opencv.hpp>
#include "Operation.h"
using namespace std;
using namespace cv;
#include <iostream>
#include <chrono>


Operation::Operation() 
{
	m_height = 0;
	m_width = 0;
	m_img = NULL;
	m_img_src = NULL;
}

Operation::Operation(cv::Mat& t_img) 
{
	m_img_src = t_img;
	m_height = t_img.rows;
	m_width = t_img.cols;
	m_img = cv::Mat(m_height, m_width, CV_8UC1, Scalar(0, 0, 0));
}

Operation::~Operation() 
{
}

bool Operation::op_get_src_img(cv::Mat& t_img)
{
	t_img = m_img_src; //copie à revoir ou reference ok ?
	return true;
}
bool Operation::op_get_current_img(cv::Mat& t_img)
{
	t_img = m_img;//copie à revoir ou reference ok ?
	return true;
}

bool Operation::op_add_img_src(cv::Mat& t_img)
{
	m_img_src = t_img;//copie à revoir ou reference ok ?
	return true;
}
bool Operation::op_rgbtogray(cv::Mat& t_img, cv::Mat& t_gray)
{
	//convert a rgb image to gray
	//New grayscale image = ( (0.3 * R) + (0.59 * G) + (0.11 * B) )
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			Point3_<uchar>* p = t_img.ptr<Point3_<uchar> >(i, j);
			m_img.at<uchar>(i, j) = (0.3 * p->z) + (0.59 * p->y) + (0.11 * p->x); //utiliser foreach
			//grayptr->at<uchar>(i, j) = ((p->z) + (p->y) + (p->x))/3;
		}
	}
	t_gray = m_img; //a revoir car copie de matrice
	return true;
}

bool Operation::op_blur(cv::Mat& t_img, cv::Mat& t_blur)
{
	//blur an image with a convolution(gaussian kernel)
	/// Declare variables
	Mat src, dst, kernel;
	Mat img_blur(m_height, m_width, CV_8UC1, Scalar(0, 0, 0));
	Point anchor;
	double delta;
	int ddepth, kernel_size;
	/// Initialize arguments for the filter
	anchor = Point(-1, -1);
	delta = 0;
	ddepth = -1;
	kernel_size = 5;
	/*kernel = 1.0f/159.0f*(Mat_<double>(5, 5) << 2, 4, 5, 4, 2, 
												4, 9, 12, 9, 4, 
												5, 12, 15, 12, 5, 
												4, 9, 12, 9, 4, 
												2, 4, 5, 4, 2);*/

	kernel = 1.0f / 400.0f * (Mat_<double>(20, 20, 1));
	/// Apply filter
	filter2D(t_img, img_blur, ddepth, kernel, anchor, delta, BORDER_DEFAULT);
	t_blur = img_blur;  //a revoir car copie de matrice
	m_img = img_blur; //a revoir car copie de matrice
	return true;
}

bool Operation::op_stitch(const imagelist& images, cv::Mat& pano)
{
	if (images.empty())
		return false;
	Stitcher::Mode mode = Stitcher::PANORAMA;
	Ptr<Stitcher> stitcher = Stitcher::create(mode);
	stitcher->stitch(images, pano);
	if (pano.empty())
		return false;
	return true;
}

