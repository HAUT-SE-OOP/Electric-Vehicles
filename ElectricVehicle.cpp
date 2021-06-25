#include "ElectricVehicle.h"
ElectricVehicle::ElectricVehicle(const std::string &brand_, const int hp_, const int range_,
                                 const std::string &originCountry_, std::string notCrashed_, const int price_,
                                 const int mileage_, const int productionYear_) : ElectricVehicleParameters(brand_, hp_, range_) {
    set_originCountry(originCountry_);
    set_notCrashed(notCrashed_);
    set_price(price_);
    set_mileage(mileage_);
    set_productionYear(productionYear_);
}

void ElectricVehicle::info() const {
    ElectricVehicleParameters::info(); // using base class logic for function info and adding additional logic
    std::cout << "\nCountry of origin = " << originCountry << "\nCrashed = " << std::boolalpha << notCrashed << "\nPrice = " << price << "\nMileage = " << mileage <<
    "\nProduction year = " << productionYear << "\n" << std::endl;
}

void ElectricVehicle::set_originCountry(const std::string &originCountry_) {
if(originCountry_.empty())
{
    throw std::runtime_error("Country of origin '" + originCountry_ + "' is incorrect!");
}
this->originCountry = originCountry_;
}

void ElectricVehicle::set_notCrashed(const std::string& notCrashed_) {
if(notCrashed_ != "true" && notCrashed_ != "false")
{
    throw std::runtime_error("'Is vehicle crashed?' condition is incorrect!");
}
if(notCrashed_ == "true")
{
    this->notCrashed = true;
}
else
{
    this->notCrashed = false;
}
}

void ElectricVehicle::set_price(const int price_) {
if(price_ < 0)
{
    throw std::runtime_error("Price is incorrect!");
}
this->price = price_;
}

void ElectricVehicle::set_mileage(const int mileage_) {
if(mileage_ < 0)
{
    throw std::runtime_error("Mileage is incorrect!");
}
this->mileage = mileage_;
}

void ElectricVehicle::set_productionYear(const int productionYear_) {
if(productionYear_ < 1970 || productionYear_ > 2030)
{
    throw std::runtime_error("Year of production is incorrect!");
}
this->productionYear = productionYear_;
}

std::string ElectricVehicle::get_originCountry() const {
    return originCountry;
}

int ElectricVehicle::get_price() const {
    return price;
}

int ElectricVehicle::get_mileage() const {
    return mileage;
}

int ElectricVehicle::get_productionYear() const {
    return productionYear;
}

bool ElectricVehicle::get_notCrashed() const {
    return notCrashed;
}
bool ElectricVehicle::operator==(const ElectricVehicle& ev) {
    if(this->getBrand() != ev.getBrand() && this->getHP() != ev.getHP() && this->getRange() != ev.getRange() && this-> originCountry != ev.originCountry && this->notCrashed != ev.notCrashed
    && this->price != ev.price && this-> mileage != ev.mileage && this-> productionYear != ev.productionYear)
    {
        return false;
    }
    return true;
}








