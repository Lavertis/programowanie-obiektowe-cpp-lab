#include "MaxBuffer.hpp"

MaxBuffer::MaxBuffer() {
    cout << "MaxBuffer constructor" << endl;
}

MaxBuffer::MaxBuffer(size_t capacity) : Buffer(capacity) {
    cout << "MaxBuffer constructor" << endl;
}

void MaxBuffer::add(int value) {
    if (getSize() == getCapacity())
        throw std::invalid_argument("Buffer is full");

    setData(getSize(), value);
    setSize(getSize() + 1);
}

double MaxBuffer::calculate() {
    if (getSize() == 0)
        throw std::invalid_argument("Cannot get max value. No data in buffer.");

    int max = getData(0);
    for (int i = 1; i < getSize(); ++i) {
        if (getData(i) > max)
            max = getData(i);
    }

    return max;
}

MaxBuffer::~MaxBuffer() {
    cout << "MaxBuffer destructor" << endl;
}