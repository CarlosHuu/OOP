#ifndef MONSTER_H
#define MONSTER_H

#include "LivingEntity.h"

class Player;

class Monster : public LivingEntity {
protected:
    int getexperience;

public:
    Monster(std::string _name, int _health, int _damage);
    void attack(Player &player);
    int getExperience();
};

class BossMonster : public Monster {
public:
    BossMonster(std::string _name, int _health, int _damage);
   
};

class FlyingMonster : public Monster {
public:
    FlyingMonster(std::string _name, int _health, int _damage);
    
};

class GroundMonster : public Monster {
public:
    GroundMonster(std::string _name, int _health, int _damage);
  
};

class MagicMonster : public Monster {
public:
    MagicMonster(std::string _name, int _health, int _damage);
    
};

#endif // MONSTER_H