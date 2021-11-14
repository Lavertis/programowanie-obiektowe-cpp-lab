#pragma once

#include <iostream>
#include <map>

using namespace std;

class Dictionary {
private:
    map<string, string> words;
public:
    Dictionary() = default;

    void addEntry(const string &word, const string &translation);

    void deleteEntry(const string &word);

    void showAllEntries();

    void translate(const string &word);

    void showAllEntriesSortedByValueDescending();
};