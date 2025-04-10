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
        if (!move_block(state, 0, 1)) { //?꾨옒濡?1移??대젮媛?붿? ?쒕룄
            land_block(state);// ?꾨옒濡??대룞?????놁쑝硫??꾩옱 ?꾩튂??釉붾줉??李⑹?
            //check_lines(state);// ?쇱씤???꾩꽦?섏뿀?붿? ?뺤씤?섍퀬 ?쒓굅(?닿굅???ы븿?섏뼱?덉????딆븯??
            spawn_new_block(state); // ?덈줈??釉붾줉 ?앹꽦
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
    while (move_block(state, 0, 1));// ?꾨옒濡??대룞??遺덇??ν븷 ?뚭퉴吏 怨꾩냽 ?대룞 ?쒕룄
    land_block(state);// ?꾨옒濡??대룞?????놁쑝硫??꾩옱 ?꾩튂??釉붾줉??李⑹?
    //check_lines(state);// ?쇱씤???꾩꽦?섏뿀?붿? ?뺤씤?섍퀬 ?쒓굅(?닿굅???ы븿?섏뼱?덉????딆븯??
    spawn_new_block(state); // ?덈줈??釉붾줉 ?앹꽦
}

void spawn_new_block(GameState& state) {
    // Implmenet your code
    //state.tetrominoes[釉붾줉 醫낅쪟 ?몃뜳??[?뚯쟾 ?곹깭 ?몃뜳??[???몃뜳??[???몃뜳??
    state.current_tetromino = state.next_tetromino;
    state.current_rotation = 0;
    state.current_block = state.tetrominoes[state.current_tetromino][state.current_rotation];
    state.next_tetromino = rand() % state.tetrominoes.size(); //?닿굅 ?댁빞 test 耳?댁뒪???묎컳???섏삤寃???    state.block_x = BOARD_WIDTH / 2 - 2;
    //if (state.current_tetromino == 1) { // O-tetromino 珥덇린 x ?꾩튂 議곗젙
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
    for (int i = 0; i < 4; ++i) {// ?꾩옱 釉붾줉??媛?????쒗쉶
        for (int j = 0; j < 4; ++j) {// 釉붾줉???대떦 ????쒖꽦?붾릺???덈떎硫?            if (state.current_block[i][j] == 1) {
                state.board[state.block_y + i][state.block_x + j] = '#';// 寃뚯엫 蹂대뱶???대떦 ?꾩튂??'#'???쒖떆?섏뿬 釉붾줉??怨좎젙
            }
        }
    }
}







///////////////////////////////////////////////////?닿굅??援ы쁽 ?덊빐???섎뒗 寃?///////////////////////////////////////////////////////
/*
// 寃뚯엫 蹂대뱶?먯꽌 媛??李??쇱씤???뺤씤?섍퀬 ?쒓굅?섎뒗 ?⑥닔
void check_lines(GameState& state) {
    int lines_cleared_in_frame = 0; // ?꾩옱 ?꾨젅?꾩뿉???쒓굅???쇱씤 ??    // 蹂대뱶???꾨옒履쎈????꾩そ?쇰줈 媛??됱쓣 寃??    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool full_line = true; // ?꾩옱 ?됱씠 媛??李쇰뒗吏 ?щ?

        // ?꾩옱 ?됱쓽 紐⑤뱺 ?댁쓣 寃??        for (int x = 0; x < BOARD_WIDTH; ++x) {
            // 鍮?移?'.')???덉쑝硫??꾩옱 ?됱? 媛??李??쇱씤???꾨떂
            if (state.board[y][x] == '.') {
                full_line = false;
                break;
            }
        }

        // ?꾩옱 ?됱씠 媛??李쇰떎硫?        if (full_line) {
            lines_cleared_in_frame++; // ?쒓굅???쇱씤 ??利앷?
            // ?꾩옱 ???꾩쓽 紐⑤뱺 ?됱쓣 ??移몄뵫 ?꾨옒濡??대룞
            for (int yy = y; yy > 0; --yy) {
                state.board[yy] = state.board[yy - 1];
            }
            // 媛?????됱쓣 鍮?移?'.')?쇰줈 梨꾩? (?덈줈??鍮??쇱씤 ?앹꽦)
            state.board[0] = std::vector<char>(BOARD_WIDTH, '.');
            y++; // ?쇱씤???쒓굅?섏뿀?쇰?濡?媛숈? y ?몃뜳?ㅻ? ?ㅼ떆 寃??(?대룞???쇱씤)
        }
    }

    // ?쒓굅???쇱씤???덈떎硫??먯닔? ?덈꺼 ?낅뜲?댄듃
    if (lines_cleared_in_frame > 0) {
        state.lines_cleared += lines_cleared_in_frame; // 珥??쒓굅???쇱씤 ???낅뜲?댄듃
        // ?먯닔 怨꾩궛: (?쒓굅???쇱씤 ??^2 * 湲곕낯 ?먯닔 * ?덈꺼
        state.score += (lines_cleared_in_frame * lines_cleared_in_frame * 100 * state.level);
        // ?덈꺼 ?낅뜲?댄듃: ?쒓굅???쇱씤 ?섍? 10??諛곗닔媛 ???뚮쭏???덈꺼 利앷?
        state.level = state.lines_cleared / 10 + 1;
        // ?덈꺼???곕씪 ?숉븯 ?띾룄 議곗젙
        state.fall_interval = 20 - (state.level - 1) * 2;
        if (state.fall_interval < 1) state.fall_interval = 1; // 理쒖냼 ?숉븯 媛꾧꺽 蹂댁옣
    }
}
*/





///?꾩껜 肄붾뱶 二쇱꽍?щ┛ 踰꾩쟾///
/*
#include "tetris.h" // ?뚰듃由ъ뒪 愿???ㅻ뜑 ?뚯씪 ?ы븿
#include <cstdlib>   // ?쒖닔 ?앹꽦???꾪븳 ?ㅻ뜑 ?뚯씪 ?ы븿
#include <ctime>     // ?쒓컙 愿???⑥닔瑜??꾪븳 ?ㅻ뜑 ?뚯씪 ?ы븿 (?쒖닔 ?쒕뱶 ?ㅼ젙???ъ슜)
#include <fstream>   // ?뚯씪 ?낆텧?μ쓣 ?꾪븳 ?ㅻ뜑 ?뚯씪 ?ы븿 (?꾩옱???ъ슜?섏? ?딆쓬)
#include <iostream>  // ?쒖? ?낆텧?μ쓣 ?꾪븳 ?ㅻ뜑 ?뚯씪 ?ы븿 (?꾩옱???ъ슜?섏? ?딆쓬)
using namespace std;  // std ?ㅼ엫?ㅽ럹?댁뒪 ?ъ슜

// 釉붾줉??二쇱뼱吏??꾩튂媛 寃뚯엫 蹂대뱶 ?댁뿉???좏슚?쒖? ?뺤씤?섎뒗 ?⑥닔 ?좎뼵
bool is_valid_position(const std::vector<std::vector<int>>& block, int x, int y, const std::vector<std::vector<char>>& board);

// ?꾩옱 ?吏곸씠??釉붾줉??寃뚯엫 蹂대뱶??李⑹??쒗궎???⑥닔 ?좎뼵
void land_block(GameState& state);

// 寃뚯엫 蹂대뱶?먯꽌 媛??李??쇱씤???뺤씤?섍퀬 ?쒓굅?섎뒗 ?⑥닔 ?좎뼵
void check_lines(GameState& state);

// ?덈줈??釉붾줉???앹꽦?섍퀬 寃뚯엫 ?곹깭瑜?珥덇린?뷀븯???⑥닔 ?좎뼵
void spawn_new_block(GameState& state);

// 寃뚯엫 ?곹깭瑜?珥덇린?뷀븯???⑥닔
void init_game(GameState& state) {
    //srand(888);  // for testing // ?뚯뒪?몄슜 怨좎젙 ?쒕뱶
    srand(time(NULL)); // ?꾩옱 ?쒓컙???쒕뱶濡??ъ슜?섏뿬 留ㅻ쾲 ?ㅻⅨ ?쒖닔 ?앹꽦

    // 寃뚯엫 蹂대뱶 珥덇린?? BOARD_HEIGHT x BOARD_WIDTH ?ш린??2李⑥썝 踰≫꽣瑜?'.'?쇰줈 梨꾩?
    state.board = std::vector<std::vector<char>>(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, '.'));

    // ?꾩옱 ?吏곸씠??釉붾줉 珥덇린?? 4x4 ?ш린??2李⑥썝 踰≫꽣瑜?0?쇰줈 梨꾩?
    state.current_block = std::vector<std::vector<int>>(4, std::vector<int>(4, 0));

    // ?뚰듃由щ???紐⑥뼇 ?뺤쓽 (I-釉붾줉 2媛吏 ?뚯쟾, O-釉붾줉 1媛吏 ?뚯쟾)
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

    // ?꾩옱 ?뚰듃由щ???醫낅쪟瑜??쒕뜡?섍쾶 ?좏깮
    state.current_tetromino = rand() % state.tetrominoes.size();
    // ?꾩옱 ?뚰듃由щ????뚯쟾 ?곹깭 珥덇린??    state.current_rotation = 0;
    // ?꾩옱 釉붾줉??珥덇린 x ?꾩튂 ?ㅼ젙 (蹂대뱶 以묒븰 ?쎄컙 ?쇱そ)
    state.block_x = BOARD_WIDTH / 2 - 2;
    // O-釉붾줉??寃쎌슦 珥덇린 x ?꾩튂 議곗젙 (O-釉붾줉? ??씠 2?대?濡?
    if (state.current_tetromino == 1) { // O-tetromino 珥덇린 x ?꾩튂 議곗젙
        state.block_x = BOARD_WIDTH / 2 - 1;
    }
    // ?꾩옱 釉붾줉??珥덇린 y ?꾩튂 ?ㅼ젙 (蹂대뱶 留???
    state.block_y = 0;
    // 寃뚯엫 ?먯닔 珥덇린??    state.score = 0;
    // 寃뚯엫 ?덈꺼 珥덇린??    state.level = 1;
    // ?쒓굅???쇱씤 ??珥덇린??    state.lines_cleared = 0;
    // 理쒓퀬 ?먯닔 珥덇린??(?꾩옱??濡쒕뱶 湲곕뒫 ?놁쓬)
    state.high_score = 0;
    // 寃뚯엫 ?ㅽ뻾 ?곹깭瑜?true濡??ㅼ젙
    state.running = true;
    // ?ㅼ쓬 ?뚰듃由щ???醫낅쪟瑜??쒕뜡?섍쾶 ?좏깮
    state.next_tetromino = rand() % state.tetrominoes.size();
    // 釉붾줉 ?먮룞 ?숉븯 ??대㉧ 珥덇린??    state.fall_timer = 0;
    // 釉붾줉 ?먮룞 ?숉븯 媛꾧꺽 ?ㅼ젙 (?꾨젅???⑥쐞, 珥덇린 ?띾룄)
    state.fall_interval = 20; // 珥덇린 ?숉븯 ?띾룄 (?꾨젅???⑥쐞)
    // ?덈줈??釉붾줉???앹꽦?섏뿬 寃뚯엫 ?쒖옉 以鍮?    spawn_new_block(state);
}

// ?ъ슜???낅젰 ?≪뀡??泥섎━?섎뒗 ?⑥닔
void handle_game_action(GameState& state, int action) {
    switch (action) {
        case ACTION_QUIT: // 醫낅즺 ?≪뀡
            state.running = false; // 寃뚯엫 ?ㅽ뻾 ?곹깭瑜?false濡?蹂寃쏀븯??寃뚯엫 猷⑦봽 醫낅즺
            break;
        case ACTION_LEFT: // ?쇱そ ?대룞 ?≪뀡
            move_block(state, -1, 0); // 釉붾줉???쇱そ?쇰줈 1移??대룞 ?쒕룄
            break;
        case ACTION_RIGHT: // ?ㅻⅨ履??대룞 ?≪뀡
            move_block(state, 1, 0);  // 釉붾줉???ㅻⅨ履쎌쑝濡?1移??대룞 ?쒕룄
            break;
        case ACTION_DOWN: // ?꾨옒履??대룞 ?≪뀡 (soft drop)
            move_block(state, 0, 1);  // 釉붾줉???꾨옒履쎌쑝濡?1移??대룞 ?쒕룄
            break;
        // case ACTION_ROTATE: // ?뚯쟾 ?≪뀡 (?꾩옱 誘멸뎄??
        //     rotate_block(state);
            break;
        case ACTION_DROP: // ?섎뱶 ?쒕∼ ?≪뀡
            drop_block_to_bottom(state); // 釉붾줉??媛?ν븳 媛???꾨옒履쎌쑝濡?利됱떆 ?대룞
            break;
        default: // ?뺤쓽?섏? ?딆? ?≪뀡
            break;
    }
}

// 寃뚯엫 ?곹깭瑜??낅뜲?댄듃?섎뒗 ?⑥닔 (?먮룞 ?숉븯 泥섎━)
void update_game(GameState& state) {
    // fall_timer瑜?利앷??쒖폒 寃쎄낵???꾨젅?꾩쓣 異붿쟻
    if (++state.fall_timer >= state.fall_interval) {
        // 釉붾줉???꾨옒濡??대룞?????덈뒗吏 ?쒕룄
        if (!move_block(state, 0, 1)) {
            // ?꾨옒濡??대룞?????놁쑝硫??꾩옱 ?꾩튂??釉붾줉??李⑹?
            land_block(state);
            // ?쇱씤???꾩꽦?섏뿀?붿? ?뺤씤?섍퀬 ?쒓굅
            check_lines(state);
            // ?덈줈??釉붾줉 ?앹꽦
            spawn_new_block(state);
            // ?덈줈??釉붾줉 ?앹꽦 ?꾩튂媛 ?좏슚?섏? ?딆쑝硫?寃뚯엫 ?ㅻ쾭
            if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) {
                state.running = false; // Game Over
            }
        }
        // ?숉븯 ??대㉧ 珥덇린??        state.fall_timer = 0;
        // ?덈꺼???곕씪 ?숉븯 ?띾룄 議곗젙 (?덈꺼???щ씪媛덉닔濡??숉븯 媛꾧꺽 媛먯냼)
        state.fall_interval = 20 - (state.level - 1) * 2;
        // 理쒖냼 ?숉븯 媛꾧꺽 蹂댁옣
        if (state.fall_interval < 1) state.fall_interval = 1;
    }
}

// 釉붾줉??dx, dy 留뚰겮 ?대룞?쒗궎???⑥닔
bool move_block(GameState& state, int dx, int dy) {
    // ?대룞???덈줈??x, y 醫뚰몴 怨꾩궛
    int new_x = state.block_x + dx;
    int new_y = state.block_y + dy;
    // ?덈줈???꾩튂媛 ?좏슚?쒖? ?뺤씤
    if (is_valid_position(state.current_block, new_x, new_y, state.board)) {
        // ?좏슚?섎㈃ 釉붾줉??x, y 醫뚰몴 ?낅뜲?댄듃
        state.block_x = new_x;
        state.block_y = new_y;
        return true; // ?대룞 ?깃났
    }
    return false; // ?대룞 ?ㅽ뙣 (踰쎌씠???ㅻⅨ 釉붾줉??遺?ろ옒)
}

// 釉붾줉??媛?ν븳 媛???꾨옒履쎌쑝濡?利됱떆 ?대룞?쒗궎???⑥닔 (?섎뱶 ?쒕∼)
void drop_block_to_bottom(GameState& state) {
    // ?꾨옒濡??대룞??遺덇??ν븷 ?뚭퉴吏 怨꾩냽 ?대룞 ?쒕룄
    while (move_block(state, 0, 1));
    // ?꾩옱 ?꾩튂??釉붾줉 李⑹?
    land_block(state);
    // ?쇱씤 泥댄겕 諛??쒓굅
    check_lines(state);
    // ?덈줈??釉붾줉 ?앹꽦
    spawn_new_block(state);
    // ?덈줈??釉붾줉 ?앹꽦 ?꾩튂媛 ?좏슚?섏? ?딆쑝硫?寃뚯엫 ?ㅻ쾭
    if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) {
        state.running = false; // Game Over
    }
}

// ?덈줈??釉붾줉???앹꽦?섍퀬 珥덇린 ?꾩튂瑜??ㅼ젙?섎뒗 ?⑥닔
void spawn_new_block(GameState& state) {
//state.tetrominoes[釉붾줉 醫낅쪟 ?몃뜳??[?뚯쟾 ?곹깭 ?몃뜳??[???몃뜳??[???몃뜳??
//state.tetrominoes[釉붾줉 醫낅쪟 ?몃뜳??[?뚯쟾 ?곹깭 ?몃뜳??[???몃뜳??[???몃뜳??
//(?닿굅 瑗?湲곗뼲!!!)
    // ?ㅼ쓬 釉붾줉 醫낅쪟瑜??꾩옱 釉붾줉?쇰줈 ?ㅼ젙
    state.current_tetromino = state.next_tetromino;
    // ?ㅼ쓬 釉붾줉 醫낅쪟瑜??쒕뜡?섍쾶 ?좏깮
    state.next_tetromino = rand() % state.tetrominoes.size();
    // ?꾩옱 釉붾줉???뚯쟾 ?곹깭 珥덇린??    state.current_rotation = 0;
    // ?꾩옱 釉붾줉??紐⑥뼇???ㅼ젙
    state.current_block = state.tetrominoes[state.current_tetromino][state.current_rotation];
    // ?꾩옱 釉붾줉??珥덇린 x ?꾩튂 ?ㅼ젙 (蹂대뱶 以묒븰 ?쎄컙 ?쇱そ)
    state.block_x = BOARD_WIDTH / 2 - 2;
    // O-釉붾줉??寃쎌슦 珥덇린 x ?꾩튂 議곗젙
    if (state.current_tetromino == 1) { // O-tetromino 珥덇린 x ?꾩튂 議곗젙
        state.block_x = BOARD_WIDTH / 2 - 1;
    }
    // ?꾩옱 釉붾줉??珥덇린 y ?꾩튂 ?ㅼ젙 (蹂대뱶 留???
    state.block_y = 0;

    // ?덈줈??釉붾줉??珥덇린 ?꾩튂媛 ?좏슚?섏? ?딆쑝硫?寃뚯엫 ?ㅻ쾭
    if (!is_valid_position(state.current_block, state.block_x, state.block_y, state.board)) {
        state.running = false; // ?덈줈??釉붾줉 ?앹꽦 ?꾩튂媛 ?좏슚?섏? ?딆쑝硫?寃뚯엫 ?ㅻ쾭
    }
}

// 釉붾줉??二쇱뼱吏??꾩튂媛 寃뚯엫 蹂대뱶 ?댁뿉???좏슚?쒖? ?뺤씤?섎뒗 ?⑥닔
bool is_valid_position(const std::vector<std::vector<int>>& block, int x, int y, const std::vector<std::vector<char>>& board) {
    // 釉붾줉??媛?????쒗쉶
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            // 釉붾줉???대떦 ????쒖꽦?붾릺???덈떎硫?            if (block[i][j] == 1) {
                // 蹂대뱶?먯꽌???ㅼ젣 x, y 醫뚰몴 怨꾩궛
                int board_x = x + j;
                int board_y = y + i;

                // 蹂대뱶 寃쎄퀎 寃??                if (board_y < 0 || board_y >= BOARD_HEIGHT || board_x < 0 || board_x >= BOARD_WIDTH) {
                    return false; // 蹂대뱶 寃쎄퀎瑜?踰쀬뼱?섎㈃ ?좏슚?섏? ?딆쓬
                }

                // 異⑸룎 寃?? 蹂대뱶???대떦 ?꾩튂???대? ?ㅻⅨ 釉붾줉???덈뒗吏 ?뺤씤
                if (board_y >= 0 && board[board_y][board_x] == '#') {
                    return false; // ?대? ?ㅻⅨ 釉붾줉???덉쑝硫??좏슚?섏? ?딆쓬
                }
            }
        }
    }
    return true; // 紐⑤뱺 議곌굔??留뚯”?섎㈃ ?좏슚???꾩튂
}

// ?꾩옱 ?吏곸씠??釉붾줉??寃뚯엫 蹂대뱶??李⑹??쒗궎???⑥닔
void land_block(GameState& state) {
    // ?꾩옱 釉붾줉??媛?????쒗쉶
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            // 釉붾줉???대떦 ????쒖꽦?붾릺???덈떎硫?            if (state.current_block[i][j] == 1) {
                // 寃뚯엫 蹂대뱶???대떦 ?꾩튂??'#'???쒖떆?섏뿬 釉붾줉??怨좎젙
                state.board[state.block_y + i][state.block_x + j] = '#';
            }
        }
    }
}

// 寃뚯엫 蹂대뱶?먯꽌 媛??李??쇱씤???뺤씤?섍퀬 ?쒓굅?섎뒗 ?⑥닔
void check_lines(GameState& state) {
    int lines_cleared_in_frame = 0; // ?꾩옱 ?꾨젅?꾩뿉???쒓굅???쇱씤 ??    // 蹂대뱶???꾨옒履쎈????꾩そ?쇰줈 媛??됱쓣 寃??    for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
        bool full_line = true; // ?꾩옱 ?됱씠 媛??李쇰뒗吏 ?щ?

        // ?꾩옱 ?됱쓽 紐⑤뱺 ?댁쓣 寃??        for (int x = 0; x < BOARD_WIDTH; ++x) {
            // 鍮?移?'.')???덉쑝硫??꾩옱 ?됱? 媛??李??쇱씤???꾨떂
            if (state.board[y][x] == '.') {
                full_line = false;
                break;
            }
        }

        // ?꾩옱 ?됱씠 媛??李쇰떎硫?        if (full_line) {
            lines_cleared_in_frame++; // ?쒓굅???쇱씤 ??利앷?
            // ?꾩옱 ???꾩쓽 紐⑤뱺 ?됱쓣 ??移몄뵫 ?꾨옒濡??대룞
            for (int yy = y; yy > 0; --yy) {
                state.board[yy] = state.board[yy - 1];
            }
            // 媛?????됱쓣 鍮?移?'.')?쇰줈 梨꾩? (?덈줈??鍮??쇱씤 ?앹꽦)
            state.board[0] = std::vector<char>(BOARD_WIDTH, '.');
            y++; // ?쇱씤???쒓굅?섏뿀?쇰?濡?媛숈? y ?몃뜳?ㅻ? ?ㅼ떆 寃??(?대룞???쇱씤)
        }
    }

    // ?쒓굅???쇱씤???덈떎硫??먯닔? ?덈꺼 ?낅뜲?댄듃
    if (lines_cleared_in_frame > 0) {
        state.lines_cleared += lines_cleared_in_frame; // 珥??쒓굅???쇱씤 ???낅뜲?댄듃
        // ?먯닔 怨꾩궛: (?쒓굅???쇱씤 ??^2 * 湲곕낯 ?먯닔 * ?덈꺼
        state.score += (lines_cleared_in_frame * lines_cleared_in_frame * 100 * state.level);
        // ?덈꺼 ?낅뜲?댄듃: ?쒓굅???쇱씤 ?섍? 10??諛곗닔媛 ???뚮쭏???덈꺼 利앷?
        state.level = state.lines_cleared / 10 + 1;
        // ?덈꺼???곕씪 ?숉븯 ?띾룄 議곗젙
        state.fall_interval = 20 - (state.level - 1) * 2;
        if (state.fall_interval < 1) state.fall_interval = 1; // 理쒖냼 ?숉븯 媛꾧꺽 蹂댁옣
    }
}
 */

