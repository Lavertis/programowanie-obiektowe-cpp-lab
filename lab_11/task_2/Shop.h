#pragma once

#include "Warehouse.h"
#include <vector>
#include <memory>

class Shop {
private:
    std::string name_;
    std::vector<std::shared_ptr<Warehouse>> warehouses_;
public:
    explicit Shop(std::string name);

    void addWarehouse(const std::shared_ptr<Warehouse> &warehouse);

    void printWarehouses();

    bool sellStock(const std::string &stockName, int count);

    [[nodiscard]] const std::string &getName() const;
};