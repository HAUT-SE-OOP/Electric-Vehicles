
#include "VehicleMenu.h"
int main() {
    try {
        
        VehicleMenu vm;
        vm.menu();

    }catch(std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }
    return 0;
}
