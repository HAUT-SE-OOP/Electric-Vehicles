
#include "VehicleMenu.h"
// parsing string to class object using stringstream
ElectricVehicle VehicleMenu::parser(const std::string &to_parse) {
    std::stringstream iss(to_parse);
    std::string param;
    std::vector<std::string> params; // temporary vector to hold Vehicle parameters
    while(iss >> param)
    {
        params.emplace_back(param);
    }
    std::string notCrashed_;
    if(params[4] == "true")
    {
        notCrashed_ = "true";
    }
    else
    {
        notCrashed_ = "false";
    }

    // returning new object ElectricVehicle initialized with parameters held in vector params
    return ElectricVehicle(params[0], std::stoi(params[1]), std::stod(params[2]), params[3], notCrashed_,
                           std::stod(params[5]),std::stod(params[6]),std::stoi(params[7]));
}

// converting class object to string
std::string VehicleMenu::toStr(const ElectricVehicle &ev) {
    char temp;
    if(ev.get_notCrashed()) temp = '1';
    else temp = '0';

    return ev.getBrand() + " " + std::to_string(ev.getHP()) + " " + std::to_string(ev.getRange()) + " " + ev.get_originCountry() + " "
           + temp + " " + std::to_string(ev.get_price()) + " " + std::to_string(ev.get_mileage()) + " " + std::to_string(ev.get_productionYear());
}

void VehicleMenu::sortByAny(const int option) {
    switch(option)
    {
        case 1: // sorting by brand name alphabetically ascending
            std::sort(eVehicles.begin(), eVehicles.end(),[](const ElectricVehicle& ev1, const ElectricVehicle& ev2) -> bool{
                    return ev1.getBrand()[0] < ev2.getBrand()[0];                           // comparing ascii value from first and second vehicle brand
            });
            break;
        case 2: // sorting by horsepower descending
            std::sort(eVehicles.begin(), eVehicles.end(), [](const ElectricVehicle& ev1, const ElectricVehicle& ev2)  -> bool{
                    return ev1.getHP() > ev2.getHP();                                       // comparing horsepower value
            });
            break;
        case 3: // sorting by range descending
            std::sort(eVehicles.begin(), eVehicles.end(), [](const ElectricVehicle& ev1, const ElectricVehicle& ev2)  -> bool{
                return ev1.getRange() > ev2.getRange();                                     // comparing range value
            });
            break;
        case 4: // sorting by country of origin alphabetically ascending
            std::sort(eVehicles.begin(), eVehicles.end(), [](const ElectricVehicle& ev1, const ElectricVehicle& ev2)  -> bool{
                return ev1.get_originCountry()[0] < ev2.get_originCountry()[0];           // comparing ascii value from first and second vehicle origin country
            });
            break;
        case 5: // sorting by price
            std::sort(eVehicles.begin(), eVehicles.end(), [](const ElectricVehicle& ev1, const ElectricVehicle& ev2)  -> bool{
                return ev1.get_price() > ev2.get_price();                                  // comparing price value
            });
            break;
        case 6: // sorting by mileage
            std::sort(eVehicles.begin(), eVehicles.end(), [](const ElectricVehicle& ev1, const ElectricVehicle& ev2)  -> bool{
                return ev1.get_mileage() > ev2.get_mileage();                               // comparing mileage value
            });
            break;
        case 7: // sorting by production year
            std::sort(eVehicles.begin(), eVehicles.end(), [](const ElectricVehicle& ev1, const ElectricVehicle& ev2)  -> bool{
                return ev1.get_productionYear() > ev2.get_productionYear();           // comparing production year value
            });
            break;
        default:
            throw std::runtime_error("wrong choice");
    }
}
// reading vehicles from file
std::vector<ElectricVehicle> VehicleMenu::readFile() {
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
void VehicleMenu::saveToFile(const ElectricVehicle& ev) {
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

void VehicleMenu::info() const {
    std::cout << "There are currently " << eVehicles.size() << " vehicles in database" << std::endl;
    for (auto& ev : eVehicles) {
        ev.info();           // using info functionality from ElectricVehicle
    }
}

void VehicleMenu::menu() {
    std::cout << "=================================== Electric Vehicles Database ===================================" << std::endl;
    std::cout << "1. Show all vehicles" << std::endl;
    std::cout << "2. Sort vehicles by selected order" << std::endl;
    std::cout << "3. Add vehicle(s) to database" << std::endl;

}




