#include <vector>
#include "Dictionary.hpp"

void Dictionary::addEntry(const string &word, const string &translation) {
    if (!words.contains(word))
        words[word] = translation;
    else
        throw runtime_error(word + " is already in the dictionary.");
}

void Dictionary::deleteEntry(const string &word) {
    if (words.contains(word))
        words.erase(word);
    else
        throw runtime_error(word + " is not in the dictionary.");
}

void Dictionary::showAllEntries() {
    for (const auto &pair: words) {
        cout << pair.first << " => " << pair.second << endl;
    }
}

void Dictionary::translate(const string &word) {
    cout << "Translation: " << words[word] << endl;
}

void Dictionary::showAllEntriesSortedByValueDescending() {
    vector<pair<string, string>> vec;
    for (const auto &pair: words)
        vec.emplace_back(pair);
    sort(vec.begin(), vec.end(), [](const pair <string, string> &p1, const pair <string, string> &p2) {
        return p1.second > p2.second;
    });
    for (const pair <string, string> &pair: vec)
        cout << pair.first << " => " << pair.second << endl;
}