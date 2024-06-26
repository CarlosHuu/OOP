#ifndef MAZE_H
#define MAZE_H

#include <chrono>
using namespace std;
#include "block.h"
#include <random>
#include "player.h"
#include "obstacle.h"
#include "portal.h"
#include "key.h"
#include "empty.h"
#include "goal.h"
#include "monster.h"
#include "hp_potion.h"
#include "exp_potion.h"
#include <utility>
#include <vector>

class Player;
class MovableGoal; // 前向聲明 MovableGoal 類別

const int LEVEL_NUM = 4;
const int BLOCK_SIZE = 3;

// Game message
void ALL_PASS();
void SHOW_LEVEL(int currentLevel);

class Maze {
private:
    vector<vector<Block*>> maze;
    vector<vector<char>> pixel;
    int nRow, nCol;
    int nKey = 0;
    std::chrono::time_point<std::chrono::steady_clock> start_time;
    bool show_time;
    std::random_device rd;
    std::mt19937 gen;
    std::vector<std::pair<Portal*, Portal*>> portals;
    std::vector<Key*> keys;
    pair<int, int> goal_position;
    int goal_row;
    int goal_col;


public:
    Maze(string input_filename);
    int get_nRow() const { return nRow; }
    int get_nCol() const { return nCol; }
    Block* get_block(int row, int col) { return maze[row][col]; }
    void printMaze(Player* player);
    void toggle_show_time();
    void print_time(std::ostream& os);
    void generate_obstacles(int level);
    void generate_monsters(int level);
    void generate_Exp_potions(int level);
    void generate_Hp_potions(int level);

    Block* get_block(int row, int col) const;
    template <typename T>
    void set_block(int row, int col, T* block);
    void set_block(int row, int col, Empty* block);
    void set_block(int row, int col, Goal* block);
    void generate_portals(int level);
    void clear_portals();
    void generate_keys(int level);
    int get_level_key_count(int level) const;
    void goal_move(int level);

};

#endif