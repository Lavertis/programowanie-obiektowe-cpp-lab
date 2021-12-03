#include "Prezent.h"

#include <utility>

Prezent::Prezent(string id, int dolnyWiek, int gornyWiek) :
        id_(std::move(id)), dolny_wiek_(dolnyWiek), gorny_wiek_(gornyWiek) {}

const string &Prezent::getId() const {
    return id_;
}

void Prezent::setId(const string &id) {
    id_ = id;
}

int Prezent::getDolnyWiek() const {
    return dolny_wiek_;
}

void Prezent::setDolnyWiek(int dolnyWiek) {
    dolny_wiek_ = dolnyWiek;
}

int Prezent::getGornyWiek() const {
    return gorny_wiek_;
}

void Prezent::setGornyWiek(int gornyWiek) {
    gorny_wiek_ = gornyWiek;
}
