#ifndef GOAL_H
#define GOAL_H
#include "block.h"
using namespace std;


class Goal : public Block{
public:
    Goal();

    void player_touched() override;

};

#endif