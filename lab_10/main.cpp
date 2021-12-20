#include <iostream>
#include <regex>
#include "AddressValidator.h"

using namespace std;

void task_1();

void task_2();

void task_3();

int main() {
//    task_1();
//    task_2();
    task_3();
}

void task_3() {
    cout << AddressValidator::validateStreet("") << endl;
    cout << AddressValidator::validateStreet("") << endl;
    cout << AddressValidator::validateStreet("") << endl;
    cout << AddressValidator::validateStreet("") << endl;
}

void task_2() {
    regex pattern("^([0-1][0-9]|2[0-3])(:[0-5][0-9]){1,2}$");
    string str[] = {"21:59:30", "24:59:30", "21:59"};
    for (const string &s: str)
        cout << s << ": " << (regex_match(s, pattern) ? "match" : "no match") << endl;
}

void task_1() {
    std::regex pattern("^[+-]?[0-9].\\d+$");
    string str[] = {"8.29", "s+7.2", "+7.2", "-7.2", "7", "0.890809890"};
    for (const string &s: str)
        cout << s << ": " << (regex_match(s, pattern) ? "match" : "no match") << endl;
}