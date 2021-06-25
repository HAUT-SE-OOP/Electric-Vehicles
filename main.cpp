
#include "VehicleMenu.h"
int main() {
    try {

        ElectricVehicle e1{"AUDI",120,250,"Poland","true",15000,2300,2012};
        ElectricVehicle e2{"BMW",110,300,"Germany","false",9000,197000,2005};
        ElectricVehicle e3{"TESLA",230,450,"France","true",183000,0,2018};
        //std::vector<ElectricVehicle> ev {e1,e2,e3};*/
    //ee.info();
    //e.info();
    /*std::vector<ElectricVehicle> e = VehicleMenu::readFile();

        for (int i = 0; i < e.size(); ++i) {
            e[i].info();
        }*/
        /*VehicleMenu::saveToFile(e1);
        VehicleMenu::saveToFile(e2);
    VehicleMenu::saveToFile(e3);*/

    VehicleMenu vm;
   // std::cout <<
    //int option;
    //vm.info();
    std::cout << "================================================================" << std::endl;
    //vm.deleteChosenVehicle(e2);

    vm.info();
    //std::cout << "wybierz opcje" << std::endl;
    //std::cin >> option; std::cin.get();
    //vm.sortByAny(option);
    std::cout << "================================================================" << std::endl;
   // vm.info();

    }catch(std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}
