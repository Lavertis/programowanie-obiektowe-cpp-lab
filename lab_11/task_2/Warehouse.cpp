#include "Warehouse.h"

Warehouse::Warehouse(std::string articleName, int stock) : article_name_(std::move(articleName)), stock_(stock) {}

void Warehouse::toString() {
    std::cout << "Warehouse{articleName: " << article_name_ << ", stock: " << stock_ << std::endl;
}

void Warehouse::sellStock(int count) {
    if (getStock() - count < 0 || count < 1)
        throw std::runtime_error("Requested amount of stock not available");
    stock_ -= count;
}

const std::string &Warehouse::getArticleName() const {
    return article_name_;
}

void Warehouse::setArticleName(const std::string &articleName) {
    article_name_ = articleName;
}

int Warehouse::getStock() const {
    return stock_;
}

void Warehouse::setStock(int stock) {
    stock_ = stock;
}