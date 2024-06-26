#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include "monster.h"
#include "maze.h"
#define MAGENTA "\033[35m" 

Monster::Monster(int level) : Block() {
    symbol = {{
        {'X', '|', 'X'},
        {'X', '|', 'X'},
        {'_', '_', '_'}
    }};
    type = tMonster; 
    
    srand(time(0));

    hp= rand() % 41 + 15*level;
    damage = rand() % 21 + 20*level;
    exp=damage*2;
}

void Monster::take_damage(int amount) {
    hp -= amount;
    if(hp<=0){
    damage=0;
    }
}

void Monster::player_touched() {

}

void Monster::change() {
    exp=0;
}