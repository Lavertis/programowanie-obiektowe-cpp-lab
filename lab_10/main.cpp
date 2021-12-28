#include <iostream>
#include <regex>
#include <fstream>
#include "task_3/AddressValidator.h"
#include "task_4/CardIndexValidator.h"

using namespace std;

void task_1();

void task_2();

void task_3();

void task_4();

int main() {
//    task_1();
//    task_2();
//    task_3();
    task_4();
}

void task_4() {
    cout << CardIndexValidator::validateFirstName("Michael") << endl;
    cout << CardIndexValidator::validateLastName("Jackson-Jackson") << endl;
    cout << CardIndexValidator::validateAge("50") << endl;
    cout << CardIndexValidator::validatePhoneNumber("456489465") << endl;
    cout << CardIndexValidator::validateEmail("michael@jackson.com") << endl;

    string firstName, lastName, age, phoneNumber, email;
    cout << "Podaj imie:" << endl;
    cin >> firstName;
    cout << "Podaj nazwisko:" << endl;
    cin >> lastName;
    cout << "Podaj wiek:" << endl;
    cin >> age;
    cout << "Podaj numer telefonu:" << endl;
    cin >> phoneNumber;
    cout << "Podaj email:" << endl;
    cin >> email;

    bool correct = true;

    if (!CardIndexValidator::validateFirstName(firstName))
        correct = false;
    if (!CardIndexValidator::validateLastName(lastName))
        correct = false;
    if (!CardIndexValidator::validateAge(age))
        correct = false;
    if (!CardIndexValidator::validatePhoneNumber(phoneNumber))
        correct = false;
    if (!CardIndexValidator::validateEmail(email))
        correct = false;

    if (!correct) {
        cout << "Niepoprawne dane" << endl;
        return;
    }

    cout << "Zapisano do pliku" << endl;
    ofstream file;
    file.open("../lab_10/task_4/users.csv", std::ios_base::app);
    file << firstName << ';' << lastName << ';' << age << ';' << phoneNumber << ';' << email << endl;
    file.close();
}

void task_3() {
    cout << AddressValidator::validateStreet("Zlota") << endl;
    cout << AddressValidator::validatePostalCode("00-120") << endl;
    cout << AddressValidator::validateHouseNumber("1A") << endl;
    cout << AddressValidator::validateFlatNumber("200") << endl;
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