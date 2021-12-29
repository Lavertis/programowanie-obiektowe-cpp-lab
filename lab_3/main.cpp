#include <iostream>
#include <limits>
#include "task_1/Adding.hpp"
#include "task_1/Student.hpp"
#include "task_3.hpp"

using namespace std;

template<typename T>
void mySwap(T &a, T &b);

template<typename T>
void showAll(T *tab[], int n);

template<typename T>
void checkType(T a);

template<typename T>
T minimalElement(T tab[], size_t size);

int main() {
    cout << "========== Szablony funkcji - mySwap ==========" << endl;
    int a = 6;
    int b = 8;
    cout << "Przed: " << a << " " << b << endl;
    mySwap<int>(a, b);
    cout << "Po: " << a << " " << b << endl;
    cout << endl;

    cout << "========== Szablony klas - Adding ==========" << endl;
    Adding<int> a1(5);
    a1.add(6);
    a1.show();
    Adding<string> a2("Pro");
    a2.add("gramowanie");
    a2.show();
    cout << endl;

    cout << "========== Specjalizacja szablonow - Student ==========" << endl;
    Student<float> s(5, "Ala");
    s.showMark();
    Student<int> s1(5, "Ala");
    s1.showMark();
    Student<string> s2(5, "Ala");
    cout << s2.showMark() << endl;
    cout << endl;

    cout << "========== Funkcje szablonowe zawierajace tablice obiektow ==========" << endl;
    Adding<int> *arrAdd[3];
    for (int i = 0; i < 3; i++) {
        arrAdd[i] = new Adding<int>(i);
    }
    showAll(arrAdd, 3);
    Student<string> *arrStu[2];
    for (int i = 0; i < 3; i++) {
        arrStu[i] = new Student<string>(i + 2, "Ala");
    }
    showAll(arrStu, 3);
    for (auto &i: arrAdd)
        delete i;
    for (auto &i: arrStu)
        delete i;
    cout << endl;

    cout << "========== Klasa szablonowa numeric_limits ==========" << endl;
    checkType(3);
    cout << endl;

    cout << "========== Zadanie 2 ==========" << endl;
    size_t size = 7;
    int tab[] = {8, 40, 2, 12, 3, 34, 20};
    cout << minimalElement(tab, size) << endl;
    cout << minimalElement<int>(tab, size) << endl;
    cout << endl;

    cout << "========== Zadanie 4 ==========" << endl;
    cout << "##### Array of integers #####" << endl;
    size_t capacity = 5;
    Array<int> array1(capacity);
    array1.show();
    for (int i = 0; i < capacity; ++i) {
        array1.add(i * 5 % 7);
        array1.show();
    }
    cout << "Element at index 2: " << array1.get(2) << endl;
    array1.sort();
    cout << "Sorted: ";
    array1.show();
    cout << "Max value: " << array1.getMax() << endl;
    cout << "Data type: " << array1.dataType();

    cout << endl << endl << "##### Array of strings #####" << endl;
    Array<string> array2(3);
    array2.add("aaaa");
    array2.add("ccccccccccccccc");
    array2.add("bbbbbbbbb");
    array2.show();
    cout << "Longest string: " << array2.getMax() << endl;
    array2.sort();
    cout << "Sorted: ";
    array2.show();
    cout << endl;
}

template<typename T>
void mySwap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
void showAll(T *tab[], int n) {
    for (int i = 0; i < n; i++)
        tab[i]->show();
}

template<typename T>
void checkType(T a) {
    T val = numeric_limits<T>::max();
    cout << val << endl;
}

template<typename T>
T minimalElement(T tab[], size_t size) {
    T min = tab[0];
    for (int i = 1; i < size; ++i) {
        if (tab[i] < min)
            min = tab[i];
    }
    return min;
}