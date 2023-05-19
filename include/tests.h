#ifndef TESTS_H
#define TESTS_H
#include "test_framework.h"
#include "log_duration.h"
#include "utility_functions.h"
#include <fstream>

template <typename Container>
bool CheckValues(Container& x, Container& test, double eps = 1e-14){
    for(size_t i = 0 ; i < x.size(); ++i){
        bool check = std::abs(x[i] - test[i]) < eps;
        if(!check){
            std::printf("std::abs(x[%lu] - test[%lu]) = %Lf \n", i, i, std::abs(x[i] - test[i]));
            std::cout << "x["<< i <<"] = " << x[i] << '\n';
            std::cout << "test["<< i <<"] = " << test[i] << '\n';
            return false;
        }
    }
    return true;
}

void TestDft();

void TestIdft();

void TestDftIdft();

void TestFft();

void TestIfft();

void TestFftIfft();

void TestMultiply();

void Test();


#endif // TESTS_H
