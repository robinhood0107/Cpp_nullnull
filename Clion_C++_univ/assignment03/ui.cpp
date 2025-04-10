#include "ui.h"
#include <ncursesw/ncurses.h>

void ui_init() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    timeout(0);
}

void ui_cleanup(const GameState& state) {
    endwin();
}

void ui_draw(const GameState& state) {
    int offset_x = 1;
    int offset_y = 1;

    //clear();  // ?붾㈃ 吏?곌린

    // ?곷떒 ?뚮몢由?    mvaddch(offset_y - 1, offset_x - 1, '+');
    mvhline(offset_y - 1, offset_x, '-', BOARD_WIDTH);
    mvaddch(offset_y - 1, offset_x + BOARD_WIDTH, '+');

    // 蹂대뱶? 醫뚯슦 ?뚮몢由?    for (int y = 0; y < BOARD_HEIGHT; ++y) {
        mvaddch(offset_y + y, offset_x - 1, '|');
        for (int x = 0; x < BOARD_WIDTH; ++x) {
            char c = state.board[y][x];
            mvaddch(offset_y + y, offset_x + x, c);
        }
        mvaddch(offset_y + y, offset_x + BOARD_WIDTH, '|');
    }

    // ?섎떒 ?뚮몢由?    mvaddch(offset_y + BOARD_HEIGHT, offset_x - 1, '+');
    mvhline(offset_y + BOARD_HEIGHT, offset_x, '-', BOARD_WIDTH);
    mvaddch(offset_y + BOARD_HEIGHT, offset_x + BOARD_WIDTH, '+');

    // ?꾩옱 釉붾줉
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (state.current_block[i][j]) {
                int draw_x = offset_x + state.block_x + j;
                int draw_y = offset_y + state.block_y + i;
                if (draw_y >= offset_y && draw_y < offset_y + BOARD_HEIGHT &&
                    draw_x >= offset_x && draw_x < offset_x + BOARD_WIDTH) {
                    mvaddch(draw_y, draw_x, '#');
                }
            }
        }
    }

    // ?ъ씠?쒕컮
    int sidebar_x = offset_x + BOARD_WIDTH + 2;
    mvprintw(offset_y, sidebar_x, "Score: %d", state.score);
    mvprintw(offset_y + 1, sidebar_x, "High Score: %d", state.high_score);
    mvprintw(offset_y + 2, sidebar_x, "Level: %d", state.level);
    mvprintw(offset_y + 4, sidebar_x, "Next:");
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            char c = state.tetrominoes[state.next_tetromino][0][i][j] ? '#' : ' ';
            mvaddch(offset_y + 5 + i, sidebar_x + j, c);
        }
    }
    refresh();
}

int convert_ncurses_key_to_action(int key) {
    switch (key) {
        case 'q': return ACTION_QUIT;
        case KEY_LEFT: return ACTION_LEFT;
        case KEY_RIGHT: return ACTION_RIGHT;
        case KEY_DOWN: return ACTION_DOWN;
        //case KEY_UP: return ACTION_ROTATE;
        case ' ': return ACTION_DROP;
        default: return ACTION_NONE;
    }
}

int ui_get_input() {
    int ch = getch();
    return convert_ncurses_key_to_action(ch);
}

