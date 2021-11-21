#include <numeric>
#include <boost/fusion/container.hpp>
#include <boost/fusion/algorithm.hpp>
#include "task_2/Contacts.hpp"

void task_2();

template<typename T>
void statistics(std::vector<T> vec);

template<typename T>
bool between(T x, T a, T b);

std::map<std::string, size_t> mix(const auto &vec);

int main() {
    std::cout << "========== Zadanie 2 - Ksiazka teleadresowa ==========" << std::endl;
    task_2();
    std::cout << std::endl;
    std::cout << "========== Zadanie 3 - Statystyka ==========" << std::endl;
    std::vector vec = {-6, -5, -4, -3, -2, 0, 2, 5, 8, 12, 16};
    statistics(vec);
    std::cout << std::endl;
    std::cout << "========== Zadanie 4 - Mix ==========" << std::endl;
    boost::fusion::vector<int, int, int, double, double, float, bool, bool, char, char> fusion_vec
            {1, 2, 3, 4.5, 5.4, 3.6f, true, false, 'a', 'b'};
    std::map<std::string, size_t> count_map = mix(fusion_vec);
    for (const auto &pair: count_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

std::map<std::string, size_t> mix(const auto &vec) {
    std::map<std::string, size_t> count_map;
    boost::fusion::for_each(vec, [&count_map](auto item) { count_map[typeid(item).name()]++; });
    return count_map;
}

template<typename T>
void statistics(std::vector<T> vec) {
    std::sort(vec.begin(), vec.end());
    T sum = std::accumulate(vec.begin(), vec.end(), 0);

    double mean = (double) sum / vec.size();
    double median = (vec[vec.size() / 2.0] + vec[(vec.size() / 2.0) - 1]) / 2.0;

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;

    size_t lessThanMeanCount = 0;
    for (auto num: vec) {
        auto res = boost::bind<double>(std::less<>(), boost::placeholders::_1, boost::placeholders::_2)(num, mean);
        if (res)
            lessThanMeanCount++;
    }
    std::cout << "Less than mean count: " << lessThanMeanCount << std::endl;

    size_t betweenMeanAndMedianCount = 0;
    for (auto num: vec) {
        auto res = std::bind(between<double>,
                             std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)(num, mean, median);
        if (res)
            betweenMeanAndMedianCount++;
    }
    std::cout << "Between mean and median count: " << betweenMeanAndMedianCount << std::endl;

    size_t positiveElementsCount = 0;
    for (auto num: vec) {
        auto res = boost::bind(std::greater<T>(), std::placeholders::_1, std::placeholders::_2)(num, 0);
        if (res)
            positiveElementsCount++;
    }
    std::cout << "Positive elements count: " << positiveElementsCount << std::endl;
}

template<typename T>
bool between(T x, T a, T b) {
    if (x >= a && x <= b)
        return true;
    if (x >= b && x <= a)
        return true;
    return false;
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