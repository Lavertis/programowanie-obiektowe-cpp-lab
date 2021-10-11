#include "Dog.hpp"

Dog::Dog(int limbCount, const string &name, bool isProtected, string breed, int levelOfGuideSkills,
         int levelOfTrackerSkills) : Animal(limbCount, name, isProtected),
                                     breed_(std::move(breed)),
                                     levelOfGuideSkills_(levelOfGuideSkills),
                                     levelOfTrackerSkills_(levelOfTrackerSkills) {
    if (levelOfGuideSkills < 1 || levelOfGuideSkills > 10)
        throw std::invalid_argument("Guide skills level must be between 1 and 10");
    if (levelOfTrackerSkills < 1 || levelOfTrackerSkills > 10)
        throw std::invalid_argument("Tracker skills level must be between 1 and 10");
}

Dog::Dog(int limbCount, const string &name, bool isProtected) : Animal(limbCount, name, isProtected) {}

int Dog::getSkillLevel(SkillType skillType) const {
    switch (skillType) {
        case GuideSkills:
            return levelOfGuideSkills_;
        case TrackerSkills:
            return levelOfTrackerSkills_;
        default:
            return -1;
    }
}

void Dog::setSkillLevel(SkillType skillType, int value) {
    if (value < 1 || value > 10)
        throw std::invalid_argument("Skill level must be between 1 and 10");

    switch (skillType) {
        case GuideSkills:
            levelOfGuideSkills_ = value;
            break;
        case TrackerSkills:
            levelOfTrackerSkills_ = value;
            break;
    }
}

void Dog::giveVoice() { // NOLINT(readability-convert-member-functions-to-static)
    cout << "Hau, hau" << endl;
}

void Dog::info() {
    cout << "Dog{limbCount: " << getLimbCount()
         << ", name: " << getName()
         << ", isProtected: " << (isProtected() ? "true" : "false")
         << ", breed: " << breed_
         << ", levelOfGuideSkills: " << levelOfGuideSkills_
         << ", levelOfTrackerSkills: " << levelOfTrackerSkills_
         << "}"
         << endl;
}




