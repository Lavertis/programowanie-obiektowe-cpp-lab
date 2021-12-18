#include "Shop.h"

Shop::Shop(std::string name) : name_(std::move(name)) {}

void Shop::addWarehouse(const std::shared_ptr<Warehouse> &warehouse) {
    warehouses_.push_back(warehouse);
    std::cout << "Added warehouse with " << warehouse->getArticleName() << " to shop " << getName() << std::endl;
}

void Shop::printWarehouses() {
    for (const auto &warehouse: warehouses_)
        warehouse->toString();
}

bool Shop::sellStock(const std::string &stockName, int count) {
    auto it = std::find_if(warehouses_.begin(), warehouses_.end(),
                           [&stockName](const std::shared_ptr<Warehouse> &ptr) {
                               return ptr->getArticleName() == stockName;
                           });
    if (it == warehouses_.end())
        return false;
    it->get()->sellStock(count);
    return true;
}

const std::string &Shop::getName() const {
    return name_;
}

Shop::~Shop() {
    std::cout << "Shop destructor" << std::endl;
}
