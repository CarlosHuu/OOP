#ifndef KEY_H
#define KEY_H
#include "block.h"
using namespace std;

class Key : public Block {
private:
    static int key_count; 
    int key_id; 

public:
    Key();

    int get_key_id() const; 
    void player_touched() override; 
};

#endif