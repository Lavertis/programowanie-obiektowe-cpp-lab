#include "Employee.hpp"

#include <utility>

Employee::Employee(string surname, int age, int experience, int salary) :
        surname_(std::move(surname)), age_(age), experience_(experience), salary_(salary) {
    cout << "Employee constructor" << endl;
}

Employee::Employee() {
    cout << "Employee constructor" << endl;
}

void Employee::show() {
    cout << "Employee{surname: " << getSurname()
         << ", age: " << getAge()
         << ", experience: " << getExperience()
         << ", salary: " << getSalary()
         << "}" << endl;
}

Employee::~Employee() {
    cout << "Employee destructor" << endl;
}

const string &Employee::getSurname() const {
    return surname_;
}

int Employee::getAge() const {
    return age_;
}

int Employee::getExperience() const {
    return experience_;
}

int Employee::getSalary() const {
    return salary_;
}

