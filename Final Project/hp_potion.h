#ifndef HPPOTION_H
#define HPPOTION_H
#include "block.h"
using namespace std;

class Hp_potion : public Block {
private:
    int add; // �ѧO�� Key �� ID

public:
    Hp_potion();
    int get_add();
    void player_touched() override; // �� Player �߰_ Key 
};

#endif 
