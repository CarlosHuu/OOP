#include "hp_potion.h"
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

Hp_potion::Hp_potion() : Block() {
    symbol = {
        {
            {'-', '-', '-'},
            {'H', ' ', 'P'},
            {'-', '-', '-'}
        }
    };
    type = tHp;
    srand(time(0));

    // �ͦ�10��20��?��?��?
    add = rand() % 11 + 10;
}

int Hp_potion::get_add() {
    return add;
}

void Hp_potion::player_touched() {

}
