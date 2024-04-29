#ifndef BATTLEEVENT_H
#define BATTLEEVENT_H
#include "Player.h"
#include "Monster.h"

class BattleEvent {
public:
    static void start(Player &player, Monster &monster);
};

#endif // BATTLEEVENT_H