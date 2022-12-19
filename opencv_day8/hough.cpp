#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat img = imread(argv[1], IMREAD_COLOR);
    Mat canny, gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, canny, Size(5, 5), 2, 2);
    Canny(canny, canny, 50, 200, 3);
    int minLineLength = 10, maxLineGap = 0;

    vector<Vec4i> lines;
    HoughLinesP(canny, lines, 1, CV_PI/180, 10, minLineLength, maxLineGap);

    Point pt1, pt2;
    for (int i = 0; i < lines.size(); i++) {
        pt1.x = lines[i][0];
        pt1.y = lines[i][1];
        pt2.x = lines[i][2];
        pt2.y = lines[i][3];

        line(img, pt1, pt2, Scalar(255, 0, 255), 3, LINE_AA);
    }

    imshow("Hough", img);
    waitKey(0);

    destroyAllWindows();

    return 0;
}

