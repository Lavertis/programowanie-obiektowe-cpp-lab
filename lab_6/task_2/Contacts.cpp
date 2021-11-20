#include "Contacts.hpp"

bool Contacts::add(const Contact &contact) {
    return contacts.insert(contact).second;
}

bool Contacts::add(const std::string &name, const std::string &surname, int age,
                   const std::string &phone_number, const std::string &street) {
    Contact contact(name, surname, age, phone_number, street);
    return contacts.insert(contact).second;
}

bool Contacts::deleteByPhoneNumber(const std::string &phone_number) {
    auto &phone_number_idx = contacts.get<PHONE_NUMBER>();
    auto contact = phone_number_idx.find(phone_number);
    if (contact == phone_number_idx.end())
        return false;

    phone_number_idx.erase(contact);
    return true;
}

std::vector<Contact> Contacts::findByStreetName(const std::string &street_name) {
    auto &street_idx = contacts.get<STREET>();
    std::vector<Contact> contact_vec;
    auto it = street_idx.find(street_name);
    while (it->street == street_name) // can do this because of ordered street index
        contact_vec.push_back(*it++);
    return contact_vec;
}

std::vector<Contact> Contacts::findByAgeRange(int lower_bound, int upper_bound) {
    auto &age_idx = contacts.get<AGE>();
    std::vector<Contact> contact_vec;
    auto it = age_idx.lower_bound(lower_bound);
    auto it_end = age_idx.upper_bound(upper_bound);
    while (it != it_end) // can do this because of ordered age index
        contact_vec.push_back(*it++);
    return contact_vec;
}

std::optional<Contact> Contacts::findByPhoneNumber(const std::string &phone_number) {
    auto &phone_number_idx = contacts.get<PHONE_NUMBER>();
    auto contact = phone_number_idx.find(phone_number);
    if (contact == phone_number_idx.end())
        return std::nullopt;
    return *contact;
}

bool Contacts::changeStreetName(const std::string &street_name, const std::string &new_street_name) {
    auto &street_name_idx = contacts.get<STREET>();
    std::vector<street_type::iterator> it_vec;
    auto it = street_name_idx.lower_bound(street_name);
    auto it_end = street_name_idx.upper_bound(street_name);
    if (it == street_name_idx.end())
        return false;

    while (it != it_end)
        it_vec.push_back(it++);

    for (auto contact: it_vec) {
        street_name_idx.modify(contact, [&new_street_name](auto &contact) {
            contact.street = new_street_name;
        });
    }
    return true;
}

size_t Contacts::adultsCount() {
    auto &age_idx = contacts.get<AGE>();
    auto it = age_idx.lower_bound(18);
    return boost::iterators::distance(it, age_idx.end());
}

size_t Contacts::uniqueSurnamesCount() {
    auto &surname_idx = contacts.get<SURNAME>();
    size_t counter = 0;
    for (auto it = surname_idx.begin(); it != surname_idx.end(); it = surname_idx.upper_bound(it->surname))
        counter++;
    return counter;
}

void Contacts::show() {
    auto &random_idx = contacts.get<RANDOM>();
    for (const auto &contact: random_idx) {
        contact.show();
    }
}