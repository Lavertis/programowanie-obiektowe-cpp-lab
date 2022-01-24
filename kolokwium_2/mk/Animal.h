#pragma once

#include <string>
#include <utility>


class Animal {
private:
    std::string name_;
    int age_;
public:
    Animal(std::string name, int age);

    [[nodiscard]] const std::string &getName() const;

    [[nodiscard]] int getAge() const;
};

Animal::Animal(std::string name, int age) : name_(std::move(name)), age_(age) {}

const std::string &Animal::getName() const {
    return name_;
}

int Animal::getAge() const {
    return age_;
}