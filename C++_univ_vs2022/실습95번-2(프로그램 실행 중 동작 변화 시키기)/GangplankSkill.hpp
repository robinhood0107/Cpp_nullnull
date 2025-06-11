#ifndef GANGPLANKSKILL_HPP
#define GANGPLANKSKILL_HPP

#include "Skill.hpp"
#include <iostream>
#include <memory>

class GangplankSkill : public Skill {
public:
    void q() override { std::cout << "TRIAL BY FIRE" << std::endl; }
    void w() override { std::cout << "PARRRLEY" << std::endl; }
    void e() override { std::cout << "REMOVE SCURVY" << std::endl; }
    void r() override { std::cout << "POWDER KEG" << std::endl; }
    ~GangplankSkill() override = default;
private:

};

#endif // GANGPLANKSKILL_H