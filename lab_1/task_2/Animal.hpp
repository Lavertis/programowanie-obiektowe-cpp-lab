#pragma once

#include <iostream>

using namespace std;

class Animal {
private:
    int limbCount_{};
    string name_;
    bool isProtected_{};
public:
    Animal() = default;

    Animal(int limbCount, string name, bool isProtected = true);

    void giveVoice();

    void info();

    [[nodiscard]] int getLimbCount() const;

    void setLimbCount(int limbCount);

    [[nodiscard]] const string &getName() const;

    void setName(const string &name);

    [[nodiscard]] bool isProtected() const;

    void setIsProtected(bool isProtected);
};