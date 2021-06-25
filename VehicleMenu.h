#include "ElectricVehicle.h"
class VehicleMenu : public ElectricVehicle{
private:
    std::vector<ElectricVehicle> eVehicles;
    void sortByAny(const int option); // function to sort vector of electric vehicles by the variable chosen by user
    static ElectricVehicle parser(const std::string& to_parse); // function to convert class object to string
    static std::string toStr(const ElectricVehicle& ev); // function to convert string to class object
public:
    explicit VehicleMenu(const std::vector<ElectricVehicle>& eVehicles_) : eVehicles(eVehicles_){}

    // save and read from text file functions
    static std::vector<ElectricVehicle> readFile();
    static void saveToFile(const ElectricVehicle& ev);

    void menu();
    void info() const override;
};

