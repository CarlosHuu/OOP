#ifndef PLAYER_H
#define PLAYER_H

#include "LivingEntity.h"
#include "Monster.h"

class Player : public LivingEntity {
private:
    int experience;
    int level;
   
    void levelUp();

public:
    Player(std::string _name, int _health, int _Damage);
    void attack(Monster &monster);
    void gainExperience(int amount);
    void restoreHealth(int amount);
    int getLevel() const;
    int getExperience() const;
    void print()const;
    
};

#endif // PLAYER_H