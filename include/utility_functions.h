#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H
#include <vector>
#include <complex>
#include <fstream>
#include <numeric>

using ldouble = long double;

// создаёт равномерно распределенную последовательность в указанном интервале.
std::vector<ldouble> linspace(ldouble start, ldouble end, ldouble num);

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
std::vector<std::complex<ldouble>> z_transform(const std::vector<ldouble>& x, const std::vector<std::complex<ldouble>>& z);

template <typename T>
std::vector<ldouble> Abs(const std::vector<T>& in){
    std::vector<ldouble> out(in.size());
    for(std::size_t i = 0; i < in.size(); ++i){
        out[i] = std::abs(in[i]);
    }
    return out;
}

#endif // UTILITY_FUNCTIONS_H
