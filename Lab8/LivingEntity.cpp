#include "LivingEntity.h"
#include <iostream>
using namespace std;
 //write constructor
LivingEntity :: LivingEntity(std::string _name, int _health,int _damage){
    name = _name;
    health = _health;
    damage = _damage;
}

bool LivingEntity::takeDamage(int damage) {
   //your turn
   health -= damage;
   
   if (health <= 0) {
      health = 0;
      return 0;
   }
   return 1;
}

bool LivingEntity::isAlive() {

    //your turn
    if (health <= 0) {
        return 0;
    }
    return 1;
}


std::string LivingEntity::getName() const {
    //your turn
    return name;
}
int LivingEntity::getHealth()const{
    //your turn
    return health;
}
void LivingEntity::print()const{
std::cout << "\n=== Monster Stats ===" << std::endl;
    std::cout << "Name: " << name<< std::endl;
    std::cout << "Health: " <<health<< std::endl;
     cout<<"====================="<<endl<<endl;}