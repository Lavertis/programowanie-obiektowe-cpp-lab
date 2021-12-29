#include "User.h"

#include <utility>

User::User(std::string firstName, std::string lastName, std::string age, std::string phoneNumber, std::string email) :
        first_name_(std::move(firstName)), last_name_(std::move(lastName)), age_(std::move(age)),
        phone_number_(std::move(phoneNumber)), email_(std::move(email)) {}

const std::string &User::getFirstName() const {
    return first_name_;
}

const std::string &User::getLastName() const {
    return last_name_;
}

const std::string &User::getPhoneNumber() const {
    return phone_number_;
}

const std::string &User::getEmail() const {
    return email_;
}
