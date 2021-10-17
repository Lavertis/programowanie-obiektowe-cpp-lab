#pragma once

#include <iostream>

using namespace std;

class Buffer {
private:
    int *data_;
    size_t capacity_;
    size_t size_;
public:
    Buffer();

    explicit Buffer(size_t capacity);

    virtual void add(int value);

    virtual double calculate() = 0;

    [[nodiscard]] size_t getCapacity() const;

    [[nodiscard]] size_t getSize() const;

    void setSize(size_t size);

    int getData(size_t i);

    void setData(size_t i, int value);

    void show();

    virtual ~Buffer();
};