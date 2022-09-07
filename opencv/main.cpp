#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
	#pragma comment(lib, "opencv_world348d.lib")
#else
	#pragma comment(lib, "opencv_world348.lib")
#endif

#define COUT(str) std::cout << str << std::endl

int main()
{
	const uint channels = 4, bytes = sizeof(short);
	cv::Mat mat(cv::Size(100, 123), CV_16SC4);
	short* pData = (short*)mat.data;
	pData[0] = 123;
	pData[1] = 122;
	pData[2] = 100;
	pData[3] = 255;

	COUT(pData[0]);
	COUT(pData[1]);
	COUT(pData[2]);
	COUT(pData[3]);
	COUT(pData[4]);
	COUT(pData[5]);
	COUT(pData[6]);

	pData[4] = 2147483647;
	COUT(pData[0]);
	COUT(pData[1]);
	COUT(pData[2]);
	COUT(pData[3]);
	COUT(pData[4]);
	COUT(pData[5]);
	COUT(pData[6]);

	pData[4] = 2147483600;
	COUT(pData[0]);
	COUT(pData[1]);
	COUT(pData[2]);
	COUT(pData[3]);
	COUT(pData[4]);
	COUT(pData[5]);
	COUT(pData[6]);
	
	//pData[mat.rows][99]

	return 0;
}