#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H
#include <vector>
#include <complex>
#include <fstream>
#include <numeric>

// создаёт равномерно распределенную последовательность в указанном интервале.
template <typename T>
std::vector<T> linspace(T start, T end, double num){
    std::vector<T> linspaced;
    if (0 != num){
        if (1 == num) {
            linspaced.push_back(start);
        }
        else if(2 == num){
            linspaced.push_back(start);
            linspaced.push_back(end);
        }
        else{
            double delta = (end - start) / (num - 1);
            for (auto i = 0; i < (num - 1); ++i){
                linspaced.push_back(start + delta * i);
            }
            linspaced.push_back(end);
        }
    }
    return linspaced;
}

// сохраняет логи в csv формате

namespace detail {
    template <typename Container, typename Linspace>
    void WriteLog(Linspace& x, Container& y, std::string path, bool complex){
        std::ofstream out(path);
        if(out.is_open()){
            for(size_t i = 0 ; i < y.size(); ++i){
                if(complex){
                    out << x[i] << ',' << std::abs(y[i]) << '\n';
                }else{
                    out << x[i] << ',' << y[i] << '\n';
                }
            }
        }
        out.close();
    }
}


// сохраняет логи в csv формате
template <typename Container, typename Linspace>
void WriteLog(Linspace& x, Container& y, std::string path){
    detail::WriteLog(x, y, path, false);
}

//
template <typename Container, typename Linspace>
void WriteComplexLog(Linspace& x, Container& y, std::string path){
    detail::WriteLog(x, y, path, true);
}

// Z-преобразование
std::vector<std::complex<double>> z_transform(const std::vector<double>& x, const std::vector<std::complex<double>>& z);

#endif // UTILITY_FUNCTIONS_H
