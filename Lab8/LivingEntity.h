#ifndef LIVINGENTITY_H
#define LIVINGENTITY_H
#include <string>
class LivingEntity {
protected:
   std::string name;
    int health;
 int damage;
public:
    LivingEntity(std::string _name, int _health,int _damage);
    bool takeDamage(int damage);
    bool isAlive();
    std::string getName() const;
    int getHealth()const;
    void print()const;
};

#endif // LIVINGENTITY_H