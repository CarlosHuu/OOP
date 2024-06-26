#ifndef WALL_H
#define WALL_H
#include "block.h"
using namespace std;


class Wall : public Block{
public:
    Wall();

    void player_touched() override;

};

#endif