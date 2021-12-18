#pragma once

#include "Buffer.h"
#include <memory>

class BufferArr : public Buffer {
private:
    std::shared_ptr<int[]> tab_;
    int size_;
    int capacity_;
public:
    explicit BufferArr(int capacity);

    void add(int a) override;

    void write() override;

    [[nodiscard]] int getSize() const;

    [[nodiscard]] int getCapacity() const;

    ~BufferArr() override;
};