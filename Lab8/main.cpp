#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "BattleEvent.h"
using namespace std;

int main(int argc,char** argv) {
  string name;
  int health;
  int attack;
  int player_health;
  int player_attack;
  int num_of_monster;
  int select_type_of_monster;
  int action;
  BattleEvent mybattle;
  ifstream in;
  in.open(argv[1]);
  in>>player_health>>player_attack;
  Player* player=new Player("HERO", player_health, player_attack); 
  player->print();
  in>>num_of_monster;
  for(int i=0;i<num_of_monster;i++){
    in>>health>>attack;
    in>>select_type_of_monster;
     in>>action;
    Monster *monster;
    switch(select_type_of_monster)
    {
      case 0:{
        Monster weakMonster("Goblin" ,health, attack);
          monster=&weakMonster;
      break;}
      case 1:{
        FlyingMonster flyingMonster("Harpy",health, attack);
          monster=&flyingMonster;
      break;}
      case 2:{
        GroundMonster groundMonster("Ogre",health, attack);
        monster=&groundMonster;
      break;}
      case 3:{
        MagicMonster magicMonster("Sorcerer",health, attack);
        monster=&magicMonster;
      break;}
      case 4:{
        BossMonster strongBoss("Ancient Dragon",health, attack);
        monster=&strongBoss;
      break;}
      default:{
      break;}
    }
   
    switch(action)
    {
      case 0:
        { cout<<endl<<endl;
          cout<<"===========BATTLE "<<i+1<<"==============="<<endl;
        monster->print();
        player->print();
        player->attack( *monster);
         monster->print();
         player->print();
        if(monster->isAlive())
        { 
        monster->attack( *player);
        monster->print();
         player->print();
        };
        
         cout<<"======================================="<<endl;
       
        
      break;}
      case 1:
        {in>>health;
        cout<<endl<<endl;
         cout<<"===========BATTLE "<<i+1<<"==============="<<endl;
        player->restoreHealth(health);
         monster->print();
        player->print();
        player->attack( *monster);
         monster->print();
         player->print();
        if(monster->isAlive())
        { 
        monster->attack( *player);
        monster->print();
         player->print();
        };
       
          cout<<"======================================="<<endl;
      break;}
      case 2:
        { cout<<"===========BATTLE "<<i+1<<"==============="<<endl;
          mybattle.start(*player,  *monster);
          monster->print();
          player->print();
          cout<<"======================================="<<endl;
      break;}
      
      default:{
      break;}
    }
  if(!player->isAlive())break;
  }
  in.close();
  return 0;
}
