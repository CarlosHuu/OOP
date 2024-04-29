#include "Monster.h"
#include "Player.h" // Add this include directive to access the full definition of the Player class
#include <iostream>
using namespace std;

//write constructor
Monster:: Monster(std::string _name, int _health, int _damage):
    LivingEntity(_name,_health,_damage), getexperience(_health*0.5){}

void Monster::attack(Player &player) {
    std::cout << name << " attacks for " << damage << " damage!" << std::endl;
    cout << player.getName() << " takes " << damage << " damage!" << std::endl;
    if (!player.takeDamage(damage)){
        cout << player.getName() << " has been defeated!" << endl;
    }
}

int Monster::getExperience() {
     // your turn
     return getexperience;
}
BossMonster::BossMonster(std::string _name, int _health, int _damage):
    Monster(_name, _health, _damage){}

FlyingMonster::FlyingMonster(std::string _name, int _health, int _damage):
    Monster(_name, _health, _damage){}

GroundMonster::GroundMonster(std::string _name, int _health, int _damage):
    Monster(_name, _health, _damage){}

MagicMonster::MagicMonster(std::string _name, int _health, int _damage):
    Monster(_name, _health, _damage){}