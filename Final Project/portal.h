#ifndef PORTAL_H
#define PORTAL_H

#include "block.h"
#include <utility> 

using namespace std;

class Portal : public Block {
private:
    static int portal_count; 
    int portal_id; 
    pair<int, int> partner_pos; 

public:
    Portal();

    void set_partner_pos(int row, int col); 
    pair<int, int> get_partner_pos() const; 
    int get_portal_id() const; 

    void player_touched() override;
};

#endif