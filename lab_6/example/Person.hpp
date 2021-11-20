#pragma once

#include <iostream>

using namespace std;

class Person {
public:
    string name;
    int age;

    void show() const;
};

void Person::show() const {
    cout << "name: " << name << " age: " << age << endl;
}
