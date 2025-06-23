#ifndef SKILL_H
#define SKILL_H

class Skill {
public:
    virtual void q() { };
    virtual void w() { };
    virtual void e() { };
    virtual void r() { };
    virtual ~Skill() { };
};

#endif // SKILL_H