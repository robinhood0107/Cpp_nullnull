#ifndef EZREALSKILL_HPP
#define EZREALSKILL_HPP
#include "Skill.hpp"
#include <iostream>
#include <memory>

class EzrealSkill : public Skill { //그리고 반드시 상속 받을 때는 public으로 받아라
public://그리고 public 절대 까먹지 마
    //가상함수 관련해서는 딱 하나만 기억하셈 기본 생성자에는 virtual 싹다 붙이고 자식은 전부 override 전부 다 붙이셈
    void q() override { std::cout << "RISING SPELL FORCE" << std::endl; }
    void w() override { std::cout << "MYSTIC SHOT" << std::endl; }
    void e() override { std::cout << "ESSENCE FLUX" << std::endl; }
    void r() override { std::cout << "ARCANE SHIFT" << std::endl; }
    ~EzrealSkill() override = default;
};


#endif //EZREALSKILL_HPP
