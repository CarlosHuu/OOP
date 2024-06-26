
#include <bits/stdc++.h>
#include "maze.h"
#include "player.h"
#include "portal.h"
#include "goal.h"
#define RED  "\033[31m"
#define CYAN "\033[36m"
#define BOLD_MAGENTA "\033[1m\033[35m"
#define RESET "\033[0m"
#include <chrono>
#include <thread>


using namespace std;

int main(int argc, char** argv){
    int atk=10;
    int lev=1;
    int exp=0;
    int hp=100;

    for (int level = 1; level <= LEVEL_NUM; level++) {
        SHOW_LEVEL(level);
        
        string input_filename("maze" + to_string(level) + ".txt");

        Maze* maze = new Maze(input_filename);

        maze->generate_obstacles(level);
        maze->generate_monsters(level);
        maze->generate_portals(level);
        maze->generate_Hp_potions(level);
        maze->generate_Exp_potions(level);
        maze->generate_keys(level); // 生成 Key 對象
        Player* player = new Player(1, 1, atk, hp, exp, lev);

        // Write your own code to generate the keys, obstacle, and ...
        maze->printMaze(player);

        while(true) {   // Condition for ending the game of this level. Write your own function to replace "true"
            char direction = player->get_direction();
            cout << "Main->direction = " << direction << endl;

            // Codes for the player touching different types of block. Use the function player_touched() to implement

            player->move(direction, maze, level);
            maze->goal_move(level);
            
            if(player->get_hp()<=0){
                cout <<RED<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<RESET<< endl;
                cout <<RED<< "!!!        。・゜・(ノД`)・゜・。       !!!" <<RESET<< endl;
                cout <<RED<< "!!!           YOU WERE KILLED           !!!" <<RESET<< endl;
                cout <<RED<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<RESET<< endl;
                exit(1);
            }
            
            maze->printMaze(player);
            
            if(player->get_exp()>=100){
                cout <<CYAN<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<RESET<< endl;
                cout <<CYAN<< "!!!        ♪───Ｏ（≧∇≦）Ｏ────♪         !!!" <<RESET<< endl;
                cout <<CYAN<< "!!!              level up               !!!" <<RESET<< endl;
                cout <<CYAN<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<RESET<< endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                player->level_up();
            }
            
            int keys_collected = player->get_keys_collected();
            int level_key_count = maze->get_level_key_count(level);
            cout <<BOLD_MAGENTA<< "Keys collected: " << keys_collected << "/" << level_key_count <<RESET<< endl;
            cout <<BOLD_MAGENTA<< "player ATK: "<<player->get_ATK()<<RESET<<endl;
            cout <<BOLD_MAGENTA<< "player hp: "<<player->get_hp()<<RESET<<endl;
            cout <<BOLD_MAGENTA<< "player exp: "<<player->get_exp()<<RESET<<endl;
            cout <<BOLD_MAGENTA<< "player level: "<<player->get_lev()<<RESET<<endl;
            atk=player->get_ATK();
            hp=player->get_hp();
            exp=player->get_exp();
            lev=player->get_lev();

            if (player->get_pass() == true) break;
        }
        
        delete maze;
        delete player;
    }

    ALL_PASS();
    system("clear");
    return 0;
}

