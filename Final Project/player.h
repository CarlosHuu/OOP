#ifndef PLAYER_H
#define PLAYER_H
#include "block.h"
using namespace std;
#include "maze.h"
class Maze;

class Player : public Block{
private:
    int player_row;
    int player_col;
    int key_Collected = 0;
    int current_direction = 0;
    int ATK; // 新增攻擊力變數,初始值為10
    int hp;
    int exp;
    int lev;

    int keys_collected; // 已收集的 Key 數量//!key
    bool pass = false;
public:
    Player(int startRow, int startCol, int atk ,int h, int e, int l);

    int get_player_row() const {return player_row;}
    int get_player_col() const {return player_col;}
    int get_ATK() {return ATK;} // 新增取得攻擊力的函式
    int get_keys_collected() const { return keys_collected; } // 新增取得已收集 Key 數量的函式//!key
    bool get_pass() {return pass;}
    char get_direction();
    void move(char direction,  Maze* maze, int level);//const -> inconst
    void change_symbol();
    void player_touched() override{};   //Not need to implement this function because the player won't touch himself/herself 
    void set_position(int row, int col, const Maze* maze);
    int get_hp(){return hp;}
    int get_exp(){return exp;}
    int get_lev(){return lev;}
    void level_up();

};

#endif