#include "Vehicle.hpp"
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Vehicle>> test_vehicles;
    
    test_vehicles.push_back(make_vehicle()); // gv70
    test_vehicles.push_back(make_vehicle()); // grandeur
    test_vehicles.push_back(make_vehicle()); // carnibal

    for (auto& v : test_vehicles)
        (*v).accelerate();
        
    return 0;
}