#include <iostream>
#include "task_2/Animal.hpp"
#include "task_2/Dog.hpp"
#include "task_2/Cat.hpp"

using namespace std;

int howManyProtectedAnimals(Animal animals[], size_t size);

int howManyTrackerDogs(Dog dogs[], size_t size);

void howManyMice(Cat cats[], size_t size);

int main() {
    Animal a(4, "Animal", false);
    a.giveVoice();
    a.info();
    cout << endl;

    Dog d(4, "Dog", true, "Husky", 3, 7);
    d.giveVoice();
    d.info();
    cout << endl;

    Cat c;
    int mice[] = {3, 6, 8, 2, 4};
    c.initCat(4, "Cat", false, 5, mice);
    c.giveVoice();
    c.info();
    cout << endl;

    Animal animals[] = {
            Animal(4, "Animal", true),
            Animal(4, "Animal", false),
            Animal(4, "Animal", false),
            Animal(4, "Animal", true),
            Animal(4, "Animal", true),
            Animal(4, "Animal", true),
    };
    cout << "How many protected animals? -> " << howManyProtectedAnimals(animals, 6) << endl << endl;

    Dog dogs[] = {
            Dog(4, "Dog", true, "Husky", 3, 7),
            Dog(4, "Dog", true, "Husky", 7, 3),
            Dog(4, "Dog", true, "Husky", 7, 3),
            Dog(4, "Dog", true, "Husky", 7, 3),
            Dog(4, "Dog", true, "Husky", 7, 3),
            Dog(4, "Dog", true, "Husky", 3, 7),

    };
    cout << "How many tracker dogs? -> " << howManyTrackerDogs(dogs, 6) << endl << endl;

    Cat cats[]{
            Cat(4, "Cat", true),
            Cat(4, "Cat", true),
            Cat(4, "Cat", true),
            Cat(4, "Cat", true),
            Cat(4, "Cat", true),
            Cat(4, "Cat", true),
    };
    for (int i = 0; i < 6; ++i) {
        int miceCaught[] = {1 + i, 2 + i, 3 + i, 4 + i, 5 + i};
        cats[i].initMice(miceCaught);
    }
    cout << "How many mice caught?" << endl;
    howManyMice(cats, 6);
    return 0;
}

int howManyProtectedAnimals(Animal animals[], size_t size) {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (animals[i].isProtected())
            counter++;
    }

    return counter;
}

int howManyTrackerDogs(Dog dogs[], size_t size) {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if (dogs[i].getSkillLevel(TrackerSkills) > dogs[i].getSkillLevel(GuideSkills))
            counter++;
    }

    return counter;
}

void howManyMice(Cat cats[], size_t size) {
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 1; j < 6; ++j)
            count += cats[i].getMice(j);
        cout << "Cat " << i << " caught: " << count << " mice" << endl;
    }
}