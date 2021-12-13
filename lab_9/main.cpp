#include <iostream>
#include <fstream>
#include <sstream>
#include "task_3/StudentRecords.h"

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
    StudentRecords studentRecords;
    cout << "Podaj sciezke do pliku:" << endl;
    string path = "../lab_9/dane.csv";
//    cin >> path;
    studentRecords.loadContactsFromFile(path);
    cout << "Pomyslnie zaladowano plik" << endl;

    bool loop = true;
    while (loop) {
        cout << "1 - Wyswietl ksiazke adresowa w postaci tabelki" << endl
             << "2 - Zapisz nowa osobe do ksiazki adresowej" << endl
             << "3 - Wyswietl osoby o podanym nazwisku" << endl
             << "4 - Zapisz kobiety i mezczyzn do oddzielnych plikow" << endl
             << "5 - wyswietl X pierwszych studentow" << endl
             << "6 - posortuj studentow rosnaco wzgledem oceny" << endl
             << "0 - Wyjscie" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                studentRecords.printAllRecords();
                break;
            case 2: {
                string name, surname, email;
                char sex;
                int mark;
                cout << "Podaj imie:" << endl;
                cin >> name;
                cout << "Podaj nazwisko:" << endl;
                cin >> surname;
                cout << "Podaj plec (litera M lub K):" << endl;
                cin >> sex;
                cout << "Podaj ocene:" << endl;
                cin >> mark;
                cout << "Podaj adres email (opcjonalnie):" << endl;
                cin.ignore();
                getline(cin, email);

                StudentRecord sr = StudentRecord(name, surname, sex, mark, email);
                try {
                    studentRecords.add(sr);
                    cout << "Pomyslnie dodano nowego studenta" << endl;
                } catch (StudentRecordException::StudentRecordException &e) {
                    std::cerr << e.what() << endl;
                }
                break;
            }
            case 3: {
                cout << "Podaj nazwisko, ktore chcesz wyszukac:" << endl;
                string surname;
                cin >> surname;
                studentRecords.printRecordsFilteredBySurname(surname);
                break;
            }
            case 4:
                studentRecords.splitToFilesBySex();
                break;
            case 5: {
                while (true) {
                    cout << "Podaj liczbe wierszy do wyswietlenia:" << endl;
                    int rows;
                    cin >> rows;
                    try {
                        studentRecords.printFirstNRecords(rows);
                        break;
                    } catch (StudentRecordsException::WrongNumberOfRecordsToDisplay &e) {
                        std::cerr << e.what() << endl;
                    }
                }
                break;
            }
            case 6:
                studentRecords.sortByMarkAsc();
                cout << "Studenci zostali posortowani" << endl;
                break;
            case 0:
                loop = false;
                break;
            default:
                cout << "Bledny wybor" << endl;
                break;
        }
    }
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