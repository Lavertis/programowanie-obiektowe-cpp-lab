#include "Car.hpp"

Car::Car(std::string modelName, int year, float engineDisplacement) :
        model_name_(std::move(modelName)), year_(year), engine_displacement_(engineDisplacement) {}

const std::string &Car::getModelName() const {
    return model_name_;
}

void Car::setModelName(const std::string &modelName) {
    model_name_ = modelName;
}

int Car::getYear() const {
    return year_;
}

void Car::setYear(int year) {
    year_ = year;
}

float Car::getEngineDisplacement() const {
    return engine_displacement_;
}

void Car::setEngineDisplacement(float engineDisplacement) {
    engine_displacement_ = engineDisplacement;
}

void Car::show() const {
    std::cout << "Car{"
              << "model: " << getModelName()
              << ", year: " << getYear()
              << ", engineDisplacement: " << getEngineDisplacement() << "L"
              << "}"
              << std::endl;
}
