#include "Developer.hpp"

Developer::Developer(const string &surname, int age, int experience, int salary) :
        Employee(surname, age, experience, salary) {
    cout << "Developer constructor" << endl;
}

Developer::Developer() {
    cout << "Developer constructor" << endl;
}

float Developer::calculateBonus(int value) {
    return static_cast<float>(value + 0.2 * value * (getSalary() + getExperience()));
}

void Developer::show() {
    cout << "Developer{surname: " << getSurname()
         << ", age: " << getAge()
         << ", experience: " << getExperience()
         << ", salary: " << getSalary()
         << "}" << endl;
}

Developer::~Developer() {
    cout << "Developer destructor" << endl;
}
