#pragma once

#include "Animal.hpp"

class Cat : public Animal {
private:
    int levelOfMouseHunting_{};
    int mice_[5]{};
public:
    Cat() = default;

    Cat(int limbCount, const string &name, bool isProtected);

    void initMice(const int *mice);

    void initCat(int limbCount, const string &name, bool isProtected, int levelOfMouseHunting, const int *mice);

    [[nodiscard]] int getLevelOfMouseHunting() const;

    void setLevelOfMouseHunting(int levelOfMouseHunting);

    int getMice(int year);

    void giveVoice();

    void info();
};

