#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat m1(4, 3, CV_32FC3);
	cout << "dimention = " << m1.dims << endl;
	cout << "rows = " << m1.rows << endl;
	cout << "cols = " << m1.cols << endl;
	cout << "Matsize = " << m1.size() << endl << endl;

	cout << "total elem number = " << m1.total() << endl;
	cout << "elem size = " << m1.elemSize() << endl;
	cout << "channel elem size = " << m1.elemSize1() << endl << endl;

	cout << "type = " << m1.type() << endl;
	cout << "type(channel depth) = " << ((m1.channels() - 1) << 3) + m1.depth() << endl;
	cout << "depth = " << m1.depth() << endl;
	cout << "channel = " << m1.channels() << endl << endl;

	cout << "step = " << m1.step << endl;
	cout << "step1() = " << m1.step1() << endl;
	return 0;
}

