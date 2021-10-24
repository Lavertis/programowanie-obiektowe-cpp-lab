#pragma once

#include <iostream>

using namespace std;

template<typename T>
class Student {
private:
    string name;
    int mark{};
public:
    Student(int mark, string name) : name(std::move(name)), mark(mark) {}

    Student() = default;

    void show() {
        cout << "imie: " << name << " ocena " << mark << endl;
    }

    void showMark() {
        cout << mark << endl;
    }
};

template<>
void Student<int>::showMark() {
    cout << "Twoja ocena to: " << mark << endl;
}

template<>
class Student<string> {
private:
    string name;
    int mark{};
public:
    Student(int mark, string name) : name(std::move(name)), mark(mark) {}

    Student() = default;

    void show() {
        cout << "imie: " << name << " ocena " << mark << endl;
    }

    [[nodiscard]] int showMark() const {
        string word[6] = {"jedynka", "dwojka", "trojka", "czworka", "piatka", "szostka"};
        cout << "Twoja ocena to: " << word[mark - 1] << endl;
        return mark;
    }
};