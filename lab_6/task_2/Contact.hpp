#pragma once

class Contact {
public:
    std::string name{};
    std::string surname{};
    int age{};
    std::string phone_number{};
    std::string street{};

    Contact(std::string name, std::string surname, int age, std::string phoneNumber, std::string street) :
            name(std::move(name)), surname(std::move(surname)), age(age), phone_number(std::move(phoneNumber)),
            street(std::move(street)) {}

    void show() const {
        std::cout << name << " " << surname << " " << age << " " << phone_number << " " << street << std::endl;
    }
};