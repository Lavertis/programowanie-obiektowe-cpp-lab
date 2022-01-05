#pragma once


class Number {
private:
    int n;
public:
    explicit Number(int n1);

    [[nodiscard]] int inc() const;

    [[nodiscard]] int getN() const;

    void setN(int n1);

};

