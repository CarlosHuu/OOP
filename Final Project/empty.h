#ifndef EMPTY_H
#define EMPTY_H
#include "block.h"
using namespace std;

class Empty : public Block{
public:
    Empty();

    void player_touched() override;
};

#endif