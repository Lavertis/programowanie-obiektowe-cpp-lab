#include <iostream>
#include "task_2/Employee.hpp"
#include "task_2/Developer.hpp"
#include "task_2/TeamLeader.hpp"
#include "task_3/MeanBuffer.hpp"
#include "task_3/MaxBuffer.hpp"

using namespace std;

void whoWorkMoreThan5Years(Employee **employees, size_t size);

int howManyHaveLessBonusThanMean(Employee **employees, size_t size);

void task_2();

void task_3();

int main() {
//    task_2();
    task_3();
}

void task_3() {
    auto **buffers = new Buffer *[2];
    cout << "========== Constructors ==========" << endl;
    buffers[0] = new MeanBuffer();
    cout << endl;
    buffers[1] = new MaxBuffer();
    cout << endl;

    cout << "========== Calculate ==========" << endl;
    for (int i = 0; i < 10; ++i)
        buffers[0]->add(i);
    buffers[0]->show();
    cout << "Mean: " << buffers[0]->calculate() << endl;

    for (int i = 0; i < 10; ++i)
        buffers[1]->add(i);
    buffers[1]->show();
    cout << "Max value: " << buffers[1]->calculate() << endl;

    cout << endl << "========== Destructors ==========" << endl;
    for (int i = 0; i < 2; ++i) {
        delete buffers[i];
        cout << endl;
    }
    delete[] buffers;
}

void task_2() {
    size_t size = 5;
    auto **employees = new Employee *[size];
    cout << "========== Constructors ==========" << endl;
    employees[0] = new Developer("Developer_1", 25, 1, 6000);
    cout << endl;
    employees[1] = new Developer("Developer_2", 27, 3, 7000);
    cout << endl;
    employees[2] = new Developer("Developer_3", 40, 12, 15000);
    cout << endl;
    employees[3] = new TeamLeader("TeamLeader_1", 35, 3, 10000);
    cout << endl;
    employees[4] = new TeamLeader("TeamLeader_2", 40, 16, 18000);
    cout << endl;

    cout << "========== Show ==========" << endl;
    for (int i = 0; i < 5; ++i) {
        employees[i]->show();
        cout << "Bonus: " << employees[i]->calculateBonus(2) << endl;
        cout << endl;
    }

    cout << "========== Employees who have been working for more than 5 years ==========" << endl;
    whoWorkMoreThan5Years(employees, size);
    cout << endl;

    cout << "How many employees have less bonus than the average of all bonuses?" << endl;
    cout << howManyHaveLessBonusThanMean(employees, size) << endl;
    cout << endl;

    cout << "========== Destructors ==========" << endl;
    for (int i = 0; i < 5; ++i) {
        delete employees[i];
        cout << endl;
    }
    delete[] employees;
}

void whoWorkMoreThan5Years(Employee **employees, size_t size) {
    for (int i = 0; i < size; ++i) {
        if (employees[i]->getExperience() > 5)
            employees[i]->show();
    }
}

int howManyHaveLessBonusThanMean(Employee **employees, size_t size) {
    double mean = 0;
    for (int i = 0; i < size; ++i)
        mean += employees[i]->calculateBonus(2);

    mean /= (double) size;
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        if (employees[i]->calculateBonus(2) < mean)
            counter++;
    }
    cout << mean << endl;
    return counter;
}