#include <bits/stdc++.h>
#include "wall.h"
using namespace std;

Wall::Wall() : Block(){
    symbol = {
                {   
                    {'*', '*', '*'}, 
                    {'*', '*', '*'}, 
                    {'*', '*', '*'} 
                }
            };
    type = tWall;
}

void Wall::player_touched() {
    //write by yourself
}