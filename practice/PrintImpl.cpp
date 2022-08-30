#include <iostream>
#include "PrintImpl.h"
using namespace std;

void PrintCRect(CRect rect) {
    printf("[l,t,r,b] Rect(%d,%d,%d,%d)\n", rect.left, rect.top, rect.right, rect.bottom);
    cout << "Width: " << rect.Width() << endl;
    cout << "Height: " << rect.Height() << endl;

    cout << "TopLeft: ";
    PrintCPoint(rect.TopLeft());
    cout << "CenterPoint: ";
    PrintCPoint(rect.CenterPoint());
    cout << "BottomRight: ";
    PrintCPoint(rect.BottomRight());
}

void PrintCPoint(CPoint point) {
    cout << "(" << point.x << "," << point.y << ")" << endl;
}