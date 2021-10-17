#pragma once

#include "Employee.hpp"

class Developer : public Employee {
public:
    Developer(const string &surname, int age, int experience, int salary);

    Developer();

    float calculateBonus(int value) override;

    void show() override;

    ~Developer() override;
};