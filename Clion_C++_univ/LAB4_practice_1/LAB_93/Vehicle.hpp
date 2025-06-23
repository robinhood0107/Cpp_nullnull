#pragma once
// #ifndef VEHICIE_HPP
// #define VEHICLE_HPP

#include <memory>

struct Vehicle {
    virtual void accelerate() = 0; //부모의 가상함수는 이렇게 만들어 두는 것
    virtual ~Vehicle() = default;
};

struct GV70 : public Vehicle {
    void accelerate() override;
};

struct Grandeur : public Vehicle {
    void accelerate() override;
};

struct Carnibal : public Vehicle {
    void accelerate() override;
};

std::unique_ptr<Vehicle> make_vehicle();



//#endif //VEHICLE_HPP
