#ifndef BLOCK_H
#define BLOCK_H
#include <vector>
using namespace std;
typedef vector<vector<vector<char>>> v3dchar;

enum BlockType{
  tPlayer,
  tKey,
  tGoal,
  tWall,
  tEmpty,
  tObstacle,
  tMonster,
  tPortal,
  tMovableGoal,
  tExp,
  tHp,
};

class Block {
protected:
    v3dchar symbol;   // 3D char vector to store symbols. One symbol is 3x3 pixel. You can have several symbols to animate blocks
    bool isVisible;   // Show whether this block is visible or not
    BlockType type;   // Type of derived class of Block 

public:
    Block();

    v3dchar get_symbol() const {return symbol;}
    BlockType get_type() const {return type;}
    // void set_type(BlockType _type) {type = _type;}
    virtual void player_touched() = 0;  //pure virtual function.  Codes for the block is touched by the player.
};

#endif
