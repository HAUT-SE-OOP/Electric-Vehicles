cmake_minimum_required(VERSION 3.19)
project(ElectricCarsDB)

set(CMAKE_CXX_STANDARD 20)

add_executable(ElectricCarsDB main.cpp libs.h ElectricVehicleParameters.cpp ElectricVehicleParameters.h ElectricVehicle.cpp ElectricVehicle.h VehicleMenu.cpp VehicleMenu.h)