#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> tokenize(const string &str);

int main() {
    fstream file;
    file.open("../kolokwium_2/mb/tekst.txt", ios::in);

    if (!file.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku" << endl;
        return -1;
    }

    string line;
    vector<string> lines;
    while (!file.eof() && getline(file, line))
        lines.push_back(line);

    file.close();

    cout << "==================== Zadanie 1 ====================" << endl;
    cout << "########## Przed posortowaniem ##########" << endl;
    for (const string &str: lines)
        cout << str << endl;

    cout << "\n########## Po posortowaniu ##########" << endl;
    std::sort(lines.begin(), lines.end());
    for (const string &str: lines)
        cout << str << endl;

    cout << "\n==================== Zadanie 2 ====================" << endl;
    vector<string> words;
    for (const string &str: lines) {
        vector<string> tokens = tokenize(str);
        for (const string &word: tokens)
            words.push_back(word);
    }

    vector<string> words_starting_with_m;
    std::copy_if(words.begin(), words.end(), back_inserter(words_starting_with_m),
                 [](const string &str) { return str.starts_with("m"); });

    cout << "Slowa na litere \"m\":" << endl;
    for (const string &str: words_starting_with_m)
        cout << str << endl;

    cout << "\n==================== Zadanie 3 ====================" << endl;
    map<int, int> count;
    for (const string &str: words) {
        int length = (int) str.length();
        count[length]++;
    }

    cout << "Statystyka dlugosci slow:" << endl;
    for (const auto &pair: count)
        cout << "Dlugosc: " << pair.first << ", wystapienia: " << pair.second << endl;
}

vector<string> tokenize(const string &str) {
    std::vector<string> tokens;
    std::stringstream ss(str);
    std::string s;
    while (ss >> s)
        tokens.push_back(s);

    return tokens;
}