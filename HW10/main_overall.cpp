#include <iostream>
#include <cstdlib>
using namespace std;

class World {
    friend class Organism;
    friend class Ant;
    friend class Doodlebug;
    public:
        void initializeWorld();
        void changeWorld_doo(int _x, int _y);
        void changeWorld_ant(int _x, int _y);
        void printWorld();
        char getElement(int x, int y) const { return world[x][y]; }
    private:
        char world[5][5];
};
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
class Organism {
public:
    virtual void move(World& currWorld) = 0;
    Organism() : x(0), y(0) {} 
    Organism(int _x, int _y) : x(_x), y(_y) {}
    int getX() const { return x; }
    int getY() const { return y; }
protected:
    int x;
    int y;
};

class Ant : public Organism {
public:
    Ant(int _x, int _y) : Organism(_x, _y) {}
    void move(World& currWorld)  {
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
    }
};

class Doodlebug : public Organism {
    public:
    Doodlebug(int _x, int _y) : Organism(_x, _y) {}
    void move(World& currWorld){
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
};

int main() {

    int doodlebug_x, doodlebug_y ;
    int ant1_x, ant1_y ;
    int ant2_x, ant2_y ;
    int ant3_x, ant3_y ;
    World net;
    net.initializeWorld();
    cin >> doodlebug_x >> doodlebug_y;
    cin >> ant1_x >> ant1_y;
    cin >> ant2_x >> ant2_y;
    cin >> ant3_x >> ant3_y;
    Doodlebug ddb(doodlebug_x, doodlebug_y);
    Ant ant_1(ant1_x, ant1_y);
    Ant ant_2(ant2_x, ant2_y);
    Ant ant_3(ant3_x, ant3_y);

    net.changeWorld_doo(doodlebug_x, doodlebug_y);
    net.changeWorld_ant(ant1_x, ant1_y);
    net.changeWorld_ant(ant2_x, ant2_y);
    net.changeWorld_ant(ant3_x, ant3_y);
    cout << "----time0----" << endl;
    net.printWorld();
    bool ant1_alive = true;
    bool ant2_alive = true;
    bool ant3_alive = true;

    int step = 1;
    while (1)
    {
        char command;
        cin >> command;
        if (command=='n'){
            cout << "----time"<<step<<"----" << endl;
            ddb.move(net);
            if (net.getElement(ant_1.getX(), ant_1.getY()) == 'x'){
                ant1_alive = false;
            }
            else if (net.getElement(ant_2.getX(), ant_2.getY()) == 'x'){
                ant2_alive = false;
            }
            else if (net.getElement(ant_3.getX(), ant_3.getY()) == 'x'){
                ant3_alive = false;
            }
            if (ant3_alive) ant_3.move(net);
            if (ant2_alive) ant_2.move(net);
            if (ant1_alive) ant_1.move(net);
            net.printWorld();
        }
        else break;
        step++;
    }
    return 0;
}