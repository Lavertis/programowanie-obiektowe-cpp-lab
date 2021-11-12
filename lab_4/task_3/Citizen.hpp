#pragma once

#include <iostream>

using namespace std;

class Citizen {
private:
    string name_;
    string surname_;
    int age_{};
    char sex_{};
    string postal_code_;
public:
    Citizen() = default;

    Citizen(string name, string surname, int age, char sex, string postalCode);

    void show() const;

    [[nodiscard]] const string &getName() const;

    [[nodiscard]] const string &getSurname() const;

    [[nodiscard]] int getAge() const;

    [[nodiscard]] char getSex() const;

    [[nodiscard]] const string &getPostalCode() const;
};

