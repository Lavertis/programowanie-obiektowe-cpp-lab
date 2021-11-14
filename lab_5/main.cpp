#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <numeric>
#include <map>

using namespace std;

void task_1();

template<typename T>
pair<T, int> duplicateAndSum(const vector<T> &vec);

void task_2();

template<typename T>
set<T> exclusiveAlternative(const set<T> &set1, const set<T> &set2, int inWhich);

void task_3();

char stringDifference(const string &str1, const string &str2);

int main() {
    cout << "========== Zadanie 1 - Duplikat ==========" << endl;
    task_1();
    cout << endl;

    cout << "========== Zadanie 2 - Alternatywa wykluczajaca ==========" << endl;
    task_2();
    cout << endl << endl;

    cout << "========== Zadanie 3 - Roznica ==========" << endl;
    task_3();
    cout << endl;
}

void task_1() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10};
    pair<int, int> res = duplicateAndSum(vec);
    cout << "Duplikat: " << res.first << endl;
    cout << "Suma: " << res.second << endl;
}

template<typename T>
pair<T, int> duplicateAndSum(const vector<T> &vec) {
    set<T> unique_values;
    T duplicated_value;

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (unique_values.contains(*it))
            duplicated_value = *it;
        unique_values.insert(*it);
    }

    int sum = std::accumulate(unique_values.begin(), unique_values.end(), 0);
    return make_pair(duplicated_value, sum);
}

void task_2() {
    set<int> set1 = {1, 2, 3, 5, 7, 9};
    set<int> set2 = {1, 2, 3, 4, 6, 8};
    set<int> set3 = exclusiveAlternative(set1, set2, 1);
    cout << "Set1: ";
    for_each(set1.begin(), set1.end(), [](auto item) { cout << item << " "; });
    cout << endl << "Set2: ";
    for_each(set2.begin(), set2.end(), [](auto item) { cout << item << " "; });
    cout << endl << "Res: ";
    for_each(set3.begin(), set3.end(), [](auto item) { cout << item << " "; });
}

template<typename T>
set<T> exclusiveAlternative(const set<T> &set1, const set<T> &set2, int inWhich) {
    set<T> res;
    switch (inWhich) {
        case 1:
            set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_iterator(res, res.begin()));
            break;
        case 2:
            set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), insert_iterator(res, res.begin()));
            break;
        default:;
    }
    return res;
}


void task_3() {
    string str1 = "aaaaabbbbcccdd";
    string str2 = "aaaaabbbbcccddd";
    shuffle(str1.begin(), str1.end(), std::mt19937(std::random_device()()));
    shuffle(str1.begin(), str1.end(), std::mt19937(std::random_device()()));
    char excess_char = stringDifference(str1, str2);
    cout << "Znak: " << excess_char << endl;
}

char stringDifference(const string &str1, const string &str2) {
    map<char, int> map1;
    map<char, int> map2;
    for (char c: str1)
        map1[c]++;
    for (char c: str2)
        map2[c]++;
    for (pair<char, int> pair: map2) {
        if (!map1.contains(pair.first) || map1[pair.first] != pair.second)
            return pair.first;
    }
    return 0;
}