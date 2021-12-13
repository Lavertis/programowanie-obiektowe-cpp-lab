#include <sstream>
#include <fstream>
#include <iomanip>
#include "StudentRecords.h"

std::vector<std::string> StudentRecords::tokenize(std::string const &str, const char delim) {
    std::vector<string> tokens;
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, delim))
        tokens.push_back(s);
    return tokens;
}

void StudentRecords::loadContactsFromFile(const string &filePath) {
    recordsFilePath = filePath;
    ifstream file;
    file.exceptions(std::ifstream::failbit);

    try {
        file.open(recordsFilePath);
        string line;
        getline(file, line);
        column_names_ = tokenize(line, ';');

        while (file.peek() != -1) {
            getline(file, line);
            vector<string> res = tokenize(line, ';');
            if (res.size() == 5)
                records_.emplace_back(res[0], res[1], res[2][0], stoi(res[3]), res[4]);
            else
                records_.emplace_back(res[0], res[1], res[2][0], stoi(res[3]), "");
        }

        file.close();
    } catch (std::ifstream::failure &e) {
        cerr << "Bledna sciezka do pliku" << endl;
        exit(-1);
    }
}

void StudentRecords::printTableWithoutBorders(const vector<StudentRecord> &records) const {
    cout << left << setfill('_');
    for (const auto &col: column_names_)
        cout << setw(20) << col;
    cout << endl;
    for (const auto &record: records) {
        cout << setw(20) << record.getName();
        cout << setw(20) << record.getSurname();
        cout << setw(20) << record.getSex();
        cout << setw(20) << record.getMark();
        cout << setw(20) << record.getEmail();
        cout << endl;
    }
}

void StudentRecords::printAllRecords() const {
    printTableWithoutBorders(records_);
}

void StudentRecords::printRecordsFilteredBySurname(const string &surname) const {
    vector<StudentRecord> vec;
    std::copy_if(records_.begin(), records_.end(), std::back_inserter(vec),
                 [&surname](const StudentRecord &sr) { return sr.getSurname() == surname; });
    printTableWithoutBorders(vec);
}

void StudentRecords::add(const StudentRecord &studentRecord) {
    if (!std::isupper(studentRecord.getName()[0]))
        throw StudentRecordException::Name();
    for (char c: studentRecord.getName()) {
        if (!isalpha(c))
            throw StudentRecordException::Name();
    }

    if (!std::isupper(studentRecord.getSurname()[0]))
        throw StudentRecordException::Surname();
    for (char c: studentRecord.getSurname()) {
        if (!isalpha(c))
            throw StudentRecordException::Surname();
    }

    if (studentRecord.getSex() != 'K' && studentRecord.getSex() != 'M')
        throw StudentRecordException::Sex();

    if (studentRecord.getMark() > 5 || studentRecord.getMark() < 2)
        throw StudentRecordException::Mark();

    if (!studentRecord.getEmail().empty() && studentRecord.getEmail().find('@') == std::string::npos)
        throw StudentRecordException::Email();

    records_.push_back(studentRecord);
}

void StudentRecords::splitToFilesBySex() const {
    ofstream fileK, fileM;
    fileK.exceptions(std::ifstream::failbit);
    fileM.exceptions(std::ifstream::failbit);
    try {
        fileK.open("../lab_9/k.csv");
        fileM.open("../lab_9/m.csv");
        string columns = serializeColumns();
        fileK << columns << endl;
        fileM << columns << endl;

        for (const StudentRecord &sr: records_) {
            switch (sr.getSex()) {
                case 'K':
                    fileK << sr.serializeToCSV() << endl;
                    break;
                case 'M':
                    fileM << sr.serializeToCSV() << endl;
                    break;
            }
        }

        fileK.close();
        fileM.close();
    } catch (std::fstream::failure &e) {
        std::cerr << "Nie udalo sie utworzyc plikow z danymi podzielonymi na plci" << endl;
    }
}

void StudentRecords::sortByMarkAsc() {
    std::sort(records_.begin(), records_.end(),
              [](const StudentRecord &sr1, const StudentRecord &sr2) { return sr1.getMark() < sr2.getMark(); });
}

void StudentRecords::printFirstNRecords(const int n) const {
    if (n > records_.size() || n < 1)
        throw StudentRecordsException::WrongNumberOfRecordsToDisplay();
    vector<StudentRecord> vec;
    std::copy(records_.begin(), records_.begin() + n, back_inserter(vec));
    printTableWithoutBorders(vec);
}

string StudentRecords::serializeColumns() const {
    stringstream columns;
    columns << column_names_[0] << ';'
            << column_names_[1] << ';'
            << column_names_[2] << ';'
            << column_names_[3] << ';'
            << column_names_[4];
    return columns.str();
}

StudentRecords::~StudentRecords() {
    ofstream file;
    file.exceptions(std::ifstream::failbit);
    try {
        file.open("../lab_9/dane.csv");
        file << serializeColumns() << endl;
        for (const StudentRecord &sr: records_)
            file << sr.serializeToCSV() << endl;
        file.close();
    }
    catch (std::fstream::failure &e) {
        std::cerr << "Blad w dopisywaniu do pliku po zakonczeniu programu" << endl;
    }
}