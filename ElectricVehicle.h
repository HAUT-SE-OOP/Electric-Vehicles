#include "ElectricVehicleParameters.h"
class ElectricVehicle : public ElectricVehicleParameters {
private:
    std::string originCountry;
    bool notCrashed; // is vehicle crashed
    int price, mileage;
    int productionYear;
public:
    // notCrashed is set by string to make it easier for user to enter data; true / false is more intuitive than 1/0
    ElectricVehicle(const std::string& brand_ = "NONE", const int hp_ = 100, const int range_ = 100, const std::string& originCountry_ = "NONE"
                          ,std::string notCrashed_ = "true", const int price_ = 100, const int mileage_ = 100, const int productionYear_ = 2000);

    //setters to validate entered data
    void set_originCountry(const std::string& originCountry_);
    void set_notCrashed(const std::string& notCrashed_);
    void set_price(const int price_);
    void set_mileage(const int mileage_);
    void set_productionYear(const int productionYear_);

    //getters
    std::string get_originCountry() const;
    int get_price() const;
    int get_mileage() const;
    int get_productionYear() const;
    bool get_notCrashed() const;

    // operator == to use for deletion of vehicle
    bool operator==(const ElectricVehicle& ev);
    void info() const override;

    ~ElectricVehicle() = default;
};


