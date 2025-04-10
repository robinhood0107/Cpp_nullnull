#include <vector>
#include <ncursesw/ncurses.h>

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

struct GameState {
    std::vector<std::vector<char>> board;
    int block_x, block_y;
    bool running;
};

void init_game(GameState& state);
void spawn_new_block(GameState& state);
void init_ui();
void draw_ui(const GameState& state);
void cleanup_ui();
int ui_get_input();

int main() {
    GameState state;

    init_ui();
    init_game(state);

    while (state.running) {
        draw_ui(state);
        if (ui_get_input() == 1) {
            state.running = false;
        }
    }

    cleanup_ui();
    return 0;
}

void init_game(GameState& state) {

    //Implement your code   

    // Initialize the board with empty spaces ('.')

    // Place a fixed I-block at the top center

    // Set the game to running
    state.board.resize(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, 0));
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            state.board[i][j] = '.';
        }
    }
    state.running = true;
    spawn_new_block(state);
}

void spawn_new_block(GameState& state) {

    //Implement your code  

    // Places the I-block at (4,0)
    for (int i = 4; i < 8; i++) {
        state.board[0][i] = '#';
    }
    state.running = true;
}

void init_ui() {
    initscr();              // Start ncurses mode
    noecho();               // Disable input echo
    cbreak();               // Disable line buffering
    keypad(stdscr, TRUE);   // Enable special keys (arrows)
    curs_set(0);            // Hide cursor
}

void draw_ui(const GameState& state) {
    //clear();

    int width = BOARD_WIDTH;
    int height = BOARD_HEIGHT;
    int offset_x = 2;
    int offset_y = 1;

    mvaddch(offset_y - 1, offset_x - 1, '+');
    mvhline(offset_y - 1, offset_x, '-', width);
    mvaddch(offset_y - 1, offset_x + width, '+');

    for (int y = 0; y < height; ++y) {
        mvaddch(offset_y + y, offset_x - 1, '|');
        for (int x = 0; x < width; ++x) {
            mvaddch(offset_y + y, offset_x + x, state.board[y][x]);
        }
        mvaddch(offset_y + y, offset_x + width, '|');
    }

    mvaddch(offset_y + height, offset_x - 1, '+');
    mvhline(offset_y + height, offset_x, '-', width);
    mvaddch(offset_y + height, offset_x + width, '+');

    refresh();
}

void cleanup_ui() {
    endwin();
}

int ui_get_input() {
    int ch = getch();
    if (ch == 'q') return 1;
    return 0;
}
