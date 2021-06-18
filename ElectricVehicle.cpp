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
// parsing string to class object using stringstream
ElectricVehicle ElectricVehicle::parser(const std::string &to_parse) {
    std::stringstream iss(to_parse);
    std::string param;
    std::vector<std::string> params; // temporary vector to hold Vehicle parameters
    while(iss >> param)
    {
        params.emplace_back(param);
    }

    // returning new object ElectricVehicle initialized with parameters held in vector params
    return ElectricVehicle(params[0], std::stoi(params[1]), std::stod(params[2]), params[3], params[4],
                                 std::stod(params[5]),std::stod(params[6]),std::stoi(params[7]));
}

// converting class object to string
std::string ElectricVehicle::toStr(const ElectricVehicle &ev) {
    char notCrashed_ = '0';
    if(ev.notCrashed)
    {
        notCrashed_ = '1';
    }
    return ev.getBrand() + " " + std::to_string(ev.getHP()) + " " + std::to_string(ev.getRange()) + " " + ev.originCountry + " "
    + notCrashed_ + " " + std::to_string(ev.price) + " " + std::to_string(ev.mileage) + " " + std::to_string(ev.productionYear);
}

void ElectricVehicle::info() const {
    ElectricVehicleParameters::info(); // using base class logic for function info
    std::cout << "origin = " << originCountry << " crashed? = " << notCrashed << " price = " << price << " mileage = " << mileage << " production year = " << productionYear << std::endl;
}

// reading vehicles from file
std::vector<ElectricVehicle> ElectricVehicle::readFile() {
    std::ifstream file;
    file.open("vehicles.txt");
    if(file.is_open())
    {
        std::string vehicle;
        std::vector<ElectricVehicle> vehiclesResult;
        while(!file.eof())
        {
            std::getline(file,vehicle); // downloading line of vehicle parameters from text file represented as a string
            if(!vehicle.empty()) {
                vehiclesResult.emplace_back(parser(vehicle)); // using previous function 'parser' to convert downloaded string to class object
            }
        }
        file.close();
        return vehiclesResult;
    }
    else
        throw std::runtime_error("Could not open file: vehicles.txt");
}

//saving vehicle to text file
void ElectricVehicle::saveToFile(const ElectricVehicle& ev) {
    std::ofstream file;
    file.open("vehicles.txt", std::ios::app);
    if(file.is_open())
    {
        file << "\n" << toStr(ev); // using function toStr to convert class object to string so it can be saved to text file
        file.close();
        std::cout << "Saved successfully!" << std::endl;
    }
    else
        throw std::runtime_error("Could not open file: vehicles.txt");
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
    throw std::runtime_error("'Is car crashed?' condition is incorrect!");
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










