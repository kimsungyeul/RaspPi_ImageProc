#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

string title = "Trackbar Event";
Mat image;

void onChange(int value, void* userdata)
{
	int add_value = value - 130;
	cout << "Added Pixel value " << add_value << endl;

	Mat tmp = image + add_value;
	imshow(title, tmp);
}

int main()
{
	int value = 128;
	image = Mat(300, 400, CV_8UC1, Scalar(120));

	namedWindow(title, WINDOW_AUTOSIZE);
	createTrackbar("bright_value", title, &value, 255, onChange);

	imshow(title, image);
	waitKey(0);
	return 0;
}
