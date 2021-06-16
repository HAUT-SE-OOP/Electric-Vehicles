
#include "ElectricVehicleStatus.h"
int main() {
    try {
    //ElectricVehicleStatus ee = ElectricVehicleStatus::parser("BMW 120 250 Germany 1 150000 0 2019");
    //ee.info();
    std::vector<ElectricVehicleStatus> e = ElectricVehicleStatus::readFile("vehicles.txt");
    for (int i = 0; i < e.size(); ++i) {
        e[i].info();
    }
    }catch(std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}
