#include <map>
#include "City.hpp"

City::City(string name) : name_(std::move(name)) {}

void City::addCitizen(const Citizen &citizen) {
    citizens_.push_back(citizen);
}

void City::deleteCitizen(const string &citizen_name, int citizen_age) {
    auto found_citizen = find_if(citizens_.begin(), citizens_.end(), [=](const Citizen &c) {
        return c.getName() == citizen_name && c.getAge() == citizen_age;
    });

    if (found_citizen == citizens_.end())
        throw invalid_argument("Citizen with such name and age not found");

    citizens_.erase(found_citizen);
}

void City::showCitizens() {
    cout << "Citizens: " << endl;
    for_each(citizens_.begin(), citizens_.end(), [](const Citizen &citizen) { citizen.show(); });
}

void City::showCity() const {
    cout << "City: " << name_ << endl;
}

size_t City::womenCount() {
    size_t count = count_if(citizens_.begin(), citizens_.end(), [](const Citizen &citizen) {
        return citizen.getSex() == 'f';
    });
    return count;
}

size_t City::citizenCount() {
    return citizens_.size();
}

size_t City::adultCount() {
    size_t count = count_if(citizens_.begin(), citizens_.end(), [](const Citizen &citizen) {
        return citizen.getAge() >= 18;
    });
    return count;
}

void City::postalCodes() {
    map<string, size_t> pc_count;
    for_each(citizens_.begin(), citizens_.end(), [&](const Citizen &citizen) {
        const string &postal_code = citizen.getPostalCode();
        if (pc_count.contains(postal_code))
            pc_count[postal_code]++;
        else
            pc_count[postal_code] = 1;
    });

    for_each(pc_count.begin(), pc_count.end(), [](const pair<string, size_t> &pair) {
        cout << pair.first << ": " << pair.second << " mieszkańców" << endl;
    });
}

const vector<Citizen> &City::getCitizens() const {
    return citizens_;
}

const string &City::getName() const {
    return name_;
}