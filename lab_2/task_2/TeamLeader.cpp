#include "TeamLeader.hpp"

TeamLeader::TeamLeader(const string &surname, int age, int experience, int salary) :
        Employee(surname, age, experience, salary) {
    cout << "TeamLeader constructor" << endl;
}

TeamLeader::TeamLeader() {
    cout << "TeamLeader constructor" << endl;
}

float TeamLeader::calculateBonus(int value) {
    return static_cast<float>(value * (1 + getSalary() + getExperience()));
}

void TeamLeader::show() {
    cout << "TeamLeader{surname: " << getSurname()
         << ", age: " << getAge()
         << ", experience: " << getExperience()
         << ", salary: " << getSalary()
         << "}" << endl;
    cout << "Jestem Team Leaderem z " << getExperience() << " letnim doswiadczeniem" << endl;
}

TeamLeader::~TeamLeader() {
    cout << "TeamLeader destructor" << endl;
}
