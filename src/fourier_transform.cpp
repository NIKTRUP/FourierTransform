#include "../include/fourier_transform.h"

void Normalize(std::vector<int>& x) {
    int carry = 0;
    for (size_t i = 0; i < x.size() ; ++i) {
        x[i] += carry;
        carry = x[i] / 10;
        x[i] %= 10;
    }
}

std::vector<int> Multiply (const std::vector<int> & a, const std::vector<int> & b) {
    std::vector<std::complex<ldouble>> fa (a.rbegin(), a.rend()), fb (b.rbegin(), b.rend());
    size_t n = 1;
    for(; n <= std::max(a.size(), b.size()); n <<= 1) {}
    n <<= 1;

    fa.resize (n),  fb.resize (n);

    fa = Fft(fa.begin(), fa.end());
    fb = Fft(fb.begin(), fb.end());
    for (size_t i=0; i < n; ++i){
        fa[i] *= fb[i];
    }
    auto out = Ifft(fa.begin(), fa.end());

    std::vector<int> result(n);
    for (size_t i=0; i<n; ++i){
        result[i] = std::round(out[i]);
    }

    Normalize(result);
    std::reverse(result.begin(), result.end());
    size_t shift = 0;
    for(size_t i = 0; i < result.size(); ++i){
        bool is_null = result[i] == 0;
        shift += (is_null) ? 1 : 0;
        if (!is_null){
            break;
        }
    }
    result = {result.begin() + shift, result.end()};
    return result;
}
