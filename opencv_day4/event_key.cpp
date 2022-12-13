#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("Keyboard Event", WINDOW_AUTOSIZE);
	imshow("Keyboard Event", image);

	while(1)
	{
		int key = waitKey(100);
		if(key == 27) break;

		switch(key)
		{
			case 'a':	cout << "a Key Input" << endl; break;
			case 'b':	cout << "b Key Input" << endl; break;
			case 0x41:	cout << "A Key Input" << endl; break;
			case 66:	cout << "B Key Input" << endl; break;

			case 0x51:	cout << "Left direct Key Input" << endl; break;
			case 0x52:	cout << "Up direct Key Input" << endl; break;
			case 0x53:	cout << "Right direct Key Input" << endl; break;
			case 0x54:	cout << "Down direct Key Input" << endl; break;
		}
	}
	return 0;
}

