#include <opencv2/highgui.hpp>

using namespace cv;

int main()
{
	cv::Mat image(300, 400, CV_8UC1, Scalar(200));
	cv::imshow("Hello World", image);
	cv::waitKey(0);
	return 0;
}
