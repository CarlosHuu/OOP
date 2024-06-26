
#include <bits/stdc++.h>
#include "maze.h"
#include "wall.h"
#include "empty.h"
#include "goal.h"
#include "monster.h"
#include "hp_potion.h"
#include "exp_potion.h"
#include <random>
#include <algorithm>

#define BLUE    "\033[34m"

using namespace std;

// Timing control
void delay(int milliseconds) { this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); }

Maze::Maze(string input_filename)
{   
    gen.seed(rd());//隨機生成
    string str;
    int col;
    int row = 0;
    ifstream input_file;
    input_file.open(input_filename);
    
    vector<Block*> tmpBlockVec;
    Block* tmpBlock;
    while (getline(input_file, str)){
        row++;
        col = str.length();
        
        for(int i = 0; i < col; i++){
            
            if(str[i] == '0'){
                Empty *empty = new Empty();
                tmpBlock = empty;
                tmpBlockVec.push_back(tmpBlock);
            }
            else if(str[i] == '1'){
                Wall *wall = new Wall();
                tmpBlock = wall;
                tmpBlockVec.push_back(tmpBlock);
            }
            else if(str[i] == '2'){
                Goal *goal = new Goal();
                tmpBlock = goal;
                tmpBlockVec.push_back(tmpBlock);
                goal_row=row-1;
                goal_col=i;
            }
            else
                continue;
        }

        maze.push_back(tmpBlockVec);
        tmpBlockVec.clear();
    }

    input_file.close();
    nRow = row;
    nCol = col;

    start_time = std::chrono::steady_clock::now(); // 記錄遊戲開始時間
    show_time = true; // 默認顯示遊戲時間
}

void Maze::toggle_show_time() {
    show_time = !show_time;
}

void Maze::print_time(std::ostream& os) {
    if (show_time) {
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed_time = current_time - start_time;

        os << "Time elapsed: "
           << std::chrono::duration_cast<std::chrono::seconds>(elapsed_time).count()
           << " seconds" << std::endl;
    }
}

void Maze::printMaze(Player* player) {
    system("clear");
    print_time(cout); // 打印遊戲時間

    for (int i = 0; i < maze.size(); i++) {
        for (int grid_r = 0; grid_r < BLOCK_SIZE; grid_r++) {
            for (int j = 0; j < maze[i].size(); j++) {
                for (int grid_c = 0; grid_c < BLOCK_SIZE; grid_c++) {
                    if (i == player->get_player_row() && j == player->get_player_col())
                        cout << "\033[1;32m" << player->get_symbol()[0][grid_r][grid_c] << "\033[0m";
                    else {
                        Block* block = maze[i][j];
                        if (block->get_type() == tObstacle || block->get_type() == tMonster) {
                            // 如果是 Obstacle 或 Monster 且生命值小於等於 0, 則不顯示
                            if (block->get_type() == tObstacle && static_cast<Obstacle*>(block)->get_hp() <= 0) {
                                cout << ' ';
                            } else if (block->get_type() == tMonster && static_cast<Monster*>(block)->get_hp() <= 0) {
                                cout << ' ';
                            } else {
                                cout << block->get_symbol()[0][grid_r][grid_c];
                            }
                        } else {
                            switch (maze[i][j]->get_type()) {
                                case tGoal:
                                    cout << "\033[1;33m" << maze[i][j]->get_symbol()[0][grid_r][grid_c] << "\033[0m";
                                    break;
                                default:
                                    cout << maze[i][j]->get_symbol()[0][grid_r][grid_c];
                            }
                        }
                    }
                }
            }
            cout << endl;
        }
    }
}


void ALL_PASS() {
    for (int i = 3; i > 0; i--) {
        system("clear");
        cout <<BLUE<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout <<BLUE<< "!!!           CONGRATULATIONS           !!!" << endl;
        cout <<BLUE<< "!!!          YOU PASS ALL LEVEL         !!!" << endl;
        cout <<BLUE<< "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "Exiting in " << i << " seconds ..." << endl;
        delay(1000);
    }
    return;
}

void SHOW_LEVEL(int currentLevel) {
    for (int shine = 0; shine < 10; shine++) {
        system("clear");
        bool shineEnable = (shine % 2 == 0);

        // Row 1
        cout << "!!!";
        for (int i = 1; i <= LEVEL_NUM; i++) {
            if (i < LEVEL_NUM) cout << "!!!!!!!!!!";
            else               cout << "!!!!!!!!";
        }
        cout << "!!!" << endl;

        // Row 2
        cout << "!!!";
        for (int i = 1; i <= LEVEL_NUM; i++) {
            string msg = " LEVEL" + to_string(i) + " ";
            // Current level shining
            if (i == currentLevel && shineEnable) cout << "\033[1;32m" << msg << "\033[0m";
            else                                  cout << msg;
            // Intervals
            if (i < LEVEL_NUM) cout << "->";
        }
        cout << "!!!" << endl;

        // Row 3
        cout << "!!!";
        for (int i = 1; i <= LEVEL_NUM; i++) {
            if (i < LEVEL_NUM) cout << "!!!!!!!!!!";
            else               cout << "!!!!!!!!";
        }
        cout << "!!!" << endl;

        delay(200);
    }

    delay(1000);
}

Block* Maze::get_block(int row, int col) const {
    return maze[row][col];
}

template <typename T>
void Maze::set_block(int row, int col, T* block) {
    delete maze[row][col]; // 釋放原有的 Block 對象
    maze[row][col] = block;
}

void Maze::generate_obstacles(int level) {
    std::uniform_int_distribution<> dis_count(level, 2 * level); // 產生 Obstacle 數量的分布
    int obstacle_count = dis_count(gen); // 獲取 Obstacle 數量

    std::vector<std::pair<int, int>> empty_positions; // 存儲空白位置的坐標

    // 找出所有空白位置的坐標
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (maze[i][j]->get_type() == tEmpty) {
                empty_positions.emplace_back(i, j);
            }
        }
    }

    // 打亂空白位置的順序
    std::shuffle(empty_positions.begin(), empty_positions.end(), gen);

    // 在隨機的空白位置上放置 Obstacle
    for (int i = 0; i < obstacle_count; i++) {
        int row = empty_positions[i].first;
        int col = empty_positions[i].second;
        delete maze[row][col]; // 刪除原有的 Empty 物件
        maze[row][col] = new Obstacle(); // 放置新的 Obstacle 物件
    }
}

void Maze::generate_monsters(int level) {
    std::uniform_int_distribution<> dis_count(level, 2 * level); // 產生 Obstacle 數量的分布
    int monster_count = dis_count(gen); // 獲取 Obstacle 數量

    std::vector<std::pair<int, int>> empty_positions; // 存儲空白位置的坐標

    // 找出所有空白位置的坐標
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (maze[i][j]->get_type() == tEmpty) {
                empty_positions.emplace_back(i, j);
            }
        }
    }

    // 打亂空白位置的順序
    std::shuffle(empty_positions.begin(), empty_positions.end(), gen);

    // 在隨機的空白位置上放置 Obstacle
    for (int i = 0; i < monster_count; i++) {
        int row = empty_positions[i].first;
        int col = empty_positions[i].second;
        delete maze[row][col]; // 刪除原有的 Empty 物件
        maze[row][col] = new Monster(level); // 放置新的 Obstacle 物件
    }
}

void Maze::generate_Hp_potions(int level) {
    std::uniform_int_distribution<> dis_count(1, level); // 產生 Obstacle 數量的分布
    int potion_count = dis_count(gen); // 獲取 Obstacle 數量

    std::vector<std::pair<int, int>> empty_positions; // 存儲空白位置的坐標

    // 找出所有空白位置的坐標
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (maze[i][j]->get_type() == tEmpty) {
                empty_positions.emplace_back(i, j);
            }
        }
    }

    // 打亂空白位置的順序
    std::shuffle(empty_positions.begin(), empty_positions.end(), gen);

    // 在隨機的空白位置上放置 Obstacle
    for (int i = 0; i < potion_count; i++) {
        int row = empty_positions[i].first;
        int col = empty_positions[i].second;
        delete maze[row][col]; // 刪除原有的 Empty 物件
        maze[row][col] = new Hp_potion(); // 放置新的 Obstacle 物件
    }
}

void Maze::generate_Exp_potions(int level) {
    std::uniform_int_distribution<> dis_count(1, level); // 產生 Obstacle 數量的分布
    int potion_count = dis_count(gen); // 獲取 Obstacle 數量

    std::vector<std::pair<int, int>> empty_positions; // 存儲空白位置的坐標

    // 找出所有空白位置的坐標
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (maze[i][j]->get_type() == tEmpty) {
                empty_positions.emplace_back(i, j);
            }
        }
    }

    // 打亂空白位置的順序
    std::shuffle(empty_positions.begin(), empty_positions.end(), gen);

    // 在隨機的空白位置上放置 Obstacle
    for (int i = 0; i < potion_count; i++) {
        int row = empty_positions[i].first;
        int col = empty_positions[i].second;
        delete maze[row][col]; // 刪除原有的 Empty 物件
        maze[row][col] = new Exp_potion(); // 放置新的 Obstacle 物件
    }
}

void Maze::generate_portals(int level) {
    clear_portals(); // 清除上一關卡的 Portal

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis_count(level, 1 * level); // 產生 Portal 對數量的分布
    int portal_pair_count = dis_count(gen); // 獲取 Portal 對數量

    std::vector<std::pair<int, int>> empty_positions; // 存儲空白位置的坐標

    // 找出所有空白位置的坐標
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (maze[i][j]->get_type() == tEmpty) {
                empty_positions.emplace_back(i, j);
            }
        }
    }

    // 打亂空白位置的順序
    std::shuffle(empty_positions.begin(), empty_positions.end(), gen);

    // 在隨機的空白位置上放置 Portal 對
    for (int i = 0; i < portal_pair_count; i++) {
        int row1 = empty_positions[2 * i].first;
        int col1 = empty_positions[2 * i].second;
        int row2 = empty_positions[2 * i + 1].first;
        int col2 = empty_positions[2 * i + 1].second;

        Portal* portal1 = new Portal();
        Portal* portal2 = new Portal();

        portal1->set_partner_pos(row2, col2);
        portal2->set_partner_pos(row1, col1);

        set_block(row1, col1, portal1);
        set_block(row2, col2, portal2);

        portals.emplace_back(portal1, portal2);
    }
}

void Maze::clear_portals() {
    for (auto& portal_pair : portals) {
        delete portal_pair.first;
        delete portal_pair.second;
    }
    portals.clear();
}

void Maze::generate_keys(int level) {
    std::uniform_int_distribution<> dis_count(level, level); // 產生 Key 數量的分布
    int key_count = dis_count(gen); // 獲取 Key 數量

    std::vector<std::pair<int, int>> empty_positions; // 存儲空白位置的坐標

    // 找出所有空白位置的坐標
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (maze[i][j]->get_type() == tEmpty) {
                empty_positions.emplace_back(i, j);
            }
        }
    }

    // 打亂空白位置的順序
    std::shuffle(empty_positions.begin(), empty_positions.end(), gen);

    // 在隨機的空白位置上放置 Key
    for (int i = 0; i < key_count; i++) {
        int row = empty_positions[i].first;
        int col = empty_positions[i].second;
        delete maze[row][col]; // 刪除原有的 Empty 物件
        maze[row][col] = new Key(); // 放置新的 Key 物件
        keys.push_back(static_cast<Key*>(maze[row][col])); // 存儲 Key 對象
    }
}

int Maze::get_level_key_count(int level) const {
    return level;
}

void Maze::set_block(int row, int col, Empty* block) {
    delete maze[row][col]; // 釋放原有的 Block 對象
    maze[row][col] = block;
}

void Maze::set_block(int row, int col,  Goal* block) {
    delete maze[row][col]; // 釋放原有的 Block 對象
    maze[row][col] = block;
}

void Maze::goal_move(int level){
    if(level<=2){
        return;
    }
    else{
    srand(time(0));
    // 生成10到20之?的?机?
    int direction = rand() % 4 + 1;
    int nextRow = goal_row, nextCol = goal_col;
    switch (direction) {
        case 1:
            nextRow -= 1;
            break;
        case 2:
            nextRow += 1;
            break;
        case 3:
            nextCol -= 1;
            break;
        case 4:
            nextCol += 1;
            break;
        default:
            return;
    }
    if (nextRow >= 0 && nextRow < nRow && nextCol >= 0 && nextCol < nCol) {
        Block* nextBlock =  get_block(nextRow, nextCol);
        if (nextBlock->get_type() != tWall && nextBlock->get_type() != tHp && nextBlock->get_type() != tExp && nextBlock->get_type() != tKey &&nextBlock->get_type() != tPortal && nextBlock->get_type() != tObstacle &&nextBlock->get_type() != tMonster) {
            set_block(goal_row, goal_col, new Empty());
            goal_row = nextRow;
            goal_col = nextCol;
            set_block(goal_row, goal_col, new Goal());
        }
    }
    return;
    }
}



