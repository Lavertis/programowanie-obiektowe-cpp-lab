#include "Citizen.hpp"

Citizen::Citizen(string name, string surname, int age, char sex, string postalCode) :
        name_(std::move(name)), surname_(std::move(surname)), age_(age), sex_(sex),
        postal_code_(std::move(postalCode)) {}

void Citizen::show() const {
    cout << "Citizen{name: " << getName()
         << ", surname: " << getSurname()
         << ", age: " << getAge()
         << ", sex: " << getSex()
         << ", postalCode: " << getPostalCode()
         << "}" << endl;
}

const string &Citizen::getName() const {
    return name_;
}

const string &Citizen::getSurname() const {
    return surname_;
}

int Citizen::getAge() const {
    return age_;
}

char Citizen::getSex() const {
    return sex_;
}

const string &Citizen::getPostalCode() const {
    return postal_code_;
}
