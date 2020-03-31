#pragma once


class Operation
{
	private:
		int height;
		int width;
		cv::Mat opimg;
		cv::Mat opimg_src;

	public:
	bool op_rgbtogray(cv::Mat& img, cv::Mat& gray);
	bool op_blur(cv::Mat& img, cv::Mat& blur);
	bool op_get_src_img(cv::Mat& img);
	bool op_get_current_img(cv::Mat& img);
	bool op_add_img_src(cv::Mat& img);
	Operation();
	Operation(cv::Mat& imgptr);
	~Operation();

};