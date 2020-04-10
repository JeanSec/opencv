#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>


class Matrix
{	
	public:
		Matrix();
		~Matrix();

	private:
	int lines;
	int cols;
	cv::Mat M;
};

cv::Mat operator+(const cv::Mat& A, const cv::Mat& B);
cv::Mat operator*(const cv::Mat& A, const cv::Mat& B);