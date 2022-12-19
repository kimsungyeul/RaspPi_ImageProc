#include "opencv2/opencv.hpp"
#include "hough.hpp"

void detect_maxObject(Mat img, Rect &rect)			// 가장 큰 객체 사각형 검색
{
	vector<vector<Point>> contours;
	findContours(img.clone(), contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	int max_area = 0;
	for(int i = 0; i<(int)contours.size(); i++)		// 가장 큰 영역 찾기
	{
		Rect r = boundingRect(contours[i]);			// 외곽선 영역 포함 사각형
		if(max_area < r.area()){
			max_area = r.area();
			rect = r;
		}
	}
	rect = rect - Point(10, 10) + Size(20, 20);		// 검출 사각형 크기 확대
}

int main()
{
	Rect rect;
	Mat	gray, canny, morph, th_gray, canny_line, dst;
	double rho = 1, theta = CV_PI/180;
	vector<Vec2f> lines;

	Mat image = imread("./line2.bmp", 1);
	CV_Assert(image.data);

	cvtColor(image, gray, COLOR_BGR2GRAY);
	threshold(gray, th_gray, 240, 255, THRESH_BINARY);
	erode(th_gray, morph, Mat(), Point(-1, -1), 2);

	detect_maxObject(morph, rect);

	//Canny(th_gray(rect), canny, 40, 100);
	Canny(gray, canny, 40, 100);
	houghLines(canny, lines, rho, theta, 50);
	draw_houghLines(canny, canny_line, lines, 1);

	double angle = (CV_PI - lines[0][1]) * 180/CV_PI;
	Point center = image.size() / 2;
	Mat rot_map = getRotationMatrix2D(center, -angle, 1);

	warpAffine(image, dst, rot_map, image.size(), INTER_LINEAR);

	imshow("image", image);
	imshow("canny_lien", canny_line);
	imshow("dst", dst);
	waitKey();
	return 0;
}
