#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void calc_Histo(const Mat& image, Mat &hist, int bins, int range_max= 256)
{
	hist = Mat(bins, 1, CV_32F, Scalar(0));
	float gap = range_max / (float)bins;

	for(int i = 0; i < image.rows; i++) {
		for(int j=0; j<image.cols; j++) {
			int idx = int(image.at<uchar>(i, j) / gap);
			hist.at<float>(idx)++;
		}
	}
}

Mat make_palatte(int rows)
{
	Mat hsv(rows, 1, CV_8UC3);
	for(int i = 0; i < rows; i++)
	{
		uchar hue = saturate_cast<uchar>((float)i / rows * 180);
		hsv.at<Vec3b>(i) = Vec3b(hue, 255, 255);
	}
	cvtColor(hsv, hsv, COLOR_HSV2BGR);
	return hsv;
}

void draw_histo_hue(Mat hist, Mat &hist_img, Size size = Size(256, 200))
{
	Mat hsv_palatte = make_palatte(hist.rows);

	hist_img = Mat(size, CV_8UC3, Scalar(255, 255, 255));
	float bin = (float)hist_img.cols / hist.rows;
	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);

	for(int i = 0; i<hist.rows; i++)
	{
		float start_x = i * bin;
		float end_x = (i + 1) * bin;
		Point2f pt1(start_x, 0);
		Point2f pt2(end_x, hist.at <float>(i));

		Scalar color = hsv_palatte.at<Vec3b>(i);
		if(pt2.y > 0)
			rectangle(hist_img, pt1, pt2, color, -1);
	}
	flip(hist_img, hist_img, 0);
}

int main()
{
	Mat image = imread("./lena.bmp", 1);
	CV_Assert(!image.empty());

	Mat HSV_img, HSV_arr[3];
	cvtColor(image, HSV_img, COLOR_BGR2HSV);
	split(HSV_img, HSV_arr);

	Mat hue_hist, hue_hist_img;
	calc_Histo(HSV_arr[0], hue_hist, 18, 180);
	draw_histo_hue(hue_hist, hue_hist_img, Size(360, 200));

	imshow("image", image);
	imshow("Hue_hist_img", hue_hist_img);
	waitKey();
	return 0;
}

