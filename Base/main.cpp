#include "base.h"

#define COUT(str) std::cout << str << std::endl;
#define ENTER() std::cout << std::endl;

int main()
{
    std::vector<int> v(4);
    v = { 1, 2, 3, 4 };
    
    tmphi::array<int> arr(v);
    
    
    arr.resize(10);
    arr[0] = 10;
    arr.resize(4);
    arr.add(v);

    tmphi::array<int> arr2(3, 21);
    auto arr3 = arr + arr2;
    
    for (size_t i = 0; i < arr2.size(); i++)
    {
        COUT(arr2[i]);
    }
    for (size_t i = 0; i < arr3.size(); i++)
    {
        COUT(arr3[i]);
    }
    //ENTER();

    
    return 0;
}