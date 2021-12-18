#include <iostream>
#include "task_1/Buffer.h"
#include "task_1/BufferArr.h"
#include "task_1/BufferFile.h"
#include <vector>
#include <random>

using namespace std;

void task_1();

int main() {
    cout << "Zadanie 1 - Bufor" << endl;
    task_1();
    cout << endl << "Zadanie 2 - Sklepy" << endl;
    cout << endl << "Zadanie 3 - Lista dwukierunkowa" << endl;
}

void task_1() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);
    vector<unique_ptr<Buffer>> bufferVector;

    for (int i = 0; i < 6; i += 2) {
        bufferVector.push_back(make_unique<BufferArr>(5));
        bufferVector.push_back(make_unique<BufferFile>("../lab_11/task_1/file" + to_string(i) + ".txt"));
        for (int j = 0; j < 5; ++j) {
            int num = (int) dist(rng);
            bufferVector[i]->add(num);
            bufferVector[i + 1]->add(num);
        }
    }

    for (const auto &buffer: bufferVector)
        buffer->write();
}