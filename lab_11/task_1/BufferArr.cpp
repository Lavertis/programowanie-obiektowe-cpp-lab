#include <iostream>
#include <memory>
#include "BufferArr.h"

using namespace std;

BufferArr::BufferArr(int capacity) : capacity_(capacity), size_(0), tab_(make_unique<int[]>(5)) {
    cout << "BufferArr constructor" << endl;
}

void BufferArr::add(int a) {
    if (size_ == capacity_)
        throw runtime_error("Buffer size exceeded");
    tab_[size_++] = a;
    cout << "Added: " << a << ". Elements in array: " << size_ << ". Capacity: " << capacity_ << endl;
}

void BufferArr::write() {
    for (int i = 0; i < size_; ++i)
        cout << tab_[i] << " ";
    cout << endl;
}

int BufferArr::getSize() const {
    return size_;
}

int BufferArr::getCapacity() const {
    return capacity_;
}

BufferArr::~BufferArr() {
    cout << "BufferArr destructor" << endl;
}