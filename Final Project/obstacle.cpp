#include <bits/stdc++.h>
#include "obstacle.h"
#include "maze.h"
// 初始化靜態成員變數
std::random_device Obstacle::rd;
std::mt19937 Obstacle::gen(rd());
std::uniform_int_distribution<> Obstacle::dis(10, 50);

Obstacle::Obstacle() : Block() {
    symbol = {
        {
            {'@', '@', '@'},
            {'@', '@', '@'},
            {'@', '@', '@'}
        }
    };
    type = tObstacle; // 設置類型為tObstacle
    hp = random_hp();
}

int Obstacle::random_hp() {
    return dis(gen);
}

void Obstacle::take_damage(int amount) {
    hp -= amount;
}

void Obstacle::player_touched() {

}
