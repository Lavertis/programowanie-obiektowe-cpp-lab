#pragma once

#include "Animal.hpp"
#include <iostream>

using namespace std;

enum SkillType {
    GuideSkills,
    TrackerSkills
};

class Dog : public Animal {
private:
    string breed_;
    int levelOfGuideSkills_{};
    int levelOfTrackerSkills_{};
public:
    Dog() = default;

    Dog(int limbCount, const string &name, bool isProtected,
        string breed, int levelOfGuideSkills, int levelOfTrackerSkills);

    Dog(int limbCount, const string &name, bool isProtected);

    [[nodiscard]] int getSkillLevel(SkillType skillType) const;

    void setSkillLevel(SkillType skillType, int value);

    void giveVoice();

    void info();
};