#include "task_2/Contacts.hpp"

void task_2();

int main() {
    task_2();
}

void task_2() {
    Contacts contacts;
    std::vector<Contact> vec{
            Contact("Sebastian", "Greenwood", 12, "111111111", "Long Street"),
            Contact("Sebastian", "Greenwood", 14, "222222222", "Long Street"),
            Contact("Skye", "Goddard", 16, "333333333", "Short Street"),
            Contact("Harriet", "Connor", 24, "444444444", "Short Street"),
            Contact("Joe", "Alexander", 25, "555555555", "Apple Pie Street"),
            Contact("Brooke", "Vaughan", 26, "666666666", "Strawberry Street"),
            Contact("Joe", "Vaughan", 27, "777777777", "Pudding Street"),
    };
    for (const auto &contact: vec)
        contacts.add(contact);
    contacts.show();
    std::cout << std::endl;

    std::cout << "Delete by phone number:" << std::endl;
    contacts.deleteByPhoneNumber("222222222");
    contacts.show();
    std::cout << std::endl;

    std::cout << "Find by street name:" << std::endl;
    auto short_street_contacts = contacts.findByStreetName("Short Street");
    for (const auto &contact: short_street_contacts)
        contact.show();
    std::cout << std::endl;

    std::cout << "Find by age range:" << std::endl;
    auto age_range_contacts = contacts.findByAgeRange(24, 26);
    for (const auto &contact: age_range_contacts)
        contact.show();
    std::cout << std::endl;

    std::cout << "Find by phone number:" << std::endl;
    auto phone_number = contacts.findByPhoneNumber("555555555");
    if (phone_number)
        phone_number->show();
    std::cout << std::endl;

    std::cout << "Change street name:" << std::endl;
    contacts.changeStreetName("Short Street", "Wall Street");
    contacts.show();
    std::cout << std::endl;

    std::cout << "Count adults:" << std::endl;
    auto adultsCount = contacts.adultsCount();
    std::cout << adultsCount << std::endl;
    std::cout << std::endl;

    std::cout << "Count unique surnames:" << std::endl;
    contacts.show();
    auto uniqueSurnamesCount = contacts.uniqueSurnamesCount();
    std::cout << uniqueSurnamesCount << std::endl;
}