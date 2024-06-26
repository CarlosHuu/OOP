#include "exp_potion.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define BLUE  "\033[34m"

Exp_potion::Exp_potion() : Block() {
    symbol = {
        {
            {'-', '-', '-'},
            {'E', 'X', 'P'},
            {'-', '-', '-'}
        }
    };
    type = tExp;
    srand(time(0));

    // 生成10到90之?的?机?
    add = rand() % 91 + 10;
}

int Exp_potion::get_add() {
    return add;
}

void Exp_potion::player_touched() {

}
