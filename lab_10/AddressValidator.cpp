#include "AddressValidator.h"

bool AddressValidator::validateStreet(const string &street) {
    return regex_match(street, street_pattern);
}

bool AddressValidator::validatePostalCode(const string &postalCode) {
    return regex_match(postalCode, postal_code_pattern);
}

bool AddressValidator::validateHouseNumber(const string &houseNumber) {
    return regex_match(houseNumber, house_number_pattern);
}

bool AddressValidator::validateFlatNumber(const string &flatNumber) {
    return regex_match(flatNumber, flat_number_pattern);
}

AddressValidator::AddressValidator() {
    street_pattern = std::regex("^$");
    postal_code_pattern = std::regex("^\\d{2}-\\d{3}$");
    house_number_pattern = std::regex("^[1-9][A-Z\\d]*$");
    flat_number_pattern = std::regex("^[1-9][0-9]*$");
}