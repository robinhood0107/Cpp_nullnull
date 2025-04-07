#include "tetris.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

bool is_valid_position(const std::vector<std::vector<int>>& block, int x, int y, const std::vector<std::vector<char>>& board);
void land_block(GameState& state);
//void check_lines(GameState& state);
void spawn_new_block(GameState& state);

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
        if (!move_block(state, 0, 1)) { //아래로 1칸 내려가는지 시도
            land_block(state);// 아래로 이동할 수 없으면 현재 위치에 블록을 착지
            //check_lines(state);// 라인이 완성되었는지 확인하고 제거(이거는 포함되어있지는 않았음)
            spawn_new_block(state); // 새로운 블록 생성
        }
        state.fall_timer = 0;
        state.fall_interval = 10 - (state.level - 1);
        if (state.fall_interval < 1) state.fall_interval = 1;
    }
}

bool move_block(GameState& state, int dx, int dy) {
    // Implmenet your code
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

void drop_block_to_bottom(GameState& state) {
    // Implmenet your code
    while (move_block(state, 0, 1));// 아래로 이동이 불가능할 때까지 계속 이동 시도
    land_block(state);// 아래로 이동할 수 없으면 현재 위치에 블록을 착지
    //check_lines(state);// 라인이 완성되었는지 확인하고 제거(이거는 포함되어있지는 않았음)
    spawn_new_block(state); // 새로운 블록 생성
}

void spawn_new_block(GameState& state) {
    // Implmenet your code
    //state.tetrominoes[블록 종류 인덱스][회전 상태 인덱스][행 인덱스][열 인덱스]
    state.current_tetromino = state.next_tetromino;
    state.current_rotation = 0;
    state.current_block = state.tetrominoes[state.current_tetromino][state.current_rotation];
    state.next_tetromino = rand() % state.tetrominoes.size(); //이거 해야 test 케이스랑 똑같이 나오게 됨
    state.block_x = BOARD_WIDTH / 2 - 2;
    //if (state.current_tetromino == 1) { // O-tetromino 초기 x 위치 조정
    //    state.block_x = BOARD_WIDTH / 2 - 1;
    //}
    state.block_y = 0;
}

// Implmenet your code if necessary
bool is_valid_position(const std::vector<std::vector<int>>& block, int x, int y, const std::vector<std::vector<char>>& board) {
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

void land_block(GameState& state) {
    for (int i = 0; i < 4; ++i) {// 현재 블록의 각 셀을 순회
        for (int j = 0; j < 4; ++j) {// 블록의 해당 셀이 활성화되어 있다면
            if (state.current_block[i][j] == 1) {
                state.board[state.block_y + i][state.block_x + j] = '#';// 게임 보드의 해당 위치에 '#'을 표시하여 블록을 고정
            }
        }
    }
}







///////////////////////////////////////////////////이거는 구현 안해도 되는 것////////////////////////////////////////////////////////
/*
// 게임 보드에서 가득 찬 라인을 확인하고 제거하는 함수
void check_lines(GameState& state) {
    int lines_cleared_in_frame = 0; // 현재 프레임에서 제거된 라인 수
    // 보드의 아래쪽부터 위쪽으로 각 행을 검사
    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool full_line = true; // 현재 행이 가득 찼는지 여부

        // 현재 행의 모든 열을 검사
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            // 빈 칸('.')이 있으면 현재 행은 가득 찬 라인이 아님
            if (state.board[y][x] == '.') {
                full_line = false;
                break;
            }
        }

        // 현재 행이 가득 찼다면
        if (full_line) {
            lines_cleared_in_frame++; // 제거된 라인 수 증가
            // 현재 행 위의 모든 행을 한 칸씩 아래로 이동
            for (int yy = y; yy > 0; --yy) {
                state.board[yy] = state.board[yy - 1];
            }
            // 가장 윗 행을 빈 칸('.')으로 채움 (새로운 빈 라인 생성)
            state.board[0] = std::vector<char>(BOARD_WIDTH, '.');
            y++; // 라인이 제거되었으므로 같은 y 인덱스를 다시 검사 (이동된 라인)
        }
    }

    // 제거된 라인이 있다면 점수와 레벨 업데이트
    if (lines_cleared_in_frame > 0) {
        state.lines_cleared += lines_cleared_in_frame; // 총 제거된 라인 수 업데이트
        // 점수 계산: (제거된 라인 수)^2 * 기본 점수 * 레벨
        state.score += (lines_cleared_in_frame * lines_cleared_in_frame * 100 * state.level);
        // 레벨 업데이트: 제거된 라인 수가 10의 배수가 될 때마다 레벨 증가
        state.level = state.lines_cleared / 10 + 1;
        // 레벨에 따라 낙하 속도 조정
        state.fall_interval = 20 - (state.level - 1) * 2;
        if (state.fall_interval < 1) state.fall_interval = 1; // 최소 낙하 간격 보장
    }
}
*/





///전체 코드 주석달린 버전///
/*
#include "tetris.h" // 테트리스 관련 헤더 파일 포함
#include <cstdlib>   // 난수 생성을 위한 헤더 파일 포함
#include <ctime>     // 시간 관련 함수를 위한 헤더 파일 포함 (난수 시드 설정에 사용)
#include <fstream>   // 파일 입출력을 위한 헤더 파일 포함 (현재는 사용되지 않음)
#include <iostream>  // 표준 입출력을 위한 헤더 파일 포함 (현재는 사용되지 않음)
using namespace std;  // std 네임스페이스 사용

// 블록의 주어진 위치가 게임 보드 내에서 유효한지 확인하는 함수 선언
bool is_valid_position(const std::vector<std::vector<int>>& block, int x, int y, const std::vector<std::vector<char>>& board);

// 현재 움직이는 블록을 게임 보드에 착지시키는 함수 선언
void land_block(GameState& state);

// 게임 보드에서 가득 찬 라인을 확인하고 제거하는 함수 선언
void check_lines(GameState& state);

// 새로운 블록을 생성하고 게임 상태를 초기화하는 함수 선언
void spawn_new_block(GameState& state);

// 게임 상태를 초기화하는 함수
void init_game(GameState& state) {
    //srand(888);  // for testing // 테스트용 고정 시드
    srand(time(NULL)); // 현재 시간을 시드로 사용하여 매번 다른 난수 생성

    // 게임 보드 초기화: BOARD_HEIGHT x BOARD_WIDTH 크기의 2차원 벡터를 '.'으로 채움
    state.board = std::vector<std::vector<char>>(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, '.'));

    // 현재 움직이는 블록 초기화: 4x4 크기의 2차원 벡터를 0으로 채움
    state.current_block = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));

    // 테트리미노 모양 정의 (I-블록 2가지 회전, O-블록 1가지 회전)
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

    // 현재 테트리미노 종류를 랜덤하게 선택
    state.current_tetromino = rand() % state.tetrominoes.size();
    // 현재 테트리미노 회전 상태 초기화
    state.current_rotation = 0;
    // 현재 블록의 초기 x 위치 설정 (보드 중앙 약간 왼쪽)
    state.block_x = BOARD_WIDTH / 2 - 2;
    // O-블록일 경우 초기 x 위치 조정 (O-블록은 폭이 2이므로)
    if (state.current_tetromino == 1) { // O-tetromino 초기 x 위치 조정
        state.block_x = BOARD_WIDTH / 2 - 1;
    }
    // 현재 블록의 초기 y 위치 설정 (보드 맨 위)
    state.block_y = 0;
    // 게임 점수 초기화
    state.score = 0;
    // 게임 레벨 초기화
    state.level = 1;
    // 제거된 라인 수 초기화
    state.lines_cleared = 0;
    // 최고 점수 초기화 (현재는 로드 기능 없음)
    state.high_score = 0;
    // 게임 실행 상태를 true로 설정
    state.running = true;
    // 다음 테트리미노 종류를 랜덤하게 선택
    state.next_tetromino = rand() % state.tetrominoes.size();
    // 블록 자동 낙하 타이머 초기화
    state.fall_timer = 0;
    // 블록 자동 낙하 간격 설정 (프레임 단위, 초기 속도)
    state.fall_interval = 20; // 초기 낙하 속도 (프레임 단위)
    // 새로운 블록을 생성하여 게임 시작 준비
    spawn_new_block(state);
}

// 사용자 입력 액션을 처리하는 함수
void handle_game_action(GameState& state, int action) {
    switch (action) {
        case ACTION_QUIT: // 종료 액션
            state.running = false; // 게임 실행 상태를 false로 변경하여 게임 루프 종료
            break;
        case ACTION_LEFT: // 왼쪽 이동 액션
            move_block(state, -1, 0); // 블록을 왼쪽으로 1칸 이동 시도
            break;
        case ACTION_RIGHT: // 오른쪽 이동 액션
            move_block(state, 1, 0);  // 블록을 오른쪽으로 1칸 이동 시도
            break;
        case ACTION_DOWN: // 아래쪽 이동 액션 (soft drop)
            move_block(state, 0, 1);  // 블록을 아래쪽으로 1칸 이동 시도
            break;
        // case ACTION_ROTATE: // 회전 액션 (현재 미구현)
        //     rotate_block(state);
            break;
        case ACTION_DROP: // 하드 드롭 액션
            drop_block_to_bottom(state); // 블록을 가능한 가장 아래쪽으로 즉시 이동
            break;
        default: // 정의되지 않은 액션
            break;
    }
}

// 게임 상태를 업데이트하는 함수 (자동 낙하 처리)
void update_game(GameState& state) {
    // fall_timer를 증가시켜 경과된 프레임을 추적
    if (++state.fall_timer >= state.fall_interval) {
        // 블록을 아래로 이동할 수 있는지 시도
        if (!move_block(state, 0, 1)) {
            // 아래로 이동할 수 없으면 현재 위치에 블록을 착지
            land_block(state);
            // 라인이 완성되었는지 확인하고 제거
            check_lines(state);
            // 새로운 블록 생성
            spawn_new_block(state);
            // 새로운 블록 생성 위치가 유효하지 않으면 게임 오버
            if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) {
                state.running = false; // Game Over
            }
        }
        // 낙하 타이머 초기화
        state.fall_timer = 0;
        // 레벨에 따라 낙하 속도 조정 (레벨이 올라갈수록 낙하 간격 감소)
        state.fall_interval = 20 - (state.level - 1) * 2;
        // 최소 낙하 간격 보장
        if (state.fall_interval < 1) state.fall_interval = 1;
    }
}

// 블록을 dx, dy 만큼 이동시키는 함수
bool move_block(GameState& state, int dx, int dy) {
    // 이동할 새로운 x, y 좌표 계산
    int new_x = state.block_x + dx;
    int new_y = state.block_y + dy;
    // 새로운 위치가 유효한지 확인
    if (is_valid_position(state.current_block, new_x, new_y, state.board)) {
        // 유효하면 블록의 x, y 좌표 업데이트
        state.block_x = new_x;
        state.block_y = new_y;
        return true; // 이동 성공
    }
    return false; // 이동 실패 (벽이나 다른 블록에 부딪힘)
}

// 블록을 가능한 가장 아래쪽으로 즉시 이동시키는 함수 (하드 드롭)
void drop_block_to_bottom(GameState& state) {
    // 아래로 이동이 불가능할 때까지 계속 이동 시도
    while (move_block(state, 0, 1));
    // 현재 위치에 블록 착지
    land_block(state);
    // 라인 체크 및 제거
    check_lines(state);
    // 새로운 블록 생성
    spawn_new_block(state);
    // 새로운 블록 생성 위치가 유효하지 않으면 게임 오버
    if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) {
        state.running = false; // Game Over
    }
}

// 새로운 블록을 생성하고 초기 위치를 설정하는 함수
void spawn_new_block(GameState& state) {
//state.tetrominoes[블록 종류 인덱스][회전 상태 인덱스][행 인덱스][열 인덱스]
//state.tetrominoes[블록 종류 인덱스][회전 상태 인덱스][행 인덱스][열 인덱스]
//(이거 꼭 기억!!!)
    // 다음 블록 종류를 현재 블록으로 설정
    state.current_tetromino = state.next_tetromino;
    // 다음 블록 종류를 랜덤하게 선택
    state.next_tetromino = rand() % state.tetrominoes.size();
    // 현재 블록의 회전 상태 초기화
    state.current_rotation = 0;
    // 현재 블록의 모양을 설정
    state.current_block = state.tetrominoes[state.current_tetromino][state.current_rotation];
    // 현재 블록의 초기 x 위치 설정 (보드 중앙 약간 왼쪽)
    state.block_x = BOARD_WIDTH / 2 - 2;
    // O-블록일 경우 초기 x 위치 조정
    if (state.current_tetromino == 1) { // O-tetromino 초기 x 위치 조정
        state.block_x = BOARD_WIDTH / 2 - 1;
    }
    // 현재 블록의 초기 y 위치 설정 (보드 맨 위)
    state.block_y = 0;

    // 새로운 블록의 초기 위치가 유효하지 않으면 게임 오버
    if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) {
        state.running = false; // 새로운 블록 생성 위치가 유효하지 않으면 게임 오버
    }
}

// 블록의 주어진 위치가 게임 보드 내에서 유효한지 확인하는 함수
bool is_valid_position(const std::vector<std::vector<int>>& block, int x, int y, const std::vector<std::vector<char>>& board) {
    // 블록의 각 셀을 순회
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            // 블록의 해당 셀이 활성화되어 있다면
            if (block[i][j] == 1) {
                // 보드에서의 실제 x, y 좌표 계산
                int board_x = x + j;
                int board_y = y + i;

                // 보드 경계 검사
                if (board_y < 0 || board_y >= BOARD_HEIGHT || board_x < 0 || board_x >= BOARD_WIDTH) {
                    return false; // 보드 경계를 벗어나면 유효하지 않음
                }

                // 충돌 검사: 보드의 해당 위치에 이미 다른 블록이 있는지 확인
                if (board_y >= 0 && board[board_y][board_x] == '#') {
                    return false; // 이미 다른 블록이 있으면 유효하지 않음
                }
            }
        }
    }
    return true; // 모든 조건이 만족되면 유효한 위치
}

// 현재 움직이는 블록을 게임 보드에 착지시키는 함수
void land_block(GameState& state) {
    // 현재 블록의 각 셀을 순회
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            // 블록의 해당 셀이 활성화되어 있다면
            if (state.current_block[i][j] == 1) {
                // 게임 보드의 해당 위치에 '#'을 표시하여 블록을 고정
                state.board[state.block_y + i][state.block_x + j] = '#';
            }
        }
    }
}

// 게임 보드에서 가득 찬 라인을 확인하고 제거하는 함수
void check_lines(GameState& state) {
    int lines_cleared_in_frame = 0; // 현재 프레임에서 제거된 라인 수
    // 보드의 아래쪽부터 위쪽으로 각 행을 검사
    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool full_line = true; // 현재 행이 가득 찼는지 여부

        // 현재 행의 모든 열을 검사
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            // 빈 칸('.')이 있으면 현재 행은 가득 찬 라인이 아님
            if (state.board[y][x] == '.') {
                full_line = false;
                break;
            }
        }

        // 현재 행이 가득 찼다면
        if (full_line) {
            lines_cleared_in_frame++; // 제거된 라인 수 증가
            // 현재 행 위의 모든 행을 한 칸씩 아래로 이동
            for (int yy = y; yy > 0; --yy) {
                state.board[yy] = state.board[yy - 1];
            }
            // 가장 윗 행을 빈 칸('.')으로 채움 (새로운 빈 라인 생성)
            state.board[0] = std::vector<char>(BOARD_WIDTH, '.');
            y++; // 라인이 제거되었으므로 같은 y 인덱스를 다시 검사 (이동된 라인)
        }
    }

    // 제거된 라인이 있다면 점수와 레벨 업데이트
    if (lines_cleared_in_frame > 0) {
        state.lines_cleared += lines_cleared_in_frame; // 총 제거된 라인 수 업데이트
        // 점수 계산: (제거된 라인 수)^2 * 기본 점수 * 레벨
        state.score += (lines_cleared_in_frame * lines_cleared_in_frame * 100 * state.level);
        // 레벨 업데이트: 제거된 라인 수가 10의 배수가 될 때마다 레벨 증가
        state.level = state.lines_cleared / 10 + 1;
        // 레벨에 따라 낙하 속도 조정
        state.fall_interval = 20 - (state.level - 1) * 2;
        if (state.fall_interval < 1) state.fall_interval = 1; // 최소 낙하 간격 보장
    }
}
 */

