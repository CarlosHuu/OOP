#include "BattleEvent.h"
#include <iostream>
using namespace std;
void BattleEvent::start(Player &player, Monster &monster) {
    monster.print();
    player.print();
    while (player.isAlive() && monster.isAlive()) {
    //write by yourself
        player.attack( monster);
        if(monster.isAlive()){ 
            monster.attack( player);
            monster.print();
            player.print();
        }
    }
}
