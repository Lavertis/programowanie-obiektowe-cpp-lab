#pragma once

#include <iostream>
#include <regex>

using namespace std;

class AddressValidator {
private:
    static std::regex street_pattern;
    static std::regex postal_code_pattern;
    static std::regex house_number_pattern;
    static std::regex flat_number_pattern;

public:
    AddressValidator();

    static bool validateStreet(const string &street);

    static bool validatePostalCode(const string &postalCode);

    static bool validateHouseNumber(const string &houseNumber);

    static bool validateFlatNumber(const string &flatNumber);
};

