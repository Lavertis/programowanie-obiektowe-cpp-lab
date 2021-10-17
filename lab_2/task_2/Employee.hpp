#pragma once

#include <iostream>

using namespace std;

class Employee {
private:
    string surname_;
    int age_{};
    int experience_{};
    int salary_{};
public:
    Employee(string surname, int age, int experience, int salary);

    Employee();

    virtual void show();

    virtual float calculateBonus(int value) = 0;

    [[nodiscard]] const string &getSurname() const;

    [[nodiscard]] int getAge() const;

    [[nodiscard]] int getExperience() const;

    [[nodiscard]] int getSalary() const;

    virtual ~Employee();
};

