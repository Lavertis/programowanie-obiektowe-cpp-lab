#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>
#include "Animal.h"

using namespace std;

struct FactorialError : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Factorial from number < 0";
    }
};

vector<string> tokenize(const string &str, char delim);

void task_1();

void task_2();

int factorial(int n);

void task_3();

int main() {
    task_1();
    task_2();
    task_3();
}

void task_3() {
    try {
        cout << factorial(1) << endl;
        cout << factorial(-1) << endl;
    } catch (FactorialError &e) {
        cerr << e.what() << endl;
    }
}

int factorial(int n) {
    if (n < 0)
        throw FactorialError();

    int fact = 1;
    for (int i = 2; i <= n; ++i)
        fact *= i;

    return fact;
}

void task_2() {
    vector<string> dates;
    regex pattern("^(19[0-9]{2}|(20[0-1][0-9]|202[0-2]))-(0[1-9]|1[0-2])$");

    for (int year = 1900; year <= 2022; ++year) {
        for (int month = 1; month <= 12; ++month) {
            string date = to_string(year) + "-" + (month < 10 ? "0" : "") + to_string(month);
            dates.push_back(date);
        }
    }

    for (const string &date: dates) {
        if (!regex_match(date, pattern))
            cerr << date << endl;
    }
}

void task_1() {
    fstream input_file;
    input_file.open("../kolokwium_2/mk/wejscie.txt", ios::in);
    vector<Animal> animals;
    string line;

    if (!input_file.is_open()) {
        cout << "Nie udalo sie otworzyc pliku" << endl;
        return;
    }

    string columns;
    getline(input_file, columns); // kolumny
    while (!input_file.eof() && getline(input_file, line)) {
        vector<string> tokens = tokenize(line, ';');
        animals.emplace_back(tokens[0], stoi(tokens[1]));
    }
    input_file.close();

    fstream output_file;
    output_file.open("../kolokwium_2/mk/wyjscie.txt", ios::out);
    output_file << columns << endl;
    for (const Animal &a: animals) {
        if (a.getName().contains(" "))
            output_file << a.getName() << ';' << a.getAge() << endl;
    }

    output_file.close();
}

vector<string> tokenize(const string &str, char delim) {
    std::vector<string> tokens;
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, delim))
        tokens.push_back(s);
    return tokens;
}