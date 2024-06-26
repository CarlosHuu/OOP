#ifndef EXPPOTION_H
#define EXPPOTION_H
#include "block.h"
using namespace std;

class Exp_potion : public Block {
private:
    int add; 

public:
    Exp_potion();
    int get_add();
    void player_touched() override;  
};

#endif 
