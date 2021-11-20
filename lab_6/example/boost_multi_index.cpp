#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/bind/bind.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <iostream>
#include "Person.hpp"

using namespace boost::multi_index;
using namespace std;


void example_1();

void UlaToUrszula(Person &x);

void AlaToAlicja(Person &x);

void example_2();

int main() {
    example_1();
    example_2();

    return 0;
}

void example_2() {
    typedef multi_index_container<Person, indexed_by<
            ordered_non_unique<member<Person, string, &Person::name>>,
            ordered_non_unique<member<Person, int, &Person::age>>,
            random_access<>
    >> person_multi;
    typedef person_multi::nth_index<0>::type name_type;
    typedef person_multi::nth_index<1>::type age_type;

    person_multi persons2;
    persons2.get<2>().push_back({"Ala", 40});
    persons2.get<2>().push_back({"Ala", 45});
    persons2.get<2>().push_back({"Piotr", 10});
    persons2.get<2>().push_back({"Ola", 18});
    persons2.get<2>().push_back({"Aga", 46});
    persons2.get<2>().push_back({"Ula", 46});
    auto &name_index = persons2.get<0>();

    auto iterStart = name_index.equal_range("Ala");
    auto iterStop = name_index.equal_range("Piotr");
    cout << "Przedzial od Ala do Piotr - wersja 1" << endl;
    for (name_type::iterator it = iterStart.first; it != iterStop.second; ++it)
        it->show();

    auto from = name_index.lower_bound("Ala");
    auto to = name_index.upper_bound("Piotr");
    cout << "Przedzial od Ala do Piotr - wersja 2" << endl;
    for (auto it = from; it != to; ++it)
        it->show();

    auto &rand_index = persons2.get<2>();
    cout << rand_index[0].name << endl;

}

void example_1() {
    typedef multi_index_container<Person, indexed_by<
            hashed_non_unique<member<Person, string, &Person::name>>,
            hashed_non_unique<member<Person, int, &Person::age>>
    >> person_multi;
    typedef person_multi::nth_index<0>::type name_type;
    typedef person_multi::nth_index<1>::type age_type;

    person_multi persons;
    persons.insert({"Ala", 40});
    persons.insert({"Piotr", 10});
    persons.insert({"Ola", 18});
    persons.insert({"Ala", 46});
    persons.insert({"Ula", 46});

    cout << "Liczba osob o imieniu Ala: " << persons.count("Ala") << endl;
    cout << "Liczba osob o imieniu Ala: " << persons.get<0>().count("Ala") << endl;
    age_type &age_index = persons.get<1>();
    cout << "Liczba osob z wiekiem 18 lat: " << age_index.count(18) << endl;

    for (const auto &it: persons.get<0>())
        it.show();

    auto &age_indexx = persons.get<1>();
    auto it_age_46 = age_indexx.find(46);
    cout << "Znaleziona osoba, ktora ma 46 lat to " << it_age_46->name << endl;

    cout << endl << "Przed modyfikacja:" << endl;
    vector<name_type::iterator> elements;
    for (name_type::iterator it = persons.get<0>().begin(); it != persons.get<0>().end(); ++it) {
        it->show();
        elements.push_back(it);
    }

    auto &name_index = persons.get<0>();
    auto it_name_ula = name_index.find("Ula");
//    name_index.modify(it_name_ula, [](auto &&PH1) { return UlaToUrszula(std::forward<decltype(PH1)>(PH1)); });
    name_index.modify(it_name_ula, boost::bind(UlaToUrszula, boost::placeholders::_1));

    for (auto &element: elements)
        name_index.modify(element, boost::bind(AlaToAlicja, boost::placeholders::_1));

    cout << endl << "Po modyfikacji:" << endl;
    for (const auto &it: persons.get<0>()) {
        it.show();
    }
}

void UlaToUrszula(Person &x) {
    if (x.name == "Ula")
        x.name = "Urszula";
}


void AlaToAlicja(Person &x) {
    if (x.name == "Ala")
        x.name = "Alicja";
}
