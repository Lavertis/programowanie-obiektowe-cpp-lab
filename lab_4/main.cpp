#include <iostream>
#include <random>
#include <algorithm>
#include <list>

using namespace std;

template<typename T>
void printVar(T var);

void task_1();

void task_2();

int digitsSum(int num);

int biggerDigitsSum(int num1, int num2);

int digitsCount(int num);

int moreDigitsCount(int num1, int num2);

int main() {
    cout << "========== Zadanie 2 - Losowanie ==========" << endl;
    task_1();
    cout << endl;

    cout << "========== Zadanie 3 - Miasto ==========" << endl;
    
    cout << endl;

    cout << "========== Zadanie 4 - Sortowanie ==========" << endl;
    task_2();
}

template<typename T>
void printVar(T var) {
    cout << var << " ";
}

void task_1() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist_n(5, 20);
    std::uniform_int_distribution<> dist(-100, 100);
    int n = dist_n(mt);
    std::list<int> list;

    for (int i = 0; i < n; ++i) {
        int num = dist(mt);
        if (num < 0)
            list.push_back(num);
        else
            list.push_front(num);
    }

    for_each(list.begin(), list.end(), printVar<int>);
}

void task_2() {
    vector<int> vec = {4, 8, 33, 77, 777, 121212, 49, 11, 43, 98, 11111, 699};

    std::sort(vec.begin(), vec.end(), biggerDigitsSum);
    for_each(vec.begin(), vec.end(), printVar<int>);
    cout << endl;
    std::sort(vec.begin(), vec.end(), moreDigitsCount);
    for_each(vec.begin(), vec.end(), printVar<int>);
}

int digitsSum(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int biggerDigitsSum(int num1, int num2) {
    int sum1 = digitsSum(num1);
    int sum2 = digitsSum(num2);
    return sum1 < sum2;
}

int digitsCount(int num) {
    int count = 0;
    while (num) {
        count++;
        num /= 10;
    }
    return count;
}

int moreDigitsCount(int num1, int num2) {
    int count1 = digitsCount(num1);
    int count2 = digitsCount(num2);
    return count1 > count2;
}