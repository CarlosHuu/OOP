#include "organism.h"
#include <iostream>
using namespace std;

void World:: initializeWorld(){
    for (int i = 0; i < 5 ; ++i){
        for (int j = 0; j < 5 ; ++j){
            world[i][j] = '-';
        }
    }
}
void World:: changeWorld_doo(int _x, int _y){
    world[_x][_y] = 'x';
}
void World :: changeWorld_ant(int _x, int _y){
    world[_x][_y] = 'o';
}
void World :: printWorld(){
    for (int i = 4 ; i >= 0 ; --i){
        for(int j = 0 ; j <= 4 ; ++j){
            cout << world[j][i];
        }
        cout << endl;
    }
}
void Ant :: move(World& currWorld) {
        //up
        if (currWorld.world[getX()][getY()+1] == '-' && getY()+1 <=4){
            int newX = x ;
            int newY = y+1;
            currWorld.world[newX][newY] = 'o';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //right
        else if (currWorld.world[getX()+1][getY()] == '-' && getX()+1 <=4){
            int newX = x +1;
            int newY = y ;
            currWorld.world[newX][newY] = 'o';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //down
        else if (currWorld.world[getX()][getY()-1] == '-'  && getY()-1 >=0 ){
            int newX = x ;
            int newY = y-1;
            currWorld.world[newX][newY] = 'o';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //left
        else if (currWorld.world[getX()-1][getY()] == '-' && getX()-1 >=0){
            int newX = x-1;
            int newY = y ;
            currWorld.world[newX][newY] = 'o';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        else{
            x=x;
            y=y;
        }
};
void Doodlebug ::move(World& currWorld){
        //up eat
        if (currWorld.world[getX()][getY()+1] == 'o' && getY()+1 <=4){
            int newX = x;
            int newY = y + 1;
            currWorld.world[newX][newY] = 'x';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //right eat
        else if (currWorld.world[getX()+1][getY()] == 'o' && getX()+1 <=4){
            int newX = x + 1;
            int newY = y ;
            currWorld.world[newX][newY] = 'x';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //down eat
        else if (currWorld.world[getX()][getY()-1] == 'o' && getY()-1 >=0){
            int newX = x;
            int newY = y-1;
            currWorld.world[newX][newY] = 'x';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //left eat 
        else if (currWorld.world[getX()-1][getY()] == 'o' && getX()-1 >=0){
            int newX = x-1;
            int newY = y;
            currWorld.world[newX][newY] = 'x';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //up
        else if (currWorld.world[getX()][getY()+1] == '-' && getY()+1 <=4){
            int newX = x ;
            int newY = y+1;
            currWorld.world[newX][newY] = 'x';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //right
        else if (currWorld.world[getX()+1][getY()] == '-' && getX()+1 <=4){
            int newX = x +1;
            int newY = y ;
            currWorld.world[newX][newY] = 'x';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //down
        else if (currWorld.world[getX()][getY()-1] == '-'  && getY()-1 >=0 ){
            int newX = x ;
            int newY = y-1;
            currWorld.world[newX][newY] = 'x';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        //left
        else if (currWorld.world[getX()-1][getY()] == '-' && getX()-1 >=0){
            int newX = x-1;
            int newY = y ;
            currWorld.world[newX][newY] = 'x';
            currWorld.world[x][y] = '-'; 
            x = newX;
            y = newY;
        }
        else{
            x=x;
            y=y;
        }
    }
