#include "include.h"
#include "DManager.hpp"

#define TEST_NUM 100
#define COUT(str) std::cout << str
#define ENTER(str) std::cout << std::endl

using namespace std;

enum class Test
{
    one = 0,
};
int main()
{
    cv::Size size;
    auto names = magic_enum::enum_names<Test>();

    COUT(size.empty());
    ENTER();
    COUT(names[0]);
    ENTER();

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