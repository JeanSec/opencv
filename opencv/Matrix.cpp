#include "Matrix.h"


Matrix::Matrix() {
	int test = 4;
}
Matrix::~Matrix() {
	int test = 4;
}

cv::Mat operator+(const cv::Mat& A, const cv::Mat& B) {
	cv::Mat test = cv::Mat(2, 2, CV_8UC1, cv::Scalar(0, 0, 0));
	return test;
}
cv::Mat operator*(const cv::Mat& A, const cv::Mat& B) {
	cv::Mat test = cv::Mat(2, 2, CV_8UC1, cv::Scalar(0, 0, 0));
	return test;
}