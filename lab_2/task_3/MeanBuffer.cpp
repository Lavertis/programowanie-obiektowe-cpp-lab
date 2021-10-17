#include "MeanBuffer.hpp"

MeanBuffer::MeanBuffer() {
    cout << "MeanBuffer constructor" << endl;
}

MeanBuffer::MeanBuffer(size_t capacity) : Buffer(capacity) {
    cout << "MeanBuffer constructor" << endl;
}

MeanBuffer::~MeanBuffer() {
    cout << "MeanBuffer destructor" << endl;
}

double MeanBuffer::calculate() {
    if (getSize() == 0)
        throw std::invalid_argument("Cannot get mean value. No data in buffer.");

    double mean = 0;

    for (int i = 0; i < getSize(); ++i)
        mean += getData(i);

    mean /= static_cast<double>(getSize());
    return mean;
}
