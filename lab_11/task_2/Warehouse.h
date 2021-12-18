#pragma once

#include <iostream>

class Warehouse {
private:
    std::string article_name_;
    int stock_;
public:
    Warehouse(std::string articleName, int stock);

    void toString();

    void sellStock(int count);

    [[nodiscard]] const std::string &getArticleName() const;

    void setArticleName(const std::string &articleName);

    [[nodiscard]] int getStock() const;

    void setStock(int stock);
};