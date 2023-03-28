#include "tests.h"

void TestDft(){
    std::vector<double> xn = {2, 4, 8, 16};
    std::vector<std::complex<double>> test = {
        {30, 0},
        {-6, -12},
        {-10, 0},
        {-6, 12}
    };
    auto X = Dft(xn.begin(), xn.end());
    ASSERT(CheckValues(X, test));
}

void TestIdft(){
    std::vector<double> test = {2, 4, 8, 16};
    std::vector<std::complex<double>> X = {
        {30, 0},
        {-6, -12},
        {-10, 0},
        {-6, 12}
    };
    auto x = Idft(X.begin(), X.end());
    ASSERT(CheckValues(x, test));
}

void TestDftIdft(){
    {
        std::vector<double> xn = {2, 4, 8, 16};
        auto X = Dft(xn.begin(), xn.end());
        auto x = Idft(X.begin(), X.end());
        ASSERT(CheckValues(x, xn));
    }

    {
        std::vector<double> xn = {1, 2, 3, 4, 5, 6, 7, 8};
        auto X = Dft(xn.begin(), xn.end());
        auto x = Idft(X.begin(), X.end());
        ASSERT(CheckValues(x, xn));
    }
}

void TestFft(){
    {
        std::vector<double> xn = {2, 4, 8, 16};
        std::vector<std::complex<double>> test = {
            {30, 0},
            {-6, -12},
            {-10, 0},
            {-6, 12}
        };
        auto X = Fft(xn.begin(), xn.end());
        ASSERT(CheckValues(X, test));
    }

    {
        std::vector<double> xn(1000, 1);
        ASSERT_THROWS(Fft(xn.begin(), xn.end()), std::invalid_argument);
    }

    {
        std::vector<double> xn(100, 1);
        ASSERT_THROWS(Fft(xn.begin(), xn.end()), std::invalid_argument);
    }

    {
        std::vector<double> xn(1, 10);
        ASSERT_DOESNT_THROW(Fft(xn.begin(), xn.end()));
    }

    {
        std::vector<double> xn(2, 10);
        ASSERT_DOESNT_THROW(Fft(xn.begin(), xn.end()));
    }

    {
        std::vector<double> xn(8, 10);
        ASSERT_DOESNT_THROW(Fft(xn.begin(), xn.end()));
    }

    {
        std::vector<double> xn(65536, 10);
        ASSERT_DOESNT_THROW(Fft(xn.begin(), xn.end()));
    }
}

void TestIfft(){
    {
        std::vector<double> test = {2, 4, 8, 16};
        std::vector<std::complex<double>> X = {
            {30, 0},
            {-6, -12},
            {-10, 0},
            {-6, 12}
        };
        auto x = Ifft(X.begin(), X.end());
        ASSERT(CheckValues(x, test));
    }

    {
        std::vector<std::complex<double>> xn(1000, {1, 1});
        ASSERT_THROWS(Ifft(xn.begin(), xn.end()), std::invalid_argument);
    }

    {
        std::vector<std::complex<double>> xn(100, {1, 1});
        ASSERT_THROWS(Ifft(xn.begin(), xn.end()), std::invalid_argument);
    }

    {
        std::vector<std::complex<double>> xn(1, {1, 1});
        ASSERT_DOESNT_THROW(Ifft(xn.begin(), xn.end()));
    }

    {
        std::vector<std::complex<double>> xn(2, {1, 1});
        ASSERT_DOESNT_THROW(Ifft(xn.begin(), xn.end()));
    }

    {
        std::vector<std::complex<double>> xn(8, {1, 1});
        ASSERT_DOESNT_THROW(Ifft(xn.begin(), xn.end()));
    }

    {
        std::vector<std::complex<double>> xn(65536, {1, 1});
        ASSERT_DOESNT_THROW(Ifft(xn.begin(), xn.end()));
    }
}

void TestFftIfft(){
    {
        std::vector<double> xn = {2, 4, 8, 16};
        auto X = Fft(xn.begin(), xn.end());
        auto x = Ifft(X.begin(), X.end());
        ASSERT(CheckValues(x, xn));
    }

    {
        std::vector<double> xn = {1, 2, 3, 4, 5, 6, 7, 8};
        auto X = Fft(xn.begin(), xn.end());
        auto x = Ifft(X.begin(), X.end());
        ASSERT(CheckValues(x, xn));
    }
}

void TestMultiply(){
    {
        std::vector<int> a = {1,2,3,4,5};
        std::vector<int> b = {2,4,8,9};

        std::vector<int> test = {3, 0, 7, 2, 6, 7, 0, 5};
        ASSERT_EQUAL(Multiply(a, b), test);
    }

    {
        std::vector<int> a = {2};
        std::vector<int> b = {2};

        std::vector<int> test = {4};
        ASSERT_EQUAL(Multiply(a, b), test);
    }

    {
        std::vector<int> a = {1,2,3,4};
        std::vector<int> b = {2,4,8,9};

        std::vector<int> test = {3, 0, 7, 1, 4, 2, 6};
        ASSERT_EQUAL(Multiply(a, b), test);
    }

    {
        std::vector<int> a = {1};
        std::vector<int> b = {9};

        std::vector<int> test = {9};
        ASSERT_EQUAL(Multiply(a, b), test);
    }

    {
        std::vector<int> a = {1};
        std::vector<int> b = {9, 0};

        std::vector<int> test = {9, 0};
        ASSERT_EQUAL(Multiply(a, b), test);
    }

    {
        std::vector<int> a = {1};
        std::vector<int> b = {9, 0, 0};

        std::vector<int> test = {9, 0, 0};
        ASSERT_EQUAL(Multiply(a, b), test);
    }

    {
        std::vector<int> a = {2, 0};
        std::vector<int> b = {9, 0, 0};

        std::vector<int> test = {1, 8, 0, 0, 0};
        ASSERT_EQUAL(Multiply(a, b), test);
    }

    {
        std::vector<int> a = {2, 0};
        std::vector<int> b = {9, 0, 0};

        std::vector<int> test = {1, 8, 0, 0, 0};
        ASSERT_EQUAL(Multiply(a, b), test);
    }

    {
        std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4};
        std::vector<int> b = {1, 2, 3};

        std::vector<int> test = {1, 5, 1, 8, 5, 1, 8, 5, 0, 6, 2, 1, 7, 8, 2};
        ASSERT_EQUAL(Multiply(a, b), test);
    }
}

void TestBenchmark(){
    size_t size =  4096;
    std::string name = "benchmark.csv";
    std::remove(name.c_str());
    std::ofstream out(name, std::ios::app);
    if(out.is_open()){

        LOG_DURATION("Benchmark");

        for(size_t  i = 1, pow_2 = std::pow(2, i); pow_2 <= size; ++i, pow_2 = std::pow(2, i)){
            auto x = linspace(0.0, 50.0, pow_2);
            std::vector<double> y(pow_2);
            for(size_t j = 0; j < pow_2; ++j){
                y[j] = std::sin(2*x[j]) + std::sin(3*x[j]) + std::sin(5*x[j]);
            }
            out << pow_2 << ',';
            {
                std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
                auto X_fft = Fft(y.begin(), y.end());
                const auto end_time = std::chrono::steady_clock::now();
                const auto dur = end_time - start_time;
                out << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << ',';
            }
            {
                std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
                auto X_dft = Dft(y.begin(), y.end());
                const auto end_time = std::chrono::steady_clock::now();
                const auto dur = end_time - start_time;
                out << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count() << '\n';
            }
        }
    }
    out.close();
}

void Test(){
    TestRunner runner;
    RUN_TEST(runner, TestDft);
    RUN_TEST(runner, TestIdft);
    RUN_TEST(runner, TestDftIdft);
    RUN_TEST(runner, TestFft);
    RUN_TEST(runner, TestIfft);
    RUN_TEST(runner, TestFftIfft);
    RUN_TEST(runner, TestBenchmark);
    RUN_TEST(runner, TestMultiply);
}
