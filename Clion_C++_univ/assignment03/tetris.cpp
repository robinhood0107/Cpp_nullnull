#include "tetris.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

void init_game(GameState& state) {
    //srand(888);  // for testing
    srand(time(NULL));
    state.board = std::vector<std::vector<char>>(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, '.'));
    state.current_block = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));
    state.tetrominoes = {
        // I-tetromino (2 rotations)
        {
            {
                {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 1, 0}
            }
        },
        // O-tetromino (1 rotation)
        {
            {
                {0, 1, 1, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            }
        },
    };
    
    state.current_tetromino = 0;
    state.current_rotation = 0;
    state.block_x = 0;
    state.block_y = 0;
    state.score = 0;
    state.level = 1;
    state.lines_cleared = 0;
    state.high_score = 0;
    state.running = true;
    state.next_tetromino = rand() % state.tetrominoes.size();
    state.fall_timer = 0;
    state.fall_interval = 10 - (state.level - 1);
    if (state.fall_interval < 1) state.fall_interval = 1;
    spawn_new_block(state);
}


void handle_game_action(GameState& state, int action) {
    switch (action) {
        case ACTION_QUIT:
            state.running = false;
            break;
        case ACTION_LEFT:
            move_block(state, -1, 0);
            break;
        case ACTION_RIGHT:
            move_block(state, 1, 0);
            break;
        case ACTION_DOWN:
            move_block(state, 0, 1);
            break;
        // case ACTION_ROTATE:
        //     rotate_block(state);
            break;
        case ACTION_DROP:
            drop_block_to_bottom(state);
            break;
        default:
            break;
    }
}

void update_game(GameState& state) {
    if (++state.fall_timer >= state.fall_interval) {
        // Implmenet your code
        // move block
        // check landing
        
        state.fall_timer = 0;
        state.fall_interval = 10 - (state.level - 1);
        if (state.fall_interval < 1) state.fall_interval = 1;
    }
}

bool move_block(GameState& state, int dx, int dy) {
    // Implmenet your code
}

void drop_block_to_bottom(GameState& state) {
    
    // Implmenet your code
    
}

void spawn_new_block(GameState& state) {
    // Implmenet your code
    for (int i = 4; i < 8; i++) {
        state.board[0][i] = '#';
    }
    state.running = true;

}

// Implmenet your code if necessary


