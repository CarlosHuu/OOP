#include "Player.h"
#include <iostream>
using namespace std;

//write player constructor

Player::Player(std::string _name, int _health, int _Damage):
    LivingEntity(_name,_health,_Damage),experience(0), level(1){}

void Player::attack(Monster &monster) {
    // your turn
    std::cout << name << " attacks for " << damage << " damage!" << std::endl;
    cout << monster.getName() << " takes " << damage << " damage!" << std::endl;
    if (!monster.takeDamage(damage)){
        cout << monster.getName() << " has been defeated!" << endl;
        gainExperience(monster.getExperience());
    }
}

void Player::gainExperience(int amount) {

    // your turn  
    cout << name << " gains " << amount << " experience!" << endl;
    experience += amount;
    if (experience >= (level*level)*20){
        levelUp();
    }
}

void Player::restoreHealth(int amount) {
   
    // your turn
    cout << name << " restores " << amount << " health!";
    health += amount;
}
void Player::levelUp() {
    
   // your turn
    level += 1;
    damage = level*20;
    health += level*20;
    cout << name << " levels up to level  " << level << "!" << endl;
}

    void Player::print()const{ 
    std::cout << "\n=== Player Stats ===" << std::endl;
    std::cout << "Name: " << name<< std::endl;
    std::cout << "Health: " <<health<< std::endl;
     std::cout << "Level: " << level << std::endl;
     std::cout << "Experience: " <<experience  << std::endl;
     std::cout << "Attack damage: " << damage << std::endl;
     cout<<"==================="<<endl<<endl;}