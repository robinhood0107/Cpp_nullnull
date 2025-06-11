#ifndef EZREALSKILL_HPP
#define EZREALSKILL_HPP

#include "Skill.hpp"
#include <iostream>
#include <memory>

class EzrealSkill : public Skill {
public:
    void q() override { std::cout << "RISING SPELL FORCE" << std::endl; }
    void w() override { std::cout << "MYSTIC SHOT" << std::endl; }
    void e() override { std::cout << "ESSENCE FLUX" << std::endl; }
    void r() override { std::cout << "ARCANE SHIFT" << std::endl; }
    ~EzrealSkill() override = default;
private:
    

};

#endif // EZREALSKILL_HPP