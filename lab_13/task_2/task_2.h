#pragma once

#include <stdexcept>

double reciprocalNumber(double x) {
    if (x == 0)
        throw std::invalid_argument("Number cannot be 0");
    return 1 / x;
}