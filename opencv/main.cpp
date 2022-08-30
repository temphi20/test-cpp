#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
	#pragma comment(lib, "opencv_world348d.lib")
#else
	#pragma comment(lib, "opencv_world348.lib")
#endif

int main()
{
	const uint channels = 4, bytes = sizeof(short);
	cv::Mat mat(cv::Size(100, 123), CV_16SC4);
	short** pData = (short**)mat.data;
	pData[0][0] = 123;
	pData[0][1] = 122;
	pData[0][2] = 100;
	pData[0][3] = 255;
	//pData[mat.rows][99]

	return 0;
}