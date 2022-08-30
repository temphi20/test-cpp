#pragma once
#define PRINTN(o) std::cout << o << std::endl
#define PRINT(t, o) std::cout << t << "(" << o << ")" << std::endl

namespace CalImpl {
    using namespace std;

    double Power(double x, int t);
    double _Power(double x, int t, double seed);

    int Average(int a = 0, int b = 0);
    double Average(double a, double b);
    double Average(double* arr, int n);
}
