#include <bits/stdc++.h>
#include "player.h"
#include "wall.h"
#include "empty.h"
#include "maze.h"
#include "obstacle.h"
#include "goal.h"
#include "monster.h"
#include "hp_potion.h"
#include "exp_potion.h" 
using namespace std;
static const vector<v3dchar> PLAYER_SYMBOLS = {
    // 向上
    {
        {
            {' ', '^', ' '},
            {'/', ' ', '\\'},
            {'/', ' ', '\\'}
        }
    },
    // 向下
    {
        {
            {' ', 'V', ' '},
            {'/', ' ', '\\'},
            {'/', ' ', '\\'}
        }
    },
    // 向左
    {
        {
            {' ', '<', ' '},
            {'/', ' ', '\\'},
            {'/', ' ', '\\'}
        }
    },
    // 向右
    {
        {
            {' ', '>', ' '},
            {'/', ' ', '\\'},
            {'/', ' ', '\\'}
        }
    }
};
Player::Player(int startRow, int startCol, int atk ,int h, int e, int l) : Block(), player_row(startRow), player_col(startCol), keys_collected(0), ATK(atk), hp(h), exp(e), lev(l){
    // symbol = {
    //             {   
    //                 {' ', 'O', ' '}, 
    //                 {'/', '|', '\\'}, 
    //                 {'/', ' ', '\\'} 
    //             }
    //         };
    symbol = PLAYER_SYMBOLS[0]; // 初始方向為向上
    type = tPlayer;
}

void Player::move(char direction,  Maze* maze, int level){//const -> inconst
    int nextRow = player_row, nextCol = player_col;
    switch (direction) {
        case 'U':
            nextRow -= 1;
            current_direction = 0;
            break;
        case 'D':
            nextRow += 1;
            current_direction = 1;
            break;
        case 'L':
            nextCol -= 1;
            current_direction = 2;
            break;
        case 'R':
            nextCol += 1;
            current_direction = 3;
            break;
        default:
            return;
    }

    if (nextRow >= 0 && nextRow < maze->get_nRow() && nextCol >= 0 && nextCol < maze->get_nCol()) {
        Block* nextBlock =  maze->get_block(nextRow, nextCol);
        
        // 如果即將移動到的位置是 Obstacle
        Obstacle* obstacle = nullptr;
        if (nextBlock->get_type() == tObstacle) {
            obstacle = dynamic_cast<Obstacle*>(nextBlock);
            obstacle->take_damage(get_ATK()); // 使用 Player 的攻擊力對 Obstacle 造成傷害
        }
        
        Monster* monster = nullptr;
        if (nextBlock->get_type() == tMonster) {
            monster = dynamic_cast<Monster*>(nextBlock);
            monster->take_damage(get_ATK());
            hp-=monster->get_damage();
            if(monster->get_hp()<=0){
                exp+=monster->get_exp();
                monster->change();
            }
        }

        if (nextBlock->get_type() == tKey) {
        Key* key = dynamic_cast<Key*>(nextBlock);
        keys_collected++; // 增加已收集的 Key 數量
        maze->set_block(nextRow, nextCol, new Empty());
        }
        
        if (nextBlock->get_type() == tHp) {
        Hp_potion* Hp = dynamic_cast<Hp_potion*>(nextBlock);
        hp+=Hp->get_add();
        maze->set_block(nextRow, nextCol, new Empty());
        }
        
        if (nextBlock->get_type() == tExp) {
        Exp_potion* Exp = dynamic_cast<Exp_potion*>(nextBlock);
        exp+=Exp->get_add();
        if(exp>=100){
                cout << "level up!" << endl;
                lev+=1;
                exp-=100;
                hp+=50;
                ATK+=5;
            }
        maze->set_block(nextRow, nextCol, new Empty());
        }
        
        if (nextBlock->get_type() == tPortal) {
            Portal* portal = dynamic_cast<Portal*>(nextBlock);
            pair<int, int> partner_pos = portal->get_partner_pos();
            set_position(partner_pos.first, partner_pos.second, maze);
            return;
        }
        if (nextBlock->get_type() == tGoal) {
            Goal* goal = dynamic_cast<Goal*>(nextBlock);
            
            // 判斷是否已收集所有 Key 並到達 Goal
            if (keys_collected == maze->get_level_key_count(level) && nextBlock->get_type() == tGoal) {
                // 可以進入下一關卡
                pass = true;
            }
        }   
        // 檢查即將移動到的位置是否為 Wall 或 Empty
        if (nextBlock->get_type() == tWall) {
            // 如果是 Wall,呼叫 Wall 的 player_touched 方法
            Wall* wall = dynamic_cast<Wall*>(nextBlock);
            // wall->player_touched();
            
        } else if (nextBlock->get_type() == tEmpty) {
            // 如果是 Empty,呼叫 Empty 的 player_touched 方法
            Empty* empty = dynamic_cast<Empty*>(nextBlock);
            // empty->player_touched();
        }
        // 只有在即將移動到的位置不是 Wall 或已被摧毀的 Obstacle 時,才允許移動
        if (nextBlock->get_type() != tWall && (nextBlock->get_type() != tObstacle || (obstacle != nullptr && obstacle->get_hp() <= 0))&&(nextBlock->get_type() != tMonster || (monster != nullptr && monster->get_hp() <= 0))) {
            player_row = nextRow;
            player_col = nextCol;
            change_symbol();
        }
    }
    return;
}

void Player::change_symbol(){
    //write by yourself
    symbol = PLAYER_SYMBOLS[current_direction];
}

char Player::get_direction() {
    while(true) {
        system("stty raw");
        char c = getchar();
        system("stty cooked");

        switch (c) {
            case 'W':
            case 'w':
                return 'U';
            case 'S':
            case 's':
                return 'D';
            case 'A':
            case 'a':
                return 'L';
            case 'D':
            case 'd':
                return 'R';
            case 'E':
            case 'e':
                system("stty cooked");
                system("clear");
                exit(0);
            default:
                continue;
        }
    }
}

void Player::set_position(int row, int col, const Maze* maze) {
    if (row >= 0 && row < maze->get_nRow() && col >= 0 && col < maze->get_nCol()) {
        player_row = row;
        player_col = col;
        change_symbol(); // 更新 Player 的外觀符號
    }
}

void Player::level_up(){
    if(exp>=100){
        lev+=1;
        exp-=100;
        hp+=50;
        ATK+=5;
    }
}

