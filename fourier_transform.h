#ifndef FOURIER_TRANSFORM_H
#define FOURIER_TRANSFORM_H

#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <exception>
#include <iostream>

namespace detail {

    template <typename Iterator>
    std::vector<std::complex<double>> Fft(Iterator begin, Iterator end, bool invert){
        std::vector<std::complex<double>> x(begin, end);

        // Если размерность не равна 1 или размер не является степенью двойки
        if(x.size() != 1 && std::fmod(std::log2(x.size()), 1) != 0){
            throw std::invalid_argument("Размерность сигнала должна быть степенью двойки ");
        }

        size_t n = x.size();
        if (n == 1)  return x;

        std::vector<std::complex<double>> x1 (n/2),  x2 (n/2);
        for (size_t i=0, j=0; i < n; i+=2, ++j) {
            x1[j] = x[i];
            x2[j] = x[i+1];
        }
        x1 = Fft (x1.begin(), x1.end(), invert);
        x2 = Fft (x2.begin(), x2.end(), invert);

        double theta = 2*M_PI/n * (invert ? -1 : 1);
        std::complex<double> w (1),  wn (std::cos(theta), std::sin(theta));
        for (size_t i = 0; i < n/2; ++i) {
            x[i] = x1[i] + w * x2[i];
            x[i+n/2] = x1[i] - w * x2[i];
            if (invert){
                x[i] /= 2,  x[i+n/2] /= 2;
            }
            w *= wn;
        }
        return x;
    }

}

template <typename Iterator>
std::vector<std::complex<double>> Fft(Iterator begin, Iterator end){
    return detail::Fft(begin, end, false);
}

template <typename Iterator>
std::vector<double> Ifft(Iterator begin, Iterator end){
    auto res = detail::Fft(begin, end, true);
    std::vector<double> out(res.size());
    for(size_t i = 0; i < out.size(); ++i){
        out[i] = std::abs(res[i]);
    }
    return out;
}

template <typename Iterator>
std::vector<std::complex<double>> Dft(Iterator begin, Iterator end){
    size_t N = std::distance(begin, end);
    std::vector<std::complex<double>> X(N);

    for (size_t k = 0; k < N; ++k) {
        X[k] = {0, 0};
        size_t i = 0;
        for (auto it = begin; it < end; ++i, ++it) {
            double angle = -2 * M_PI * k * i / N;
            X[k] = {X[k].real() + (*it) * std::cos(angle),
                    X[k].imag() - (*it) * std::sin(angle)};
        }
    }
    return X;
}

template <typename Iterator>
std::vector<double> Idft(Iterator begin, Iterator end)
{
    size_t N = std::distance(begin, end);
    std::vector<double> x(N);

    for (size_t i = 0; i < N; ++i) {
        x[i] = 0;
        size_t k = 0;
        for (auto it = begin; it < end; ++k, ++it) {
            double angle = (-2 * M_PI * k * i) / N;
            x[i] += it->real() * cos(angle) + it->imag() * sin(angle);
        }
        x[i] /= N;
    }
    std::reverse(x.begin()+1, x.end());
    return x;
}

void Normalize(std::vector<int>& x);


std::vector<int> Multiply (const std::vector<int> & a, const std::vector<int> & b);


#endif // FOURIER_TRANSFORM_H
