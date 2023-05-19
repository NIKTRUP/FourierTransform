#include "../include/utility_functions.h"

std::vector<ldouble> linspace(ldouble start, ldouble end, ldouble num){
    std::vector<ldouble> linspaced;
    if (0 != num){
        if (1 == num) {
            linspaced.push_back(start);
        }
        else if(2 == num){
            linspaced.push_back(start);
            linspaced.push_back(end);
        }
        else{
            ldouble delta = (end - start) / (num - 1);
            for (auto i = 0; i < (num - 1); ++i){
                linspaced.push_back(start + delta * i);
            }
            linspaced.push_back(end);
        }
    }
    return linspaced;
}

// Z-преобразование
std::vector<std::complex<ldouble>> z_transform(const std::vector<ldouble>& x, const std::vector<std::complex<ldouble>>& z){

    std::vector<std::complex<ldouble>> out(z.size(), 0.0);
    std::vector<ldouble> range(x.size());
    std::iota(range.begin(), range.end(), 0);
    for(size_t i = 0; i < z.size(); ++i){
        for(size_t j = 0; j < range.size(); ++j){
            out[i] +=  x[j]*std::pow(z[i], -range[j]);
        }
    }
    return out;
}
