#pragma once

#include "Buffer.hpp"

class MeanBuffer : public Buffer {
public:
    MeanBuffer();

    explicit MeanBuffer(size_t capacity);

    double calculate() override;

    ~MeanBuffer() override;
};

