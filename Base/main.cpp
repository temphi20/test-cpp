#include "base.h"

#define COUT(str) std::cout << str << "/ ";
#define COUTN(str) std::cout << str << std::endl;
#define ENTER() std::cout << std::endl;

int main()
{
    struct ST
    {
        byte a;
        short b;
        bool c;
        double d;
    };
    std::vector<ST> v(4);
    v = { {1, 1, true, 0}, { 1, 1, true, 0}, {3, 21, true, -10.7}, {4, 1, false, 0.223} };
    
    tmphi::array<ST> arr(v);
    
    
    arr.resize(10);
    arr.resize(3);
    //arr.add(v);

    arr.makeSet();
    /*tmphi::array<int> arr2(3, 21);
    auto arr3 = arr + arr2;
    arr3.makeSet();*/
    /*for (size_t i = 0; i < arr2.size(); i++)
    {
        COUT(arr2[i]);
    }*/
    //arr.ascend();
    for (size_t i = 0; i < arr.size(); i++)
    {
        COUT((uint)arr[i].a);
        COUT(arr[i].b);
        COUT(arr[i].c);
        COUTN(arr[i].d);
    }
    /*arr3.descend();
    for (size_t i = 0; i < arr3.size(); i++)
    {
        COUT(arr3[i]);
    }*/
    //ENTER();

    
    return 0;
}