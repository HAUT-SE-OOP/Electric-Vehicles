
#include "VehicleMenu.h"
int main() {
    try {
        ElectricVehicle e1{"AUDI",120,250,"Poland","true",15000,2300,2012};
        ElectricVehicle e2{"BMW",110,300,"Germany","false",9000,197000,2005};
        ElectricVehicle e3{"TESLA",230,450,"France","true",183000,0,2018};
        std::vector<std::unique_ptr<ElectricVehicle>> ev {std::make_unique<ElectricVehicle>(e1), std::make_unique<ElectricVehicle>(e2), std::make_unique<ElectricVehicle>(e3)};

    //ee.info();
    //e.info();
    //std::vector<ElectricVehicle> e = ElectricVehicle::readFile();
    //ElectricVehicle::saveToFile(e);

    VehicleMenu vm{ev};

    int option;
    vm.info();
    std::cout << "wybierz opcje" << std::endl;
    std::cin >> option; std::cin.get();
    vm.sortByAny(option);


    }catch(std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}
