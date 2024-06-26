#include "key.h"
#include <bits/stdc++.h>

int Key::key_count = 0; // 初始化靜態變數

Key::Key() : Block() {
    symbol = {
        {
            {'$', '$', '$'},
            {' ', '$', ' '},
            {' ', '$', ' '}
        }
    };
    type = tKey;
    key_id = ++key_count; // 為新建的 Key 分配一個唯一 ID
}

int Key::get_key_id() const {
    return key_id;
}

void Key::player_touched() {
    // 不需要任何操作,撿起 Key 的邏輯將在 Player 的 move 函數中實現
}