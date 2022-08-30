#include <iostream>
#include "CalImpl.h"

double CalImpl::_Power(double x, int t, double seed) {
    if (t == 0) return seed;
    else if (t < 0) return _Power(x, t + 1, seed / x);
    return _Power(x, t - 1, seed * x);
}

double CalImpl::Power(double x, int t) {
    cout << "Power(" << x << "^" << t << ")" << endl;
    return _Power(x, t, 1);
}

int CalImpl::Average(int a, int b) {
    cout << "int Average(" << a << "," << b << ")" << endl;
    return (a + b) / 2;
}

double CalImpl::Average(double a, double b) {
    cout << "double Average(" << a << "," << b << ")" << endl;
    return (a + b) / 2;
}

double CalImpl::Average(double* arr, int n) {
    double sum = 0;
    cout << "Common Average(";

    for (int i = 0; i < n; i++)
    {
        cout << ((double*)arr)[i];
        if (i != n - 1) cout << ",";
        else cout << ")" << endl;

        sum += arr[i];
    }

    return sum / n;
}