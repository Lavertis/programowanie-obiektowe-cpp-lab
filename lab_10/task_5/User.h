#pragma once

#include <string>

class User {
private:
    std::string first_name_;
    std::string last_name_;
    std::string age_;
    std::string phone_number_;
    std::string email_;
public:
    User(std::string firstName, std::string lastName, std::string age,
         std::string phoneNumber, std::string email);

    [[nodiscard]] const std::string &getFirstName() const;

    [[nodiscard]] const std::string &getLastName() const;

    [[nodiscard]] const std::string &getPhoneNumber() const;

    [[nodiscard]] const std::string &getEmail() const;
};