#include "ElectricVehicle.h"
class VehicleMenu : public ElectricVehicle{
private:
    std::vector<ElectricVehicle> eVehicles;
public:
    void sortByAny(const int option); // function to sort vector of electric vehicles by the variable chosen by user
    /*explicit VehicleMenu(const std::string& brand_ = "", const int hp_ = 0, const int range_ = 0, const std::string& originCountry_ = ""
            ,std::string notCrashed_ = "true", const int price_ = 0, const int mileage_ = 0, const int productionYear_ = 0, const std::vector<ElectricVehicle>& ev = {})
            : ElectricVehicle(brand_,hp_,range_,originCountry_,notCrashed_,price_,mileage_,productionYear_), eVehicles(ev){}*/
    explicit VehicleMenu(const std::vector<ElectricVehicle>& eVehicles_ = {}) : ElectricVehicle(), eVehicles(eVehicles_){};
    void info() const override;
};

