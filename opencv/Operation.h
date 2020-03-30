#pragma once

class Operation
{
	private:
		int height;
		int width;
		cv::Mat* opimgptr;
	public:

	bool op_rgbtogray(cv::Mat* grayptr, int use_gpu);

	Operation();
	Operation(cv::Mat* imgptr);
	~Operation();

};