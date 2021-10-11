#include "Cat.hpp"

Cat::Cat(int limbCount, const string &name, bool isProtected) : Animal(limbCount, name, isProtected) {}

void Cat::initMice(const int *mice) {
    for (int i = 0; i < 5; ++i)
        mice_[i] = mice[i];
}

void Cat::initCat(int limbCount, const string &name, bool isProtected, int levelOfMouseHunting, const int *mice) {
    setLimbCount(limbCount);
    setName(name);
    setIsProtected(isProtected);
    setLevelOfMouseHunting(levelOfMouseHunting);
    for (int i = 0; i < 5; ++i)
        mice_[i] = mice[i];
}

int Cat::getLevelOfMouseHunting() const {
    return levelOfMouseHunting_;
}

void Cat::setLevelOfMouseHunting(int levelOfMouseHunting) {
    if (levelOfMouseHunting < 1 || levelOfMouseHunting > 10)
        throw std::invalid_argument("Mouse hunting level must be between 1 and 10");
    levelOfMouseHunting_ = levelOfMouseHunting;
}

int Cat::getMice(int year) {
    if (year < 1 || year > 5)
        throw std::invalid_argument("Year must be between 1 and 5");
    return mice_[year - 1];
}

void Cat::giveVoice() { // NOLINT(readability-convert-member-functions-to-static)
    cout << "Miau miau" << endl;
}

void Cat::info() {
    string miceArrayAsStr = "[";
    for (int m: mice_)
        miceArrayAsStr += to_string(m) + ", ";
    miceArrayAsStr = miceArrayAsStr.substr(0, miceArrayAsStr.length() - 2);
    miceArrayAsStr += "]";

    cout << "Cat{limbCount: " << getLimbCount()
         << ", name: " << getName()
         << ", isProtected: " << (isProtected() ? "true" : "false")
         << ", levelOfMouseHunting: " << getLevelOfMouseHunting()
         << ", mice: " << miceArrayAsStr
         << "}"
         << endl;
}