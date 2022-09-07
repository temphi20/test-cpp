#pragma once

#include <iostream>
#include <vector>
#include <span>

#include <opencv2/opencv.hpp>
#include <exprtk.hpp>
#include <magic_enum.hpp>
#include <rapidjson/rapidjson.h>

#include <boost/algorithm/algorithm.hpp>
#include <boost/chrono.hpp>
//#include <boost/array.hpp>

#ifdef _DEBUG
	#pragma comment(lib, "opencv_world348d.lib")
#else
	#pragma comment(lib, "opencv_world348.lib")
#endif

typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned long long ullong;
typedef long long llong;
typedef wchar_t wchar;

#include "array.hpp"
#include "timer.h"