#ifndef MONSTER_H
#define MONSTER_H

#include "block.h"
#include <random>

class Monster : public Block {
private:
    int hp;
    int damage;
    int exp;

public:
    Monster(int level);
    int get_hp() { return hp; }
    int get_damage() { return damage; }
    void take_damage(int amount);
    void player_touched() override;
    int get_exp(){return exp;}
    void change();
};

#endif
