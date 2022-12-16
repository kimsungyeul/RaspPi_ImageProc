#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void differential(Mat image, Mat& dst, float data1[], float data2[])
{
	Mat dst1, dst2;
	Mat mask1(3, 3, CV_32F, data1);
	Mat mask2(3, 3, CV_32F, data2);

	filter2D(image, dst1, CV_32F, mask1);
	filter2D(image, dst2, CV_32F, mask2);
	magnitude(dst1, dst2, dst);
	dst.convertTo(dst, CV_8U);

	convertScaleAbs(dst1, dst1);
	convertScaleAbs(dst2, dst2);
	imshow("dst1 - 수직 마스크", dst1);
	imshow("dst2 - 수평 마스크", dst2);
}

int main()
{
	Mat image = imread("./lena.bmp", IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	float data1[] = {
		-1, 0, 1,
		-1, 0, 1,
		-1, 0, 1
	};

	float data2[] = {
		-1, -1, -1,
		 0, 0, 0,
		 1, 1, 1
	};
	
	Mat dst;
	differential(image, dst, data1, data2);

	imshow("image", image);
	imshow("프리윗 에지", dst);
	waitKey();
	return 0;
}
