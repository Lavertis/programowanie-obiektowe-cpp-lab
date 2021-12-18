#pragma once

#include "Buffer.h"
#include <iostream>
#include <memory>
#include <fstream>

class BufferFile : public Buffer {
private:
    std::string filePath_;
    std::shared_ptr<std::fstream> file_;
public:
    explicit BufferFile(std::string filePath);

    void add(int a) override;

    void write() override;

    ~BufferFile() override;
};