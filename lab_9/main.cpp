#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void task_1();

void task_2();

int main() {
//    task_1();
    task_2();
}

void task_2() {
    int sum = 0;
    string input;
    int successful_attempts = 0;
    int unsuccessful_attempts = 0;

    while (sum != 21) {
        cout << "Podaj liczbe:" << endl;
        cin >> input;
        try {
            int num = stoi(input);
            if (num < 1)
                throw invalid_argument("Negative number");
            if (sum + num > 21)
                throw runtime_error("Sum greater than 21");
            sum += num;
            cout << "Suma: " << sum << endl;
            successful_attempts++;
        } catch (std::invalid_argument &) {
            cerr << "Wprowadzono nieprawidlowa wartosc" << endl;
        } catch (std::runtime_error &) {
            cerr << "Suma przekroczyla wartosc 21" << endl;
            unsuccessful_attempts++;
        }
    }
    cout << endl << "Wygrales!" << endl;
    cout << "Udane proby: " << successful_attempts << endl;
    cout << "Nieudane proby: " << unsuccessful_attempts << endl;
}

void task_1() {
    string path = "../lab_9/kod.txt";
    ifstream file;
    file.exceptions(std::ifstream::failbit);

    try {
        file.open(path);
        string str;
        getline(file, str, '\0');
        long pos = 0;
        while ((pos = (long) str.find("//", pos)) != std::string::npos) {
            string::iterator newLine = std::find(str.begin() + pos, str.end(), '\n');
            str.erase(str.begin() + pos, newLine);
        }
        cout << str;
        file.close();
    } catch (std::ifstream::failure &e) {
        std::cerr << "The file could not be opened" << endl;
        std::cerr << e.what() << endl;
    }

    cout << endl << endl;

    try {
        file.open(path);
        stringstream ss;
        string contents;
        while (file.peek() != -1) {
            char tmp = (char) file.get();
            if (tmp == '/' && file.peek() == '/') {
                while (file.peek() != '\n')
                    file.ignore();
                continue;
            }
            ss << tmp;
        }
        contents = ss.str();
        cout << contents;
        file.close();
    } catch (std::fstream::failure &e) {
        std::cerr << "The file could not be opened" << endl;
        std::cerr << e.what() << endl;
    }
}