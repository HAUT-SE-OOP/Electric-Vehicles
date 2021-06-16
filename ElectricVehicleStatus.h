#include "ElectricVehicleParameters.h"
class ElectricVehicleStatus : public ElectricVehicleParameters {
private:
    std::string originCountry;
    bool notCrashed;
    double price, mileage;
    int productionYear;
    std::vector<ElectricVehicleStatus> vehicles;

    ElectricVehicleStatus parser(const std::string& to_parse);
public:
    ElectricVehicleStatus();

     void info() const override;
    ~ElectricVehicleStatus() = default;


};


