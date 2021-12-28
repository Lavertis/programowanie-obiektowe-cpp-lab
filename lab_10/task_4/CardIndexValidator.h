#pragma once

#include <regex>

class CardIndexValidator {
private:
    static std::regex first_name_pattern;
    static std::regex last_name_pattern;
    static std::regex age_pattern;
    static std::regex phone_number_pattern;
    static std::regex email_pattern;
public:
    static bool validateFirstName(const std::string &firstName);

    static bool validateLastName(const std::string &lastName);

    static bool validateAge(const std::string &age);

    static bool validatePhoneNumber(const std::string &phoneNumber);

    static bool validateEmail(const std::string &email);
};