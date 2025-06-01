#pragma once
// #ifndef VEHICIE_HPP
// #define VEHICLE_HPP

#include <memory>

struct Vehicle {
    virtual void accelerate() = 0;
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

std::unique_ptr<Vehicle> make_vehicle(); // main.cpp에서 make_vehicle() 함수의 선언 필요하기 때문에 헤더파일에서 선언(main.cpp를 고칠 수는 없으므로)

// #endif //VEHICLE_HPP