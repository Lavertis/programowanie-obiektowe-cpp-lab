#include "Animal.hpp"

Animal::Animal(int limbCount, string name, bool isProtected) :
        limbCount_(limbCount), name_(std::move(name)), isProtected_(isProtected) {}

void Animal::giveVoice() { // NOLINT(readability-convert-member-functions-to-static)
    cout << "Chrum, miau, hau, piiiii" << endl;
}

void Animal::info() {
    cout << "Animal{limbCount: " << limbCount_
         << ", name: " << name_
         << ", isProtected: " << (isProtected_ ? "true" : "false") << "}"
         << endl;
}

int Animal::getLimbCount() const {
    return limbCount_;
}

void Animal::setLimbCount(int limbCount) {
    limbCount_ = limbCount;
}

const string &Animal::getName() const {
    return name_;
}

void Animal::setName(const string &name) {
    name_ = name;
}

bool Animal::isProtected() const {
    return isProtected_;
}

void Animal::setIsProtected(bool isProtected) {
    isProtected_ = isProtected;
}
