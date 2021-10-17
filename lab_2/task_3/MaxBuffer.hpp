#pragma once

#include "Buffer.hpp"

class MaxBuffer : public Buffer {
public:
    MaxBuffer();

    explicit MaxBuffer(size_t capacity);

    void add(int value) override;

    double calculate() override;

    ~MaxBuffer() override;
};