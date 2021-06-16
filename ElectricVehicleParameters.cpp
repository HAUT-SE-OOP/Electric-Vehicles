#include "ElectricVehicleParameters.h"

std::string ElectricVehicleParameters::getBrand() const {
    return brand;
}

int ElectricVehicleParameters::getHP() const {
    return hp;
}

double ElectricVehicleParameters::getRange() const {
    return range;
}

void ElectricVehicleParameters::setBrand(const std::string& brand_) {
if(brand_.length() < 0 || brand_.length() > 15)
{
    throw std::runtime_error("Brand name is incorrect!");
}
this->brand = brand_;
}

void ElectricVehicleParameters::setHP(const int hp_) {
if(hp_ < 0 || hp > 500)
{
    throw std::runtime_error("Horsepower value is incorrect!");
}
this->hp = hp_;
}

void ElectricVehicleParameters::setRange(const double range_) {
if(range_ < 0 || range_ > 1000)
{
    throw std::runtime_error("Range value is incorrect!");
}
this->range = range_;
}

ElectricVehicleParameters::ElectricVehicleParameters(const std::string &brand_, const int hp_, const double range_) {
    setBrand(brand_);
    setHP(hp_);
    setRange(range_);
}

void ElectricVehicleParameters::info() const {
    std::cout << "Brand = " << getBrand() << " horsepower = " << getHP() << " range = " << getRange() << std::endl;
}
