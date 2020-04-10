#pragma once

typedef std::vector<cv::Mat> imagelist;

struct Square
{
	cv::Point a; //left top
	int size;
};

class Operation
{
	private:
		int m_height;
		int m_width;
		cv::Mat m_img;
		cv::Mat m_img_src;

	public:
	bool op_rgbtogray(cv::Mat& t_img, cv::Mat& t_gray);
	bool op_blur(cv::Mat& t_img, cv::Mat& t_blur);
	bool op_blur_zone(cv::Mat& t_img, cv::Mat& t_blur, const Square t_zone);
	bool op_get_src_img(cv::Mat& t_img);
	bool op_get_current_img(cv::Mat& t_img);
	bool op_add_img_src(cv::Mat& t_img);
	Operation();
	Operation(cv::Mat& t_img);
	~Operation();
	bool op_stitch(const imagelist& images, cv::Mat& pano);
};
