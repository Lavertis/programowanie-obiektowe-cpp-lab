#include <sstream>
#include "StudentRecord.h"

StudentRecord::StudentRecord(string name, string surname, char sex, int mark, string email) :
        name_(std::move(name)), surname_(std::move(surname)), sex_(sex), mark_(mark), email_(std::move(email)) {}

const string &StudentRecord::getName() const {
    return name_;
}

const string &StudentRecord::getSurname() const {
    return surname_;
}

char StudentRecord::getSex() const {
    return sex_;
}

int StudentRecord::getMark() const {
    return mark_;
}

const string &StudentRecord::getEmail() const {
    return email_;
}

string StudentRecord::toString() const {
    stringstream ss;
    ss << "StudentRecord{";
    ss << "name: " << getName();
    ss << ", surname: " << getSurname();
    ss << ", sex: " << getSex();
    ss << ", mark: " << getMark();
    ss << ", email: " << getEmail();
    ss << "}";
    return ss.str();
}

string StudentRecord::serializeToCSV() const {
    stringstream ss;
    ss << getName() << ';';
    ss << getSurname() << ';';
    ss << getSex() << ';';
    ss << getMark() << ';';
    ss << getEmail();
    return ss.str();
}