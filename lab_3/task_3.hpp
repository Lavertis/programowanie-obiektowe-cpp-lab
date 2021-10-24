#pragma once

#include <algorithm>

template<typename T>
class Array {
private:
    T *data_;
    size_t capacity_{};
    size_t size_{};
public:
    Array();

    explicit Array(size_t capacity);

    void add(T value);

    T get(size_t index);

    T getMax();

    void sort();

    void show();

    string dataType();

    ~Array();
};

template<typename T>
Array<T>::Array() : Array(10) {}

template<typename T>
Array<T>::Array(size_t capacity) : capacity_(capacity), data_(new T[capacity]) {}

template<typename T>
void Array<T>::add(T value) {
    if (size_ == capacity_)
        throw std::runtime_error("Could not add element. Array is full.");

    data_[size_] = value;
    size_++;
}

template<typename T>
T Array<T>::get(size_t index) {
    if (index > size_ - 1 || index < 0)
        throw std::invalid_argument("Index out of bounds");

    return data_[index];
}

template<typename T>
T Array<T>::getMax() {
    if (size_ == 0)
        throw std::runtime_error("Cannot find max value. Array is empty.");

    return *std::max_element(data_, data_ + size_);
}

template<>
string Array<string>::getMax() {
    if (size_ == 0)
        throw std::runtime_error("Cannot find max value. Array is empty.");

    return *std::max_element(data_, data_ + size_, [](const string &a, const string &b) {
        return a.length() < b.length();
    });
}

template<typename T>
void Array<T>::sort() {
    std::sort(data_, data_ + size_);
}

template<>
void Array<string>::sort() {
    std::sort(data_, data_ + size_, [](const string &a, const string &b) {
        return a.length() < b.length();
    });
}

template<typename T>
void Array<T>::show() {
    cout << "Array[";
    for (int i = 0; i < size_; ++i) {
        cout << data_[i];
        if (i < size_ - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

template<typename T>
string Array<T>::dataType() {
    return typeid(T).name();
}

template<typename T>
Array<T>::~Array() {
    delete[] data_;
}