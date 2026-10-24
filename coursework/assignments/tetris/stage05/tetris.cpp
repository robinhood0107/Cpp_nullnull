#include "tetris.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

void init_game(GameState& state) {
    srand(888);
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
        // T-tetromino (4 rotations)
        {
            {
                {0, 1, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            }
        },
        // S-tetromino (2 rotations)
        {
            {
                {0, 1, 1, 0},
                {1, 1, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            }
        },
        // Z-tetromino (2 rotations)
        {
            {
                {1, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 1, 0},
                {0, 1, 1, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            }
        },
        // J-tetromino (4 rotations)
        {
            {
                {1, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 1, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {1, 1, 0, 0},
                {0, 0, 0, 0}
            }
        },
        // L-tetromino (4 rotations)
        {
            {
                {0, 0, 1, 0},
                {1, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}
            },
            {
                {0, 0, 0, 0},
                {1, 1, 1, 0},
                {1, 0, 0, 0},
                {0, 0, 0, 0}
            },
            {
                {1, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0}
            }
        }
    };
    
    state.current_tetromino = 0;
    state.current_rotation = 0;
    state.block_x = 0;
    state.block_y = 0;
    state.score = 0;
    state.level = 1;
    state.lines_cleared = 0;
    state.high_score = 2200;
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
        case ACTION_ROTATE:
            rotate_block(state);
            break;
        case ACTION_DROP:
            drop_block_to_bottom(state);
            break;
        default:
            break;
    }
}

// Implement your code
bool is_valid_position(const std::vector<std::vector<int>>& block, int x, int y, const std::vector<std::vector<char>>& board) { //착각 금지) 앞에 is로 네이밍 한 만큼 true가 회전 및 이동 가능하다는 것 
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (block[i][j] == 1) {
                int board_x = x + j;
                int board_y = y + i;
                if (board_y < 0 || board_y >= BOARD_HEIGHT || board_x < 0 || board_x >= BOARD_WIDTH) {
                    return false;
                }
                if (board_y >= 0 && board[board_y][board_x] == '#') {
                    return false;
                }
            }
        }
    }
    return true;
}

void rotate_block(GameState& state) {
        int total_rotations = 4;
        int next_R = (state.current_rotation + 1) % total_rotations; //%는 나머지를 남기는 연산이므로 0은 0도 1은 90도 2는 180도 .. 이런식으로 가는 것
        int kind_R = state.tetrominoes[state.current_tetromino].size(); //회전의 종류개수 //이런식으로 없는 행은 예외처리를 해줘야겠다고 생각함
        if (next_R >= 0 && next_R < kind_R) { //회전가능시
            std::vector<std::vector<int>> temp_rotation_block = state.tetrominoes[state.current_tetromino][next_R]; //말 그대로 임시로 돌린 다음 블럭 2차원 배열 = 2차원 배열(4차원 배열의 2차원 배열)
            if (is_valid_position(temp_rotation_block, state.block_x, state.block_y,state.board)) { //블럭을 돌려도 될 경우(앞에 ! 붙임)
                //is_valid_position ----> true가 회전 및 이동 가능하다는 것
                //임시로 돌린게 만족하는지 확인
                // 내가 실수한 점 : is_valid_position에 들어가야하는 block은 임시로 돌린 블록이어야 한다(이 임시 블럭이 벽에 안닿아야 실제로 회전시키니까)
                state.current_block = temp_rotation_block;
                state.current_rotation = next_R;
            }
        }
}

void check_lines(GameState& state) {
    int deleted_line_num = 0; // 현재 프레임에서 제거된 라인 수에 대한 변수다 // 가득 찬 라인 수 = 지울 라인 수
    // 이중 for문으로 보드의 아래쪽부터 위쪽으로 각 행을 검사할 것이다.
    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool full_line = true; //일단 다 차있다고 가정하고 내부 for문으로 빈칸 나오면 full_line을 false로 하고 빈칸있다고 처리 후 다음행으로 
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            // 빈 칸('.')이 있으면 현재 행은 가득차있지 않음
            if (state.board[y][x] == '.') {
                full_line = false;
                break;
            }
        }

        // 해당 행이 가득 찼다면 지워야지...
        if (full_line) {
            deleted_line_num++; // 현재 프레임에서 제거된 라인 수에 대한 변수다 // 가득 찬 라인 수 = 지울 라인 수
            // 현재 행 위의 모든 행을 한 칸씩 아래로 이동
            for (int down_y = y; down_y > 0; --down_y) { //down_y를 y로 설정하고 밑으로 계속 내리는거 ->그래서 이름 down_y로 함
                state.board[down_y] = state.board[down_y - 1];
            }
            // 가장 윗 행을 빈 칸('.')으로 채움 (새로운 빈 라인 생성)
            state.board[0] = std::vector<char>(BOARD_WIDTH, '.');
            y++; // 라인이 제거되었으므로 같은 y 인덱스를 다시 검사 (이동된 라인)
        }
    }

    if (deleted_line_num > 0) {
        state.lines_cleared += deleted_line_num;
        state.score += (deleted_line_num * 100 * state.level);
        state.level = state.lines_cleared / 10 + 1;
        state.fall_interval = 20 - (state.level - 1) * 2;
        if (state.fall_interval < 1) state.fall_interval = 1;
    }
}

void spawn_new_block(GameState& state) {
    //state.tetrominoes[블록 종류 인덱스][회전 상태 인덱스][행 인덱스][열 인덱스]
    state.current_tetromino = state.next_tetromino;
    state.current_rotation = 0;
    state.current_block = state.tetrominoes[state.current_tetromino][state.current_rotation];
    state.next_tetromino = rand() % state.tetrominoes.size(); //이거 해야 test 케이스랑 똑같이 나오게 됨
    state.block_x = BOARD_WIDTH / 2 - 2;
    state.block_y = 1;

    //게임 오버 조건
    if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) {
        state.running = false;
    }
}

void drop_block_to_bottom(GameState& state) {
    while (move_block(state, 0, 1));
    land_block(state);
    check_lines(state);
    spawn_new_block(state);
}


void update_game(GameState& state) {
    if (++state.fall_timer >= state.fall_interval) {
        if (!move_block(state, 0, 1)) { 
            land_block(state);
            check_lines(state);
            spawn_new_block(state); 
        }
        state.fall_timer = 0;
        state.fall_interval = 10 - (state.level - 1);
        if (state.fall_interval < 1) state.fall_interval = 1;
    }
}

bool move_block(GameState& state, int dx, int dy) {
    int current_x = state.block_x+dx;
    int current_y = state.block_y+dy;
    if (is_valid_position(state.current_block,current_x,current_y,state.board)) {
        state.block_x = current_x;
        state.block_y = current_y;
        return true;
    }
    else {
        return false;
    }
}

void land_block(GameState& state) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (state.current_block[i][j] == 1) {
                state.board[state.block_y + i][state.block_x + j] = '#';
            }
        }
    }
}

