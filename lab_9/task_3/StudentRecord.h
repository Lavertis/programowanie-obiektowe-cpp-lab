#pragma once

#include <iostream>
#include <vector>

using namespace std;

class StudentRecord {
private:
    string name_;
    string surname_;
    char sex_{};
    int mark_{};
    string email_;
public:
    StudentRecord() = default;

    StudentRecord(string name, string surname, char sex, int mark, string email);

    [[nodiscard]] const string &getName() const;

    [[nodiscard]] const string &getSurname() const;

    [[nodiscard]] char getSex() const;

    [[nodiscard]] int getMark() const;

    [[nodiscard]] const string &getEmail() const;

    [[nodiscard]] string toString() const;

    [[nodiscard]] string serializeToCSV() const;
};

namespace StudentRecordException {
    struct Name : public std::exception {
        [[nodiscard]] const char *what() const noexcept override {
            return "Wrong name format";
        }
    };

    struct Surname : public std::exception {
        [[nodiscard]] const char *what() const noexcept override {
            return "Wrong surname format";
        }
    };

    struct Sex : public std::exception {
        [[nodiscard]] const char *what() const noexcept override {
            return "Wrong sex format";
        }
    };

    struct Mark : public std::exception {
        [[nodiscard]] const char *what() const noexcept override {
            return "Wrong mark format";
        }
    };

    struct Email : public std::exception {
        [[nodiscard]] const char *what() const noexcept override {
            return "Wrong email format";
        }
    };
}