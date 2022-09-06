#include <iostream>
#include "DManager.hpp"

#define TEST_NUM 100
#define COUT(str) std::cout << str << std::end

using namespace std;

int main()
{
    tmphi::DManager<double> man;
    man.push(234);
    man.push(4244);
    
    double* arr = new double[2];
    arr[0] = 3.4;
    arr[1] = 3.14;
    man.push(arr, 2);
    
    for (size_t i = 0; i < man.size(); i++)
    {
        std::cout << man[i];
        std::cout << std::endl;
    }

    delete[] arr;
    return 0;
}