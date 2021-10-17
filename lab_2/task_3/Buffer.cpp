#include "Buffer.hpp"

Buffer::Buffer() : capacity_(10), data_(new int[10]), size_(0) {
    cout << "Buffer constructor" << endl;
}

Buffer::Buffer(size_t capacity) : capacity_(capacity), data_(new int[capacity]), size_(0) {
    cout << "Buffer constructor" << endl;
}

void Buffer::add(int value) {
    data_[size_] = value;
    size_++;
}

size_t Buffer::getCapacity() const {
    return capacity_;
}

size_t Buffer::getSize() const {
    return size_;
}

void Buffer::setSize(size_t size) {
    size_ = size;
}

void Buffer::show() {
    cout << "Buffer[";
    for (int i = 0; i < size_; ++i) {
        cout << data_[i];
        if (i < size_ - 1)
            cout << ", ";
    }
    cout << ']' << endl;
}

int Buffer::getData(size_t i) {
    if (i > size_ - 1)
        throw std::invalid_argument("Buffer data index out of bounds");

    return data_[i];
}

void Buffer::setData(size_t i, int value) {
    data_[i] = value;
}

Buffer::~Buffer() {
    cout << "Buffer destructor" << endl;
    delete[] data_;
}