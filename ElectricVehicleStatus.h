#include "ElectricVehicleParameters.h"
class ElectricVehicleStatus : public ElectricVehicleParameters {
private:
    std::string originCountry;
    bool notCrashed;
    double price, mileage;
    int productionYear;
    static ElectricVehicleStatus parser(const std::string& to_parse);
public:
    ElectricVehicleStatus(const std::string& brand_ = "", const int hp_ = 0, const double range_ = 0, const std::string& originCountry_ = ""
                          ,bool notCrashed_ = true, const double price_ = 0, const double mileage_ = 0, const int productionYear_ = 0)
                          : ElectricVehicleParameters(brand_,hp_,range_),originCountry(originCountry_), notCrashed(notCrashed_), price(price_), mileage(mileage_)
                          ,productionYear(productionYear_){}

    static std::vector<ElectricVehicleStatus> readFile(const std::string& filename);
    void info() const override;
    ~ElectricVehicleStatus() = default;


};


