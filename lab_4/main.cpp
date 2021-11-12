#include <iostream>
#include <random>
#include <algorithm>
#include <list>
#include <set>
#include "task_3/City.hpp"

using namespace std;

template<typename T>
void printVar(T var);

void task_1();

void task_2();

int digitsSum(int num);

int biggerDigitsSum(int num1, int num2);

int digitsCount(int num);

int moreDigitsCount(int num1, int num2);

void task3();

void showCities(vector<City> c);

void theMost(const vector<City> &c, int mode);


int main() {
    cout << "========== Zadanie 2 - Losowanie ==========" << endl;
    task_1();
    cout << endl;

    cout << "========== Zadanie 3 - Miasto ==========" << endl;
    task3();
    cout << endl;

    cout << "========== Zadanie 4 - Sortowanie ==========" << endl;
    task_2();
}

template<typename T>
void printVar(T var) {
    cout << var << " ";
}

void task_1() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist_n(5, 20);
    std::uniform_int_distribution<> dist(-100, 100);
    int n = dist_n(mt);
    std::list<int> list;

    for (int i = 0; i < n; ++i) {
        int num = dist(mt);
        if (num < 0)
            list.push_back(num);
        else
            list.push_front(num);
    }

    for_each(list.begin(), list.end(), printVar<int>);
}

void task_2() {
    vector<int> vec = {4, 8, 33, 77, 777, 121212, 49, 11, 43, 98, 11111, 699};

    std::sort(vec.begin(), vec.end(), biggerDigitsSum);
    for_each(vec.begin(), vec.end(), printVar<int>);
    cout << endl;
    std::sort(vec.begin(), vec.end(), moreDigitsCount);
    for_each(vec.begin(), vec.end(), printVar<int>);
}

int digitsSum(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int biggerDigitsSum(int num1, int num2) {
    int sum1 = digitsSum(num1);
    int sum2 = digitsSum(num2);
    return sum1 < sum2;
}

int digitsCount(int num) {
    int count = 0;
    while (num) {
        count++;
        num /= 10;
    }
    return count;
}

int moreDigitsCount(int num1, int num2) {
    int count1 = digitsCount(num1);
    int count2 = digitsCount(num2);
    return count1 > count2;
}

void task3() {
    Citizen citizen1("Bill", "Gates", 50, 'm', "20-389");
    Citizen citizen2("Taylor", "Swift", 12, 'f', "10-678");
    Citizen citizen3("Nicolas", "Cage", 40, 'm', "20-389");
    Citizen citizen4("Celine", "Dion", 16, 'f', "30-678");
    Citizen citizen5("Michaej", "Jackson", 50, 'm', "30-678");
    Citizen citizen6("Bill", "Gates", 50, 'm', "20-389");
    Citizen citizen7("Taylor", "Swift", 30, 'f', "30-678");
    Citizen citizen8("Nicolas", "Cage", 40, 'm', "40-234");

    City city1("City1");
    city1.addCitizen(citizen1);
    city1.addCitizen(citizen2);
    city1.addCitizen(citizen3);
    city1.addCitizen(citizen4);
    city1.addCitizen(citizen5);

    City city2("City2");
    city2.addCitizen(citizen6);
    city2.addCitizen(citizen7);
    city2.addCitizen(citizen8);

    City city3("City3");
    city3.addCitizen(citizen2);
    city3.addCitizen(citizen4);
    city3.addCitizen(citizen6);
    city3.addCitizen(citizen8);

    vector<City> cities;
    cities.push_back(city1);
    cities.push_back(city2);
    cities.push_back(city3);
    showCities(cities);
    theMost(cities, 1);
    theMost(cities, 2);
}

void showCities(vector<City> c) {
    for_each(c.begin(), c.end(), [](City city) {
        city.showCity();
        city.showCitizens();
    });
}

void theMost(const vector<City> &c, int mode) {
    switch (mode) {
        case 1: {
            const City *max_city;
            size_t max_count = 0;
            for_each(c.begin(), c.end(), [&max_city, &max_count](const City &city) {
                auto citizens = city.getCitizens();
                set<string> postal_codes;

                for_each(citizens.begin(), citizens.end(), [&postal_codes](const Citizen &citizen) {
                    postal_codes.insert(citizen.getPostalCode());
                });

                if (postal_codes.size() > max_count) {
                    max_city = &city;
                    max_count = postal_codes.size();
                }
            });
            cout << "Most different postal codes -> ";
            max_city->showCity();
            break;
        }
        case 2: {
            auto city = min_element(c.begin(), c.end(), [](City city1, City city2) {
                return city1.citizenCount() < city2.citizenCount();
            });
            cout << "Least citizens -> ";
            city->showCity();
            break;
        }
        default:;
    }
}