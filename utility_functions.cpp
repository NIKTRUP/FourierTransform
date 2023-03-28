#include "utility_functions.h"

// Z-преобразование
std::vector<std::complex<double>> z_transform(const std::vector<double>& x, const std::vector<std::complex<double>>& z){

    std::vector<std::complex<double>> out(z.size(), 0.0);
    std::vector<double> range(x.size());
    std::iota(range.begin(), range.end(), 0);
    for(size_t i = 0; i < z.size(); ++i){
        for(size_t j = 0; j < range.size(); ++j){
            out[i] +=  x[j]*std::pow(z[i], -range[j]);
        }
    }
    return out;
}
