#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "block.h"
#include <random>

class Obstacle : public Block {
private:
    int hp;
    static std::random_device rd;
    static std::mt19937 gen;
    static std::uniform_int_distribution<> dis;

public:
    Obstacle();
    int get_hp() const { return hp; }
    void take_damage(int amount);
    void player_touched() override;
    static int random_hp();
};

#endif