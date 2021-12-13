#pragma once

#include <iostream>
#include <vector>
#include "StudentRecord.h"

using namespace std;

class StudentRecords {
private:
    vector<string> column_names_;
    vector<StudentRecord> records_;
    string recordsFilePath;

    static std::vector<std::string> tokenize(std::string const &str, char delim = ';');

    void printTableWithoutBorders(const vector<StudentRecord> &records) const;

    [[nodiscard]] string serializeColumns() const;

public:
    StudentRecords() = default;

    void loadContactsFromFile(const string &filePath);

    void printAllRecords() const;

    void printRecordsFilteredBySurname(const string &surname) const;

    void add(const StudentRecord &studentRecord);

    void splitToFilesBySex() const;

    void printFirstNRecords(int n) const;

    void sortByMarkAsc();

    ~StudentRecords();
};

namespace StudentRecordsException {
    struct WrongNumberOfRecordsToDisplay : public std::exception {
        [[nodiscard]] const char *what() const noexcept override {
            return "Wrong number of records to display";
        }
    };
}