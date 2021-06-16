
#include "ElectricVehicle.h"
int main() {
    try {
        ElectricVehicle e{"AUDI",120,250,"Poland","true",15000,2300,2012};
    //ee.info();
    e.info();
    //std::vector<ElectricVehicle> e = ElectricVehicle::readFile();
    //ElectricVehicle::saveToFile(e);
    }catch(std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}
