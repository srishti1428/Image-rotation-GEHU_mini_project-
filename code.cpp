#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	float angleofrotation;
	cout << "Enter the angle of rotation of image: ";
	cin >> angleofrotation;
	Mat outputimage;
	Mat inputimage = imread("pic12.jpg",IMREAD_UNCHANGED);
	if (inputimage.empty())
	{
		cout << "Error!!";
		cin.get();
		return -1;
	}
	String inputwindowname = "Input Image";
	namedWindow(inputwindowname, WINDOW_NORMAL);
	imshow(inputwindowname, inputimage);

	outputimage = inputimage;

	String outputwindowname = "Output Image";
	Point2f pt(inputimage.cols / 2., inputimage.rows / 2.);
	Mat r=getRotationMatrix2D(pt, angleofrotation, 1.0);
	warpAffine(inputimage, outputimage, r, Size(inputimage.cols, inputimage.rows));
	namedWindow(outputwindowname, WINDOW_NORMAL);
	imshow(outputwindowname, outputimage);

	waitKey(0);
	return 0;
}
