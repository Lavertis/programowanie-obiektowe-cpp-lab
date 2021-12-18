#include <iostream>
#include "task_1/Buffer.h"
#include "task_1/BufferArr.h"
#include "task_1/BufferFile.h"
#include "task_2/Warehouse.h"
#include "task_2/Shop.h"
#include "task_3/BidirectionalList.h"
#include <vector>
#include <random>

void task_1();

void task_2();

void task_3();

int main() {
//    std::cout << "Zadanie 1 - Bufor" << std::endl;
//    task_1();
//    std::cout << std::endl;
//    std::cout << "Zadanie 2 - Sklepy" << std::endl;
//    task_2();
//    std::cout << std::endl;
    std::cout << "Zadanie 3 - Lista dwukierunkowa" << std::endl;
    task_3();
}

void task_3() {
    BidirectionalList<int> bidirectionalList;
    bidirectionalList.pushFront(1);
    bidirectionalList.pushFront(2);
    bidirectionalList.pushBack(3);
    bidirectionalList.pushBack(4);
    bidirectionalList.print();
    bidirectionalList.popBack();
    bidirectionalList.popFront();
    bidirectionalList.popBack();
    bidirectionalList.print();
}

void task_2() {
    std::shared_ptr warehouse1 = std::make_shared<Warehouse>("Cars", 30);
    std::shared_ptr warehouse2 = std::make_shared<Warehouse>("Books", 800);
    std::shared_ptr warehouse3 = std::make_shared<Warehouse>("Computers", 650);
    std::shared_ptr warehouse4 = std::make_shared<Warehouse>("Animals", 400);
    std::shared_ptr warehouse5 = std::make_shared<Warehouse>("Pianos", 65);

    std::vector<std::unique_ptr<Shop>> shops;
    shops.push_back(std::make_unique<Shop>("Shop 1"));
    shops.push_back(std::make_unique<Shop>("Shop 2"));

    shops[0]->addWarehouse(warehouse1);
    shops[1]->addWarehouse(warehouse1);
    shops[0]->addWarehouse(warehouse2);
    shops[1]->addWarehouse(warehouse3);
    shops[0]->addWarehouse(warehouse4);
    shops[1]->addWarehouse(warehouse4);
    shops[0]->addWarehouse(warehouse5);

    std::cout << std::endl;
    std::cout << "Shop 1 warehouses" << std::endl;
    shops[0]->printWarehouses();
    std::cout << "Shop 2 warehouses" << std::endl;
    shops[1]->printWarehouses();

    shops[0]->sellStock("Cars", 3);
    shops[1]->sellStock("Cars", 2);
    shops[0]->sellStock("Books", 250);
    shops[1]->sellStock("Computers", 55);
    shops[0]->sellStock("Animals", 75);
    shops[1]->sellStock("Animals", 25);
    shops[0]->sellStock("Pianos", 65);

    std::cout << std::endl;
    std::cout << "Shop 1 warehouses after sellout" << std::endl;
    shops[0]->printWarehouses();
    std::cout << "Shop 2 warehouses after sellout" << std::endl;
    shops[1]->printWarehouses();
}

void task_1() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);
    std::vector<std::unique_ptr<Buffer>> bufferVector;

    for (int i = 0; i < 6; i += 2) {
        bufferVector.push_back(std::make_unique<BufferArr>(5));
        bufferVector.push_back(make_unique<BufferFile>("../lab_11/task_1/file" + std::to_string(i) + ".txt"));
        for (int j = 0; j < 5; ++j) {
            int num = (int) dist(rng);
            bufferVector[i]->add(num);
            bufferVector[i + 1]->add(num);
        }
    }

    for (const auto &buffer: bufferVector)
        buffer->write();
}