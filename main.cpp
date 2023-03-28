#include <cmath>
#include <iostream>
#include <random>
#include "tests.h"

using namespace std;

void ExampleDft1(){
    size_t size = 1024;
    auto x = linspace(0.0, 50.0, size);
    std::vector<double> y(size);
    for(size_t i = 0; i < size; ++i){
        y[i] = std::sin(2*x[i]) + std::sin(3*x[i]) + std::sin(5*x[i]);
    }
    WriteLog(x, y, "signal.csv"s);
    auto X = Dft(y.begin(), y.end());
    WriteComplexLog(x, X, "spectrum.csv"s);

    std::cout << __FUNCTION__ << " is Done" << std::endl;
}

void ExampleDft2(){
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, 1.0);
    size_t size = 1024;
    auto x = linspace(0.0, 50.0, size);
    std::vector<double> y(size);
    for(size_t i = 0; i < size; ++i){
        double x1 = std::sin(2*x[i]) + std::sin(3*x[i]) + std::sin(5*x[i]);
        y[i] = x1 + distribution(generator);
    }
    WriteLog(x, y, "signal.csv"s);
    auto X = Dft(y.begin(), y.end());
    WriteComplexLog(x, X, "spectrum.csv"s);

    std::cout << __FUNCTION__ << " is Done" << std::endl;
}

void ExampleFft(){
    size_t size = 1024;
    auto x = linspace(0.0, 50.0, size);
    std::vector<double> y(size);
    for(size_t i = 0; i < size; ++i){
        y[i] = std::sin(2*x[i]) + std::sin(3*x[i]) + std::sin(5*x[i]);
    }
    WriteLog(x, y, "signal.csv"s);
    auto X = Fft(y.begin(), y.end());
    WriteComplexLog(x, X, "spectrum.csv"s);

    std::cout << __FUNCTION__ << " is Done" << std::endl;
}

void ExampleMultiply(){
    {
        std::vector<int> a = {1,2,3,4};
        std::vector<int> b = {2,4,8,9};

        std::vector<int> test = {3, 0, 7, 1, 4, 2, 6};
        std::cout << "test 1 = " << test << '\n';
        std::cout << "result 1 = " << Multiply(a, b) << std::endl;
    }

    {
        std::vector<int> a = {1,2,3,4,5};
        std::vector<int> b = {2,4,8,9};

        std::vector<int> test = {3, 0, 7, 2, 6, 7, 0, 5};
        std::cout << "test 2 = " << test << '\n';
        std::cout << "result 2 = " << Multiply(a, b) << std::endl;
    }
}

int main(){

#ifndef NDEBUG
    Test();
#endif
    //ExampleDft1();
    //ExampleDft2();
    //ExampleFft();
    ExampleMultiply();
    return 0;
}

