#ifndef HPPOTION_H
#define HPPOTION_H
#include "block.h"
using namespace std;

class Hp_potion : public Block {
private:
    int add; // 識別該 Key 的 ID

public:
    Hp_potion();
    int get_add();
    void player_touched() override; // 當 Player 撿起 Key 
};

#endif 
