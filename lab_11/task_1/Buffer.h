#pragma once

class Buffer {
public:
    virtual void add(int a) = 0;

    virtual void write() = 0;

    Buffer();

    virtual ~Buffer();
};