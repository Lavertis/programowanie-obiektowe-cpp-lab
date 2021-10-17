#pragma once

#include "Employee.hpp"

class TeamLeader : public Employee {
public:
    TeamLeader(const string &surname, int age, int experience, int salary);

    TeamLeader();

    float calculateBonus(int value) override;

    void show() override;

    ~TeamLeader() override;
};

