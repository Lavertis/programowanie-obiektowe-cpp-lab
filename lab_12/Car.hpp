#pragma once

#include <iostream>

class Car {
private:
    std::string model_name_;
    int year_;
    float engine_displacement_;
public:
    Car(std::string modelName, int year, float engineDisplacement);

    [[nodiscard]] const std::string &getModelName() const;

    void setModelName(const std::string &modelName);

    [[nodiscard]] int getYear() const;

    void setYear(int year);

    [[nodiscard]] float getEngineDisplacement() const;

    void setEngineDisplacement(float engineDisplacement);

    void show() const;
};

