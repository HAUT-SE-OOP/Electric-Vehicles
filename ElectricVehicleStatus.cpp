#include "ElectricVehicleStatus.h"

// parsing string to class object using stringstream
ElectricVehicleStatus ElectricVehicleStatus::parser(const std::string &to_parse) {
    std::stringstream iss(to_parse);
    std::string param;
    std::vector<std::string> params; // temporary vector to hold Vehicle parameters
    while(iss >> param)
    {
        params.emplace_back(param);
    }

    bool notCrashed_ = false; // temporary variable to convert from string to bool
    if(params[4] == "true")
    {
        notCrashed_ = true;
    }
    // returning new object ElectricVehicleStatus initialized with parameters held in vector params
    return ElectricVehicleStatus(params[0], std::stoi(params[1]), std::stod(params[2]), params[3], notCrashed_,
                                 std::stod(params[5]),std::stod(params[6]),std::stoi(params[7]));
}


void ElectricVehicleStatus::info() const {
    ElectricVehicleParameters::info(); // using base class logic for function info
    std::cout << "origin = " << originCountry << " crashed? = " << notCrashed << " price = " << price << " mileage = " << mileage << " production year = " << productionYear << std::endl;
}

// reading vehicles from file
std::vector<ElectricVehicleStatus> ElectricVehicleStatus::readFile(const std::string& filename) {
    std::ifstream file;
    file.open(filename);
    if(file.is_open())
    {
        std::string vehicle;
        std::vector<ElectricVehicleStatus> vehiclesResult;
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
        throw std::runtime_error("Could not open file: " + filename);
}


