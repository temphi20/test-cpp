#include "ExCal.h"
#include "TT.h"
#include <iostream>
#include <vector>
#include <span>
#include <map>
#include <thread>
#include <future>
#include <random>
#define TEST_NUM 100
using namespace std;

double worker(size_t start, map<int, Ex::ExCal<double>>* map);

int main()
{
    //map<int, Ex::ExCal<double>> sets;
    //vector<future<double>> futures;
    //for (size_t i = 0; i < TEST_NUM; i++)
    //{
    //    futures.emplace_back(async(launch::async, worker, i, &sets));
    //}
    //
    //for (size_t i = 0; i < TEST_NUM; i++)
    //{
    //    double ret = futures[i].get();
    //    cout << "[" << i << "] " << ret << endl;
    //}
    //cout << " -------------------------------------------------- " << endl;
    //for (size_t i = 0; i < TEST_NUM; i++)
    //{
    //    cout << "[" << i << "] ";
    //    sets[i].Print();
    //    cout << endl;
    //}

    //int a[] = { 0, 1, 2, 3 };
    vector<int> v1 = { 0, 1, -1, 2, 3 };
    Ex::TT<int> tt1(v1);
    cout << tt1[2] << endl;

    vector<float> v2 = { 0.1, 1.1, 2.1, 3.1 };
    Ex::TT<float> tt2(v2);
    cout << tt1[2] << endl;

    return 0;
}

double worker(size_t start, map<int, Ex::ExCal<double>>* map)
{
    /*random_device device;
    mt19937_64 gen(device());
    uniform_int_distribution dis(1, 99);*/
    
    Ex::ExCal<double> cal;
    for (int i = 1; i < 6; i++)
    {
        //cout << "in worker" << start << '/' << i << endl;
        cal.Push(i * start);
        cal.Push(start / i);
    }
    map->insert({start, cal});
    //cout << start << " / " << cal.Average() << endl;

    return cal.Average();
}