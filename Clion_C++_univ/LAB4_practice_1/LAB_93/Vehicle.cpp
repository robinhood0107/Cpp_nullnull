#include "Vehicle.hpp"
#include <iostream>
#include <memory>
#include <string>
using namespace std;

void GV70::accelerate() {
    cout << "The speed of the gv70 has increased by 30 km/h." << endl;
}

void Grandeur::accelerate() {
    cout << "The speed of the grandeur has increased by 20 km/h." << endl;
}

void Carnibal::accelerate() {
    cout << "The speed of the carnibal has increased by 10 km/h." << endl;
}

unique_ptr<Vehicle> make_vehicle() {

    string choice;

    cin >> choice;

    if (choice == "gv70")
        return make_unique<GV70>();

    else if (choice == "grandeur")
        return make_unique<Grandeur>();

    else if (choice == "carnibal")
        return make_unique<Carnibal>();

    else
        return make_unique<GV70>();

}

    //unique_ptr 문법!!!!
    //포인터 = std::unique_ptr<자료형> 이름(new 자료형[크기]) 막 이렇게 하면 됨!!!!)
    //make_unique<자료형>(값)으로 해도 되는데 걍 위가 훨씬 편하다!!!!

