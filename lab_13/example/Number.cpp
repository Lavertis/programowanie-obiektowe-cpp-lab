#include "Number.h"

Number::Number(int n1) {
    n = n1;
}

int Number::inc() const {
    return n + 1;
}

int Number::getN() const {
    return n;
}

void Number::setN(int n1) {
    n = n1;
}