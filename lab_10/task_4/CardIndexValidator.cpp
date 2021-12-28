#include "CardIndexValidator.h"

std::regex CardIndexValidator::first_name_pattern = std::regex(R"(^[A-Z][a-z]+$)");
std::regex CardIndexValidator::last_name_pattern = std::regex(R"(^[A-Z][a-z]+(-[A-Z][a-z]+)?$)");
std::regex CardIndexValidator::age_pattern = std::regex(R"(^[1-9][0-9]?$)");
std::regex CardIndexValidator::phone_number_pattern = std::regex(R"(^[1-9][0-9]{8}$)");
std::regex CardIndexValidator::email_pattern = std::regex(R"(^[A-Za-z][\w-._]+@\w+.\w+$)");

bool CardIndexValidator::validateFirstName(const std::string &firstName) {
    return regex_match(firstName, first_name_pattern);
}

bool CardIndexValidator::validateLastName(const std::string &lastName) {
    return regex_match(lastName, last_name_pattern);
}

bool CardIndexValidator::validateAge(const std::string &age) {
    return regex_match(age, age_pattern);
}

bool CardIndexValidator::validatePhoneNumber(const std::string &phoneNumber) {
    return regex_match(phoneNumber, phone_number_pattern);
}

bool CardIndexValidator::validateEmail(const std::string &email) {
    return regex_match(email, email_pattern);
}
