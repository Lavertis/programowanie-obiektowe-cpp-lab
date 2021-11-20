#pragma once

#include <iostream>
#include <vector>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/iterator/distance.hpp>
#include "Contact.hpp"

enum Index {
    PHONE_NUMBER, STREET, AGE, SURNAME, RANDOM
};

using namespace boost::multi_index;

typedef multi_index_container<Contact, indexed_by<
        hashed_unique<member<Contact, std::string, &Contact::phone_number>>,
        ordered_non_unique<member<Contact, std::string, &Contact::street>>,
        ordered_non_unique<member<Contact, int, &Contact::age>>,
        ordered_non_unique<member<Contact, std::string, &Contact::surname>>,
        random_access<>
>> ContactsMultiIndex;
typedef ContactsMultiIndex::nth_index<PHONE_NUMBER>::type phone_number_type;
typedef ContactsMultiIndex::nth_index<STREET>::type street_type;
typedef ContactsMultiIndex::nth_index<AGE>::type age_type;
typedef ContactsMultiIndex::nth_index<SURNAME>::type surname_type;

class Contacts {
private:
    ContactsMultiIndex contacts;
public:
    bool add(const Contact &contact);

    bool add(const std::string &name, const std::string &surname, int age,
             const std::string &phone_number, const std::string &street);

    bool deleteByPhoneNumber(const std::string &phone_number);

    [[nodiscard]] std::vector<Contact> findByStreetName(const std::string &street_name);

    [[nodiscard]] std::vector<Contact> findByAgeRange(int lower_bound, int upper_bound);

    [[nodiscard]] std::optional<Contact> findByPhoneNumber(const std::string &phone_number);

    bool changeStreetName(const std::string &street_name, const std::string &new_street_name);

    [[nodiscard]] size_t adultsCount();

    [[nodiscard]] size_t uniqueSurnamesCount();

    void show();
};