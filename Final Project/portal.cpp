#include "portal.h"
#include <bits/stdc++.h>
int Portal::portal_count = 0; // 初始化靜態變數

Portal::Portal() : Block() {
    symbol = {
        {
            {'o', 'o', 'o'},
            {'o', 'P', 'o'},
            {'o', 'o', 'o'}
        }
    };
    type = tPortal;
    portal_id = ++portal_count; 
}

void Portal::set_partner_pos(int row, int col) {
    partner_pos = make_pair(row, col);
}

pair<int, int> Portal::get_partner_pos() const {
    return partner_pos;
}

int Portal::get_portal_id() const {
    return portal_id;
}

void Portal::player_touched() {
    
}