#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Point_<int> pt1(100, 200);
	Point_<float> pt2(92.3f, 125.23f);
	Point_<double> pt3(100.2, 300.9);

	Point2i	pt4(120, 69);
	Point2f	pt5(0.3f, 0.f), pt6(0.f, 0.4f);
	Point2d pt7(0.25, 0.6);

	Point	pt8 = pt1 + (Point)pt2;
	Point2f	pt9 = pt6 * 3.14f;
	Point2d	pt10 = (pt3 + (Point2d) pt6) *10;
	Point	test = pt2;
	Point	test1 = (Point)pt2;

	
	cout << "test =" << test << " , " << test1 << std::endl;
	cout << "pt8 =" << pt8.x << " , " << pt8.y << std::endl;
	cout << "[pt9] =" << pt9 << endl;
	cout << (pt2 == pt6) << endl;
	cout << "pt7 and pt8 inner product : " << pt7.dot(pt8) << endl;
	cout << "pt8 and pt7 inner product : " << pt8.dot(pt7) << endl;


	return 0;
}
