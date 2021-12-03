#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

template<typename T>
set<T> task_1(set<T> set1, set<T> set2);

size_t task_2(const map<string, float> &students);

void task_3(vector<int> &vec, int a, int b);

template<typename T>
std::pair<T, T> task_4(vector<T> vec);

vector<string> task_5(vector<string> vec);

int main() {
    // Funkcja szablonowa zwracająca zbiór liczb niepowtarzających się w 2 zbiorach
    set<int> set1{1, 2, 3, 4, 5, 6, 7, 8, 10};
    set<int> set2{1, 2, 4, 5, 6, 8, 9, 10};
    set<int> set3 = task_1(set1, set2); // 3, 7, 9
    std::for_each(set3.begin(), set3.end(), [](auto x) { cout << x << endl; });

    // Funkcja przyjmująca mapę pesel i średnia i zwracająca liczbę studentów ze średnią > 4
    map<string, float> students{{"1", 3.4},
                                {"2", 4.5},
                                {"3", 4.8},
                                {"4", 3.8}};
    cout << task_2(students) << endl;

    // Funkcja usuwająca elementy z wektora nienależące do przedziału <a, b>
    vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    task_3(vec1, 5, 14);
    for_each(vec1.begin(), vec1.end(), [](int x) { cout << x << endl; });

    // Vector, który ma liczby od 1 do n, gdzie jedna jest zdublowana i zadaniem funkcji było znalezienie zdublowanej liczby i tej brakującej
    vector<int> vec2{1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10};
    auto res1 = task_4(vec2);
    cout << res1.first << " " << res1.second << endl;

    // Funkcja, która przyjmuje wektor napisów i zwraca vector, gdzie te napisy mają * z przodu i z tyłu
    vector<string> vec3{"1", "22", "333", "4444", "55555"};
    vector<string> res2 = task_5(vec3);
    for_each(res2.begin(), res2.end(), [](auto el) { cout << el << endl; });
}

vector<string> task_5(vector<string> vec) {
    // Funkcja, która przyjmuje wektor napisów i zwraca vector, gdzie te napisy mają * z przodu i z tyłu
    vector<string> res(std::move(vec));
    std::transform(res.begin(), res.end(), res.begin(), [](auto str) { return "*" + str + "*"; });
//    std::for_each(res.begin(), res.end(), [](auto &str) { str = "*" + str + "*"; });
    return res;
}

template<typename T>
std::pair<T, T> task_4(vector<T> vec) {
    // Vector, który ma liczby od 1 do n, gdzie jedna jest zdublowana i zadaniem funkcji było znalezienie zdublowanej liczby i tej brakującej
    set<T> set;
    pair<T, T> res;
    for (auto x: vec) {
        if (!set.insert(x).second)
            res.first = x;
    }
    for (int i = 1;; ++i) {
        if (!set.contains(i)) {
            res.second = i;
            break;
        }
    }

    return res;
}

void task_3(vector<int> &vec, int a, int b) {
    // Funkcja usuwająca elementy z wektora nienależące do przedziału <a, b>
    std::erase_if(vec, [=](int x) { return x >= a && x <= b; });
}

size_t task_2(const map<string, float> &students) {
    // Funkcja przyjmująca mapę pesel i średnia i zwracająca liczbę studentów ze średnią > 4
    return std::count_if(students.begin(), students.end(),
                         [](const pair<string, float> &pair) { return pair.second > 4; }
    );
}

template<typename T>
set<T> task_1(set<T> set1, set<T> set2) {
    // Funkcja szablonowa zwracająca zbiór liczb niepowtarzających się w 2 zbiorach
    set<T> intersection;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersection, intersection.begin()));
    set<T> res;
    set_difference(set1.begin(), set1.end(), intersection.begin(), intersection.end(), inserter(res, res.begin()));
    set_difference(set2.begin(), set2.end(), intersection.begin(), intersection.end(), inserter(res, res.begin()));
    return res;
}