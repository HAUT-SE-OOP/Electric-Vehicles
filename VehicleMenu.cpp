
#include "VehicleMenu.h"

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

void VehicleMenu::info() const {
    for (int i = 0; i < eVehicles.size(); ++i) {
        eVehicles[i].info();
    }
}

VehicleMenu::VehicleMenu(const std::vector<ElectricVehicle> &eVehicles_){
    eVehicles = eVehicles_;
}


