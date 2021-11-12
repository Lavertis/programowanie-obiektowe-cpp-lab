#pragma once

#include <iostream>
#include <vector>
#include "Citizen.hpp"

using namespace std;

class City {
private:
    vector<Citizen> citizens_;
    string name_;
public:
    explicit City(string name);

    void addCitizen(const Citizen &citizen);

    void deleteCitizen(const string &citizen_name, int citizen_age);

    void showCitizens();

    void showCity() const;

    size_t womenCount();

    size_t citizenCount();

    size_t adultCount();

    void postalCodes();

    [[nodiscard]] const string &getName() const;

    [[nodiscard]] const vector<Citizen> &getCitizens() const;
};

