#include "ElectricVehicleParameters.h"
class ElectricVehicle : public ElectricVehicleParameters {
private:
    std::string originCountry;
    bool notCrashed; // is vehicle crashed
    int price, mileage;
    int productionYear;
    static ElectricVehicle parser(const std::string& to_parse); // function to convert class object to string
    static std::string toStr(const ElectricVehicle& ev); // function to convert string to class object
public:
    ElectricVehicle(const std::string& brand_ = "NaN", const int hp_ = 100, const int range_ = 100, const std::string& originCountry_ = "NaN"
                          ,std::string notCrashed_ = "true", const int price_ = 100, const int mileage_ = 100, const int productionYear_ = 2000);

    //setters
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


    static std::vector<ElectricVehicle> readFile();
    //static ElectricVehicle getElectricVehicleFromUser();
    static void saveToFile(const ElectricVehicle& ev);


    void info() const override;
    ~ElectricVehicle() = default;
};


