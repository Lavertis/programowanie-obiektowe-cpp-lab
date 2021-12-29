#include <iostream>
#include <regex>
#include <fstream>
#include "task_3/AddressValidator.h"
#include "task_4/CardIndexValidator.h"
#include "task_5/User.h"

using namespace std;

void task_1();

void task_2();

void task_3();

void task_4();

void task_5();

std::vector<string> tokenize(std::string const &str, char delim);

int main() {
//    task_1();
//    task_2();
//    task_3();
//    task_4();
    task_5();
}

std::vector<string> tokenize(std::string const &str, const char delim) {
    std::vector<string> tokens;
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, delim))
        tokens.push_back(s);
    return tokens;
}

void task_5() {
    ifstream file;
    file.open("../lab_10/users.csv");
    vector<User> users;
    string line;

    while (file.peek() != -1) {
        getline(file, line);
        vector<string> res = tokenize(line, ';');
        users.emplace_back(res[0], res[1], res[2], res[3], res[4]);
    }

    map<string, int> domains;
    int phoneNumbersWithEvenLastDigit = 0;
    int combinedLastNames = 0;
    map<string, int> names;
    for (const User &user: users) {
        smatch res;
        regex pattern("(@)(.*)");
        regex_search(user.getEmail(), res, pattern);
        domains[res[2]]++;

        pattern = "([1-9][0-9]{7})([02468])";
        regex_search(user.getPhoneNumber(), res, pattern);
        if (res[2] != "")
            phoneNumbersWithEvenLastDigit++;

        pattern = "(-)(.*)";
        regex_search(user.getLastName(), res, pattern);
        if (res[1] == '-')
            combinedLastNames++;

        names[user.getFirstName()]++;
    }
    cout << "Unikatowe domeny: " << std::count_if(domains.begin(), domains.end(), [](const auto pair) {
        return pair.second == 1;
    }) << endl;
    cout << "Numery telefonow z ostatnia cyfra parzysta: " << phoneNumbersWithEvenLastDigit << endl;
    cout << "Nazwiska laczone: " << combinedLastNames << endl;
    cout << "Ilosc danego imienia:" << endl;
    for (const auto &pair: names)
        cout << pair.first << ": " << pair.second << endl;

    file.close();
}

void task_4() {
    cout << CardIndexValidator::validateFirstName("Michael") << endl;
    cout << CardIndexValidator::validateLastName("Jackson-Jackson") << endl;
    cout << CardIndexValidator::validateAge("50") << endl;
    cout << CardIndexValidator::validatePhoneNumber("456489465") << endl;
    cout << CardIndexValidator::validateEmail("michael@jackson.com") << endl;

    string firstName = "Michael";
    string lastName = "Jackson-Jackson";
    string age = "50";
    string phoneNumber = "456489465";
    string email = "michael@jackson.com";
//    cout << "Podaj imie:" << endl;
//    cin >> firstName;
//    cout << "Podaj nazwisko:" << endl;
//    cin >> lastName;
//    cout << "Podaj wiek:" << endl;
//    cin >> age;
//    cout << "Podaj numer telefonu:" << endl;
//    cin >> phoneNumber;
//    cout << "Podaj email:" << endl;
//    cin >> email;

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
    file.open("../lab_10/users.csv", std::ios_base::app);
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