#include <iostream>
#include <cstdlib>
#include "organism.h"
using namespace std;

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