#include "../coursework/assignments/tetris/stage05/tetris.h"
#include <algorithm>
#include <iostream>

int main() {
    GameState state{};
    init_game(state);
    if (!state.running || state.board.size() != BOARD_HEIGHT || state.score != 0) return 1;
    const int start = state.block_x;
    handle_game_action(state, ACTION_LEFT);
    if (state.block_x != start - 1) return 2;
    handle_game_action(state, ACTION_RIGHT);
    if (state.block_x != start) return 3;
    handle_game_action(state, ACTION_ROTATE);
    if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) return 4;
    while (move_block(state, -1, 0)) {}
    const int edge = state.block_x;
    if (move_block(state, -1, 0) || state.block_x != edge) return 5;
    handle_game_action(state, ACTION_DROP);
    bool landed = false;
    for (const auto& row : state.board) landed = landed || std::find(row.begin(), row.end(), '#') != row.end();
    if (!landed) return 6;
    for (auto& row : state.board) std::fill(row.begin(), row.end(), '.');
    std::fill(state.board.back().begin(), state.board.back().end(), '#');
    check_lines(state);
    if (state.lines_cleared != 1 || state.score != 100) return 7;
    handle_game_action(state, ACTION_QUIT);
    if (state.running) return 8;
    std::cout << "테트리스 이동·충돌·착지·줄 제거·종료 검증 통과\n";
}
